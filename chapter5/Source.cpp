#include "../../std_lib_facilities.h"

class Bad_area {};

//void error(string s)
//{
//	throw runtime_error(s);
//}


int area(int length, int width)
{
	if (length <= 0 || width <= 0) error("test");//throw Bad_area{};
	return length * width;
}

int framed_area(int x, int y) // calculate area within frame
{
	constexpr int frame_width = 2;
	if (x-frame_width <= 0 || y-frame_width <= 0) throw Bad_area{};
	return area(x-frame_width, y-frame_width);
}

int main() {
	try {
		vector<int> v = { 5, 101, 9, 4, 6, 8 };
		cout << v[6] << "\n";
		int x = -1;
		int y = 2;
		int z = 4;
		// . . .
		if (x = -1) error("x=-1");
		int area1 = area(x, y);
		int area2 = framed_area(1, z);
		int area3 = framed_area(y, z);
		double ratio = area1 / area3;
	}
	catch (Bad_area) {
		cout << "Oops! bad arguments to area()\n";
		return 1;
	}
	//catch (...) {
	//	cerr << "Oops: unknown exception!\n";
	//	keep_window_open();
	//	return 2; // 2 indicates failure
	//}
	catch (exception& k) {
		cerr << "runtime error: " << k.what() << '\n';
		keep_window_open();
		return 1; // 1 indicates failure
	}
}
