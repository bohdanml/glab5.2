#include "pch.h"
#include "CppUnitTest.h"
#include "..\\glab 5.2\lab.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(A(1, 1, 1) < 1 < 10e-10);
		}
	};
}
