#include <stdio.h>
#include <math.h>
#define ep 1e-9

double function1(double x2, double x3, double a11, double a12, double a13, double b1){
    return (b1-(a12*x2)-(a13*x3))/a11;
}

double function2(double x1, double x3, double a21, double a22, double a23, double b2){
    return (b2-(a21*x1)-(a23*x3))/a22;
}

double function3(double x1, double x2, double a31, double a32, double a33, double b3){
    return (b3-(a31*x1)-(a32*x2))/a33;
}


int main(void){
    double a11, a12, a13, b1, a21, a22, a23, b2, a31, a32, a33, b3;
    double x1_boomer, x2_boomer, x3_boomer, x1_genz, x2_genz, x3_genz, e1, e2, e3, max_error;
    x1_boomer = x2_boomer = x3_boomer = 0.0;
    int itr=0;
    
    printf("enter a11,a12,a13 and b1\n");
    scanf("%lf%lf%lf%lf",&a11,&a12,&a13,&b1);
    printf("enter a21,a22,a23 and b2\n");
    scanf("%lf%lf%lf%lf",&a21,&a22,&a23,&b2);
    printf("enter a31,a32,a33 and b3\n");
    scanf("%lf%lf%lf%lf",&a31,&a32,&a33,&b3);

    //check
    if((!(fabs(a11)>fabs(a12)+fabs(a13)) && 
        !(fabs(a22)>fabs(a21)+fabs(a23)) &&
        !(fabs(a33)>fabs(a31)+fabs(a33))))
    {
        printf("This is not valid for Jacobis iteration method!");
        return 0;
    }

    while(1){
        itr++;
        x1_genz = function1(x2_boomer,x3_boomer, a11, a12, a13, b1);
        x2_genz = function2(x1_boomer,x3_boomer, a21, a22, a23, b2);
        x3_genz = function3(x1_boomer,x2_boomer, a31, a32, a33, b3);

        e1 = fabs(x1_boomer-x1_genz);
        e2 = fabs(x2_boomer-x2_genz);
        e3 = fabs(x3_boomer-x3_genz);

        if(e1>e2 && e2>e1){
            max_error = e1;
        }
        else if(e2>e1 && e1>e3){
            max_error = e2;
        }
        else{
            max_error = e3;
        }

        x1_boomer = x1_genz;
        x2_boomer = x2_genz;
        x3_boomer = x3_genz;

        if(max_error<ep)
            break;
    }

    printf("Total iteration: %d\n", itr);
    printf("Answer: x=%0.3lf, y=%0.3lf and z = %0.3lf\n",x1_genz,x2_genz,x3_genz);

    return 0;
}
