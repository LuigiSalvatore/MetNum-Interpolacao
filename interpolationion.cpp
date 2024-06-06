struct point{
    double x;
    double y;
};
#include <iostream>
#include <vector>
using namespace std;


std::vector<point> points;
std::vector<double> res;


void pop(){
    for(int i = 0; i < 10; i++){
        point p;
        p.x = i;
        p.y = i+10;
        points.push_back(p);
    }

}

double p(double x){
    return 3 + 2 * (x - 2) + 0.5833333333333334 * (x - 2) * (x - 3);
}
void doStuff(double d){
    int n_points = points.size();
    for(int i = 0; i < n_points; i++)
        std::cout << "(" << points[i].x << "," << p(points[i].x) << ")" << std::endl;

    for(int i = 0; n_points - 1; i++)
         res.push_back((points[i+1].y) - (points[i].y) / (points[i+1].x - points[i].x));
    
}
void doStuff(double x , double y){
    point a = {2,3}, b = {3,5}, c = {6,4};
    std::cout   << "a: (" << a.x << "," << a.y << ")" << std::endl
                << "b: (" << b.x << "," << b.y << ")" << std::endl
                << "c: (" << c.x << "," << c.y << ")" << std::endl;

    double w = (b.y - a.y) / (b.x - a.x);
    double z = (c.y - b.y) / (c.x - b.x);
    double restult = (z - w) / (c.x - a.x);

    std::cout << "w = ("<< b.y << " - " << a.y << ") / (" << b.x << " - " << a.x << ") = " << w << std::endl; 
    std::cout << "z = ("<< c.y << " - " << b.y << ") / (" << c.x << " - " << b.x << ") = " << z << std::endl;
    std::cout << "Result = (" << z << " - " << w << ") / (" << c.x << " - " << a.x << ") = " << restult << std::endl;
    /*
        p(x) = 3 + 2* (x-2)
        p(x) = 3 + 2* (x-2) + 0.5833333333333334 * (x-2) * (x-3)
    */
    std::cout << "p(x) = " << a.y << " + " << w << " * (x - " << a.x << ")" << std::endl;
}
int main(){
    while(1){
        int x, y;
        std::cin >> x >> y;
        if(x == -1 && y == -1) break;
        point p;
        p.x = x; p.y = y;
        points.push_back(p);
    }
    doStuff(0,0);

    return 0;
}