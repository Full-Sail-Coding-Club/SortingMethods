#include "pch.h"
#include "CppUnitTest.h"
#include "../SortingMethods/Quicksort.h"
#include "../SortingMethods/Quicksort.cpp"
#include "../SortingMethods/BubbleSort.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingMethodsTest
{

	TEST_CLASS(SortingMethodsTests)
	{
		Sorter<int>* s;
		int n = 6;

	public:
		#pragma region Helpers
		template<class T>
		void AreArraysEqual(T expected[], T actual[], size_t len) {
			for (size_t i = 0; i < len; i++) {
				Assert::AreEqual(expected[i], actual[i]);
			}
		}

		template<class T>
		void printArray(T arr[], size_t size) {
			for (size_t i = 0; i < size; i++) {
				printf("%d", arr[i]);
				if (i < size - 1) printf(", ");
			}
		}
		#pragma endregion

		#pragma region Positive Tests
		template<class T>
		void positive_FullSort(Sorter<T>* s) {
			int testing[] = { 10, 7, 8, 9, 1, 5 };
			int expected[] = { 1, 5, 7, 8, 9, 10 };
			s->sort(testing, 0, n - 1);
			AreArraysEqual(expected, testing, n);
		}

		template<class T>
		void positive_PartialSort_Begin(Sorter<T>* s) {
			int testing[] = { 10, 7, 8, 9, 1, 5 };
			int expected[] = { 7, 8, 9, 10, 1, 5 };
			s->sort(testing, 0, 3);
			AreArraysEqual(expected, testing, n);
		}

		template<class T>
		void positive_PartialSort_Mid(Sorter<T>* s) {
			int testing[] = { 10, 7, 8, 9, 1, 5 };
			int expected[] = { 10, 1, 7, 8, 9, 5 };
			s->sort(testing, 1, 4);
			AreArraysEqual(expected, testing, n);
		}

		template<class T>
		void positive_PartialSort_End(Sorter<T>* s) {
			int testing[] = { 10, 7, 8, 9, 1, 5 };
			int expected[] = { 10, 7, 1, 5, 8, 9 };
			s->sort(testing, 2, 5);
			AreArraysEqual(expected, testing, n);
		}

		template<class T>
		void positive_Tests(Sorter<T>* s) {
			positive_FullSort(s);
			positive_PartialSort_Begin(s);
			positive_PartialSort_Mid(s);
			positive_PartialSort_End(s);
		}
		#pragma endregion

		#pragma region Negative Tests

		template<class T>
		void negative_LowGreaterThanHigh(Sorter<T>* s) {
			int testing[] = { 10, 7, 8, 9, 1, 5 };
			int expected[] = { 10, 7, 8, 9, 1, 5 };
			s->sort(testing, 2, 0);
			AreArraysEqual(expected, testing, n);
		}

		template<class T>
		void negative_Tests(Sorter<T>*s) {
			negative_LowGreaterThanHigh(s);
		}

		#pragma endregion

		//run before every test
		//TEST_METHOD_INITIALIZE(setup) {}

		//run after every test
		TEST_METHOD_CLEANUP(teardown) {
			delete s;
		}

		TEST_METHOD(quickSort) {
			s = new Quicksort<int>();
			positive_Tests(s);
		}

		TEST_METHOD(bubbleSort) {
			s = new BubbleSort<int>();
			positive_Tests(s);
			negative_Tests(s);
		}
	};
}
