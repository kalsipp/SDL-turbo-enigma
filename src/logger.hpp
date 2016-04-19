#pragma once
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
/*
filename is placed in /logs
just choose filename as name.ending
*/
class Logger{
public:
	Logger(const std::string &  filename);
	void log(const std::string &  message);
private:
	std::string m_filename;
	std::chrono::system_clock::time_point m_start_time;
};

