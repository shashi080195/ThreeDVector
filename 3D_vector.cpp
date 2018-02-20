/*
Created By : Shashi Shekhar
Date : 20 Feb 2018
pushed at github : https://github.com/shashi080195
*/
#include<bits/stdc++.h>
using namespace std;

class ThreeDVector
{
protected :
    float x;
    float y;
    float z;
public :
    float inline dotProduct(const ThreeDVector &second);
    ThreeDVector crossProduct(const ThreeDVector &second);
};

class Vector : public ThreeDVector
{
public :
    Vector(float x,float y,float z)
    {
        this->x=x;
        this->y=y;
        this->z=z;
    };
    Vector()
    {
        this->x=0;
        this->y=0;
        this->z=0;
    }
    ///getter and setter methods
    void setX(float x)
    {
        this->x=x;
    }
    float getX()
    {
        return this->x;
    }
    void setY(float y)
    {
        this->y=y;
    }
    float getY()
    {
        return this->y;
    }
    void setZ(float z)
    {
        this->z=z;
    }
    float getZ()
    {
        return this->z;
    }
    ///inherited function from base class to calculate dot product of two 3D vector
    float inline dotProduct(const Vector &second)
    {
        return this->x * second.x + this->y * second.y + this->z * second.z;
    }
    ///inherited function from base class to calculate cross product of two 3D vector
    Vector crossProduct(const Vector &second)
    {
         return Vector((this->y * second.z - this->z * second.y),
                  (this->z * second.x - this->x * second.z),
                  (this->x * second.y - this->y * second.x));
    }
    ///function to find out whether two vectors are parallel or not
    bool areParallel(const Vector &second)
    {
        Vector third = crossProduct(second);
        if(third.getX()==0&&third.getY()==0&&third.getZ()==0)
            return true;
        return false;
    }
    ///functions to calculate whether two vectors are perpendicular or not
    bool arePerpendicular(const Vector &second)
    {
        return dotProduct(second)==0;
    }
    ///overloaded '+' operator to add two vectors
    inline Vector operator+(const Vector &second)
    {
        return Vector(this->x+second.x, this->y+second.y, this->z+second.z);
    }
    ///overloaded '-' operator to subtract two vectors
    inline Vector operator-(const Vector &second)
    {
        return Vector(this->x-second.x, this->y-second.y, this->z-second.z);
    }
    ///overloaded '*" operator for scalar multiplication
    inline Vector operator*(float scalar)
    {
        return Vector(this->x * scalar, this->y * scalar, this->z * scalar);
    }
    ///overloaded output stream operator to display vector
    friend ostream& operator<<(ostream& os, const Vector& first);
};

ostream& operator<<(ostream& os, const Vector& first)
{
    os<<first.x<<"i";
    if(first.y<0)
        os<<first.y<<"j";
    else
        os<<"+"<<first.y<<"j";

    if(first.z<0)
        os<<first.z<<"k";
    else
        os<<"-"<<first.z<<"k";
    return os;
}

int main()
{

    Vector first(2,1,1) , second(3,-6,0) ,third;
    third = first + second;
    cout<<first<<" + "<<second<<" = "<<third<<endl;
    cout<<" 3.25 * "<<third<<" = "<<(third*3.25)<<endl;

    cout<<"dot product of "<<first<<" and "<<second<<"="<<first.dotProduct(second)<<endl;
    cout<<"cross product of "<<first<<" and "<<second<<"="<<first.crossProduct(second)<<endl;
}
