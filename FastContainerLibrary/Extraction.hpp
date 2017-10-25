#pragma once

#include "FastContainerLibrary.hpp"

namespace FastContainer {
	namespace Functions {

#pragma region take

		/*[0]～[size]までを取得 実装モード切替*/
		template<typename T>
		std::vector<T> take(std::vector<T>& target, int size) { return SWITCH_FAST_CONTAONER_FUNCTION(take)(target, size); }
		/*[0]～[size]までを取得*/
		template<typename T>
		std::vector<T> take_com(std::vector<T>& target, int size) {
			FAST_CONTAINER_EXCEPTION_CHECK(size <= target.size(), fast_container_exception());
			std::vector<T> result(size);
			for (int i = 0; i < size; ++i) {
				result[i] = target[i];
			}
			return result;
		}
		/*[0]～[size]までを取得 AMP実装*/
		template<typename T>
		std::vector<T> take_amp(std::vector<T>& target, int size) {
			FAST_CONTAINER_EXCEPTION_CHECK(size <= target.size(), fast_container_exception());
			std::vector<T> result(size);
			concurrency::array_view<const T, 1> av_target(target.size(), &target[0]);
			concurrency::array_view<T, 1> av_result(size, &result[0]);
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = av_target[idx];
			});
			av_result.synchronize();
			return result;
		}
		/*[0]～[size]までを取得 PPL実装*/
		template<typename T>
		std::vector<T> take_ppl(std::vector<T>& target, int size) {
			FAST_CONTAINER_EXCEPTION_CHECK(size <= target.size(), fast_container_exception());
			std::vector<T> result(size);
			concurrency::parallel_for<int>(0, size, [&](int i) {
				result[i] = target[i];
			});
			return result;
		}
		/*行[0]～[size]までを取得 実装モード切替*/
		template<typename T>
		std::vector<T> take_rows(std::vector<T>& target, int row, int col, int size) { return SWITCH_FAST_CONTAONER_FUNCTION(take_rows)(target, row, col, size); }
		/*行[0]～[size]までを取得*/
		template<typename T>
		std::vector<T> take_rows_com(std::vector<T>& target, int row, int col, int size) {
			FAST_CONTAINER_EXCEPTION_CHECK(size <= row, fast_container_exception());
			int res_size = size * col;
			std::vector<T> result(res_size);
			for (int i = 0; i < res_size; ++i) {
				result[i] = target[i];
			}
			return result;
		}
		/*行[0]～[size]までを取得 AMP実装*/
		template<typename T>
		std::vector<T> take_rows_amp(std::vector<T>& target, int row, int col, int size) {
			FAST_CONTAINER_EXCEPTION_CHECK(size <= row, fast_container_exception());
			int res_size = size * col;
			std::vector<T> result(res_size);
			concurrency::array_view<const T, 1> av_target(row * col, &target[0]);
			concurrency::array_view<T, 1> av_result(res_size, &result[0]);
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = av_target[idx];
			});
			av_result.synchronize();
			return result;
		}
		/*行[0]～[size]までを取得 PPL実装*/
		template<typename T>
		std::vector<T> take_rows_ppl(std::vector<T>& target, int row, int col, int size) {
			FAST_CONTAINER_EXCEPTION_CHECK(size <= row, fast_container_exception());
			int res_size = size * col;
			std::vector<T> result(res_size);
			concurrency::parallel_for<int>(0, res_size, [&](int i) {
				result[i] = target[i];
			});
			return result;
		}
		/*列[0]～[size]までを取得 実装モード切替*/
		template<typename T>
		std::vector<T> take_columns(std::vector<T>& target, int row, int col, int size) { return SWITCH_FAST_CONTAONER_FUNCTION(take_columns)(target, row, col, size); }
		/*列[0]～[size]までを取得*/
		template<typename T>
		std::vector<T> take_columns_com(std::vector<T>& target, int row, int col, int size) {
			FAST_CONTAINER_EXCEPTION_CHECK(size <= col, fast_container_exception());
			std::vector<T> result(row * size);
			for (int i = 0; i < row; ++i) {
				int res_offset = i * size;
				int ent_offset = i * col;
				for (int j = 0; j < size; ++j) {
					result[res_offset + j] = target[ent_offset + j];
				}
			}
			return result;
		}
		/*列[0]～[size]までを取得 AMP実装*/
		template<typename T>
		std::vector<T> take_columns_amp(std::vector<T>& target, int row, int col, int size) {
			FAST_CONTAINER_EXCEPTION_CHECK(size <= col, fast_container_exception());
			std::vector<T> result(row * size);
			concurrency::array_view<const T, 2> av_target(row, col, &target[0]);
			concurrency::array_view<T, 2> av_result(row, size, &result[0]);
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<2> idx) restrict(amp) {
				av_result[idx] = av_target[idx];
			});
			av_result.synchronize();
			return result;
		}
		/*列[0]～[size]までを取得 PPL実装*/
		template<typename T>
		std::vector<T> take_columns_ppl(std::vector<T>& target, int row, int col, int size) {
			FAST_CONTAINER_EXCEPTION_CHECK(size <= col, fast_container_exception());
			std::vector<T> result(row * size);
			concurrency::parallel_for<int>(0, row, [&](int i) {
				int res_offset = i * size;
				int ent_offset = i * col;
				for (int j = 0; j < size; ++j) {
					result[res_offset + j] = target[ent_offset + j];
				}
			});
			return result;
		}

