#ifndef __LOGGER_H__
#define __LOGGER_H__
#include <iostream>
#include "../GbStructs.h"

constexpr auto PREF_ERROR = "ERROR  ::  ";
constexpr auto PREF_DEBUG = "DEBUG  ::  ";

class Logger
{
public:
	static void Debug(std::string msg);
	static void Debug(Registers r);
	static void Debug(CpuInstruction inst);
	static void Error(CpuInstruction inst);

	static void FalseBreakpoint();
};


#endif /!__LOGGER_H__

