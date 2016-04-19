#pragma once
#include <tuple>
class Point{
public:
	Point();
	Point(float x, float y, float z);
	Point(const Point &);
	~Point();
	Point & operator=(const Point &);
	float & x();
	const float & x()const;
	float & y();
	const float & y()const;
	float & z();
	const float & z()const;

	void add(const Point &);
	void subtract(const Point &);
	void multiply(const Point &);
	void multiply(const float &);
	Point operator+(const Point &);
	Point operator-(const Point &);
	Point operator*(const Point &);
	Point operator*(const float &);
	Point & operator+=(const Point &);
	Point & operator-=(const Point &);

private:
	std::tuple<float, float, float> * m_position = nullptr;
};