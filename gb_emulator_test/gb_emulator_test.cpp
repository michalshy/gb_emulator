#include "pch.h"
#include "CppUnitTest.h"
#include "../GbCpu.h"
#include "../GbCpu.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace gbemulatortest
{
	TEST_CLASS(gbemulatortest)
	{
	public:
		
		TEST_METHOD(TestSetsResets)
		{
			GbCpu gbCpu;
			gbCpu.SetFlag(7);
			Assert::AreEqual(0b10000000, static_cast<int>(gbCpu.DumpRegs().f));
			gbCpu.ResetFlag(7);
			Assert::AreEqual(0b00000000, static_cast<int>(gbCpu.DumpRegs().f));
		}

		TEST_METHOD(TestAdditionsLowerHigherOwerflow)
		{
			GbCpu gbCpu;
			u8 a = 255;
			gbCpu.ADD(a);
			gbCpu.ADD(a);
			Assert::AreEqual(0b00110000, static_cast<int>(gbCpu.DumpRegs().f));
		}
	};
}
