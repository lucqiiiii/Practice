#include <iostream>
#include "Point3d.h"
using namespace std;

Point3d::Point3d(double x, double y, double z):x(x),y(y),z(z){
}

void Point3d::setX(double x){
    this -> x = x;
}

void Point3d::setY(double y){
    this -> y = y;
}

void Point3d::setZ(double z){
    this ->z = z;
}

void Point3d::shift(int axis, double distance){
    if (axis == 0){
        x += distance;
    }
    else if (axis == 1){
        y += distance;
    }
    else{
        z += distance;
    }
}

double Point3d::getX() const{
    return x;
}

double Point3d::getY() const{
    return y;
}

double Point3d::getZ() const{
    return z;
}

bool operator == (const Point3d& p1, const Point3d& p2){
    if(p1.getX() == p2.getX() && p1.getY() == p2.getY() && p1.getZ() == p2.getZ()){
    //if(p1.x == p2.x && p1.y == p2.y && p1.z == p2.z){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Point3d p(3.0,0.0,5.0);
    Point3d q(0,0,0);
    Point3d r(-5,-5,9);
    q.setX(-5);
    q.setY(-5);
    q.setZ(7);
    cout<< p.getX() << endl;
    cout<< p.getY() << endl;
    cout<< p.getZ() << endl;
    cout<< q.getX() << endl;
    cout<< q.getY() << endl;
    cout<< q.getZ() << endl;
    p.shift(0,4);
    q.shift(2,2);
    cout<< p.getX() << endl;
    cout<< p.getY() << endl;
    cout<< p.getZ() << endl;
    cout<< q.getX() << endl;
    cout<< q.getY() << endl;
    cout<< q.getZ() << endl;    
    if (q == r){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    return 0;
}

