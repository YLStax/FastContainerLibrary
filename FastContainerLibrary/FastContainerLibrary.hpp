#pragma once

/*
実装モード切替式の関数の実装モードを切替
*/
#ifdef FAST_CONTAONER_FUNCTIONS_AMP_MODE
#elif defined FAST_CONTAONER_FUNCTIONS_PPL_MODE
#else
#define FAST_CONTAONER_FUNCTIONS_COM_MODE
#endif

/*
エラーチェックの有無を切替
*/
#ifdef FAST_CONTAINER_NO_EXCEPTION
#endif

#ifdef FAST_CONTAONER_FUNCTIONS_COM_MODE
#define SWITCH_FAST_CONTAONER_FUNCTION(func) func ## _com
#elif defined FAST_CONTAONER_FUNCTIONS_AMP_MODE
#define SWITCH_FAST_CONTAONER_FUNCTION(func) func ## _amp
#elif defined FAST_CONTAONER_FUNCTIONS_PPL_MODE
#define SWITCH_FAST_CONTAONER_FUNCTION(func) func ## _ppl
#endif

#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <ostream>
#include <stdio.h>
#include <ctype.h>
#include <random>
#include <amp.h>
#include <amp_math.h>
#include <ppl.h>
#include <iomanip>
#include <sstream>

#include "Exception.hpp"
#include "ApplyFunction.hpp"
#include "Random.hpp"
#include "Calculation01.hpp"
#include "Calculation02.hpp"
#include "Math01.hpp"
#include "Math02.hpp"
#include "Extraction.hpp"

#include "FastVector.hpp"
#include "FastMatrix.hpp"

namespace FastContainer {

}
