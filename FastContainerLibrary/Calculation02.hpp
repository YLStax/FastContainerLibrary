#pragma once

#include "FastContainerLibrary.hpp"

namespace FastContainer {
	namespace Functions {

#pragma region dot

		template<typename T>
		inline T dot(std::vector<T>& target1, std::vector<T>& target2) {
			FAST_CONTAINER_EXCEPTION_CHECK(target1.size() == target2.size(), fast_container_exception());
			T result = 0;
			int size = target1.size();
			for (int i = 0; i < size; ++i) {
				result += target1[i] * target2[i];
			}
			return result;
		}
		template<typename T>
		inline std::vector<T> dot(std::vector<T>& target1, std::vector<T>& target2, int row, int mid, int col) { return SWITCH_FAST_CONTAONER_FUNCTION(dot)(target1, target2, row, mid, col); }
		template<typename T>
		inline std::vector<T> dot_com(std::vector<T>& target1, std::vector<T>& target2, int row, int mid, int col) {
			FAST_CONTAINER_EXCEPTION_CHECK(row * mid == target1.size(), fast_container_exception());
			FAST_CONTAINER_EXCEPTION_CHECK(mid * col == target2.size(), fast_container_exception());
			std::vector<T> result(row * col);
			for (int i = 0; i < row; ++i) {
				int res_offset = i * col;
				int t1_pos = i * mid;
				int t2_offset = 0;
				for (int k = 0; k < mid; ++k, ++t1_pos, t2_offset += col) {
					for (int j = 0; j < col; ++j) {
						result[res_offset + j] += target1[t1_pos] * target2[t2_offset + j];
					}
				}
			}
			return result;
		}
		template<typename T>
		inline std::vector<T> dot_amp(std::vector<T>& target1, std::vector<T>& target2, int row, int mid, int col) {
			FAST_CONTAINER_EXCEPTION_CHECK(row * mid == target1.size(), fast_container_exception());
			FAST_CONTAINER_EXCEPTION_CHECK(mid * col == target2.size(), fast_container_exception());
			std::vector<T> result(row * col);
			concurrency::array_view<const T, 2> av_target1(row, mid, &target1[0]);
			concurrency::array_view<const T, 2> av_target2(mid, col, &target2[0]);
			concurrency::array_view<T, 2> av_result(row, col, &result[0]);
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<2> idx) restrict(amp) {
				av_result[idx] = 0;
				for (int i = 0; i < mid; ++i) {
					av_result[idx] += av_target1[idx[0]][i] * av_target2[i][idx[1]];
				}
			});
			av_result.synchronize();
			return result;
		}
		template<typename T>
		inline std::vector<T> dot_ppl(std::vector<T>& target1, std::vector<T>& target2, int row, int mid, int col) {
			FAST_CONTAINER_EXCEPTION_CHECK(row * mid == target1.size(), fast_container_exception());
			FAST_CONTAINER_EXCEPTION_CHECK(mid * col == target2.size(), fast_container_exception());
			std::vector<T> result(row * col);
			concurrency::parallel_for<int>(0, row, [&](int i) {
				int res_offset = i * col;
				int t1_pos = i * mid;
				int t2_offset = 0;
				for (int k = 0; k < mid; ++k, ++t1_pos, t2_offset += col) {
					for (int j = 0; j < col; ++j) {
						result[res_offset + j] += target1[t1_pos] * target2[t2_offset + j];
					}
				}
			});
			return result;
		}

#pragma endregion

	}
}
