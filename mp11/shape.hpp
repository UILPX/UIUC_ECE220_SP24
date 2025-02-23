#ifndef SHAPE_H_
#define SHAPE_H_

#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<list>
#include<fstream>
#include <iomanip>    

using namespace std;

//Base class
//Please implement Shape's member functions
//constructor, getName()
class Shape{
public:
	//Base class' constructor should be called in derived classes'
	//constructor to initizlize Shape's private variable 
  	Shape(string name) {
		name_ = name;
	}
	
  	string getName() {
		return name_;
	}
	
  	virtual double getArea() const = 0;
  	virtual double getVolume() const = 0;
	
private:
  string name_;


};

//Rectangle
//Please implement the member functions of Rectangle:
//constructor, getArea(), getVolume(), operator+, operator-, getWidth(), getLength()

template <class T>
class Rectangle : public Shape{
public:
  	Rectangle<T>(T width = 0, T length = 0):Shape("Rectangle") {
		width_ = width;
		length_ = length;
	}
	
  	double getArea() const {
		return (double)width_*length_;
	}
	
  	double getVolume() const {
		return 0;
	}
	
	Rectangle<T> operator + (const Rectangle<T>& rec) {
		return (Rectangle<T>{width_ + rec.getWidth(), length_ + rec.getLength()});
	}
	
	Rectangle<T> operator - (const Rectangle<T>& rec) {
		T newWidth = max(0.0,(double)(width_ - rec.getWidth()));
		T newLength = max(0.0,(double)(length_ - rec.getLength()));
		return Rectangle<T>(newWidth, newLength);
	} 
	
	T getWidth() const { 
		return width_;
	}
	
	T getLength() const { 
		return length_;
	}
private:
	T width_;
    T length_;

};

//Circle
//Please implement the member functions of Circle:
//constructor, getArea(), getVolume(), operator+, operator-, getRadius()

class Circle : public Shape{
public:
  	Circle(double radius):Shape("Circle") {
		radius_ = radius;
	}
	
  	double getArea() const{
		return radius_ * radius_ * M_PI;
	}
	
 	double getVolume() const{
		return 0;
	}
	
  	Circle operator + (const Circle& cir){
		return Circle(radius_ + cir.getRadius());
	}
	
	Circle operator - (const Circle& cir){
		double newRadius = max(0.0, radius_ - cir.getRadius());
		return Circle(newRadius);
	} 

	double getRadius() const { 
		return radius_;
	}
	
private:
	double radius_;
};



//Sphere
//Please implement the member functions of Sphere:
//constructor, getArea(), getVolume(), operator+, operator-, getRadius()

class Sphere : public Shape{
public:
  	Sphere(double radius):Shape("Sphere") {
		radius_=radius;
	}

  	double getVolume() const {
		return ((4.0/3.0)* radius_* radius_* radius_ * M_PI); 
	}	
	
  	double getArea() const {
		return 4.0*M_PI* radius_* radius_;
	}

	Sphere operator + (const Sphere& sph) {
		return Sphere(radius_ + sph.getRadius());
	}

	Sphere operator - (const Sphere& sph) {
		double newRadius = max(0.0,radius_ - sph.getRadius());
		return Sphere(newRadius);
	} 
	
	double getRadius() const {
		return radius_;
	}

private:
	double radius_;

};

//Rectprism
//Please implement the member functions of RectPrism:
//constructor, getArea(), getVolume(), operator+, operator-,
//getWidth(), getLength(), getHeight()

class RectPrism : public Shape{
public:
  	RectPrism(double width, double length, double height):Shape("RectPrism") {
		width_ = width;
		length_ = length;
		height_ = height;
	}
	
  	double getVolume() const {
		return length_*width_*height_;
	}
  	
	double getArea() const {
		return 2*(length_*width_+length_*height_+width_*height_);
	}
	
	RectPrism operator + (const RectPrism& rectp){
		return RectPrism(width_+ rectp.getWidth(), length_+ rectp.getLength(), height_+rectp.getHeight());
	}
	
	RectPrism operator - (const RectPrism& rectp){
		double newWidth = max(0.0, width_ - rectp.getWidth());
		double newLength = max(0.0, length_ - rectp.getLength());
		double newHeight = max(0.0, height_ - rectp.getHeight());
		return RectPrism(newWidth,newLength,newHeight);
	}	
	
	double getWidth() const { 
		return width_;
	}
	
	double getLength() const { 
		return length_;
	}
	
	double getHeight() const { 
		return height_;
	}
  
private:
  	double length_;
  	double width_;
  	double height_;

};

// Read shapes from test.txt and initialize the objects
// Return a vector of pointers that points to the objects 

static list<Shape*> CreateShapes(char* file_name) {
	//@@Insert your code here
	list<Shape*> shapes;
	ifstream ifs(file_name);

	string shapeType;
	while(ifs >>shapeType){
        if (shapeType == "Circle") {
            double radius;
            ifs >> radius;
            shapes.push_back(new Circle(radius));
        } else if (shapeType == "Rectangle") {
            double width, length;
            ifs >> width >> length;
            shapes.push_back(new Rectangle<double>(width, length));
        } else if (shapeType == "Sphere") {
            double radius;
            ifs >> radius;
            shapes.push_back(new Sphere(radius));
        } else if (shapeType == "RectPrism") {
            double width, length, height;
            ifs >> width >> length >> height;
            shapes.push_back(new RectPrism(width, length, height));
        }
	}

	ifs.close();
	return shapes;
}

// call getArea() of each object 
// return the max area
static double MaxArea(list<Shape*> shapes){
	double max_area = 0;
	//@@Insert your code here
	double area;
	for(list<Shape*>::iterator ita = shapes.begin(); ita != shapes.end();ita++){
		area = (*ita)->getArea();
		if(area > max_area){
			max_area= area;
		}
	}
	
	return max_area;
}

// call getVolume() of each object 
// return the max volume
static double MaxVolume(list<Shape*> shapes){
	double max_volume = 0;
	//@@Insert your code here
	double volume;
	for(list<Shape*>::iterator itv = shapes.begin();itv != shapes.end();itv++){
		volume = (*itv)->getVolume();
		if(volume>max_volume){
			max_volume= volume;
		}
	}
	
	return max_volume;
}
#endif

