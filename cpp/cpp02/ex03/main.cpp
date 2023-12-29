
#include "Point.hpp"
#include <iostream>

int main()
{
	Point origin(0, 0);
	Point p1(10, 0), p2(0, 10);
	Point point_on_x(5, 0);
	std::cout << "[expect 0(out)]" << std::endl;
	std::cout << "point_on_x : " << bsp(origin, p1, p2, point_on_x) << std::endl;
	std::cout << "point_on_x : " << bsp(origin, p2, p1, point_on_x) << std::endl;
	Point point_on_y(0, 5);
	std::cout << "point_on_y : " << bsp(origin, p1, p2, point_on_y) << std::endl;
	std::cout << "point_on_y : " << bsp(origin, p2, p1, point_on_y) << std::endl;
	Point point_on_digonal(5, 5);
	std::cout << "point_on_digonal : " << bsp(origin, p1, p2, point_on_digonal) << std::endl;
	std::cout << "point_on_digonal : " << bsp(origin, p2, p1, point_on_digonal) << std::endl;
	Point point_on_p1(p1);
	std::cout << "point_on_p1 : " << bsp(origin, p1, p2, point_on_p1) << std::endl;
	std::cout << "point_on_p1 : " << bsp(origin, p2, p1, point_on_p1) << std::endl;
	Point point_on_p2(p2);
	std::cout << "point_on_p2 : " << bsp(origin, p1, p2, point_on_p2) << std::endl;
	std::cout << "point_on_p2 : " << bsp(origin, p2, p1, point_on_p2) << std::endl;
	Point point_on_origin(origin);
	std::cout << "point_on_origin : " << bsp(origin, p1, p2, point_on_origin) << std::endl;
	std::cout << "point_on_origin : " << bsp(origin, p2, p1, point_on_origin) << std::endl;
	Point point_under(5, -0.1);
	std::cout << "point_under : " << bsp(origin, p1, p2, point_under) << std::endl;
	std::cout << "point_under : " << bsp(origin, p2, p1, point_under) << std::endl;
	Point point_over(5.1, 5.1);
	std::cout << "point_over : " << bsp(origin, p1, p2, point_over) << std::endl;
	std::cout << "point_over : " << bsp(origin, p2, p1, point_over) << std::endl;
	Point point_left(-0.1, 5);
	std::cout << "point_left : " << bsp(origin, p1, p2, point_left) << std::endl;
	std::cout << "point_left : " << bsp(origin, p2, p1, point_left) << std::endl;
	std::cout << "[expect 1(in)]" << std::endl;
	Point point_inner(0.1, 0.1);
	std::cout << "point_inner : " << bsp(origin, p1, p2, point_inner) << std::endl;
	std::cout << "point_inner : " << bsp(origin, p2, p1, point_inner) << std::endl;
	return 0;
}