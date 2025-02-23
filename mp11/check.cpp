#include "check.hpp"
#include "gshape.hpp"
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<list>
#include<fstream>
#include <iomanip>    

using namespace std;

bool isEqual(double d1, double d2) {
	return abs(d1 - d2) < 0.001;
}

bool CheckFile(char* fileName){

list<GShape*> gshapes = CreateGShapesGold(fileName);
if (gshapes.size() == 0)
	return false;
if (gshapes.front() == NULL) {
    printf("%d", gshapes.size());
	return false;
}
return true;
}


int CheckMaxArea(char* fileName){
	int score = 10;
	list<Shape*> shapes1 = CreateShapes(fileName);
    list<GShape*> gshapes1 = CreateGShapesGold(fileName);

    list<Shape*> shapes2(2, NULL);
	shapes2.front() = new Rectangle<double>(3.0, 2.0);
	shapes2.back() = new Rectangle<double>(2.0, 5.0);
	list<GShape*> gshapes2(2, NULL);
	gshapes2.front() = new GRectangle(3, 2);
	gshapes2.back() = new GRectangle(2, 5);

	if(!isEqual(MaxArea(shapes1), MaxAreaGold(gshapes1)) || !isEqual(MaxArea(shapes2), MaxAreaGold(gshapes2))){

		cout << "Maxarea() or constructors are incorrect" << endl;
		score = 0;
	}
	return score;


}

int CheckMaxVolume(char* fileName){
	int score = 10;
	list<Shape*> shapes1 = CreateShapes(fileName);
    list<GShape*> gshapes1 = CreateGShapesGold(fileName);

    list<Shape*> shapes2(2, NULL);
	shapes2.front() = new Rectangle<double>(3.0, 2.0);
	shapes2.back() = new Rectangle<double>(2.0, 5.0);
	list<GShape*> gshapes2(2, NULL);
	gshapes2.front() = new GRectangle(3, 2);
	gshapes2.back() = new GRectangle(2, 5);
	

	if(!isEqual(MaxVolume(shapes1), MaxVolumeGold(gshapes1)) || !isEqual(MaxVolume(shapes2), MaxVolumeGold(gshapes2))){

		cout << "MaxVolume() or Constructors are incorrect" << endl;
		score = 0;
	}
	return score;


}

int CheckRec(){
	int score = 16;
	Rectangle<double> rec1(4, 5);
	Rectangle<double>  rec2(3, 2);
	Rectangle<double>  rec3(10, 3);
	Rectangle<double>  rec4 = rec1 + rec2;
	Rectangle<double>  rec5 = rec1 - rec3;
	Rectangle<int> rec6((int)3.2, (int)3.2);
	Rectangle<int> rec7(1, 2);
	Rectangle<int> rec8 = rec6 - rec7;

	double area1 = 20, area2 = 6, area3 = 30;
	double vol1 = 0, vol2 = 0, vol3 = 0, vol6 = 0, vol7 = 0;
	double w4 = 7, l4 = 7;
	double w5 = 0, l5 = 2;
	double w1 = 4, w1n = 1;
	int w8 = 2, l8 = 1;
	double area6 = 9.0;
	double area7 = 2.0;
	if(!isEqual(rec1.getArea(), area1) || !isEqual(rec2.getArea(), area2) || !isEqual(rec3.getArea(), area3)|| !isEqual(rec6.getArea(), area6)|| !isEqual(rec7.getArea(), area7)){
		cout << "Rectangle::getArea() incorrect " << endl;
		score -= 4;
	}	
	if(!isEqual(rec1.getVolume(), vol1) || !isEqual(rec2.getVolume(), vol2) || !isEqual(rec3.getVolume(), vol3)|| !isEqual(rec6.getVolume(), vol6)|| !isEqual(rec7.getVolume(), vol7)){
		cout << "Rectangle::getVolume() incorrect " << endl;
		score -= 4;
	}	
    if(!isEqual(rec4.getLength(), l4) || !isEqual(rec4.getWidth() , w4)){
		cout << "Rectangle::operator + incorrect " << endl;
		score -= 4;
	}	
	if(!isEqual(rec5.getLength(), l5) || !isEqual(rec5.getWidth(), w5)|| !isEqual(rec8.getWidth(), w8)|| !isEqual(rec8.getWidth(), w8)){
		cout << "Rectangle::operator - incorrect " << endl;
		score -= 4;
	}	

	// rec7 = rec1;
	// rec1.setWidth(w1);
	// if(!isEqual(rec7.getWidth(), w1n)){
	// 	cout << "Rectangle::clear() incorrect" << endl;
	// 	score -= 8;
	// }

	return score;
}


