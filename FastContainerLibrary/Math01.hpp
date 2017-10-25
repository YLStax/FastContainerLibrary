#pragma once

#include "FastContainerLibrary.hpp"

namespace FastContainer {
	namespace Functions {

#pragma region min

		/*�ŏ��l*/
		template<typename T>
		inline T get_min(std::vector<T>& target) {
			T result = target[0];
			for (auto x : target) result = min(result, x);
			return result;
		}
		/*�s���̍ŏ��l �������[�h�ؑ�*/
		template<typename T>
		std::vector<T> min_by_rows(std::vector<T>& target, int row, int col) { return SWITCH_FAST_CONTAONER_FUNCTION(min_by_rows)(target, row, col); }
		/*�s���̍ŏ��l*/
		template<typename T>
		std::vector<T> min_by_rows_com(std::vector<T>& target, int row, int col) {
			std::vector<T> result(row);
			for (int i = 0; i < row; ++i) {
				int offset = i * col;
				result[i] = target[offset];
				for (int j = 0; j < col; ++j) {
					T b_result = result[i];
					T b_target = target[offset + j];
					result[i] = min(b_result, b_target);
				}
			}
			return result;
		}
		/*�s���̍ŏ��l AMP����*/
		template<typename T>
		std::vector<T> min_by_rows_amp(std::vector<T>& target, int row, int col) {
			std::vector<T> result(row);
			concurrency::array_view<const T, 2> av_target(row, col, &target[0]);
			concurrency::array_view<T, 1> av_result(row, &result[0]);
			int b_col = col;
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = av_target[idx[0]][0];
				for (int i = 0; i < b_col; ++i) {
					T b_result = av_result[idx];
					T b_target = av_target[idx[0]][i];
					av_result[idx] = min(b_result, b_target);
				}
			});
			av_result.synchronize();
			return result;
		}
		/*�s���̍ŏ��l PPL����*/
		template<typename T>
		std::vector<T> min_by_rows_ppl(std::vector<T>& target, int row, int col) {
			std::vector<T> result(row);
			concurrency::parallel_for<int>(0, row, [&](int i) {
				int offset = i * col;
				result[i] = target[offset];
				for (int j = 0; j < col; ++j) {
					T b_result = result[i];
					T b_target = target[offset + j];
					result[i] = min(b_result, b_target);
				}
			});
			return result;
		}
		/*�񖈂̍ŏ��l �������[�h�ؑ�*/
		template<typename T>
		std::vector<T> min_by_columns(std::vector<T>& target, int row, int col) { return SWITCH_FAST_CONTAONER_FUNCTION(min_by_columns)(target, row, col); }
		/*�񖈂̍ŏ��l*/
		template<typename T>
		std::vector<T> min_by_columns_com(std::vector<T>& target, int row, int col) {
			std::vector<T> result(col);
			for (int i = 0; i < col; ++i) {
				result[i] = target[i];
				for (int j = 0; j < row; ++j) {
					T b_result = result[i];
					T b_target = target[j * col + i];
					result[i] = min(b_result, b_target);
				}
			}
			return result;
		}
		/*�񖈂̍ŏ��l AMP����*/
		template<typename T>
		std::vector<T> min_by_columns_amp(std::vector<T>& target, int row, int col) {
			std::vector<T> result(col);
			concurrency::array_view<const T, 2> av_target(row, col, &target[0]);
			concurrency::array_view<T, 1> av_result(col, &result[0]);
			int b_row = row;
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = av_target[0][idx[0]];
				for (int i = 0; i < b_row; ++i) {
					T b_result = av_result[idx];
					T b_target = av_target[i][idx[0]];
					av_result[idx] = min(b_result, b_target);
				}
			});
			av_result.synchronize();
			return result;
		}
		/*�񖈂̍ŏ��l PPL����*/
		template<typename T>
		std::vector<T> min_by_columns_ppl(std::vector<T>& target, int row, int col) {
			std::vector<T> result(col);
			concurrency::parallel_for<int>(0, col, [&](int i) {
				result[i] = target[i];
				for (int j = 0; j < row; ++j) {
					T b_result = result[i];
					T b_target = target[j * col + i];
					result[i] = min(b_result, b_target);
				}
			});
			return result;
		}

#pragma endregion

