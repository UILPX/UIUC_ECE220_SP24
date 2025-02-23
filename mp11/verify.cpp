#include "check.hpp"


int main(int argc, char *argv[]){
	if(argc != 2) {
    	cerr << "USAGE: ./verify_mp11 input.txt" << endl; 
    	return -1;
  	}
	cout << " \n\n ------------------- Begin Verifying MP11 ---------------------" << endl;
	ifstream ifs (argv[1], std::ifstream::in);
    if(ifs.fail()){
        std::cout << "ERROR: " << argv[1] << " does not exist " << endl;
        cout << "-------------------- Stop Verifying MP11 ----------------------" << endl << endl << endl;
        return 0;
    }
    if(!CheckFile(argv[1])){
        std::cout << "ERROR: " << argv[1] << " incorrect input file " << endl;
        cout << "-------------------- Stop Verifying MP11 ----------------------" << endl << endl << endl;
        return 0;
    }
     
    int name_p = CheckGetName();
	int rec_p = CheckRec();
	int cir_p = CheckCircle();	
	int s_p = CheckSphere();
	int rp_p = CheckRectprism();
	int ma_p = CheckMaxArea(argv[1]);
	int mv_p = CheckMaxVolume(argv[1]);
    int cs_p = CheckCreateShape(argv[1]);
	cout << "getName() " << name_p << "/6" << endl;	
	cout << "Rectangle: " << rec_p << "/16" << endl;
	cout << "Circle: " << cir_p << "/16" << endl;
	cout << "Sphere: " << s_p << "/16" << endl;
	cout << "RectPrism: " << rp_p << "/16" << endl;
	cout << "MaxArea(): " << ma_p << "/10" << endl;
	cout << "MaxVolume(): " << mv_p << "/10" << endl;
    cout << "CreateShape() " << cs_p << "/10" << endl;
	cout << "Your total Score for MP11: " << mv_p + ma_p + name_p + rec_p + cir_p + s_p + rp_p + cs_p << "/100" << endl;
	cout << "-------------------- End Verifying MP11 ----------------------" << endl << endl << endl;
	
	return 0;
}
