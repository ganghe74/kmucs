#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(void) {
	ifstream inStream;
	int numTestCases;

	inStream.open("input.txt"); //open input file
	if(inStream.fail()) {
		cerr << "Input file opening failed.\n";
		exit(1);
	}
	//read the number of test casese
	inStream >> numTestCases;

	for(int i=0; i<numTestCases; i++)
    {
 	    float a1, a2, b1, b2, c1, c2;
		inStream >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
		//cout << a1 << a2 << b1 << b2 << c1 << c2 << endl;

		float a = (a1-b1)*(a1-b1) + (a2-b2)*(a2-b2);
		float b = (b1-c1)*(b1-c1) + (b2-c2)*(b2-c2);
		float c = (c1-a1)*(c1-a1) + (c2-a2)*(c2-a2);
		//cout << a << " " << b << " " << c << endl;
		if((b2-a2)/(b1-a1) != (c2-a2)/(c1-a1))
        { // 세점이 한 직선에 있지 않을 때
			float top;
			float mid, bot;

			if(a>=b) {
				if(a>=c) {
					top = a; mid = b; bot = c;
				} else {
					top = c; mid = a; bot = b;
				}
			} else {
				if(b>=c) {
					top = b; mid = a; bot = c;
				} else {
					top = c; mid = b; bot = a;
				}
			}

			//cout << top << " " << mid << " " << bot << endl;
            if((a1==b1)&&(a2==b2) ||(b1==c1)&&(b2==c2) || (c1==a1)&&(c2==a2)) // 중복되는 점이 있는 경우 
                cout<<"0"<<"\n";
			else if(top == mid + bot) cout << 1 << endl; // 직각
			else if(top > mid + bot) cout << 2 << endl; // 둔각
			else if(top < mid + bot) cout << 3 << endl; // 예각
		} else cout << 0 << endl; // 세점이 한 직선에 있어서 삼각형을 만들지 못할때
	}


	inStream.close(); //close input file

	return 0;
}