#pragma region max

		/*�ő�l*/
		template<typename T>
		inline T get_max(std::vector<T>& target) {
			T result = target[0];
			for (auto x : target) result = max(result, x);
			return result;
		}
		/*�s���̍ő�l �������[�h�ؑ�*/
		template<typename T>
		std::vector<T> max_by_rows(std::vector<T>& target, int row, int col) { return SWITCH_FAST_CONTAONER_FUNCTION(max_by_rows)(target, row, col); }
		/*�s���̍ő�l*/
		template<typename T>
		std::vector<T> max_by_rows_com(std::vector<T>& target, int row, int col) {
			std::vector<T> result(row);
			for (int i = 0; i < row; ++i) {
				int offset = i * col;
				result[i] = target[offset];
				for (int j = 0; j < col; ++j) {
					T b_result = result[i];
					T b_target = target[offset + j];
					result[i] = max(b_result, b_target);
				}
			}
			return result;
		}
		/*�s���̍ő�l AMP����*/
		template<typename T>
		std::vector<T> max_by_rows_amp(std::vector<T>& target, int row, int col) {
			std::vector<T> result(row);
			concurrency::array_view<const T, 2> av_target(row, col, &target[0]);
			concurrency::array_view<T, 1> av_result(row, &result[0]);
			int b_col = col;
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = av_target[idx[0]][0];
				for (int i = 0; i < b_col; ++i) {
					T b_result = av_result[idx];
					T b_target = av_target[idx[0]][i];
					av_result[idx] = max(b_result, b_target);
				}
			});
			av_result.synchronize();
			return result;
		}
		/*�s���̍ő�l PPL����*/
		template<typename T>
		std::vector<T> max_by_rows_ppl(std::vector<T>& target, int row, int col) {
			std::vector<T> result(row);
			concurrency::parallel_for<int>(0, row, [&](int i) {
				int offset = i * col;
				result[i] = target[offset];
				for (int j = 0; j < col; ++j) {
					T b_result = result[i];
					T b_target = target[offset + j];
					result[i] = max(b_result, b_target);
				}
			});
			return result;
		}
		/*�񖈂̍ő�l �������[�h�ؑ�*/
		template<typename T>
		std::vector<T> max_by_columns(std::vector<T>& target, int row, int col) { return SWITCH_FAST_CONTAONER_FUNCTION(max_by_columns)(target, row, col); }
		/*�񖈂̍ő�l*/
		template<typename T>
		std::vector<T> max_by_columns_com(std::vector<T>& target, int row, int col) {
			std::vector<T> result(col);
			for (int i = 0; i < col; ++i) {
				result[i] = target[i];
				for (int j = 0; j < row; ++j) {
					T b_result = result[i];
					T b_target = target[j * col + i];
					result[i] = max(b_result, b_target);
				}
			}
			return result;
		}
		/*�񖈂̍ő�l AMP����*/
		template<typename T>
		std::vector<T> max_by_columns_amp(std::vector<T>& target, int row, int col) {
			std::vector<T> result(col);
			concurrency::array_view<const T, 2> av_target(row, col, &target[0]);
			concurrency::array_view<T, 1> av_result(col, &result[0]);
			int b_row = row;
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = av_target[0][idx[0]];
				for (int i = 0; i < b_row; ++i) {
					T b_result = av_result[idx];
					T b_target = av_target[i][idx[0]];
					av_result[idx] = max(b_result, b_target);
				}
			});
			av_result.synchronize();
			return result;
		}
		/*�񖈂̍ő�l PPL����*/
		template<typename T>
		std::vector<T> max_by_columns_ppl(std::vector<T>& target, int row, int col) {
			std::vector<T> result(col);
			concurrency::parallel_for<int>(0, col, [&](int i) {
				result[i] = target[i];
				for (int j = 0; j < row; ++j) {
					T b_result = result[i];
					T b_target = target[j * col + i];
					result[i] = max(b_result, b_target);
				}
			});
			return result;
		}

#pragma endregion