#pragma endregion

#pragma region skip

		/*[size]～[end]までを取得 実装モード切替*/
		template<typename T>
		std::vector<T> skip(std::vector<T>& target, int size) { return SWITCH_FAST_CONTAONER_FUNCTION(skip)(target, size); }
		/*[size]～[end]までを取得*/
		template<typename T>
		std::vector<T> skip_com(std::vector<T>& target, int size) {
			int t_size = target.size();
			FAST_CONTAINER_EXCEPTION_CHECK(size < t_size, fast_container_exception());
			int res_size = t_size - size;
			std::vector<T> result(res_size);
			for (int i = 0; i < res_size; ++i) {
				result[i] = target[size + i];
			}
			return result;
		}
		/*[size]～[end]までを取得 AMP実装*/
		template<typename T>
		std::vector<T> skip_amp(std::vector<T>& target, int size) {
			int t_size = target.size();
			FAST_CONTAINER_EXCEPTION_CHECK(size <= t_size, fast_container_exception());
			int res_size = t_size - size;
			std::vector<T> result(res_size);
			concurrency::array_view<const T, 1> av_target(target.size(), &target[0]);
			concurrency::array_view<T, 1> av_result(res_size, &result[0]);
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = av_target[size + idx];
			});
			av_result.synchronize();
			return result;
		}
		/*[size]～[end]までを取得 PPL実装*/
		template<typename T>
		std::vector<T> skip_ppl(std::vector<T>& target, int size) {
			int t_size = target.size();
			FAST_CONTAINER_EXCEPTION_CHECK(size <= t_size, fast_container_exception());
			int res_size = t_size - size;
			std::vector<T> result(res_size);
			concurrency::parallel_for<int>(0, res_size, [&](int i) {
				result[i] = target[size + i];
			});
			return result;
		}
		/*行[size]～[end]までを取得 実装モード切替*/
		template<typename T>
		std::vector<T> skip_rows(std::vector<T>& target, int row, int col, int size) { return SWITCH_FAST_CONTAONER_FUNCTION(skip_rows)(target, row, col, size); }
		/*行[row]～[end]までを取得*/
		template<typename T>
		std::vector<T> skip_rows_com(std::vector<T>& target, int row, int col, int size) {
			FAST_CONTAINER_EXCEPTION_CHECK(size < row, fast_container_exception());
			int res_row = row - size;
			int res_size = res_row * col;
			int skip_size = size * col;
			std::vector<T> result(res_size);
			for (int i = 0; i < res_size; ++i) {
				result[i] = target[skip_size + i];
			}
			return result;
		}
		/*行[size]～[end]までを取得 AMP実装*/
		template<typename T>
		std::vector<T> skip_rows_amp(std::vector<T>& target, int row, int col, int size) {
			FAST_CONTAINER_EXCEPTION_CHECK(size < row, fast_container_exception());
			int res_row = row - size;
			int res_size = res_row * col;
			int skip_size = size * col;
			std::vector<T> result(res_size);
			concurrency::array_view<const T, 1> av_target(row * col, &target[0]);
			concurrency::array_view<T, 1> av_result(res_size, &result[0]);
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = av_target[skip_size + idx];
			});
			av_result.synchronize();
			return result;
		}
		/*行[size]～[end]までを取得 PPL実装*/
		template<typename T>
		std::vector<T> skip_rows_ppl(std::vector<T>& target, int row, int col, int size) {
			FAST_CONTAINER_EXCEPTION_CHECK(size < row, fast_container_exception());
			int res_row = row - size;
			int res_size = res_row * col;
			int skip_size = size * col;
			std::vector<T> result(res_size);
			concurrency::parallel_for<int>(0, res_size, [&](int i) {
				result[i] = target[skip_size + i];
			});
			return result;
		}
		/*列[size]～[end]までを取得 実装モード切替*/
		template<typename T>
		std::vector<T> skip_columns(std::vector<T>& target, int row, int col, int size) { return SWITCH_FAST_CONTAONER_FUNCTION(skip_columns)(target, row, col, size); }
		/*列[size]～[end]までを取得*/
		template<typename T>
		std::vector<T> skip_columns_com(std::vector<T>& target, int row, int col, int size) {
			FAST_CONTAINER_EXCEPTION_CHECK(size < col, fast_container_exception());
			int res_col = col - size;
			std::vector<T> result(row * res_col);
			for (int i = 0; i < row; ++i) {
				int res_offset = i * res_col;
				int ent_offset = i * col + size;
				for (int j = 0; j < res_col; ++j) {
					result[res_offset + j] = target[ent_offset + j];
				}
			}
			return result;
		}
		/*列[size]～[end]までを取得 AMP実装*/
		template<typename T>
		std::vector<T> skip_columns_amp(std::vector<T>& target, int row, int col, int size) {
			FAST_CONTAINER_EXCEPTION_CHECK(size < col, fast_container_exception());
			int res_col = col - size;
			std::vector<T> result(row * res_col);
			concurrency::array_view<const T, 2> av_target(row, col, &target[0]);
			concurrency::array_view<T, 2> av_result(row, res_col, &result[0]);
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<2> idx) restrict(amp) {
				av_result[idx] = av_target[idx[0]][size + idx[1]];
			});
			av_result.synchronize();
			return result;
		}
		/*列[size]～[end]までを取得 PPL実装*/
		template<typename T>
		std::vector<T> skip_columns_ppl(std::vector<T>& target, int row, int col, int size) {
			FAST_CONTAINER_EXCEPTION_CHECK(size < col, fast_container_exception());
			int res_col = col - size;
			std::vector<T> result(row * res_col);
			concurrency::parallel_for<int>(0, row, [&](int i) {
				int res_offset = i * res_col;
				int ent_offset = i * col + size;
				for (int j = 0; j < res_col; ++j) {
					result[res_offset + j] = target[ent_offset + j];
				}
			});
			return result;
		}

