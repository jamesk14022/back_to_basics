/* fast method for finding inverse square roots adapted from the Quake 3 source code */
# include <stdio.h>
# include <stdlib.h>

float inv_sq(float number);

int main(int argc, int *argv[]){
	printf("Inverse Square of 9 is %f \n", inv_sq(9.0F));
	printf("Inverse Square of 16 is %f \n", inv_sq(16.0F));
	printf("Inverse Square of 101 is %f \n", inv_sq(101.0F));
}


float inv_sq(float number){
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1 iteration of Newton's rootfinding method 
	return y;
}
