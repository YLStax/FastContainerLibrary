// FastContainerLibrary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define FAST_CONTAONER_FUNCTIONS_COM_MODE
//#define FAST_CONTAONER_FUNCTIONS_AMP_MODE
//#define FAST_CONTAONER_FUNCTIONS_PPL_MODE

//#define FAST_CONTAINER_NO_EXCEPTION

#include "FastContainerLibrary.hpp"

#include <chrono>
#include <iostream>
#include <time.h>

using namespace std;
using namespace FastContainer;

template<typename T>
void cout_calc_span(T func, int cycle_num = 1, std::string str = "calc") {
	clock_t start = clock();
	for (int i = 0; i < cycle_num; i++) {
		func();
	}
	clock_t end = clock();
	const auto timeSpan = (double)(end - start) / CLOCKS_PER_SEC / cycle_num;
	cout << str.c_str() << ": " << timeSpan << "s" << endl;
}

int main()
{
	auto m1 = FastMatrix<double>::real_random_com(5, 3);
	auto m2 = FastMatrix<double>::real_random_ppl(5, 3);
	auto m3 = FastMatrix<double>::int_random_com(5, 3, 0, 10);
	auto m4 = FastMatrix<double>::int_random_ppl(5, 3, 0, 10);
	auto m5 = FastMatrix<double>::normal_random_com(5, 3);
	auto m6 = FastMatrix<double>::normal_random_ppl(5, 3);
	auto v1 = FastVector<double>::real_random_com(10);
	auto v2 = FastVector<double>::real_random_ppl(10);
	auto v3 = FastVector<double>::int_random_com(10, 0, 10);
	auto v4 = FastVector<double>::int_random_ppl(10, 0, 10);
	auto v5 = FastVector<double>::normal_random_com(10);
	auto v6 = FastVector<double>::normal_random_ppl(10);
	auto v7 = FastVector<int>::int_hash_random(3, 0, 4);

	cout << m1.to_string().c_str() << endl;

	getchar();
	
    return 0;
}