#pragma endregion

#pragma region batch

		/*バッチの取得 実装モード切替*/
		template<typename T>
		std::vector<T> batch(std::vector<T>& target, std::vector<int>& mask) { return SWITCH_FAST_CONTAONER_FUNCTION(batch)(target, mask); }
		/*バッチの取得*/
		template<typename T>
		std::vector<T> batch_com(std::vector<T>& target, std::vector<int>& mask) {
			int m_size = mask.size();
			FAST_CONTAINER_EXCEPTION_CHECK(target.size() >= m_size, fast_container_exception());
			std::vector<T> result(m_size);
			for (int i = 0; i < m_size; ++i) {
				result[i] = target[mask[i]];
			}
			return result;
		}
		/*バッチの取得 AMP実装*/
		template<typename T>
		std::vector<T> batch_amp(std::vector<T>& target, std::vector<int>& mask) {
			int t_size = target.size();
			int m_size = mask.size();
			FAST_CONTAINER_EXCEPTION_CHECK(t_size >= m_size, fast_container_exception());
			std::vector<T> result(m_size);
			concurrency::array_view<const T, 1> av_target(t_size, &target[0]);
			concurrency::array_view<const int, 1> av_mask(m_size, &mask[0]);
			concurrency::array_view<T, 1> av_result(m_size, &result[0]);
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = av_target[av_mask[idx]];
			});
			av_result.synchronize();
			return result;
		}
		/*バッチの取得 PPL実装*/
		template<typename T>
		std::vector<T> batch_ppl(std::vector<T>& target, std::vector<int>& mask) {
			int m_size = mask.size();
			FAST_CONTAINER_EXCEPTION_CHECK(target.size() >= m_size, fast_container_exception());
			std::vector<T> result(m_size);
			concurrency::parallel_for<int>(0, m_size, [&](int i) {
				result[i] = target[mask[i]];
			});
			return result;
		}
		/*バッチの取得 実装モード切替*/
		template<typename T>
		std::vector<T> batch(std::vector<T>& target, int row, int col, std::vector<int>& mask) { return SWITCH_FAST_CONTAONER_FUNCTION(batch)(target, row, col, mask); }
		/*バッチの取得*/
		template<typename T>
		std::vector<T> batch_com(std::vector<T>& target, int row, int col, std::vector<int>& mask) {
			int res_row = mask.size();
			FAST_CONTAINER_EXCEPTION_CHECK(row >= res_row, fast_container_exception());
			std::vector<T> result(res_row * col);
			for (int i = 0; i < res_row; ++i) {
				int r_offset = i * col;
				int e_offset = mask[i] * col;
				for (int j = 0; j < col; ++j) {
					result[r_offset + j] = target[e_offset + j];
				}
			}
			return result;
		}
		/*バッチの取得 AMP実装*/
		template<typename T>
		std::vector<T> batch_amp(std::vector<T>& target, int row, int col, std::vector<int>& mask) {
			int res_row = mask.size();
			FAST_CONTAINER_EXCEPTION_CHECK(row >= res_row, fast_container_exception());
			std::vector<T> result(res_row * col);
			concurrency::array_view<const T, 2> av_target(row, col, &target[0]);
			concurrency::array_view<const int, 1> av_mask(res_row, &mask[0]);
			concurrency::array_view<T, 2> av_result(res_row, col, &result[0]);
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<2> idx) restrict(amp) {
				av_result[idx] = av_target[av_mask[idx[0]]][idx[1]];
			});
			av_result.synchronize();
			return result;
		}
		/*バッチの取得 PPL実装*/
		template<typename T>
		std::vector<T> batch_ppl(std::vector<T>& target, int row, int col, std::vector<int>& mask) {
			int res_row = mask.size();
			FAST_CONTAINER_EXCEPTION_CHECK(row >= res_row, fast_container_exception());
			int res_size = res_row * col;
			std::vector<T> result(res_size);
			concurrency::parallel_for<int>(0, res_size, [&](int i) {
				result[i] = target[mask[i / col] * col + (i % col)];
			});
			return result;
		}

		/*ランダムなバッチの取得 実装モード切替*/
		template<typename T>
		std::vector<T> random_batch(std::vector<T>& target, int size) { return SWITCH_FAST_CONTAONER_FUNCTION(random_batch)(target, size); }
		/*ランダムなバッチの取得*/
		template<typename T>
		std::vector<T> random_batch_com(std::vector<T>& target, int size) { return batch_com(target, int_hash_random(size, 0, target.size() - 1)); }
		/*ランダムなバッチの取得 AMP実装*/
		template<typename T>
		std::vector<T> random_batch_amp(std::vector<T>& target, int size) { return batch_amp(target, int_hash_random(size, 0, target.size() - 1)); }
		/*ランダムなバッチの取得 PPL実装*/
		template<typename T>
		std::vector<T> random_batch_ppl(std::vector<T>& target, int size) { return batch_ppl(target, int_hash_random(size, 0, target.size() - 1)); }
		/*ランダムなバッチの取得 実装モード切替*/
		template<typename T>
		std::vector<T> random_batch(std::vector<T>& target, int row, int col, int size) { return SWITCH_FAST_CONTAONER_FUNCTION(random_batch)(target, row, col, size); }
		/*ランダムなバッチの取得*/
		template<typename T>
		std::vector<T> random_batch_com(std::vector<T>& target, int row, int col, int size) { return batch_com(target, row, col, int_hash_random(size, 0, row - 1)); }
		/*ランダムなバッチの取得 AMP実装*/
		template<typename T>
		std::vector<T> random_batch_amp(std::vector<T>& target, int row, int col, int size) { return batch_amp(target, row, col, int_hash_random(size, 0, row - 1)); }
		/*ランダムなバッチの取得 PPL実装*/
		template<typename T>
		std::vector<T> random_batch_ppl(std::vector<T>& target, int row, int col, int size) { return batch_ppl(target, row, col, int_hash_random(size, 0, row - 1)); }

