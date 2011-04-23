#include <time.h>
#include "time_utils.h"


void sleep(int miliseconds){
	clock_t t = clock();
	while( miliseconds > clock() - t);
}