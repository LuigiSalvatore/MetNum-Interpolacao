#include <iostream> 
#include <stdio.h>   

using namespace std;

class Calc
{

    int    n;       
    int    i, j;    
    double t;      
    double c[100];  
    double w[100];  
    double s;       

    public:
        void calc();
        double interpolateNewton(double x[], double y[], int n, double t);
};

void Calc::calc()
{
    double x[] = {2, 4, 6, 8, 10, 12};
    double y[] = {95, 135, 190, 265, 385, 516};

    n = sizeof(x) / sizeof(x[0]);

    printf("      x      y\n");
    for (t = x[0]; t <= x[n - 1]; t += .2)
        printf("%7.2f%7.2f\n", t, interpolateNewton(x, y, n, t));
}

double Calc::interpolateNewton(double x[], double y[], int n, double t)
{
    for (i = 0; i < n; i++) {
        w[i] = y[i];
        for (j = i - 1; j >= 0; j--)
            w[j] = (w[j+1] - w[j]) / (x[i] - x[j]);
        c[i] = w[0];
    }
    s = c[n-1];
    for (i = n - 2; i >= 0; i--)
        s = s * (t - x[i]) + c[i];

    return s;
}


int main()
{
    Calc objCalc;
    objCalc.calc();
    return 0;
}