#pragma region argmax

		/*�ő�l�̃C���f�b�N�X*/
		template<typename T>
		inline T argmax(std::vector<T>& target) {
			int result = 0;
			int size = target.size();
			T max = target[0];
			for (int i = 0; i < size; ++i) {
				T buf = target[i];
				if (max < buf) {
					max = buf;
					result = i;
				}
			}
			return result;
		}
		/*�s���̍ő�l�̃C���f�b�N�X �������[�h�ؑ�*/
		template<typename T>
		std::vector<T> argmax_by_rows(std::vector<T>& target, int row, int col) { return SWITCH_FAST_CONTAONER_FUNCTION(argmax_by_rows)(target, row, col); }
		/*�s���̍ő�l�̃C���f�b�N�X*/
		template<typename T>
		std::vector<T> argmax_by_rows_com(std::vector<T>& target, int row, int col) {
			std::vector<T> result(row);
			for (int i = 0; i < row; ++i) {
				int offset = i * col;
				T max = target[offset];
				for (int j = 0; j < col; ++j) {
					T b_target = target[offset + j];
					if (max < b_target) {
						max = b_target;
						result[i] = j;
					}
				}
			}
			return result;
		}
		/*�s���̍ő�l�̃C���f�b�N�X AMP����*/
		template<typename T>
		std::vector<T> argmax_by_rows_amp(std::vector<T>& target, int row, int col) {
			std::vector<T> result(row);
			concurrency::array_view<const T, 2> av_target(row, col, &target[0]);
			concurrency::array_view<T, 1> av_result(row, &result[0]);
			int b_col = col;
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = 0;
				T max = av_target[idx[0]][0];
				for (int i = 0; i < b_col; ++i) {
					T b_target = av_target[idx[0]][i];
					if (max < b_target) {
						max = b_target;
						av_result[idx] = i;
					}
				}
			});
			av_result.synchronize();
			return result;
		}
		/*�s���̍ő�l�̃C���f�b�N�X PPL����*/
		template<typename T>
		std::vector<T> argmax_by_rows_ppl(std::vector<T>& target, int row, int col) {
			std::vector<T> result(row);
			concurrency::parallel_for<int>(0, row, [&](int i) {
				int offset = i * col;
				T max = target[offset];
				for (int j = 0; j < col; ++j) {
					T b_target = target[offset + j];
					if (max < b_target) {
						max = b_target;
						result[i] = j;
					}
				}
			});
			return result;
		}
		/*�񖈂̍ő�l�̃C���f�b�N�X �������[�h�ؑ�*/
		template<typename T>
		std::vector<T> argmax_by_columns(std::vector<T>& target, int row, int col) { return SWITCH_FAST_CONTAONER_FUNCTION(argmax_by_columns)(target, row, col); }
		/*�񖈂̍ő�l�̃C���f�b�N�X*/
		template<typename T>
		std::vector<T> argmax_by_columns_com(std::vector<T>& target, int row, int col) {
			std::vector<T> result(col);
			for (int i = 0; i < col; ++i) {
				T max = target[i];
				for (int j = 0; j < row; ++j) {
					T b_target = target[j * col + i];
					if (max < b_target) {
						max = b_target;
						result[i] = j;
					}
				}
			}
			return result;
		}
		/*�񖈂̍ő�l�̃C���f�b�N�X AMP����*/
		template<typename T>
		std::vector<T> argmax_by_columns_amp(std::vector<T>& target, int row, int col) {
			std::vector<T> result(col);
			concurrency::array_view<const T, 2> av_target(row, col, &target[0]);
			concurrency::array_view<T, 1> av_result(col, &result[0]);
			int b_row = row;
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = 0;
				T max = av_target[0][idx[0]];
				for (int i = 0; i < b_row; ++i) {
					T b_target = av_target[i][idx[0]];
					if (max < b_target) {
						max = b_target;
						av_result[idx] = i;
					}
				}
			});
			av_result.synchronize();
			return result;
		}
		/*�񖈂̍ő�l�̃C���f�b�N�X PPL����*/
		template<typename T>
		std::vector<T> argmax_by_columns_ppl(std::vector<T>& target, int row, int col) {
			std::vector<T> result(col);
			concurrency::parallel_for<int>(0, col, [&](int i) {
				T max = target[i];
				for (int j = 0; j < row; ++j) {
					T b_target = target[j * col + i];
					if (max < b_target) {
						max = b_target;
						result[i] = j;
					}
				}
			});
			return result;
		}

#pragma endregion

