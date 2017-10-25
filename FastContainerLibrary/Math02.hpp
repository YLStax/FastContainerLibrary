#pragma once

#include "FastContainerLibrary.hpp"

namespace FastContainer {
	namespace Functions {

#pragma region abs

		template<typename T>
		inline std::vector<T> abs(std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(abs)(target); }
		template<typename T>
		inline std::vector<T> abs_com(std::vector<T>& target) { return apply_com_func([](T x) { return std::abs(x); }, target); }
		template<typename T>
		inline std::vector<T> abs_amp(std::vector<T>& target) { return apply_amp_func([](T x) restrict(amp) { return concurrency::fast_math::fabs(x); }, target); }
		template<typename T>
		inline std::vector<T> abs_ppl(std::vector<T>& target) { return apply_ppl_func([](T x) { return std::abs(x); }, target); }

#pragma endregion

#pragma region log

		template<typename T>
		inline std::vector<T> log(std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(log)(target); }
		template<typename T>
		inline std::vector<T> log_com(std::vector<T>& target) { return apply_com_func([](T x) { return std::log(x); }, target); }
		template<typename T>
		inline std::vector<T> log_amp(std::vector<T>& target) { return apply_amp_func([](T x) restrict(amp) { return concurrency::fast_math::log(x); }, target); }
		template<typename T>
		inline std::vector<T> log_ppl(std::vector<T>& target) { return apply_ppl_func([](T x) { return std::log(x); }, target); }

#pragma endregion

#pragma region log10

		template<typename T>
		inline std::vector<T> log10(std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(log10)(target); }
		template<typename T>
		inline std::vector<T> log10_com(std::vector<T>& target) { return apply_com_func([](T x) { return std::log10(x); }, target); }
		template<typename T>
		inline std::vector<T> log10_amp(std::vector<T>& target) { return apply_amp_func([](T x) restrict(amp) { return concurrency::fast_math::log10(x); }, target); }
		template<typename T>
		inline std::vector<T> log10_ppl(std::vector<T>& target) { return apply_ppl_func([](T x) { return std::log10(x); }, target); }

#pragma endregion

#pragma region sqrt

		template<typename T>
		inline std::vector<T> sqrt(std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(sqrt)(target); }
		template<typename T>
		inline std::vector<T> sqrt_com(std::vector<T>& target) { return apply_com_func([](T x) { return std::sqrt(x); }, target); }
		template<typename T>
		inline std::vector<T> sqrt_amp(std::vector<T>& target) { return apply_amp_func([](T x) restrict(amp) { return concurrency::fast_math::sqrt(x); }, target); }
		template<typename T>
		inline std::vector<T> sqrt_ppl(std::vector<T>& target) { return apply_ppl_func([](T x) { return std::sqrt(x); }, target); }

#pragma endregion

#pragma region pow

		template<typename T>
		inline std::vector<T> pow(std::vector<T>& target, T exp) { return SWITCH_FAST_CONTAONER_FUNCTION(pow)(target, exp); }
		template<typename T>
		inline std::vector<T> pow_com(std::vector<T>& target, T exp) { return apply_com_func([=](T x) { return std::pow(x, exp); }, target); }
		template<typename T>
		inline std::vector<T> pow_amp(std::vector<T>& target, T exp) { return apply_amp_func([=](T x) restrict(amp) { return concurrency::fast_math::pow(x, exp); }, target); }
		template<typename T>
		inline std::vector<T> pow_ppl(std::vector<T>& target, T exp) { return apply_ppl_func([=](T x) { return std::pow(x, exp); }, target); }

#pragma endregion

#pragma region exp

		template<typename T>
		inline std::vector<T> exp(std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(exp)(target); }
		template<typename T>
		inline std::vector<T> exp_com(std::vector<T>& target) { return apply_com_func([](T x) { return std::exp(x); }, target); }
		template<typename T>
		inline std::vector<T> exp_amp(std::vector<T>& target) { return apply_amp_func([](T x) restrict(amp) { return concurrency::fast_math::exp(x); }, target); }
		template<typename T>
		inline std::vector<T> exp_ppl(std::vector<T>& target) { return apply_ppl_func([](T x) { return std::exp(x); }, target); }

#pragma endregion

#pragma region sigmoid

		template<typename T>
		inline std::vector<T> sigmoid(std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(sigmoid)(target); }
		template<typename T>
		inline std::vector<T> sigmoid_com(std::vector<T>& target) { return apply_com_func([](T x) { return (T)1 / (1 + std::exp(-x)); }, target); }
		template<typename T>
		inline std::vector<T> sigmoid_amp(std::vector<T>& target) { return apply_amp_func([](T x) restrict(amp) { return (T)1 / (1 + concurrency::fast_math::exp(-x)); }, target); }
		template<typename T>
		inline std::vector<T> sigmoid_ppl(std::vector<T>& target) { return apply_ppl_func([](T x) { return (T)1 / (1 + std::exp(-x)); }, target); }

#pragma endregion

#pragma region relu

