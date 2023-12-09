/*

#include <iostream>



float cart1[3] = {10, 20, 30};
float cart2[3] = {20, 30, 40};
float r = 1;
float center[3] = {10, 20, 30};



float d[3] = {cart2[0] - cart1[0], cart2[1] - cart1[1], cart2[2] - cart1[2]};
float f[3] = {cart2[0] - center[0], cart2[1] - center[1], cart2[2] - center[2] };


float a = d[0] * d[0] + d[1] * d[1] + d[2] * d[2];

float b = 2* (  f[0] * d[0] + f[1] * d[1] + f[2] * d[2]);
float c = (  f[0] * f[0] + f[1] * f[1] + f[2] * f[2]) - r*r;

float t1 = 0;
float t2 = 0;


float discriminant = b*b-4*a*c;

void SegmentCollision(){

    std::cout << (discriminant >= 0);
}

 */