#pragma region sum

		/*���v*/
		template<typename T>
		inline T sum(std::vector<T>& target) {
			T result = 0;
			for (auto x : target) result += x;
			return result;
		}
		/*�s���̍��v �������[�h�ؑ�*/
		template<typename T>
		std::vector<T> sum_by_rows(std::vector<T>& target, int row, int col) { return SWITCH_FAST_CONTAONER_FUNCTION(sum_by_rows)(target, row, col); }
		/*�s���̍��v*/
		template<typename T>
		std::vector<T> sum_by_rows_com(std::vector<T>& target, int row, int col) {
			std::vector<T> result(row);
			for (int i = 0; i < row; ++i) {
				int offset = i * col;
				for (int j = 0; j < col; ++j) {
					result[i] += target[offset + j];
				}
			}
			return result;
		}
		/*�s���̍��v AMP����*/
		template<typename T>
		std::vector<T> sum_by_rows_amp(std::vector<T>& target, int row, int col) {
			std::vector<T> result(row);
			concurrency::array_view<const T, 2> av_target(row, col, &target[0]);
			concurrency::array_view<T, 1> av_result(row, &result[0]);
			int b_col = col;
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = 0;
				for (int i = 0; i < b_col; ++i) {
					av_result[idx] += av_target[idx[0]][i];
				}
			});
			av_result.synchronize();
			return result;
		}
		/*�s���̍��v PPL����*/
		template<typename T>
		std::vector<T> sum_by_rows_ppl(std::vector<T>& target, int row, int col) {
			std::vector<T> result(row);
			concurrency::parallel_for<int>(0, row, [&](int i) {
				int offset = i * col;
				for (int j = 0; j < col; ++j) {
					result[i] += target[offset + j];
				}
			});
			return result;
		}
		/*�񖈂̍��v �������[�h�ؑ�*/
		template<typename T>
		std::vector<T> sum_by_columns(std::vector<T>& target, int row, int col) { return SWITCH_FAST_CONTAONER_FUNCTION(sum_by_columns)(target, row, col); }
		/*�񖈂̍��v*/
		template<typename T>
		std::vector<T> sum_by_columns_com(std::vector<T>& target, int row, int col) {
			std::vector<T> result(col);
			for (int j = 0; j < row; ++j) {
				int offset = j * col;
				for (int i = 0; i < col; ++i) {
					result[i] += target[offset + i];
				}
			}
			return result;
		}
		/*�񖈂̍��v AMP����*/
		template<typename T>
		std::vector<T> sum_by_columns_amp(std::vector<T>& target, int row, int col) {
			std::vector<T> result(col);
			concurrency::array_view<const T, 2> av_target(row, col, &target[0]);
			concurrency::array_view<T, 1> av_result(col, &result[0]);
			int b_row = row;
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = 0;
				for (int i = 0; i < b_row; ++i) {
					av_result[idx] += av_target[i][idx[0]];
				}
			});
			av_result.synchronize();
			return result;
		}
		/*�񖈂̍��v PPL����*/
		template<typename T>
		std::vector<T> sum_by_columns_ppl(std::vector<T>& target, int row, int col) {
			std::vector<T> result(col);
			concurrency::parallel_for<int>(0, col, [&](int i) {
				for (int j = 0; j < row; ++j) {
					result[i] += target[j * col + i];
				}
			});
			return result;
		}

#pragma endregion

#pragma region mean

		/*����*/
		template<typename T>
		inline T mean(std::vector<T>& target) {
			return sum(target) / target.size();
		}
		/*�s���̕��� �������[�h�ؑ�*/
		template<typename T>
		std::vector<T> mean_by_rows(std::vector<T>& target, int row, int col) { return SWITCH_FAST_CONTAONER_FUNCTION(mean_by_rows)(target, row, col); }
		/*�s���̕���*/
		template<typename T>
		std::vector<T> mean_by_rows_com(std::vector<T>& target, int row, int col) {
			std::vector<T> result(row);
			for (int i = 0; i < row; ++i) {
				int offset = i * col;
				for (int j = 0; j < col; ++j) {
					result[i] += target[offset + j];
				}
				result[i] /= col;
			}
			return result;
		}
		/*�s���̕��� AMP����*/
		template<typename T>
		std::vector<T> mean_by_rows_amp(std::vector<T>& target, int row, int col) {
			std::vector<T> result(row);
			concurrency::array_view<const T, 2> av_target(row, col, &target[0]);
			concurrency::array_view<T, 1> av_result(row, &result[0]);
			int b_col = col;
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = 0;
				for (int i = 0; i < b_col; ++i) {
					av_result[idx] += av_target[idx[0]][i];
				}
				av_result[idx] /= b_col;
			});
			av_result.synchronize();
			return result;
		}
		/*�s���̕��� PPL����*/
		template<typename T>
		std::vector<T> mean_by_rows_ppl(std::vector<T>& target, int row, int col) {
			std::vector<T> result(row);
			concurrency::parallel_for<int>(0, row, [&](int i) {
				int offset = i * col;
				for (int j = 0; j < col; ++j) {
					result[i] += target[offset + j];
				}
				result[i] /= col;
			});
			return result;
		}
		/*�񖈂̕��� �������[�h�ؑ�*/
		template<typename T>
		std::vector<T> mean_by_columns(std::vector<T>& target, int row, int col) { return SWITCH_FAST_CONTAONER_FUNCTION(mean_by_columns)(target, row, col); }
		/*�񖈂̕���*/
		template<typename T>
		std::vector<T> mean_by_columns_com(std::vector<T>& target, int row, int col) {
			std::vector<T> result(col);
			for (int i = 0; i < col; ++i) {
				for (int j = 0; j < row; ++j) {
					result[i] += target[j * col + i];
				}
				result[i] /= row;
			}
			return result;
		}
		/*�񖈂̕��� AMP����*/
		template<typename T>
		std::vector<T> mean_by_columns_amp(std::vector<T>& target, int row, int col) {
			std::vector<T> result(col);
			concurrency::array_view<const T, 2> av_target(row, col, &target[0]);
			concurrency::array_view<T, 1> av_result(col, &result[0]);
			int b_row = row;
			av_result.discard_data();
			concurrency::parallel_for_each(av_result.extent, [=](concurrency::index<1> idx) restrict(amp) {
				av_result[idx] = 0;
				for (int i = 0; i < b_row; ++i) {
					av_result[idx] += av_target[i][idx[0]];
				}
				av_result[idx] /= b_row;
			});
			av_result.synchronize();
			return result;
		}
		/*�񖈂̕��� PPL����*/
		template<typename T>
		std::vector<T> mean_by_columns_ppl(std::vector<T>& target, int row, int col) {
			std::vector<T> result(col);
			concurrency::parallel_for<int>(0, col, [&](int i) {
				for (int j = 0; j < row; ++j) {
					result[i] += target[j * col + i];
				}
				result[i] /= row;
			});
			return result;
		}

