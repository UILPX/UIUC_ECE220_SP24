#ifndef GSHAPE_H_
#define GSHAPE_H_

#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<list>
#include<fstream>
#include <iomanip>    

using namespace std;


class GShape{
public:
  	GShape(string name);
  	string getName();
  	virtual double getArea() const = 0;
  	virtual double getVolume() const = 0;
	
private:
  string name_;


};



class GRectangle : public GShape{
public:
  	GRectangle(double width = 0, double length = 0);
  	virtual double getArea() const;
  	virtual double getVolume() const;
	GRectangle operator + (const GRectangle& rec);
	GRectangle operator - (const GRectangle& rec);
	double getWidth() const;
	double getLength() const;
private:
	double width_;
  	double length_;

};


class GCircle : public GShape{
public:
  	GCircle(double radius);
  	virtual double getArea() const;
 	virtual double getVolume() const;
  	GCircle operator + (const GCircle& cir);
	GCircle operator - (const GCircle& cir);
	double getRadius() const;
private:
	double radius_;

};





class GSphere : public GShape{
public:
  	GSphere(double radius);
  	virtual double getVolume() const;
  	virtual double getArea() const;
	GSphere operator + (const GSphere& sph);
	GSphere operator - (const GSphere& sph);
	double getRadius() const;

private:
	double radius_;

};

class GRectPrism : public GShape{
public:
  	GRectPrism(double width, double length, double height);
  	virtual double getVolume() const;
  	virtual double getArea() const;
	GRectPrism operator + (const GRectPrism& rectp);
	GRectPrism operator - (const GRectPrism& rectp);
	double getWidth() const;
	double getLength() const;
	double getHeight() const;
private:
  	double length_;
  	double width_;
  	double height_;



};

list<GShape*> CreateGShapesGold(char* file_name);
double MaxAreaGold(list<GShape*> shapes);
double MaxVolumeGold(list<GShape*> shapes);

#endif
