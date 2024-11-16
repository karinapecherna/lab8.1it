#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <cstring>
#include "../lab8.1/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		// Test method for ProcessTXT1 function
		TEST_METHOD(TestProcessTXT1)
		{
			// Define the test file name
			const char* testFileName = "test_file.txt";

			// Create a test file with sample data
			std::ofstream fout(testFileName);
			fout << "This is a test file with OGO and AGA in it." << std::endl;
			fout << "Let's check the OGO and AGA occurrences." << std::endl;
			fout << "Another OGO and AGA example here." << std::endl;
			fout.close();

			// Now call ProcessTXT1 to count the occurrences of "OGO" and "AGA"
			int count = ProcessTXT1(const_cast<char*>(testFileName));

			// Assert the expected result
			Assert::AreEqual(count, 4); // There are 4 occurrences of "OGO" or "AGA" in the test file

			// Optionally, remove the test file after the test
			std::remove(testFileName);
		}
	};
}