#pragma endregion

#pragma region cross_entropy_error

		/*�����G���g���s�[�덷 �������[�h�ؑ�*/
		template<typename T>
		T cross_entropy_error(std::vector<T>& target, std::vector<T>& teacher, T delta = 0.0000001, int row = 1) { return SWITCH_FAST_CONTAONER_FUNCTION(cross_entropy_error)(target, teacher, delta, row); }
		/*�����G���g���s�[�덷*/
		template<typename T>
		T cross_entropy_error_com(std::vector<T>& target, std::vector<T>& teacher, T delta = 0.0000001, int row = 1) {
			return sum(apply_com_combo_func([=](T x1, T x2) { return (T)-1 * x2 * std::log(x1 + delta) + (1 - x2) * std::log(1 - x1 + delta); }, target, teacher)) / row;
		}
		/*�����G���g���s�[�덷 AMP����*/
		template<typename T>
		T cross_entropy_error_amp(std::vector<T>& target, std::vector<T>& teacher, T delta = 0.0000001, int row = 1) {
			return sum(apply_amp_combo_func([=](T x1, T x2) restrict(amp) { return (T)-1 * x2 * concurrency::fast_math::log(x1 + delta) + (1 - x2) * concurrency::fast_math::log(1 - x1 + delta); }, target, teacher)) / row;
		}
		/*�����G���g���s�[�덷 PPL����*/
		template<typename T>
		T cross_entropy_error_ppl(std::vector<T>& target, std::vector<T>& teacher, T delta = 0.0000001, int row = 1) {
			return sum(apply_ppl_combo_func([=](T x1, T x2) { return (T)-1 * x2 * std::log(x1 + delta) + (1 - x2) * std::log(1 - x1 + delta); }, target, teacher)) / row;
		}

		/*�����G���g���s�[�덷 ���ޖ�� �������[�h�ؑ�*/
		template<typename T>
		T cross_entropy_error_class(std::vector<T>& target, std::vector<T>& teacher, T delta = 0.0000001, int row = 1) { return SWITCH_FAST_CONTAONER_FUNCTION(cross_entropy_error_class)(target, teacher, delta, row); }
		/*�����G���g���s�[�덷 ���ޖ��*/
		template<typename T>
		T cross_entropy_error_class_com(std::vector<T>& target, std::vector<T>& teacher, T delta = 0.0000001, int row = 1) {
			return sum(apply_com_combo_func([=](T x1, T x2) { return (T)-1 * x2 * std::log(x1 + delta); }, target, teacher)) / row;
		}
		/*�����G���g���s�[�덷 ���ޖ�� AMP����*/
		template<typename T>
		T cross_entropy_error_class_amp(std::vector<T>& target, std::vector<T>& teacher, T delta = 0.0000001, int row = 1) {
			return sum(apply_amp_combo_func([=](T x1, T x2) restrict(amp) { return (T)-1 * x2 * concurrency::fast_math::log(x1 + delta); }, target, teacher)) / row;
		}
		/*�����G���g���s�[�덷 ���ޖ�� PPL����*/
		template<typename T>
		T cross_entropy_error_class_ppl(std::vector<T>& target, std::vector<T>& teacher, T delta = 0.0000001, int row = 1) {
			return sum(apply_ppl_combo_func([=](T x1, T x2) { return (T)-1 * x2 * std::log(x1 + delta); }, target, teacher)) / row;
		}

#pragma endregion

	}
}
