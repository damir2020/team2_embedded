/*
sudo -i

echo "#in" > /sys/class/gpio/export
echo "#out" > /sys/class/gpio/export

echo "in" > /sys/class/gpio/gpio#in/direction
echo "out" > /sys/class/gpio/gpio#out/direction

*/


/*
sudo apt-get install --no-install-recommends bluetooth

hcitool scan

sudo rfcomm connect 0 12:34:56:78:90:00 10 >/dev/null &

hcitool rssi 12:34:56:78:90:00

watch -n 0.5 hcitool rssi 12:34:56:78:90:00
*/



/*
#include <linux/i2c-dev.h>

using namespace std;

int main(){



  return 0
}
