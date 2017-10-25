#pragma once

#include "FastContainerLibrary.hpp"

namespace FastContainer {
	namespace Functions {

		/*関数を適用
		func: T(*func)(T x)*/
		template<typename T, class F>
		inline std::vector<T> apply_com_func(F func, std::vector<T>& target) {
			int size = target.size();
			std::vector<T> result(size);
			for (int i = 0; i < size; ++i) {
				result[i] = func(target[i]);
			}
			return result;
		}

		/*関数を適用 AMP実装
		func: T(*func)(T x) restrict(amp)*/
		template<typename T, class F>
		inline std::vector<T> apply_amp_func(F func, std::vector<T>& target) {
			int size = target.size();
			std::vector<T> result(size);
			concurrency::array_view<const T, 1> av_target(size, &target[0]);
			concurrency::array_view<T, 1> av_result(size, &result[0]);
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = func(av_target[idx]);
			});
			av_result.synchronize();
			return result;
		}

		/*関数を適用 PPL実装
		func: T(*func)(T x)*/
		template<typename T, class F>
		inline std::vector<T> apply_ppl_func(F func, std::vector<T>& target) {
			int size = target.size();
			std::vector<T> result(size);
			concurrency::parallel_for<int>(0, size, [&](int i) {
				result[i] = func(target[i]);
			});
			return result;
		}

		/*関数を適用
		func: T(*func)(T x1, T x2)*/
		template<typename T, class F>
		inline std::vector<T> apply_com_combo_func(F func, std::vector<T>& target1, std::vector<T>& target2) {
			FAST_CONTAINER_EXCEPTION_CHECK(target1.size() == target2.size(), fast_container_exception());
			int size = target1.size();
			std::vector<T> result(size);
			for (int i = 0; i < size; ++i) {
				result[i] = func(target1[i], target2[i]);
			}
			return result;
		}

		/*関数を適用 AMP実装
		func: T(*func)(T x1, T x2) restrict(amp)*/
		template<typename T, class F>
		inline std::vector<T> apply_amp_combo_func(F func, std::vector<T>& target1, std::vector<T>& target2) {
			FAST_CONTAINER_EXCEPTION_CHECK(target1.size() == target2.size(), fast_container_exception());
			int size = target1.size();
			std::vector<T> result(size);
			concurrency::array_view<const T, 1> av_target1(size, &target1[0]);
			concurrency::array_view<const T, 1> av_target2(size, &target2[0]);
			concurrency::array_view<T, 1> av_result(size, &result[0]);
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = func(av_target1[idx], av_target2[idx]);
			});
			av_result.synchronize();
			return result;
		}

		/*関数を適用 PPL実装
		func: T(*func)(T x1, T x2)*/
		template<typename T, class F>
		inline std::vector<T> apply_ppl_combo_func(F func, std::vector<T>& target1, std::vector<T>& target2) {
			FAST_CONTAINER_EXCEPTION_CHECK(target1.size() == target2.size(), fast_container_exception());
			int size = target1.size();
			std::vector<T> result(size);
			concurrency::parallel_for<int>(0, size, [&](int i) {
				result[i] = func(target1[i], target2[i]);
			});
			return result;
		}

		/*行毎に関数を適用
		func: T(*func)(T x1, T x2)*/
		template<typename T, class F>
		inline std::vector<T> apply_com_combo_func_by_rows(F func, std::vector<T>& target1, int row, int col, std::vector<T>& target2) {
			int size = target1.size();
			FAST_CONTAINER_EXCEPTION_CHECK(size == row * col, fast_container_exception());
			FAST_CONTAINER_EXCEPTION_CHECK(col == target2.size(), fast_container_exception());
			std::vector<T> result(size);
			for (int i = 0; i < size; ++i) {
				result[i] = func(target1[i], target2[i % col]);
			}
			return result;
		}

		/*行毎に関数を適用 AMP実装
		func: T(*func)(T x1, T x2) restrict(amp)*/
		template<typename T, class F>
		inline std::vector<T> apply_amp_combo_func_by_rows(F func, std::vector<T>& target1, int row, int col, std::vector<T>& target2) {
			int size = target1.size();
			FAST_CONTAINER_EXCEPTION_CHECK(size == row * col, fast_container_exception());
			FAST_CONTAINER_EXCEPTION_CHECK(col == target2.size(), fast_container_exception());
			std::vector<T> result(size);
			concurrency::array_view<const T, 2> av_target1(row, col, &target1[0]);
			concurrency::array_view<const T, 1> av_target2(col, &target2[0]);
			concurrency::array_view<T, 2> av_result(row, col, &result[0]);
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<2> idx) restrict(amp) {
				av_result[idx] = func(av_target1[idx], av_target2[idx[1]]);
			});
			av_result.synchronize();
			return result;
		}

		/*行毎に関数を適用 PPL実装
		func: T(*func)(T x1, T x2)*/
		template<typename T, class F>
		inline std::vector<T> apply_ppl_combo_func_by_rows(F func, std::vector<T>& target1, int row, int col, std::vector<T>& target2) {
			int size = target1.size();
			FAST_CONTAINER_EXCEPTION_CHECK(size == row * col, fast_container_exception());
			FAST_CONTAINER_EXCEPTION_CHECK(col == target2.size(), fast_container_exception());
			std::vector<T> result(size);
			concurrency::parallel_for<int>(0, size, [&](int i) {
				result[i] = func(target1[i], target2[i % col]);
			});
			return result;
		}

		/*列毎に関数を適用
		func: T(*func)(T x1, T x2)*/
		template<typename T, class F>
		inline std::vector<T> apply_com_combo_func_by_columns(F func, std::vector<T>& target1, int row, int col, std::vector<T>& target2) {
			int size = target1.size();
			FAST_CONTAINER_EXCEPTION_CHECK(size == row * col, fast_container_exception());
			FAST_CONTAINER_EXCEPTION_CHECK(row == target2.size(), fast_container_exception());
			std::vector<T> result(size);
			for (int i = 0; i < size; ++i) {
				result[i] = func(target1[i], target2[i / col]);
			}
			return result;
		}

		/*列毎に関数を適用 AMP実装
		func: T(*func)(T x1, T x2) restrict(amp)*/
		template<typename T, class F>
		inline std::vector<T> apply_amp_combo_func_by_columns(F func, std::vector<T>& target1, int row, int col, std::vector<T>& target2) {
			int size = target1.size();
			FAST_CONTAINER_EXCEPTION_CHECK(size == row * col, fast_container_exception());
			FAST_CONTAINER_EXCEPTION_CHECK(row == target2.size(), fast_container_exception());
			std::vector<T> result(size);
			concurrency::array_view<const T, 2> av_target1(row, col, &target1[0]);
			concurrency::array_view<const T, 1> av_target2(row, &target2[0]);
			concurrency::array_view<T, 2> av_result(row, col, &result[0]);
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<2> idx) restrict(amp) {
				av_result[idx] = func(av_target1[idx], av_target2[idx[0]]);
			});
			av_result.synchronize();
			return result;
		}

		/*列毎に関数を適用 PPL実装
		func: T(*func)(T x1, T x2)*/
		template<typename T, class F>
		inline std::vector<T> apply_ppl_combo_func_by_columns(F func, std::vector<T>& target1, int row, int col, std::vector<T>& target2) {
			int size = target1.size();
			FAST_CONTAINER_EXCEPTION_CHECK(size == row * col, fast_container_exception());
			FAST_CONTAINER_EXCEPTION_CHECK(row == target2.size(), fast_container_exception());
			std::vector<T> result(size);
			concurrency::parallel_for<int>(0, size, [&](int i) {
				result[i] = func(target1[i], target2[i / col]);
			});
			return result;
		}

	}
}