int CheckRectprism(){
	int score = 16;
	RectPrism recp1(4, 5, 1);
	RectPrism recp2(3, 2, 5);
	RectPrism recp3(10, 3, 6);
	RectPrism recp4 = recp1 + recp2;
	RectPrism recp5 = recp3 - recp2;

	double area1 = 58, area2 = 62, area3 = 216;
	double vol1 = 20, vol2 = 30, vol3 = 180;
	double w4 =	7, l4 = 7, h4 = 6;
	double w5 = 7, l5 = 1, h5 = 1;
	double w1 = 4, w1n = 1;
	if(!isEqual(recp1.getArea(), area1) || !isEqual(recp2.getArea(), area2) || !isEqual(recp3.getArea(), area3)){
		cout << "RectPrism::getArea() incorrect " << endl;
		score -= 4;
	}	
	if(!isEqual(recp1.getVolume(), vol1) || !isEqual(recp2.getVolume(), vol2) || !isEqual(recp3.getVolume(), vol3)){
		cout << "RectPrism::getVolume() incorrect " << endl;
		score -= 4;
	}	
    if(!isEqual(recp4.getLength() , l4) || !isEqual(recp4.getWidth() , w4) || !isEqual(recp4.getHeight() , h4)){
		cout << "RectPrism::operator + incorrect " << endl;
		score -= 4;
	}	
	if(!isEqual(recp5.getLength(), l5) || !isEqual(recp5.getWidth(), w5) || !isEqual(recp5.getHeight() , h5)){
		cout << "RectPrism::operator - incorrect " << endl;
		score -= 4;
	}	

	return score;

}

int CheckSphere(){
	int score = 16;
	Sphere sph1(4);
	Sphere sph2(3);
	Sphere sph3(10);
	Sphere sph4 = sph1 + sph2;
	Sphere sph5 = sph3 - sph2;

	double area1 = M_PI * 64.0, area2 = M_PI * 36.0, area3 = M_PI * 400.0;
	double vol1 = (4.0 / 3.0) * M_PI * 64.0, vol2 = (4.0 / 3.0) * M_PI * 27.0, vol3 = (4.0 / 3.0) * M_PI * 1000.0;
	double r4 =	7;
	double r5 = 7;
	double r1 = 4;
	if(!isEqual(sph1.getArea(), area1) || !isEqual(sph2.getArea(), area2) || !isEqual(sph3.getArea(), area3)){
		cout << "Sphere::getArea() incorrect " << endl;
		score -= 4;
	}	
	if(!isEqual(sph1.getVolume(), vol1) || !isEqual(sph2.getVolume(), vol2) || !isEqual(sph3.getVolume(), vol3)){
		cout << "Sphere::getVolume() incorrect " << endl;
		score -= 4;
	}	
    if(!isEqual(sph4.getRadius(), r4)){
		cout << "Sphere::operator + incorrect " << endl;
		score -= 4;
	}	
	if(!isEqual(sph5.getRadius(), r5)){
		cout << "Sphere::operator - incorrect " << endl;
		score -= 4;
	}	

	return score;

}