		template<typename T>
		inline std::vector<T> relu(std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(relu)(target); }
		template<typename T>
		inline std::vector<T> relu_com(std::vector<T>& target) { return apply_com_func([](T x) { return x > 0 ? x : 0; }, target); }
		template<typename T>
		inline std::vector<T> relu_amp(std::vector<T>& target) { return apply_amp_func([](T x) restrict(amp) { return x > 0 ? x : 0; }, target); }
		template<typename T>
		inline std::vector<T> relu_ppl(std::vector<T>& target) { return apply_ppl_func([](T x) { return x > 0 ? x : 0; }, target); }

#pragma endregion

#pragma region normalization

		template<typename T>
		inline std::vector<T> normalization(std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(normalization)(target); }
		template<typename T>
		inline std::vector<T> normalization_com(std::vector<T>& target) { T max = get_max(target); return apply_com_func([=](T x) { return x / max; }, target); }
		template<typename T>
		inline std::vector<T> normalization_amp(std::vector<T>& target) { T max = get_max(target); return apply_amp_func([=](T x) restrict(amp) { return x / max; }, target); }
		template<typename T>
		inline std::vector<T> normalization_ppl(std::vector<T>& target) { T max = get_max(target); return apply_ppl_func([=](T x) { return x / max; }, target); }

#pragma endregion

#pragma region num_diff

		template<typename T, class F>
		inline std::vector<T> num_diff(std::vector<T>& target, F func, T delta = 0.0001) { return SWITCH_FAST_CONTAONER_FUNCTION(num_diff)(target, func, delta); }
		template<typename T, class F>
		inline std::vector<T> num_diff_com(std::vector<T>& target, F func, T delta = 0.0001) { return apply_com_func([=](T x) { return (func(x + delta) - func(x - delta)) / (2 * delta); }, target); }
		template<typename T, class F>
		inline std::vector<T> num_diff_amp(std::vector<T>& target, F func, T delta = 0.0001) { return apply_amp_func([=](T x) restrict(amp) { return (func(x + delta) - func(x - delta)) / (2 * delta); }, target); }
		template<typename T, class F>
		inline std::vector<T> num_diff_ppl(std::vector<T>& target, F func, T delta = 0.0001) { return apply_ppl_func([=](T x) { return (func(x + delta) - func(x - delta)) / (2 * delta); }, target); }

#pragma endregion

#pragma region softmax

		template<typename T>
		inline std::vector<T> softmax(std::vector<T>& target) { return SWITCH_FAST_CONTAONER_FUNCTION(softmax)(target); }
		template<typename T>
		inline std::vector<T> softmax_com(std::vector<T>& target) {
			T max = get_max(target);
			auto ex = apply_com_func([=](T x) { return std::exp(x - max); }, target);
			return div_com(ex, sum(ex));
		}
		template<typename T>
		inline std::vector<T> softmax_amp(std::vector<T>& target) {
			T max = get_max(target);
			auto ex = apply_amp_func([=](T x) restrict(amp) { return concurrency::fast_math::exp(x - max); }, target);
			return div_amp(ex, sum(ex));
		}
		template<typename T>
		inline std::vector<T> softmax_ppl(std::vector<T>& target) {
			T max = get_max(target);
			auto ex = apply_ppl_func([=](T x) { return std::exp(x - max); }, target);
			return div_ppl(ex, sum(ex));
		}

		template<typename T>
		inline std::vector<T> softmax(std::vector<T>& target, int row, int col) { return SWITCH_FAST_CONTAONER_FUNCTION(softmax)(target, row, col); }
		template<typename T>
		inline std::vector<T> softmax_com(std::vector<T>& target, int row, int col) {
			T max = get_max(target);
			auto ex = apply_com_func([=](T x) { return std::exp(x - max); }, target);
			return div_by_columns_com(ex, row, col, sum_by_rows_com(ex, row, col));
		}
		template<typename T>
		inline std::vector<T> softmax_amp(std::vector<T>& target, int row, int col) {
			T max = get_max(target);
			auto ex = apply_amp_func([=](T x) restrict(amp) { return concurrency::fast_math::exp(x - max); }, target);
			return div_by_columns_amp(ex, row, col, sum_by_rows_amp(ex, row, col));
		}
		template<typename T>
		inline std::vector<T> softmax_ppl(std::vector<T>& target, int row, int col) {
			T max = get_max(target);
			auto ex = apply_ppl_func([=](T x) { return std::exp(x - max); }, target);
			return div_by_columns_ppl(ex, row, col, sum_by_rows_ppl(ex, row, col));
		}

#pragma endregion

	}
}
