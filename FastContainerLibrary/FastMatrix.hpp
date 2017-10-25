#pragma once

#include "FastContainerLibrary.hpp"

namespace FastContainer {

	template<typename T>
	class FastMatrix {
	public:
		FastMatrix() {}
		FastMatrix(std::vector<T>& vec, int row, int col) {
			FAST_CONTAINER_EXCEPTION_CHECK(vec.size() == row * col, fast_container_exception());
			entity = vec;
			row_size = row;
			column_size = col;
		}
		~FastMatrix() {}

		std::vector<T>& get_entity() { return entity; }
		int get_row_size() { return row_size; }
		int get_column_size() { return column_size; }

		T& operator[](int idx) { return entity[idx]; }
		T& operator()(int row, int col) { return entity[row * column_size + col]; }

		auto begin() { return entity.begin(); }
		auto begin() const { return entity.begin(); }
		auto end() { return entity.end(); }
		auto end() const { return entity.end(); }

		FastMatrix<T> identity() { return this; }

		FastMatrix<T> add_by_rows(FastVector<T>& target) { return FastMatrix<T>(Functions::add_by_rows(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> add_by_rows_com(FastVector<T>& target) { return FastMatrix<T>(Functions::add_by_rows_com(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> add_by_rows_amp(FastVector<T>& target) { return FastMatrix<T>(Functions::add_by_rows_amp(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> add_by_rows_ppl(FastVector<T>& target) { return FastMatrix<T>(Functions::add_by_rows_ppl(entity, row_size, column_size, target.get_entity()), row_size, column_size); }

		FastMatrix<T> add_by_columns(FastVector<T>& target) { return FastMatrix<T>(Functions::add_by_columns(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> add_by_columns_com(FastVector<T>& target) { return FastMatrix<T>(Functions::add_by_columns_com(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> add_by_columns_amp(FastVector<T>& target) { return FastMatrix<T>(Functions::add_by_columns_amp(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> add_by_columns_ppl(FastVector<T>& target) { return FastMatrix<T>(Functions::add_by_columns_ppl(entity, row_size, column_size, target.get_entity()), row_size, column_size); }

		FastMatrix<T> sub_by_rows(FastVector<T>& target) { return FastMatrix<T>(Functions::sub_by_rows(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> sub_by_rows_com(FastVector<T>& target) { return FastMatrix<T>(Functions::sub_by_rows_com(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> sub_by_rows_amp(FastVector<T>& target) { return FastMatrix<T>(Functions::sub_by_rows_amp(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> sub_by_rows_ppl(FastVector<T>& target) { return FastMatrix<T>(Functions::sub_by_rows_ppl(entity, row_size, column_size, target.get_entity()), row_size, column_size); }

		FastMatrix<T> sub_by_columns(FastVector<T>& target) { return FastMatrix<T>(Functions::sub_by_columns(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> sub_by_columns_com(FastVector<T>& target) { return FastMatrix<T>(Functions::sub_by_columns_com(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> sub_by_columns_amp(FastVector<T>& target) { return FastMatrix<T>(Functions::sub_by_columns_amp(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> sub_by_columns_ppl(FastVector<T>& target) { return FastMatrix<T>(Functions::sub_by_columns_ppl(entity, row_size, column_size, target.get_entity()), row_size, column_size); }

		FastMatrix<T> mul_by_rows(FastVector<T>& target) { return FastMatrix<T>(Functions::mul_by_rows(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> mul_by_rows_com(FastVector<T>& target) { return FastMatrix<T>(Functions::mul_by_rows_com(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> mul_by_rows_amp(FastVector<T>& target) { return FastMatrix<T>(Functions::mul_by_rows_amp(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> mul_by_rows_ppl(FastVector<T>& target) { return FastMatrix<T>(Functions::mul_by_rows_ppl(entity, row_size, column_size, target.get_entity()), row_size, column_size); }

		FastMatrix<T> mul_by_columns(FastVector<T>& target) { return FastMatrix<T>(Functions::mul_by_columns(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> mul_by_columns_com(FastVector<T>& target) { return FastMatrix<T>(Functions::mul_by_columns_com(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> mul_by_columns_amp(FastVector<T>& target) { return FastMatrix<T>(Functions::mul_by_columns_amp(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> mul_by_columns_ppl(FastVector<T>& target) { return FastMatrix<T>(Functions::mul_by_columns_ppl(entity, row_size, column_size, target.get_entity()), row_size, column_size); }

		FastMatrix<T> div_by_rows(FastVector<T>& target) { return FastMatrix<T>(Functions::div_by_rows(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> div_by_rows_com(FastVector<T>& target) { return FastMatrix<T>(Functions::div_by_rows_com(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> div_by_rows_amp(FastVector<T>& target) { return FastMatrix<T>(Functions::div_by_rows_amp(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> div_by_rows_ppl(FastVector<T>& target) { return FastMatrix<T>(Functions::div_by_rows_ppl(entity, row_size, column_size, target.get_entity()), row_size, column_size); }

		FastMatrix<T> div_by_columns(FastVector<T>& target) { return FastMatrix<T>(Functions::div_by_columns(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> div_by_columns_com(FastVector<T>& target) { return FastMatrix<T>(Functions::div_by_columns_com(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> div_by_columns_amp(FastVector<T>& target) { return FastMatrix<T>(Functions::div_by_columns_amp(entity, row_size, column_size, target.get_entity()), row_size, column_size); }
		FastMatrix<T> div_by_columns_ppl(FastVector<T>& target) { return FastMatrix<T>(Functions::div_by_columns_ppl(entity, row_size, column_size, target.get_entity()), row_size, column_size); }

		FastMatrix<T> dot(FastMatrix<T>& target) { return FastMatrix<T>(Functions::dot(entity, target.get_entity(), row_size, column_size, target.get_column_size()), row_size, target.get_column_size()); }
		FastMatrix<T> dot_com(FastMatrix<T>& target) { return FastMatrix<T>(Functions::dot_com(entity, target.get_entity(), row_size, column_size, target.get_column_size()), row_size, target.get_column_size()); }
		FastMatrix<T> dot_amp(FastMatrix<T>& target) { return FastMatrix<T>(Functions::dot_amp(entity, target.get_entity(), row_size, column_size, target.get_column_size()), row_size, target.get_column_size()); }
		FastMatrix<T> dot_ppl(FastMatrix<T>& target) { return FastMatrix<T>(Functions::dot_ppl(entity, target.get_entity(), row_size, column_size, target.get_column_size()), row_size, target.get_column_size()); }

		T get_min() { return Functions::get_min(entity); }
		T get_max() { return Functions::get_max(entity); }
		T argmax() { return Functions::argmax(entity); }
		T sum() { return Functions::sum(entity); }
		T mean() { return Functions::mean(entity); }

		FastVector<T> min_by_rows() { return FastVector<T>(Functions::min_by_rows(entity, row_size, column_size)); }
		FastVector<T> min_by_rows_com() { return FastVector<T>(Functions::min_by_rows_com(entity, row_size, column_size)); }
		FastVector<T> min_by_rows_amp() { return FastVector<T>(Functions::min_by_rows_amp(entity, row_size, column_size)); }
		FastVector<T> min_by_rows_ppl() { return FastVector<T>(Functions::min_by_rows_ppl(entity, row_size, column_size)); }

		FastVector<T> min_by_columns() { return FastVector<T>(Functions::min_by_columns(entity, row_size, column_size)); }
		FastVector<T> min_by_columns_com() { return FastVector<T>(Functions::min_by_columns_com(entity, row_size, column_size)); }
		FastVector<T> min_by_columns_amp() { return FastVector<T>(Functions::min_by_columns_amp(entity, row_size, column_size)); }
		FastVector<T> min_by_columns_ppl() { return FastVector<T>(Functions::min_by_columns_ppl(entity, row_size, column_size)); }

		FastVector<T> max_by_rows() { return FastVector<T>(Functions::max_by_rows(entity, row_size, column_size)); }
		FastVector<T> max_by_rows_com() { return FastVector<T>(Functions::max_by_rows_com(entity, row_size, column_size)); }
		FastVector<T> max_by_rows_amp() { return FastVector<T>(Functions::max_by_rows_amp(entity, row_size, column_size)); }
		FastVector<T> max_by_rows_ppl() { return FastVector<T>(Functions::max_by_rows_ppl(entity, row_size, column_size)); }

		FastVector<T> max_by_columns() { return FastVector<T>(Functions::max_by_columns(entity, row_size, column_size)); }
		FastVector<T> max_by_columns_com() { return FastVector<T>(Functions::max_by_columns_com(entity, row_size, column_size)); }
		FastVector<T> max_by_columns_amp() { return FastVector<T>(Functions::max_by_columns_amp(entity, row_size, column_size)); }
		FastVector<T> max_by_columns_ppl() { return FastVector<T>(Functions::max_by_columns_ppl(entity, row_size, column_size)); }

		FastVector<T> argmax_by_rows() { return FastVector<T>(Functions::argmax_by_rows(entity, row_size, column_size)); }
		FastVector<T> argmax_by_rows_com() { return FastVector<T>(Functions::argmax_by_rows_com(entity, row_size, column_size)); }
		FastVector<T> argmax_by_rows_amp() { return FastVector<T>(Functions::argmax_by_rows_amp(entity, row_size, column_size)); }
		FastVector<T> argmax_by_rows_ppl() { return FastVector<T>(Functions::argmax_by_rows_ppl(entity, row_size, column_size)); }

		FastVector<T> argmax_by_columns() { return FastVector<T>(Functions::argmax_by_columns(entity, row_size, column_size)); }
		FastVector<T> argmax_by_columns_com() { return FastVector<T>(Functions::argmax_by_columns_com(entity, row_size, column_size)); }
		FastVector<T> argmax_by_columns_amp() { return FastVector<T>(Functions::argmax_by_columns_amp(entity, row_size, column_size)); }
		FastVector<T> argmax_by_columns_ppl() { return FastVector<T>(Functions::argmax_by_columns_ppl(entity, row_size, column_size)); }

		FastVector<T> sum_by_rows() { return FastVector<T>(Functions::sum_by_rows(entity, row_size, column_size)); }
		FastVector<T> sum_by_rows_com() { return FastVector<T>(Functions::sum_by_rows_com(entity, row_size, column_size)); }
		FastVector<T> sum_by_rows_amp() { return FastVector<T>(Functions::sum_by_rows_amp(entity, row_size, column_size)); }
		FastVector<T> sum_by_rows_ppl() { return FastVector<T>(Functions::sum_by_rows_ppl(entity, row_size, column_size)); }

		FastVector<T> sum_by_columns() { return FastVector<T>(Functions::sum_by_columns(entity, row_size, column_size)); }
		FastVector<T> sum_by_columns_com() { return FastVector<T>(Functions::sum_by_columns_com(entity, row_size, column_size)); }
		FastVector<T> sum_by_columns_amp() { return FastVector<T>(Functions::sum_by_columns_amp(entity, row_size, column_size)); }
		FastVector<T> sum_by_columns_ppl() { return FastVector<T>(Functions::sum_by_columns_ppl(entity, row_size, column_size)); }

		FastVector<T> mean_by_rows() { return FastVector<T>(Functions::mean_by_rows(entity, row_size, column_size)); }
		FastVector<T> mean_by_rows_com() { return FastVector<T>(Functions::mean_by_rows_com(entity, row_size, column_size)); }
		FastVector<T> mean_by_rows_amp() { return FastVector<T>(Functions::mean_by_rows_amp(entity, row_size, column_size)); }
		FastVector<T> mean_by_rows_ppl() { return FastVector<T>(Functions::mean_by_rows_ppl(entity, row_size, column_size)); }

		FastVector<T> mean_by_columns() { return FastVector<T>(Functions::mean_by_columns(entity, row_size, column_size)); }
		FastVector<T> mean_by_columns_com() { return FastVector<T>(Functions::mean_by_columns_com(entity, row_size, column_size)); }
		FastVector<T> mean_by_columns_amp() { return FastVector<T>(Functions::mean_by_columns_amp(entity, row_size, column_size)); }
		FastVector<T> mean_by_columns_ppl() { return FastVector<T>(Functions::mean_by_columns_ppl(entity, row_size, column_size)); }

		T cross_entropy_error(FastMatrix<T>& teacher, T delta = 0.0000001) { return Functions::cross_entropy_error(entity, teacher.get_entity(), delta, row_size); }
		T cross_entropy_error_com(FastMatrix<T>& teacher, T delta = 0.0000001) { return Functions::cross_entropy_error_com(entity, teacher.get_entity(), delta, row_size); }
		T cross_entropy_error_amp(FastMatrix<T>& teacher, T delta = 0.0000001) { return Functions::cross_entropy_error_amp(entity, teacher.get_entity(), delta, row_size); }
		T cross_entropy_error_ppl(FastMatrix<T>& teacher, T delta = 0.0000001) { return Functions::cross_entropy_error_ppl(entity, teacher.get_entity(), delta, row_size); }

		T cross_entropy_error_class(FastMatrix<T>& teacher, T delta = 0.0000001) { return Functions::cross_entropy_error_class(entity, teacher.get_entity(), delta, row_size); }
		T cross_entropy_error_class_com(FastMatrix<T>& teacher, T delta = 0.0000001) { return Functions::cross_entropy_error_class_com(entity, teacher.get_entity(), delta, row_size); }
		T cross_entropy_error_class_amp(FastMatrix<T>& teacher, T delta = 0.0000001) { return Functions::cross_entropy_error_class_amp(entity, teacher.get_entity(), delta, row_size); }
		T cross_entropy_error_class_ppl(FastMatrix<T>& teacher, T delta = 0.0000001) { return Functions::cross_entropy_error_class_ppl(entity, teacher.get_entity(), delta, row_size); }

		FastMatrix<T> abs() { return FastMatrix<T>(Functions::abs(entity), row_size, column_size); }
		FastMatrix<T> abs_com() { return FastMatrix<T>(Functions::abs_com(entity), row_size, column_size); }
		FastMatrix<T> abs_amp() { return FastMatrix<T>(Functions::abs_amp(entity), row_size, column_size); }
		FastMatrix<T> abs_ppl() { return FastMatrix<T>(Functions::abs_ppl(entity), row_size, column_size); }

		FastMatrix<T> log() { return FastMatrix<T>(Functions::log(entity), row_size, column_size); }
		FastMatrix<T> log_com() { return FastMatrix<T>(Functions::log_com(entity), row_size, column_size); }
		FastMatrix<T> log_amp() { return FastMatrix<T>(Functions::log_amp(entity), row_size, column_size); }
		FastMatrix<T> log_ppl() { return FastMatrix<T>(Functions::log_ppl(entity), row_size, column_size); }

		FastMatrix<T> log10() { return FastMatrix<T>(Functions::log10(entity), row_size, column_size); }
		FastMatrix<T> log10_com() { return FastMatrix<T>(Functions::log10_com(entity), row_size, column_size); }
		FastMatrix<T> log10_amp() { return FastMatrix<T>(Functions::log10_amp(entity), row_size, column_size); }
		FastMatrix<T> log10_ppl() { return FastMatrix<T>(Functions::log10_ppl(entity), row_size, column_size); }

		FastMatrix<T> sqrt() { return FastMatrix<T>(Functions::sqrt(entity), row_size, column_size); }
		FastMatrix<T> sqrt_com() { return FastMatrix<T>(Functions::sqrt_com(entity), row_size, column_size); }
		FastMatrix<T> sqrt_amp() { return FastMatrix<T>(Functions::sqrt_amp(entity), row_size, column_size); }
		FastMatrix<T> sqrt_ppl() { return FastMatrix<T>(Functions::sqrt_ppl(entity), row_size, column_size); }

		FastMatrix<T> pow(T exp) { return FastMatrix<T>(Functions::pow(entity, exp), row_size, column_size); }
		FastMatrix<T> pow_com(T exp) { return FastMatrix<T>(Functions::pow_com(entity, exp), row_size, column_size); }
		FastMatrix<T> pow_amp(T exp) { return FastMatrix<T>(Functions::pow_amp(entity, exp), row_size, column_size); }
		FastMatrix<T> pow_ppl(T exp) { return FastMatrix<T>(Functions::pow_ppl(entity, exp), row_size, column_size); }

		FastMatrix<T> exp() { return FastMatrix<T>(Functions::exp(entity), row_size, column_size); }
		FastMatrix<T> exp_com() { return FastMatrix<T>(Functions::exp_com(entity), row_size, column_size); }
		FastMatrix<T> exp_amp() { return FastMatrix<T>(Functions::exp_amp(entity), row_size, column_size); }
		FastMatrix<T> exp_ppl() { return FastMatrix<T>(Functions::exp_ppl(entity), row_size, column_size); }

		FastMatrix<T> sigmoid() { return FastMatrix<T>(Functions::sigmoid(entity), row_size, column_size); }
		FastMatrix<T> sigmoid_com() { return FastMatrix<T>(Functions::sigmoid_com(entity), row_size, column_size); }
		FastMatrix<T> sigmoid_amp() { return FastMatrix<T>(Functions::sigmoid_amp(entity), row_size, column_size); }
		FastMatrix<T> sigmoid_ppl() { return FastMatrix<T>(Functions::sigmoid_ppl(entity), row_size, column_size); }

		FastMatrix<T> relu() { return FastMatrix<T>(Functions::relu(entity), row_size, column_size); }
		FastMatrix<T> relu_com() { return FastMatrix<T>(Functions::relu_com(entity), row_size, column_size); }
		FastMatrix<T> relu_amp() { return FastMatrix<T>(Functions::relu_amp(entity), row_size, column_size); }
		FastMatrix<T> relu_ppl() { return FastMatrix<T>(Functions::relu_ppl(entity), row_size, column_size); }

		FastMatrix<T> normalization() { return FastMatrix<T>(Functions::normalization(entity), row_size, column_size); }
		FastMatrix<T> normalization_com() { return FastMatrix<T>(Functions::normalization_com(entity), row_size, column_size); }
		FastMatrix<T> normalization_amp() { return FastMatrix<T>(Functions::normalization_amp(entity), row_size, column_size); }
		FastMatrix<T> normalization_ppl() { return FastMatrix<T>(Functions::normalization_ppl(entity), row_size, column_size); }

		template<class F>
		FastMatrix<T> num_diff(F func, T delta = 0.0001) { return FastMatrix<T>(Functions::num_diff(entity, func, delta), row_size, column_size); }
		template<class F>
		FastMatrix<T> num_diff_com(F func, T delta = 0.0001) { return FastMatrix<T>(Functions::num_diff_com(entity, func, delta), row_size, column_size); }
		template<class F>
		FastMatrix<T> num_diff_amp(F func, T delta = 0.0001) { return FastMatrix<T>(Functions::num_diff_amp(entity, func, delta), row_size, column_size); }
		template<class F>
		FastMatrix<T> num_diff_ppl(F func, T delta = 0.0001) { return FastMatrix<T>(Functions::num_diff_ppl(entity, func, delta), row_size, column_size); }

		FastMatrix<T> softmax() { return FastMatrix<T>(Functions::softmax(entity, row_size, column_size), row_size, column_size); }
		FastMatrix<T> softmax_com() { return FastMatrix<T>(Functions::softmax_com(entity, row_size, column_size), row_size, column_size); }
		FastMatrix<T> softmax_amp() { return FastMatrix<T>(Functions::softmax_amp(entity, row_size, column_size), row_size, column_size); }
		FastMatrix<T> softmax_ppl() { return FastMatrix<T>(Functions::softmax_ppl(entity, row_size, column_size), row_size, column_size); }

		FastMatrix<T> take_rows(int size) { return FastMatrix<T>(Functions::take_rows(entity, row_size, column_size, size), size, column_size); }
		FastMatrix<T> take_rows_com(int size) { return FastMatrix<T>(Functions::take_rows_com(entity, row_size, column_size, size), size, column_size); }
		FastMatrix<T> take_rows_amp(int size) { return FastMatrix<T>(Functions::take_rows_amp(entity, row_size, column_size, size), size, column_size); }
		FastMatrix<T> take_rows_ppl(int size) { return FastMatrix<T>(Functions::take_rows_ppl(entity, row_size, column_size, size), size, column_size); }

		FastMatrix<T> take_columns(int size) { return FastMatrix<T>(Functions::take_columns(entity, row_size, column_size, size), row_size, size); }
		FastMatrix<T> take_columns_com(int size) { return FastMatrix<T>(Functions::take_columns_com(entity, row_size, column_size, size), row_size, size); }
		FastMatrix<T> take_columns_amp(int size) { return FastMatrix<T>(Functions::take_columns_amp(entity, row_size, column_size, size), row_size, size); }
		FastMatrix<T> take_columns_ppl(int size) { return FastMatrix<T>(Functions::take_columns_ppl(entity, row_size, column_size, size), row_size, size); }

		FastMatrix<T> skip_rows(int size) { return FastMatrix<T>(Functions::skip_rows(entity, row_size, column_size, size), row_size - size, column_size); }
		FastMatrix<T> skip_rows_com(int size) { return FastMatrix<T>(Functions::skip_rows_com(entity, row_size, column_size, size), row_size - size, column_size); }
		FastMatrix<T> skip_rows_amp(int size) { return FastMatrix<T>(Functions::skip_rows_amp(entity, row_size, column_size, size), row_size - size, column_size); }
		FastMatrix<T> skip_rows_ppl(int size) { return FastMatrix<T>(Functions::skip_rows_ppl(entity, row_size, column_size, size), row_size - size, column_size); }

		FastMatrix<T> skip_columns(int size) { return FastMatrix<T>(Functions::skip_columns(entity, row_size, column_size, size), row_size, column_size - size); }
		FastMatrix<T> skip_columns_com(int size) { return FastMatrix<T>(Functions::skip_columns_com(entity, row_size, column_size, size), row_size, column_size - size); }
		FastMatrix<T> skip_columns_amp(int size) { return FastMatrix<T>(Functions::skip_columns_amp(entity, row_size, column_size, size), row_size, column_size - size); }
		FastMatrix<T> skip_columns_ppl(int size) { return FastMatrix<T>(Functions::skip_columns_ppl(entity, row_size, column_size, size), row_size, column_size - size); }

		FastMatrix<T> batch(FastVector<int>& mask) { return FastMatrix<T>(Functions::batch(entity, row_size, column_size, mask.get_entity()), mask.get_size(), column_size); }
		FastMatrix<T> batch_com(FastVector<int>& mask) { return FastMatrix<T>(Functions::batch_com(entity, row_size, column_size, mask.get_entity()), mask.get_size(), column_size); }
		FastMatrix<T> batch_amp(FastVector<int>& mask) { return FastMatrix<T>(Functions::batch_amp(entity, row_size, column_size, mask.get_entity()), mask.get_size(), column_size); }
		FastMatrix<T> batch_ppl(FastVector<int>& mask) { return FastMatrix<T>(Functions::batch_ppl(entity, row_size, column_size, mask.get_entity()), mask.get_size(), column_size); }

		FastMatrix<T> random_batch(int size) { return FastMatrix<T>(Functions::random_batch(entity, row_size, column_size, size), size, column_size); }
		FastMatrix<T> random_batch_com(int size) { return FastMatrix<T>(Functions::random_batch_com(entity, row_size, column_size, size), size, column_size); }
		FastMatrix<T> random_batch_amp(int size) { return FastMatrix<T>(Functions::random_batch_amp(entity, row_size, column_size, size), size, column_size); }
		FastMatrix<T> random_batch_ppl(int size) { return FastMatrix<T>(Functions::random_batch_ppl(entity, row_size, column_size, size), size, column_size); }

		FastVector<T> row(int point) { return FastVector<T>(Functions::row(entity, row_size, column_size, point)); }
		FastVector<T> row_com(int point) { return FastVector<T>(Functions::row_com(entity, row_size, column_size, point)); }
		FastVector<T> row_amp(int point) { return FastVector<T>(Functions::row_amp(entity, row_size, column_size, point)); }
		FastVector<T> row_ppl(int point) { return FastVector<T>(Functions::row_ppl(entity, row_size, column_size, point)); }

		FastVector<T> column(int point) { return FastVector<T>(Functions::column(entity, row_size, column_size, point)); }
		FastVector<T> column_com(int point) { return FastVector<T>(Functions::column_com(entity, row_size, column_size, point)); }
		FastVector<T> column_amp(int point) { return FastVector<T>(Functions::column_amp(entity, row_size, column_size, point)); }
		FastVector<T> column_ppl(int point) { return FastVector<T>(Functions::column_ppl(entity, row_size, column_size, point)); }

		FastMatrix<T> reverse() { return FastMatrix<T>(Functions::reverse(entity, row_size, column_size), column_size, row_size); }
		FastMatrix<T> reverse_com() { return FastMatrix<T>(Functions::reverse_com(entity, row_size, column_size), column_size, row_size); }
		FastMatrix<T> reverse_amp() { return FastMatrix<T>(Functions::reverse_amp(entity, row_size, column_size), column_size, row_size); }
		FastMatrix<T> reverse_ppl() { return FastMatrix<T>(Functions::reverse_ppl(entity, row_size, column_size), column_size, row_size); }



		/*ランダムなFastMatrixを生成*/
		static FastMatrix<T> real_random_com(int row, int col, T min = -1, T max = 1) { return FastMatrix<T>(Functions::real_random_com<T>(row * col, min, max), row, col); }
		/*ランダムなFastMatrixを生成 PPL実装*/
		static FastMatrix<T> real_random_ppl(int row, int col, T min = -1, T max = 1) { return FastMatrix<T>(Functions::real_random_ppl<T>(row * col, min, max), row, col); }
		/*ランダムなFastMatrixを生成*/
		static FastMatrix<T> int_random_com(int row, int col, int min = -1, int max = 1) { return FastMatrix<T>(Functions::int_random_com<T>(row * col, min, max), row, col); }
		/*ランダムなFastMatrixを生成 PPL実装*/
		static FastMatrix<T> int_random_ppl(int row, int col, int min = -1, int max = 1) { return FastMatrix<T>(Functions::int_random_ppl<T>(row * col, min, max), row, col); }
		/*平均:mean, 標準偏差:sd のランダムなFastMatrixを生成*/
		static FastMatrix<T> normal_random_com(int row, int col, T mean = 0, T sd = 1) { return FastMatrix<T>(Functions::normal_random_com<T>(row * col, mean, sd), row, col); }
		/*平均:mean, 標準偏差:sd のランダムなFastMatrixを生成 PPL実装*/
		static FastMatrix<T> normal_random_ppl(int row, int col, T mean = 0, T sd = 1) { return FastMatrix<T>(Functions::normal_random_ppl<T>(row * col, mean, sd), row, col); }

		/*[row,column] ((values1),(values2),...)*/
		std::string to_string() {
			std::ostringstream stream;
			stream << "[" << row_size << ", " << column_size << "](";
			for (int i = 0; i < row_size; i++) {
				if (i) stream << ",(";
				else stream << "(";
				for (int j = 0; j < column_size; j++) {
					if (j) stream << ", " << entity[i * column_size + j];
					else stream << entity[i * column_size + j];
				}
				stream << ")";
			}
			stream << ")";
			return stream.str();
		}

	private:
		std::vector<T> entity;
		int row_size;
		int column_size;
	};

	template<typename T>
	inline FastMatrix<T> operator+(FastMatrix<T>& target1, FastMatrix<T>& target2) { return FastMatrix<T>(Functions::add(target1.get_entity(), target2.get_entity()), target1.get_row_size(), target1.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator-(FastMatrix<T>& target1, FastMatrix<T>& target2) { return FastMatrix<T>(Functions::sub(target1.get_entity(), target2.get_entity()), target1.get_row_size(), target1.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator*(FastMatrix<T>& target1, FastMatrix<T>& target2) { return FastMatrix<T>(Functions::mul(target1.get_entity(), target2.get_entity()), target1.get_row_size(), target1.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator/(FastMatrix<T>& target1, FastMatrix<T>& target2) { return FastMatrix<T>(Functions::div(target1.get_entity(), target2.get_entity()), target1.get_row_size(), target1.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator==(FastMatrix<T>& target1, FastMatrix<T>& target2) { return FastMatrix<T>(Functions::equal(target1.get_entity(), target2.get_entity()), target1.get_row_size(), target1.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator!=(FastMatrix<T>& target1, FastMatrix<T>& target2) { return FastMatrix<T>(Functions::not_equal(target1.get_entity(), target2.get_entity()), target1.get_row_size(), target1.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator>(FastMatrix<T>& target1, FastMatrix<T>& target2) { return FastMatrix<T>(Functions::more(target1.get_entity(), target2.get_entity()), target1.get_row_size(), target1.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator<(FastMatrix<T>& target1, FastMatrix<T>& target2) { return FastMatrix<T>(Functions::less(target1.get_entity(), target2.get_entity()), target1.get_row_size(), target1.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator>=(FastMatrix<T>& target1, FastMatrix<T>& target2) { return FastMatrix<T>(Functions::not_less(target1.get_entity(), target2.get_entity()), target1.get_row_size(), target1.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator<=(FastMatrix<T>& target1, FastMatrix<T>& target2) { return FastMatrix<T>(Functions::not_more(target1.get_entity(), target2.get_entity()), target1.get_row_size(), target1.get_column_size()); }

	template<typename T>
	inline FastMatrix<T> operator+(FastMatrix<T>& target, T value) { return FastMatrix<T>(Functions::add(target.get_entity(), value), target.get_row_size(), target.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator-(FastMatrix<T>& target, T value) { return FastMatrix<T>(Functions::sub(target.get_entity(), value), target.get_row_size(), target.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator*(FastMatrix<T>& target, T value) { return FastMatrix<T>(Functions::mul(target.get_entity(), value), target.get_row_size(), target.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator/(FastMatrix<T>& target, T value) { return FastMatrix<T>(Functions::div(target.get_entity(), value), target.get_row_size(), target.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator==(FastMatrix<T>& target, T value) { return FastMatrix<T>(Functions::equal(target.get_entity(), value), target.get_row_size(), target.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator!=(FastMatrix<T>& target, T value) { return FastMatrix<T>(Functions::not_equal(target.get_entity(), value), target.get_row_size(), target.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator>(FastMatrix<T>& target, T value) { return FastMatrix<T>(Functions::more(target.get_entity(), value), target.get_row_size(), target.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator<(FastMatrix<T>& target, T value) { return FastMatrix<T>(Functions::less(target.get_entity(), value), target.get_row_size(), target.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator>=(FastMatrix<T>& target, T value) { return FastMatrix<T>(Functions::not_less(target.get_entity(), value), target.get_row_size(), target.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator<=(FastMatrix<T>& target, T value) { return FastMatrix<T>(Functions::not_more(target.get_entity(), value), target.get_row_size(), target.get_column_size()); }

	template<typename T>
	inline FastMatrix<T> operator+(T value, FastMatrix<T>& target) { return FastMatrix<T>(Functions::add(value, target.get_entity()), target.get_row_size(), target.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator-(T value, FastMatrix<T>& target) { return FastMatrix<T>(Functions::sub(value, target.get_entity()), target.get_row_size(), target.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator*(T value, FastMatrix<T>& target) { return FastMatrix<T>(Functions::mul(value, target.get_entity()), target.get_row_size(), target.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator/(T value, FastMatrix<T>& target) { return FastMatrix<T>(Functions::div(value, target.get_entity()), target.get_row_size(), target.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator==(T value, FastMatrix<T>& target) { return FastMatrix<T>(Functions::equal(value, target.get_entity()), target.get_row_size(), target.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator!=(T value, FastMatrix<T>& target) { return FastMatrix<T>(Functions::not_equal(value, target.get_entity()), target.get_row_size(), target.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator>(T value, FastMatrix<T>& target) { return FastMatrix<T>(Functions::more(value, target.get_entity()), target.get_row_size(), target.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator<(T value, FastMatrix<T>& target) { return FastMatrix<T>(Functions::less(value, target.get_entity()), target.get_row_size(), target.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator>=(T value, FastMatrix<T>& target) { return FastMatrix<T>(Functions::not_less(value, target.get_entity()), target.get_row_size(), target.get_column_size()); }
	template<typename T>
	inline FastMatrix<T> operator<=(T value, FastMatrix<T>& target) { return FastMatrix<T>(Functions::not_more(value, target.get_entity()), target.get_row_size(), target.get_column_size()); }

}
