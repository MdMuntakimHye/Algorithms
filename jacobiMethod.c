#include<stdio.h>
#include<stdlib.h>

#include<math.h>



#define EPS 1.0e-9

int main(void)
{

	int n=0;
	double x1a,x2a,x3a,x1n,x2n,x3n;
	x1a=x2a=x3a=0;
 	
 	while (1) {
 	
 		x1n = (85-(3*x2a-2*x3a))/15;
 		x2n = (51-(2*x1a+1*x3a))/10;
 		x3n = (5-(1*x1a-2*x2a))/8;
 		
 		n++;
 		
 		if (fabs(x1a-x1n)<EPS && fabs(x2a-x2n)<EPS && fabs(x3a-x3n)<EPS) {
 		
 			printf("root = %16.9lf,%16.9lf,%16.9lf\n",x1n,x2n,x3n);
 			printf("Iteration numbers = %d\n",n);
 			exit(0);
 		
 		}
 		
 		x1a = x1n;
 		x2a = x2n;
 		x3a = x3n;
 		
 	
 	}

 }
