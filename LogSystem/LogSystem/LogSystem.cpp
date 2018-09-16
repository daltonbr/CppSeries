// LogSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class Log
{
public:
	enum Level
	{
		LevelError = 1,
		LevelWarning = 2,
		LevelInfo = 4
	};
	
private:
	Level m_LogLevel = LevelInfo;
public:
	void SetLevel(Level level)
	{
		m_LogLevel = level;
	}
	void Error(const char* message)
	{
		if (m_LogLevel >= LevelError)
			std::cout << "[ERROR]: " << message << std::endl;
	}
	void Warn(const char* message)
	{
		if (m_LogLevel >= LevelWarning)
			std::cout << "[WARNING]: " << message << std::endl;
	}
	void Info(const char* message)
	{
		if (m_LogLevel >= LevelInfo)
			std::cout << "[INFO]: " << message << std::endl;
	}
};

int main()
{
	Log log;
	log.SetLevel(Log::LevelWarning);
	log.Warn("Hello!");
	log.Error("Hello!");
	log.Info("Hello!");

	std::cin.get();
}
