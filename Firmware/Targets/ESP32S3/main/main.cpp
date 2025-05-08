/* C++ exception handling example

   orhan yigit durmaz
   hi
*/

#include <cstdio>
#include <cstdlib>
void* lol = 0;
/* Inside .cpp file, app_main function must be declared with C linkage */
extern "C" void app_main(void)
{
	printf("DONE");
	while (1) {lol = malloc(12200);};
}

//originally this file has the setup functions for stm32 peripherals.
//what im going to do is to not include all of them here, just enough to make it think it is doing it
