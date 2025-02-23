#ifndef CHECK_H_
#define CHECK_H_

#include<cmath>
#include<vector>
#include<fstream>
#include <iomanip>    
#include<fstream>
#include <iomanip>   
#include "shape.hpp"
using namespace std;
//int CheckCreateShapes(char* fileName);
int CheckMaxVolume(char* fileName);
int CheckMaxArea(char* fileName);
int CheckRec();
int CheckCircle();
int CheckSphere();
int CheckRectprism();
int CheckGetName();
int CheckCreateShape(char* fileName);
bool CheckFile(char* fileName);
//vector<Shape*> GoldenCreateShapes(char* file_name);

#endif
