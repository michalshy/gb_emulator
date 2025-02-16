#include "Logger.h"

void Logger::Debug(Registers r)
{
	std::cout << "Regs \n"
		<< "AF: " << std::hex << r.af << " \n"
		<< "BC: " << std::hex << r.bc << " \n"
		<< "DE: " << std::hex << r.de << " \n"
		<< "HL: " << std::hex << r.hl << " \n"
		<< "PC: " << std::hex << r.pc << " \n"
		<< "SP: " << std::hex << r.sp << " \n";
}

void Logger::Debug(CpuInstruction inst)
{
	std::string msg = PREF_DEBUG + inst.name + ", " +
		std::to_string(inst.size) + " - OK";
	std::cout << msg << std::endl;
}

void Logger::Error(CpuInstruction inst)
{
	std::string msg = PREF_ERROR + inst.name + ", " + 
		std::to_string(inst.size) + " - Failed to resolve instruction";
	std::cout << msg << std::endl;
}

void Logger::FalseBreakpoint()
{
	std::cout << "Execution stopped due to previous errors, press any key to exit." << std::endl;
	std::cin.get();
}
