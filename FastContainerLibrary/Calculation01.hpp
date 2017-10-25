#pragma once

#include "FastContainerLibrary.hpp"

namespace FastContainer {
	namespace Functions {

#pragma region add

		template<typename T>
		inline std::vector<T> add(std::vector<T>& target1, std::vector<T>& target2) { return SWITCH_FAST_CONTAONER_FUNCTION(add)(target1, target2); }
		template<typename T>
		inline std::vector<T> add_com(std::vector<T>& target1, std::vector<T>& target2) { return apply_com_combo_func([=](T x1, T x2) {return x1 + x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> add_amp(std::vector<T>& target1, std::vector<T>& target2) { return apply_amp_combo_func([=](T x1, T x2) restrict(amp) {return x1 + x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> add_ppl(std::vector<T>& target1, std::vector<T>& target2) { return apply_ppl_combo_func([=](T x1, T x2) {return x1 + x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> add(std::vector<T>& target, T value) { return SWITCH_FAST_CONTAONER_FUNCTION(add)(target, value); }
		template<typename T>
		inline std::vector<T> add_com(std::vector<T>& target, T value) { return apply_com_func([=](T x) {return x + value; }, target); }
		template<typename T>
		inline std::vector<T> add_amp(std::vector<T>& target, T value) { return apply_amp_func([=](T x) restrict(amp) {return x + value; }, target); }
		template<typename T>
		inline std::vector<T> add_ppl(std::vector<T>& target, T value) { return apply_ppl_func([=](T x) {return x + value; }, target); }
		template<typename T>
		inline std::vector<T> add(T value, std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(add)(value, target); }
		template<typename T>
		inline std::vector<T> add_com(T value, std::vector<T>& target) { return apply_com_func([=](T x) {return value + x; }, target); }
		template<typename T>
		inline std::vector<T> add_amp(T value, std::vector<T>& target) { return apply_amp_func([=](T x) restrict(amp) {return value + x; }, target); }
		template<typename T>
		inline std::vector<T> add_ppl(T value, std::vector<T>& target) { return apply_ppl_func([=](T x) {return value + x; }, target); }
		template<typename T>
		inline std::vector<T> add_by_rows(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return SWITCH_FAST_CONTAONER_FUNCTION(add_by_rows)(target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> add_by_rows_com(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_com_combo_func_by_rows([=](T x1, T x2) {return x1 + x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> add_by_rows_amp(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_amp_combo_func_by_rows([=](T x1, T x2) restrict(amp) {return x1 + x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> add_by_rows_ppl(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_ppl_combo_func_by_rows([=](T x1, T x2) {return x1 + x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> add_by_columns(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return SWITCH_FAST_CONTAONER_FUNCTION(add_by_columns)(target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> add_by_columns_com(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_com_combo_func_by_columns([=](T x1, T x2) {return x1 + x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> add_by_columns_amp(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_amp_combo_func_by_columns([=](T x1, T x2) restrict(amp) {return x1 + x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> add_by_columns_ppl(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_ppl_combo_func_by_columns([=](T x1, T x2) {return x1 + x2; }, target1, row, col, target2); }

#pragma endregion

#pragma region sub

		template<typename T>
		inline std::vector<T> sub(std::vector<T>& target1, std::vector<T>& target2) { return SWITCH_FAST_CONTAONER_FUNCTION(sub)(target1, target2); }
		template<typename T>
		inline std::vector<T> sub_com(std::vector<T>& target1, std::vector<T>& target2) { return apply_com_combo_func([=](T x1, T x2) {return x1 - x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> sub_amp(std::vector<T>& target1, std::vector<T>& target2) { return apply_amp_combo_func([=](T x1, T x2) restrict(amp) {return x1 - x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> sub_ppl(std::vector<T>& target1, std::vector<T>& target2) { return apply_ppl_combo_func([=](T x1, T x2) {return x1 - x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> sub(std::vector<T>& target, T value) { return SWITCH_FAST_CONTAONER_FUNCTION(sub)(target, value); }
		template<typename T>
		inline std::vector<T> sub_com(std::vector<T>& target, T value) { return apply_com_func([=](T x) {return x - value; }, target); }
		template<typename T>
		inline std::vector<T> sub_amp(std::vector<T>& target, T value) { return apply_amp_func([=](T x) restrict(amp) {return x - value; }, target); }
		template<typename T>
		inline std::vector<T> sub_ppl(std::vector<T>& target, T value) { return apply_ppl_func([=](T x) {return x - value; }, target); }
		template<typename T>
		inline std::vector<T> sub(T value, std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(sub)(value, target); }
		template<typename T>
		inline std::vector<T> sub_com(T value, std::vector<T>& target) { return apply_com_func([=](T x) {return value - x; }, target); }
		template<typename T>
		inline std::vector<T> sub_amp(T value, std::vector<T>& target) { return apply_amp_func([=](T x) restrict(amp) {return value - x; }, target); }
		template<typename T>
		inline std::vector<T> sub_ppl(T value, std::vector<T>& target) { return apply_ppl_func([=](T x) {return value - x; }, target); }
		template<typename T>
		inline std::vector<T> sub_by_rows(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return SWITCH_FAST_CONTAONER_FUNCTION(sub_by_rows)(target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> sub_by_rows_com(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_com_combo_func_by_rows([=](T x1, T x2) {return x1 - x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> sub_by_rows_amp(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_amp_combo_func_by_rows([=](T x1, T x2) restrict(amp) {return x1 - x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> sub_by_rows_ppl(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_ppl_combo_func_by_rows([=](T x1, T x2) {return x1 - x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> sub_by_columns(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return SWITCH_FAST_CONTAONER_FUNCTION(sub_by_columns)(target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> sub_by_columns_com(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_com_combo_func_by_columns([=](T x1, T x2) {return x1 - x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> sub_by_columns_amp(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_amp_combo_func_by_columns([=](T x1, T x2) restrict(amp) {return x1 - x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> sub_by_columns_ppl(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_ppl_combo_func_by_columns([=](T x1, T x2) {return x1 - x2; }, target1, row, col, target2); }

#pragma endregion

#pragma region mul

		template<typename T>
		inline std::vector<T> mul(std::vector<T>& target1, std::vector<T>& target2) { return SWITCH_FAST_CONTAONER_FUNCTION(mul)(target1, target2); }
		template<typename T>
		inline std::vector<T> mul_com(std::vector<T>& target1, std::vector<T>& target2) { return apply_com_combo_func([=](T x1, T x2) {return x1 * x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> mul_amp(std::vector<T>& target1, std::vector<T>& target2) { return apply_amp_combo_func([=](T x1, T x2) restrict(amp) {return x1 * x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> mul_ppl(std::vector<T>& target1, std::vector<T>& target2) { return apply_ppl_combo_func([=](T x1, T x2) {return x1 * x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> mul(std::vector<T>& target, T value) { return SWITCH_FAST_CONTAONER_FUNCTION(mul)(target, value); }
		template<typename T>
		inline std::vector<T> mul_com(std::vector<T>& target, T value) { return apply_com_func([=](T x) {return x * value; }, target); }
		template<typename T>
		inline std::vector<T> mul_amp(std::vector<T>& target, T value) { return apply_amp_func([=](T x) restrict(amp) {return x * value; }, target); }
		template<typename T>
		inline std::vector<T> mul_ppl(std::vector<T>& target, T value) { return apply_ppl_func([=](T x) {return x * value; }, target); }
		template<typename T>
		inline std::vector<T> mul(T value, std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(mul)(value, target); }
		template<typename T>
		inline std::vector<T> mul_com(T value, std::vector<T>& target) { return apply_com_func([=](T x) {return value * x; }, target); }
		template<typename T>
		inline std::vector<T> mul_amp(T value, std::vector<T>& target) { return apply_amp_func([=](T x) restrict(amp) {return value * x; }, target); }
		template<typename T>
		inline std::vector<T> mul_ppl(T value, std::vector<T>& target) { return apply_ppl_func([=](T x) {return value * x; }, target); }
		template<typename T>
		inline std::vector<T> mul_by_rows(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return SWITCH_FAST_CONTAONER_FUNCTION(mul_by_rows)(target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> mul_by_rows_com(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_com_combo_func_by_rows([=](T x1, T x2) {return x1 * x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> mul_by_rows_amp(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_amp_combo_func_by_rows([=](T x1, T x2) restrict(amp) {return x1 * x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> mul_by_rows_ppl(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_ppl_combo_func_by_rows([=](T x1, T x2) {return x1 * x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> mul_by_columns(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return SWITCH_FAST_CONTAONER_FUNCTION(mul_by_columns)(target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> mul_by_columns_com(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_com_combo_func_by_columns([=](T x1, T x2) {return x1 * x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> mul_by_columns_amp(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_amp_combo_func_by_columns([=](T x1, T x2) restrict(amp) {return x1 * x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> mul_by_columns_ppl(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_ppl_combo_func_by_columns([=](T x1, T x2) {return x1 * x2; }, target1, row, col, target2); }

#pragma endregion

#pragma region div

		template<typename T>
		inline std::vector<T> div(std::vector<T>& target1, std::vector<T>& target2) { return SWITCH_FAST_CONTAONER_FUNCTION(div)(target1, target2); }
		template<typename T>
		inline std::vector<T> div_com(std::vector<T>& target1, std::vector<T>& target2) { return apply_com_combo_func([=](T x1, T x2) {return x1 / x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> div_amp(std::vector<T>& target1, std::vector<T>& target2) { return apply_amp_combo_func([=](T x1, T x2) restrict(amp) {return x1 / x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> div_ppl(std::vector<T>& target1, std::vector<T>& target2) { return apply_ppl_combo_func([=](T x1, T x2) {return x1 / x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> div(std::vector<T>& target, T value) { return SWITCH_FAST_CONTAONER_FUNCTION(div)(target, value); }
		template<typename T>
		inline std::vector<T> div_com(std::vector<T>& target, T value) { return apply_com_func([=](T x) {return x / value; }, target); }
		template<typename T>
		inline std::vector<T> div_amp(std::vector<T>& target, T value) { return apply_amp_func([=](T x) restrict(amp) {return x / value; }, target); }
		template<typename T>
		inline std::vector<T> div_ppl(std::vector<T>& target, T value) { return apply_ppl_func([=](T x) {return x / value; }, target); }
		template<typename T>
		inline std::vector<T> div(T value, std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(div)(value, target); }
		template<typename T>
		inline std::vector<T> div_com(T value, std::vector<T>& target) { return apply_com_func([=](T x) {return value / x; }, target); }
		template<typename T>
		inline std::vector<T> div_amp(T value, std::vector<T>& target) { return apply_amp_func([=](T x) restrict(amp) {return value / x; }, target); }
		template<typename T>
		inline std::vector<T> div_ppl(T value, std::vector<T>& target) { return apply_ppl_func([=](T x) {return value / x; }, target); }
		template<typename T>
		inline std::vector<T> div_by_rows(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return SWITCH_FAST_CONTAONER_FUNCTION(div_by_rows)(target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> div_by_rows_com(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_com_combo_func_by_rows([=](T x1, T x2) {return x1 / x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> div_by_rows_amp(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_amp_combo_func_by_rows([=](T x1, T x2) restrict(amp) {return x1 / x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> div_by_rows_ppl(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_ppl_combo_func_by_rows([=](T x1, T x2) {return x1 / x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> div_by_columns(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return SWITCH_FAST_CONTAONER_FUNCTION(div_by_columns)(target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> div_by_columns_com(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_com_combo_func_by_columns([=](T x1, T x2) {return x1 / x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> div_by_columns_amp(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_amp_combo_func_by_columns([=](T x1, T x2) restrict(amp) {return x1 / x2; }, target1, row, col, target2); }
		template<typename T>
		inline std::vector<T> div_by_columns_ppl(std::vector<T>& target1, int row, int col, std::vector<T>& target2) { return apply_ppl_combo_func_by_columns([=](T x1, T x2) {return x1 / x2; }, target1, row, col, target2); }

#pragma endregion

#pragma region equal

		template<typename T>
		inline std::vector<T> equal(std::vector<T>& target1, std::vector<T>& target2) { return SWITCH_FAST_CONTAONER_FUNCTION(equal)(target1, target2); }
		template<typename T>
		inline std::vector<T> equal_com(std::vector<T>& target1, std::vector<T>& target2) { return apply_com_combo_func([=](T x1, T x2) {return x1 == x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> equal_amp(std::vector<T>& target1, std::vector<T>& target2) { return apply_amp_combo_func([=](T x1, T x2) restrict(amp) {return x1 == x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> equal_ppl(std::vector<T>& target1, std::vector<T>& target2) { return apply_ppl_combo_func([=](T x1, T x2) {return x1 == x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> equal(std::vector<T>& target, T value) { return SWITCH_FAST_CONTAONER_FUNCTION(equal)(target, value); }
		template<typename T>
		inline std::vector<T> equal_com(std::vector<T>& target, T value) { return apply_com_func([=](T x) {return x == value; }, target); }
		template<typename T>
		inline std::vector<T> equal_amp(std::vector<T>& target, T value) { return apply_amp_func([=](T x) restrict(amp) {return x == value; }, target); }
		template<typename T>
		inline std::vector<T> equal_ppl(std::vector<T>& target, T value) { return apply_ppl_func([=](T x) {return x == value; }, target); }
		template<typename T>
		inline std::vector<T> equal(T value, std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(equal)(value, target); }
		template<typename T>
		inline std::vector<T> equal_com(T value, std::vector<T>& target) { return apply_com_func([=](T x) {return value == x; }, target); }
		template<typename T>
		inline std::vector<T> equal_amp(T value, std::vector<T>& target) { return apply_amp_func([=](T x) restrict(amp) {return value == x; }, target); }
		template<typename T>
		inline std::vector<T> equal_ppl(T value, std::vector<T>& target) { return apply_ppl_func([=](T x) {return value == x; }, target); }

#pragma endregion

#pragma region not_equal

		template<typename T>
		inline std::vector<T> not_equal(std::vector<T>& target1, std::vector<T>& target2) { return SWITCH_FAST_CONTAONER_FUNCTION(not_equal)(target1, target2); }
		template<typename T>
		inline std::vector<T> not_equal_com(std::vector<T>& target1, std::vector<T>& target2) { return apply_com_combo_func([=](T x1, T x2) {return x1 != x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> not_equal_amp(std::vector<T>& target1, std::vector<T>& target2) { return apply_amp_combo_func([=](T x1, T x2) restrict(amp) {return x1 != x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> not_equal_ppl(std::vector<T>& target1, std::vector<T>& target2) { return apply_ppl_combo_func([=](T x1, T x2) {return x1 != x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> not_equal(std::vector<T>& target, T value) { return SWITCH_FAST_CONTAONER_FUNCTION(not_equal)(target, value); }
		template<typename T>
		inline std::vector<T> not_equal_com(std::vector<T>& target, T value) { return apply_com_func([=](T x) {return x != value; }, target); }
		template<typename T>
		inline std::vector<T> not_equal_amp(std::vector<T>& target, T value) { return apply_amp_func([=](T x) restrict(amp) {return x != value; }, target); }
		template<typename T>
		inline std::vector<T> not_equal_ppl(std::vector<T>& target, T value) { return apply_ppl_func([=](T x) {return x != value; }, target); }
		template<typename T>
		inline std::vector<T> not_equal(T value, std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(not_equal)(value, target); }
		template<typename T>
		inline std::vector<T> not_equal_com(T value, std::vector<T>& target) { return apply_com_func([=](T x) {return value != x; }, target); }
		template<typename T>
		inline std::vector<T> not_equal_amp(T value, std::vector<T>& target) { return apply_amp_func([=](T x) restrict(amp) {return value != x; }, target); }
		template<typename T>
		inline std::vector<T> not_equal_ppl(T value, std::vector<T>& target) { return apply_ppl_func([=](T x) {return value != x; }, target); }

#pragma endregion

#pragma region more

		template<typename T>
		inline std::vector<T> more(std::vector<T>& target1, std::vector<T>& target2) { return SWITCH_FAST_CONTAONER_FUNCTION(more)(target1, target2); }
		template<typename T>
		inline std::vector<T> more_com(std::vector<T>& target1, std::vector<T>& target2) { return apply_com_combo_func([=](T x1, T x2) {return x1 > x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> more_amp(std::vector<T>& target1, std::vector<T>& target2) { return apply_amp_combo_func([=](T x1, T x2) restrict(amp) {return x1 > x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> more_ppl(std::vector<T>& target1, std::vector<T>& target2) { return apply_ppl_combo_func([=](T x1, T x2) {return x1 > x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> more(std::vector<T>& target, T value) { return SWITCH_FAST_CONTAONER_FUNCTION(more)(target, value); }
		template<typename T>
		inline std::vector<T> more_com(std::vector<T>& target, T value) { return apply_com_func([=](T x) {return x > value; }, target); }
		template<typename T>
		inline std::vector<T> more_amp(std::vector<T>& target, T value) { return apply_amp_func([=](T x) restrict(amp) {return x > value; }, target); }
		template<typename T>
		inline std::vector<T> more_ppl(std::vector<T>& target, T value) { return apply_ppl_func([=](T x) {return x > value; }, target); }
		template<typename T>
		inline std::vector<T> more(T value, std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(more)(value, target); }
		template<typename T>
		inline std::vector<T> more_com(T value, std::vector<T>& target) { return apply_com_func([=](T x) {return value > x; }, target); }
		template<typename T>
		inline std::vector<T> more_amp(T value, std::vector<T>& target) { return apply_amp_func([=](T x) restrict(amp) {return value > x; }, target); }
		template<typename T>
		inline std::vector<T> more_ppl(T value, std::vector<T>& target) { return apply_ppl_func([=](T x) {return value > x; }, target); }

#pragma endregion

#pragma region less

		template<typename T>
		inline std::vector<T> less(std::vector<T>& target1, std::vector<T>& target2) { return SWITCH_FAST_CONTAONER_FUNCTION(less)(target1, target2); }
		template<typename T>
		inline std::vector<T> less_com(std::vector<T>& target1, std::vector<T>& target2) { return apply_com_combo_func([=](T x1, T x2) {return x1 < x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> less_amp(std::vector<T>& target1, std::vector<T>& target2) { return apply_amp_combo_func([=](T x1, T x2) restrict(amp) {return x1 < x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> less_ppl(std::vector<T>& target1, std::vector<T>& target2) { return apply_ppl_combo_func([=](T x1, T x2) {return x1 < x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> less(std::vector<T>& target, T value) { return SWITCH_FAST_CONTAONER_FUNCTION(less)(target, value); }
		template<typename T>
		inline std::vector<T> less_com(std::vector<T>& target, T value) { return apply_com_func([=](T x) {return x < value; }, target); }
		template<typename T>
		inline std::vector<T> less_amp(std::vector<T>& target, T value) { return apply_amp_func([=](T x) restrict(amp) {return x < value; }, target); }
		template<typename T>
		inline std::vector<T> less_ppl(std::vector<T>& target, T value) { return apply_ppl_func([=](T x) {return x < value; }, target); }
		template<typename T>
		inline std::vector<T> less(T value, std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(less)(value, target); }
		template<typename T>
		inline std::vector<T> less_com(T value, std::vector<T>& target) { return apply_com_func([=](T x) {return value < x; }, target); }
		template<typename T>
		inline std::vector<T> less_amp(T value, std::vector<T>& target) { return apply_amp_func([=](T x) restrict(amp) {return value < x; }, target); }
		template<typename T>
		inline std::vector<T> less_ppl(T value, std::vector<T>& target) { return apply_ppl_func([=](T x) {return value < x; }, target); }

#pragma endregion

#pragma region not_less

		template<typename T>
		inline std::vector<T> not_less(std::vector<T>& target1, std::vector<T>& target2) { return SWITCH_FAST_CONTAONER_FUNCTION(not_less)(target1, target2); }
		template<typename T>
		inline std::vector<T> not_less_com(std::vector<T>& target1, std::vector<T>& target2) { return apply_com_combo_func([=](T x1, T x2) {return x1 >= x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> not_less_amp(std::vector<T>& target1, std::vector<T>& target2) { return apply_amp_combo_func([=](T x1, T x2) restrict(amp) {return x1 >= x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> not_less_ppl(std::vector<T>& target1, std::vector<T>& target2) { return apply_ppl_combo_func([=](T x1, T x2) {return x1 >= x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> not_less(std::vector<T>& target, T value) { return SWITCH_FAST_CONTAONER_FUNCTION(not_less)(target, value); }
		template<typename T>
		inline std::vector<T> not_less_com(std::vector<T>& target, T value) { return apply_com_func([=](T x) {return x >= value; }, target); }
		template<typename T>
		inline std::vector<T> not_less_amp(std::vector<T>& target, T value) { return apply_amp_func([=](T x) restrict(amp) {return x >= value; }, target); }
		template<typename T>
		inline std::vector<T> not_less_ppl(std::vector<T>& target, T value) { return apply_ppl_func([=](T x) {return x >= value; }, target); }
		template<typename T>
		inline std::vector<T> not_less(T value, std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(not_less)(value, target); }
		template<typename T>
		inline std::vector<T> not_less_com(T value, std::vector<T>& target) { return apply_com_func([=](T x) {return value >= x; }, target); }
		template<typename T>
		inline std::vector<T> not_less_amp(T value, std::vector<T>& target) { return apply_amp_func([=](T x) restrict(amp) {return value >= x; }, target); }
		template<typename T>
		inline std::vector<T> not_less_ppl(T value, std::vector<T>& target) { return apply_ppl_func([=](T x) {return value >= x; }, target); }

#pragma endregion

#pragma region not_more

		template<typename T>
		inline std::vector<T> not_more(std::vector<T>& target1, std::vector<T>& target2) { return SWITCH_FAST_CONTAONER_FUNCTION(not_more)(target1, target2); }
		template<typename T>
		inline std::vector<T> not_more_com(std::vector<T>& target1, std::vector<T>& target2) { return apply_com_combo_func([=](T x1, T x2) {return x1 <= x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> not_more_amp(std::vector<T>& target1, std::vector<T>& target2) { return apply_amp_combo_func([=](T x1, T x2) restrict(amp) {return x1 <= x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> not_more_ppl(std::vector<T>& target1, std::vector<T>& target2) { return apply_ppl_combo_func([=](T x1, T x2) {return x1 <= x2; }, target1, target2); }
		template<typename T>
		inline std::vector<T> not_more(std::vector<T>& target, T value) { return SWITCH_FAST_CONTAONER_FUNCTION(not_more)(target, value); }
		template<typename T>
		inline std::vector<T> not_more_com(std::vector<T>& target, T value) { return apply_com_func([=](T x) {return x <= value; }, target); }
		template<typename T>
		inline std::vector<T> not_more_amp(std::vector<T>& target, T value) { return apply_amp_func([=](T x) restrict(amp) {return x <= value; }, target); }
		template<typename T>
		inline std::vector<T> not_more_ppl(std::vector<T>& target, T value) { return apply_ppl_func([=](T x) {return x <= value; }, target); }
		template<typename T>
		inline std::vector<T> not_more(T value, std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(not_more)(value, target); }
		template<typename T>
		inline std::vector<T> not_more_com(T value, std::vector<T>& target) { return apply_com_func([=](T x) {return value <= x; }, target); }
		template<typename T>
		inline std::vector<T> not_more_amp(T value, std::vector<T>& target) { return apply_amp_func([=](T x) restrict(amp) {return value <= x; }, target); }
		template<typename T>
		inline std::vector<T> not_more_ppl(T value, std::vector<T>& target) { return apply_ppl_func([=](T x) {return value <= x; }, target); }

#pragma endregion

	}
}