#pragma endregion

#pragma region row

		/*指定行を取得 実装モード切替*/
		template<typename T>
		std::vector<T> row(std::vector<T>& target, int row, int col, int point) { return SWITCH_FAST_CONTAONER_FUNCTION(row)(target, row, col, point); }
		/*指定行を取得*/
		template<typename T>
		std::vector<T> row_com(std::vector<T>& target, int row, int col, int point) {
			FAST_CONTAINER_EXCEPTION_CHECK(point <= row, fast_container_exception());
			std::vector<T> result(col);
			for (int i = 0, j = point * col; i < col; ++i, ++j) {
				result[i] = target[j];
			}
			return result;
		}
		/*指定行を取得 AMP実装*/
		template<typename T>
		std::vector<T> row_amp(std::vector<T>& target, int row, int col, int point) {
			FAST_CONTAINER_EXCEPTION_CHECK(point <= row, fast_container_exception());
			std::vector<T> result(col);
			concurrency::array_view<const T, 2> av_target(row, col, &target[0]);
			concurrency::array_view<T, 1> av_result(col, &result[0]);
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = av_target[point][idx[0]];
			});
			av_result.synchronize();
			return result;
		}
		/*指定行を取得 PPL実装*/
		template<typename T>
		std::vector<T> row_ppl(std::vector<T>& target, int row, int col, int point) {
			FAST_CONTAINER_EXCEPTION_CHECK(point <= row, fast_container_exception());
			std::vector<T> result(col);
			concurrency::parallel_for<int>(0, col, [&](int i) {
				result[i] = target[point * col + i];
			});
			return result;
		}

