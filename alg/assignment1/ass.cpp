#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#define HARD_LIMIT 99999999
struct Point {double x; double y;};
typedef struct Point Point;

bool xcompare(Point p1, Point p2); 
bool ycompare(Point *p1, Point *p2);
double closest_pair(Point* Px, Point* Py[], int size); 
double dist (Point p1, Point p2);

int counter = 0;

int main() {
	std::ifstream in("input.txt");
	std::string line;
	std::getline(in, line);
	int n = atoi(line.c_str());
	Point Px[n];
	Point* Py[n];
	Point point;
	for(int i=0; i<n; i++) {
		in >> point.x;
		in >> point.y;
		Px[i] = point;
		Py[i] = &Px[i];
	}
	std::sort(Px, Px+n, xcompare);
	std::sort(Py, Py+n, ycompare);
	double ans = closest_pair(Px, Py, n);
	int squared = (int)(ans* ans);
	std::cout << "n: "<< n << "ans:" << squared << "c:" << counter << std::endl;
	std::ofstream out("output.txt");
	out << squared;
}

bool xcompare(Point p1, Point p2) {
	return p1.x < p2.x;
}

bool ycompare(Point *p1, Point *p2) {
	return p1->y < p2->y;
}

double dist (Point p1, Point p2) {
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

double closest_pair(Point* Px, Point* Py[], int size) {
	counter++;
	if (size < 4) {
		double min_dist = HARD_LIMIT;
		for(int i=0; i<size; i++) {
			for(int j=i+1; j<size; j++) {
				double point_dist = dist(Px[i], Px[j]);
				min_dist = std::min(min_dist, point_dist);
			}
		}
		return min_dist;
	}
	int mid = ceil(size/2);
	Point x_left[mid], x_right[size-mid];
	std::memcpy(x_left, Px, mid * sizeof(Point));
	std::memcpy(x_right, &Px[mid], (size-mid) * sizeof(Point));
	Point* y_left[mid];
	Point* y_right[size-mid];
	int counter_l = 0, counter_r = 0;
	for (int i=0; i<size; i++) {
		if (Py[i]->x > mid) {
			y_left[counter_l] = Py[i];
			counter_l++;
		} else {
			y_right[counter_r] = Py[i];
			counter_r++;
		}
	}
	double ans_left = closest_pair(x_left, y_left, mid);
	double ans_right = closest_pair(x_right, y_right, size-mid);

	// get delta
	double delta = std::max(ans_left, ans_right);
	double x_star = Px[mid].x;
	std::vector<Point> set_S;
	for(int i=0; i<size; i++) {
		if (x_star - delta <= Py[i]->x && Py[i]->x <= x_star + delta) {
			set_S.push_back(*Py[i]);
		}
	}
	int set_size = set_S.size();
	Point array_s[set_size];
	std::copy(set_S.begin(), set_S.end(), array_s);
	double mid_min_dist = HARD_LIMIT;
	for (int i=0;i<set_size;i++) {
	}
	for (int i=0; i<set_size; i++) {
		int comparing_points = std::min(11, set_size-i-1);
		for (int j=1; j<= comparing_points; ++j) {
			mid_min_dist = std::min(mid_min_dist,dist(array_s[i], array_s[i+j])); 
		}
	}
	return std::min(delta, mid_min_dist);
}