int CheckCircle(){
	int score = 16;
	Circle sph1(4);
	Circle sph2(3);
	Circle sph3(10);
	Circle sph4 = sph1 + sph2;
	Circle sph5 = sph3 - sph2;

	double area1 = M_PI * 16.0, area2 = M_PI * 9.0, area3 = M_PI * 100.0;

	double r4 =	7;
	double r5 = 7;
	double r1 = 4;
	if(!isEqual(sph1.getArea(), area1) || !isEqual(sph2.getArea(), area2) || !isEqual(sph3.getArea(), area3)){
		cout << "Circle::getArea() incorrect " << endl;
		score -= 4;
	}	
	if(!isEqual(sph1.getVolume(), 0.0) || !isEqual(sph2.getVolume(), 0.0) || !isEqual(sph3.getVolume(), 0.0)){
		cout << "Circle::getVolume() incorrect " << endl;
		score -= 4;
	}	
    if(!isEqual(sph4.getRadius(), r4)){
		cout << "Circle::operator + incorrect " << endl;
		score -= 4;
	}	
	if(!isEqual(sph5.getRadius(), r5)){
		cout << "Circle::operator - incorrect " << endl;
		score -= 4;
	}	

	return score;

}

int CheckGetName(){
	int score = 6;
	Rectangle<double> rec = Rectangle<double>(1.0, 2.0);
	RectPrism rc = RectPrism(4, 3, 2);	
	if(rec.getName() != "Rectangle" || rc.getName() != "RectPrism"){
		cout << "Shape::getName incorrect " << endl;
		score -= 6;
	}	
	return score;


}

int CheckCreateShape(char* file_name){
    list<GShape*> shapes_gold = CreateGShapesGold(file_name);
    list<Shape*> shapes = CreateShapes(file_name);
    if(shapes_gold.size() != shapes.size() || shapes.size() == 0){
        cout << "CreateShape incorrect" << endl;
        return 0;
    }
    for(list<Shape*>::iterator it= shapes.begin(); it != shapes.end(); it++){
        if (*it == NULL){
            cout << "CreateShape incorrect" << endl;
            return 0;
        }
    }
	list<Shape*>::iterator it = shapes.begin();
	list<GShape*>::iterator it_gold = shapes_gold.begin();
	
    for(int i = 0; i < shapes_gold.size(); ++i){
        if ((*it)->getName() != (*it_gold)->getName()){
            cout << "CreateShape() or getName() incorrect" << endl;
            return 0;
        }

        else if((*it_gold)->getName() == "Rectangle"){
            if(dynamic_cast<GRectangle*>(*it_gold)->getWidth() != dynamic_cast<Rectangle<double>*>(*it)->getWidth() 
             || dynamic_cast<GRectangle*>(*it_gold)->getLength() != dynamic_cast<Rectangle<double>*>(*it)->getLength())
            {
                cout << "CreateShape() or Rectangle incorrect" << endl;
                return 0;
            }
        }
        else if((*it_gold)->getName() == "RectPrism"){
            if(dynamic_cast<GRectPrism*>(*it_gold)->getWidth() != dynamic_cast<RectPrism*>(*it)->getWidth() || dynamic_cast<GRectPrism*>(*it_gold)->getLength() !=dynamic_cast<RectPrism*>(*it)->getLength()  ||dynamic_cast<GRectPrism*>(*it_gold)->getHeight() != dynamic_cast<RectPrism*>(*it)->getHeight() )
            {
                cout << "CreateShape() or RectPrism incorrect" << endl;
                return 0;
            }
        }
		else if((*it_gold)->getName() == "Sphere"){
            if(dynamic_cast<GSphere*>(*it_gold)->getRadius() != dynamic_cast<Sphere*>(*it)->getRadius() )
            {
                cout << "CreateShape() or Sphere incorrect" << endl;
                return 0;
            }
        }
		else if((*it_gold)->getName() == "Circle"){
            if(dynamic_cast<GCircle*>(*it_gold)->getRadius() != dynamic_cast<Circle*>(*it)->getRadius() )
            {
                cout << "CreateShape() or Circle incorrect" << endl;
                return 0;
            }
        }
        else{
            cout << "CreateShape() incorrect" << endl;
            return 0;

        }
    

    }
    return 10;


}


