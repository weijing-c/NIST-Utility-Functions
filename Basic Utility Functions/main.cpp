
#include "SpherePoint.h"
#include "SphereSegment.h"
#include "CubePoint.h"


//include proper header files from functions that need to be tested
#include <stdio.h>
#include <time.h>




int main(){

    clock_t start = clock(); //start the clock

    //the code that needs to be timed must be between the start and stop lines

    int iterations = 500000; //iterate function desired amount of times


    for (int i = 0; i < iterations; ++i) {
        //insert function for testing
        //SpherePoint();
        //SegmentCollision();
    }

    int n = 100;
    int i=0;
    while(i<100*n)
        i++;

    clock_t stop = clock(); //stop the clock
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    CubePoint();
    return 0;






}