#pragma endregion

#pragma region column

		/*指定列を取得 実装モード切替*/
		template<typename T>
		std::vector<T> column(std::vector<T>& target, int row, int col, int point) { return SWITCH_FAST_CONTAONER_FUNCTION(column)(target, row, col, point); }
		/*指定列を取得*/
		template<typename T>
		std::vector<T> column_com(std::vector<T>& target, int row, int col, int point) {
			FAST_CONTAINER_EXCEPTION_CHECK(point <= col, fast_container_exception());
			std::vector<T> result(row);
			for (int i = 0, j = point; i < row; ++i, j += col) {
				result[i] = target[j];
			}
			return result;
		}
		/*指定列を取得 AMP実装*/
		template<typename T>
		std::vector<T> column_amp(std::vector<T>& target, int row, int col, int point) {
			FAST_CONTAINER_EXCEPTION_CHECK(point <= col, fast_container_exception());
			std::vector<T> result(row);
			concurrency::array_view<const T, 2> av_target(row, col, &target[0]);
			concurrency::array_view<T, 1> av_result(row, &result[0]);
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = av_target[idx[0]][point];
			});
			av_result.synchronize();
			return result;
		}
		/*指定列を取得 PPL実装*/
		template<typename T>
		std::vector<T> column_ppl(std::vector<T>& target, int row, int col, int point) {
			FAST_CONTAINER_EXCEPTION_CHECK(point <= col, fast_container_exception());
			std::vector<T> result(row);
			concurrency::parallel_for<int>(0, row, [&](int i) {
				result[i] = target[i * col + point];
			});
			return result;
		}

#pragma endregion

#pragma region reverse

		/*転置行列 実装モード切替*/
		template<typename T>
		std::vector<T> reverse(std::vector<T>& target, int row, int col) { return SWITCH_FAST_CONTAONER_FUNCTION(reverse)(target, row, col); }
		/*転置行列*/
		template<typename T>
		std::vector<T> reverse_com(std::vector<T>& target, int row, int col) {
			std::vector<T> result(col * row);
			for (int i = 0; i < row; ++i) {
				int offset = i * col;
				for (int j = 0; j < col; ++j) {
					result[j * row + i] = target[offset + j];
				}
			}
			return result;
		}
		/*転置行列 AMP実装*/
		template<typename T>
		std::vector<T> reverse_amp(std::vector<T>& target, int row, int col) {
			std::vector<T> result(col * row);
			concurrency::array_view<const T, 2> av_target(row, col, &target[0]);
			concurrency::array_view<T, 2> av_result(col, row, &result[0]);
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<2> idx) restrict(amp) {
				av_result[idx] = av_target[idx[1]][idx[0]];
			});
			av_result.synchronize();
			return result;
		}
		/*転置行列 PPL実装*/
		template<typename T>
		std::vector<T> reverse_ppl(std::vector<T>& target, int row, int col) {
			int size = col * row;
			std::vector<T> result(size);
			concurrency::parallel_for<int>(0, size, [&](int i) {
				result[i] = target[(i % row) * col + i / row];
			});
			return result;
		}

#pragma endregion

	}
}
