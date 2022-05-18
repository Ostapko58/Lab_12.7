#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.7/Lab_12.7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL,
				* last = NULL;
			for (int i = 0; i < 5; i++)
			{
				enqueue(first, last, i);
			}
			Assert::AreEqual(RemoveValue(first, 3), true);
		}
	};
}
