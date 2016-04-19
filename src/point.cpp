#include "point.hpp"

Point::Point(){
	m_position = new std::tuple<float, float, float>(0,0,0);
}
Point::Point(float x, float y, float z){
	m_position = new std::tuple<float, float, float>(x,y,z);
}
Point::Point(const Point & other){
	m_position = new std::tuple<float, float, float>(other.x(), other.y(), other.z());
}
Point::~Point(){
	if(m_position != nullptr){
		delete m_position;
		m_position = nullptr;
	}
}
Point & Point::operator=(const Point & other){
	x() = other.x();
	y() = other.y();
	z() = other.z();
	return *this;
}

float & Point::x(){
	return std::get<0>(*m_position);
}
const float & Point::x()const{
	return std::get<0>(*m_position);
}
float & Point::y(){
	return std::get<1>(*m_position);
}
const float & Point::y()const{
	return std::get<1>(*m_position);
}
float & Point::z(){
	return std::get<2>(*m_position);
}
const float & Point::z()const{
	return std::get<2>(*m_position);
}

void Point::add(const Point &other){
	x() += other.x();
	y() += other.y();
	z() += other.z();
}
void Point::subtract(const Point & other){
	x() -= other.x();
	y() -= other.y();
	z() -= other.z();
}
void Point::multiply(const Point & other){
	x() *= other.x();
	y() *= other.y();
	z() *= other.z();
}
void Point::multiply(const float & val){
	x() *= val;
	y() *= val;
	z() *= val;
}
Point Point::operator+(const Point & other){
	Point p(*this);
	p.add(other);
	return p;
}
Point Point::operator-(const Point & other){
	Point p(*this);
	p.subtract(other);
	return p;
}
Point Point::operator*(const Point & other){
	Point p(*this);
	p.multiply(other);
	return p;
}
Point Point::operator*(const float & val){
	Point p(*this);
	p.multiply(val);
	return p;
}
Point & Point::operator+=(const Point & other){
	add(other);
	return *this;
}
Point & Point::operator-=(const Point & other){
	subtract(other);
	return *this;
}
/*
*/