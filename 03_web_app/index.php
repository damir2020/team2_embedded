<?php
//index.php
$connect = mysqli_connect("localhost", "root", "labuser", "sensor_log");

 
  $query = '
  SELECT sensor_value, UNIX_TIMESTAMP(timestamp) AS datetime  
  FROM table_sensor_log 
  WHERE UNIX_TIMESTAMP(timestamp)>= '.time().'-24070
  ORDER BY timestamp ASC
  LIMIT 600
  '; 
 

$result = mysqli_query($connect, $query);
$rows = array();
$table = array();

$table['cols'] = array(
 array(
  'label' => 'Date Time', 
  'type' => 'datetime'
 ),
 array(
  'label' => 'Temperature (°C)', 
  'type' => 'number'
 )
);

while($row = mysqli_fetch_array($result))
{
 $sub_array = array();
 $datetime = explode(".", $row["datetime"]);
 $sub_array[] =  array(
      "v" => 'Date(' . $datetime[0] . '000)'
     );
 $sub_array[] =  array(
      "v" => $row["sensor_value"]
     );
 $rows[] =  array(
     "c" => $sub_array
    );
}
$table['rows'] = $rows;
$jsonTable = json_encode($table);

if($_POST['timestamp']!=''){
  header('Content-type:application/json');
  echo $jsonTable;
  exit();
 }

?>


<html>
 <head>
  <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
  <script type="text/javascript" src="//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
  <script type="text/javascript">
   google.charts.load('current', {'packages':['corechart']});
   google.charts.setOnLoadCallback(drawChart);
   function drawChart()
   {
    jsonTable = <?php echo $jsonTable;?>;
    window.data = new google.visualization.DataTable(<?php echo $jsonTable; ?>);

    window.options = {
     title:'Sensors Data',
     legend:{position:'bottom'},
     chartArea:{width:'95%', height:'65%'}
    };

    window.chart = new google.visualization.LineChart(document.getElementById('line_chart'));

    chart.draw(data, options);
   }

   function updateChart(jsonTable){
    data = new google.visualization.DataTable(jsonTable);
 
    chart.draw(data, options);
   }
    setInterval(function(){
       $.post('',{'timestamp':2},function(jT){ updateChart(jT);},'json');
    },1000);
    
  </script>
  <style>
  .page-wrapper
  {
   width:1000px;
   margin:0 auto;
  }
  </style>
 </head>  
 <body>
  <div class="page-wrapper">
   <br />
   <h2 align="center">Display Google Line Chart with JSON PHP & Mysql</h2>
   <div id="line_chart" style="width: 100%; height: 500px"></div>
  </div>
 </body>
</html>