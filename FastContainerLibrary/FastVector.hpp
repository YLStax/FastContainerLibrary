#pragma once

#include "FastContainerLibrary.hpp"

namespace FastContainer {

	template<typename T>
	class FastVector {
	public:
		FastVector() {}
		FastVector(int size) { entity.resize(size); this->size = size; }
		FastVector(std::vector<T>& vec) { this->size = vec.size(); entity = vec; }
		~FastVector() {}

		std::vector<T>& get_entity() { return entity; }
		int get_size() { return size; }

		T& operator[](int index) { return entity[index]; }

		auto begin() { return entity.begin(); }
		auto begin() const { return entity.begin(); }
		auto end() { return entity.end(); }
		auto end() const { return entity.end(); }

		FastVector<T> identity() { return this; }

		T dot(FastVector<T>& teacher) { return Functions::dot(entity, teacher.get_entity()); }

		T get_min() { return Functions::get_min(entity); }
		T get_max() { return Functions::get_max(entity); }
		T argmax() { return Functions::argmax(entity); }
		T sum() { return Functions::sum(entity); }
		T mean() { return Functions::mean(entity); }

		T cross_entropy_error(FastVector<T>& teacher, T delta = 0.0000001) { return Functions::cross_entropy_error(entity, teacher.get_entity(), delta); }
		T cross_entropy_error_com(FastVector<T>& teacher, T delta = 0.0000001) { return Functions::cross_entropy_error_com(entity, teacher.get_entity(), delta); }
		T cross_entropy_error_amp(FastVector<T>& teacher, T delta = 0.0000001) { return Functions::cross_entropy_error_amp(entity, teacher.get_entity(), delta); }
		T cross_entropy_error_ppl(FastVector<T>& teacher, T delta = 0.0000001) { return Functions::cross_entropy_error_ppl(entity, teacher.get_entity(), delta); }

		T cross_entropy_error_class(FastVector<T>& teacher, T delta = 0.0000001) { return Functions::cross_entropy_error_class(entity, teacher.get_entity(), delta); }
		T cross_entropy_error_class_com(FastVector<T>& teacher, T delta = 0.0000001) { return Functions::cross_entropy_error_class_com(entity, teacher.get_entity(), delta); }
		T cross_entropy_error_class_amp(FastVector<T>& teacher, T delta = 0.0000001) { return Functions::cross_entropy_error_class_amp(entity, teacher.get_entity(), delta); }
		T cross_entropy_error_class_ppl(FastVector<T>& teacher, T delta = 0.0000001) { return Functions::cross_entropy_error_class_ppl(entity, teacher.get_entity(), delta); }

		FastVector<T> abs() { return FastVector<T>(Functions::abs(entity)); }
		FastVector<T> abs_com() { return FastVector<T>(Functions::abs_com(entity)); }
		FastVector<T> abs_amp() { return FastVector<T>(Functions::abs_amp(entity)); }
		FastVector<T> abs_ppl() { return FastVector<T>(Functions::abs_ppl(entity)); }

		FastVector<T> log() { return FastVector<T>(Functions::log(entity)); }
		FastVector<T> log_com() { return FastVector<T>(Functions::log_com(entity)); }
		FastVector<T> log_amp() { return FastVector<T>(Functions::log_amp(entity)); }
		FastVector<T> log_ppl() { return FastVector<T>(Functions::log_ppl(entity)); }

		FastVector<T> log10() { return FastVector<T>(Functions::log10(entity)); }
		FastVector<T> log10_com() { return FastVector<T>(Functions::log10_com(entity)); }
		FastVector<T> log10_amp() { return FastVector<T>(Functions::log10_amp(entity)); }
		FastVector<T> log10_ppl() { return FastVector<T>(Functions::log10_ppl(entity)); }

		FastVector<T> sqrt() { return FastVector<T>(Functions::sqrt(entity)); }
		FastVector<T> sqrt_com() { return FastVector<T>(Functions::sqrt_com(entity)); }
		FastVector<T> sqrt_amp() { return FastVector<T>(Functions::sqrt_amp(entity)); }
		FastVector<T> sqrt_ppl() { return FastVector<T>(Functions::sqrt_ppl(entity)); }

		FastVector<T> pow(T exp) { return FastVector<T>(Functions::pow(entity, exp)); }
		FastVector<T> pow_com(T exp) { return FastVector<T>(Functions::pow_com(entity, exp)); }
		FastVector<T> pow_amp(T exp) { return FastVector<T>(Functions::pow_amp(entity, exp)); }
		FastVector<T> pow_ppl(T exp) { return FastVector<T>(Functions::pow_ppl(entity, exp)); }

		FastVector<T> exp() { return FastVector<T>(Functions::exp(entity)); }
		FastVector<T> exp_com() { return FastVector<T>(Functions::exp_com(entity)); }
		FastVector<T> exp_amp() { return FastVector<T>(Functions::exp_amp(entity)); }
		FastVector<T> exp_ppl() { return FastVector<T>(Functions::exp_ppl(entity)); }

		FastVector<T> sigmoid() { return FastVector<T>(Functions::sigmoid(entity)); }
		FastVector<T> sigmoid_com() { return FastVector<T>(Functions::sigmoid_com(entity)); }
		FastVector<T> sigmoid_amp() { return FastVector<T>(Functions::sigmoid_amp(entity)); }
		FastVector<T> sigmoid_ppl() { return FastVector<T>(Functions::sigmoid_ppl(entity)); }

		FastVector<T> relu() { return FastVector<T>(Functions::relu(entity)); }
		FastVector<T> relu_com() { return FastVector<T>(Functions::relu_com(entity)); }
		FastVector<T> relu_amp() { return FastVector<T>(Functions::relu_amp(entity)); }
		FastVector<T> relu_ppl() { return FastVector<T>(Functions::relu_ppl(entity)); }

		FastVector<T> normalization() { return FastVector<T>(Functions::normalization(entity)); }
		FastVector<T> normalization_com() { return FastVector<T>(Functions::normalization_com(entity)); }
		FastVector<T> normalization_amp() { return FastVector<T>(Functions::normalization_amp(entity)); }
		FastVector<T> normalization_ppl() { return FastVector<T>(Functions::normalization_ppl(entity)); }

		template<class F>
		FastVector<T> num_diff(F func, T delta = 0.0001) { return FastVector<T>(Functions::num_diff(entity, func, delta)); }
		template<class F>
		FastVector<T> num_diff_com(F func, T delta = 0.0001) { return FastVector<T>(Functions::num_diff_com(entity, func, delta)); }
		template<class F>
		FastVector<T> num_diff_amp(F func, T delta = 0.0001) { return FastVector<T>(Functions::num_diff_amp(entity, func, delta)); }
		template<class F>
		FastVector<T> num_diff_ppl(F func, T delta = 0.0001) { return FastVector<T>(Functions::num_diff_ppl(entity, func, delta)); }

		FastVector<T> softmax() { return FastVector<T>(Functions::softmax(entity)); }
		FastVector<T> softmax_com() { return FastVector<T>(Functions::softmax_com(entity)); }
		FastVector<T> softmax_amp() { return FastVector<T>(Functions::softmax_amp(entity)); }
		FastVector<T> softmax_ppl() { return FastVector<T>(Functions::softmax_ppl(entity)); }

		FastVector<T> take(int size) { return FastVector<T>(Functions::take(entity, size)); }
		FastVector<T> take_com(int size) { return FastVector<T>(Functions::take_com(entity, size)); }
		FastVector<T> take_amp(int size) { return FastVector<T>(Functions::take_amp(entity, size)); }
		FastVector<T> take_ppl(int size) { return FastVector<T>(Functions::take_ppl(entity, size)); }

		FastVector<T> skip(int size) { return FastVector<T>(Functions::skip(entity, size)); }
		FastVector<T> skip_com(int size) { return FastVector<T>(Functions::skip_com(entity, size)); }
		FastVector<T> skip_amp(int size) { return FastVector<T>(Functions::skip_amp(entity, size)); }
		FastVector<T> skip_ppl(int size) { return FastVector<T>(Functions::skip_ppl(entity, size)); }

		FastVector<T> batch(FastVector<int>& mask) { return FastVector<T>(Functions::batch(entity, mask.get_entity())); }
		FastVector<T> batch_com(FastVector<int>& mask) { return FastVector<T>(Functions::batch_com(entity, mask.get_entity())); }
		FastVector<T> batch_amp(FastVector<int>& mask) { return FastVector<T>(Functions::batch_amp(entity, mask.get_entity())); }
		FastVector<T> batch_ppl(FastVector<int>& mask) { return FastVector<T>(Functions::batch_ppl(entity, mask.get_entity())); }

		FastVector<T> random_batch(int size) { return FastVector<T>(Functions::random_batch(entity, size)); }
		FastVector<T> random_batch_com(int size) { return FastVector<T>(Functions::random_batch_com(entity, size)); }
		FastVector<T> random_batch_amp(int size) { return FastVector<T>(Functions::random_batch_amp(entity, size)); }
		FastVector<T> random_batch_ppl(int size) { return FastVector<T>(Functions::random_batch_ppl(entity, size)); }

		/*[size] (value1,value2,...)*/
		std::string to_string() {
			std::ostringstream stream;
			stream << "[" << size << "](";
			for (int i = 0; i < size; i++) {
				if (i) stream << ", " << entity[i];
				else stream << entity[i];
			}
			stream << ")";
			return stream.str();
		}

		/*ランダムなFastVectorを生成*/
		static FastVector<T> real_random_com(int size, T min = -1, T max = 1) { return FastVector<T>(Functions::real_random_com<T>(size, min, max)); }
		/*ランダムなFastVectorを生成 PPL実装*/
		static FastVector<T> real_random_ppl(int size, T min = -1, T max = 1) { return FastVector<T>(Functions::real_random_ppl<T>(size, min, max)); }
		/*ランダムなFastVectorを生成*/
		static FastVector<T> int_random_com(int size, int min = -1, int max = 1) { return FastVector<T>(Functions::int_random_com<T>(size, min, max)); }
		/*ランダムなFastVectorを生成 PPL実装*/
		static FastVector<T> int_random_ppl(int size, int min = -1, int max = 1) { return FastVector<T>(Functions::int_random_ppl<T>(size, min, max)); }
		/*平均:mean, 標準偏差:sd のランダムなFastVectorを生成*/
		static FastVector<T> normal_random_com(int size, T mean = 0, T sd = 1) { return FastVector<T>(Functions::normal_random_com<T>(size, mean, sd)); }
		/*平均:mean, 標準偏差:sd のランダムなFastVectorを生成 PPL実装*/
		static FastVector<T> normal_random_ppl(int size, T mean = 0, T sd = 1) { return FastVector<T>(Functions::normal_random_ppl<T>(size, mean, sd)); }
		/*重複のないランダムなFastVector<int>を生成*/
		static FastVector<int> int_hash_random(int size, int min, int max) { return FastVector<int>(Functions::int_hash_random(size, min, max)); }

	private:
		std::vector<T> entity;
		int size;
	};

	template<typename T>
	FastVector<T> operator+(FastVector<T>& target1, FastVector<T>& target2) { return FastVector<T>(Functions::add(target1.get_entity(), target2.get_entity())); }
	template<typename T>
	FastVector<T> operator-(FastVector<T>& target1, FastVector<T>& target2) { return FastVector<T>(Functions::sub(target1.get_entity(), target2.get_entity())); }
	template<typename T>
	FastVector<T> operator*(FastVector<T>& target1, FastVector<T>& target2) { return FastVector<T>(Functions::mul(target1.get_entity(), target2.get_entity())); }
	template<typename T>
	FastVector<T> operator/(FastVector<T>& target1, FastVector<T>& target2) { return FastVector<T>(Functions::div(target1.get_entity(), target2.get_entity())); }
	template<typename T>
	FastVector<T> operator==(FastVector<T>& target1, FastVector<T>& target2) { return FastVector<T>(Functions::equal(target1.get_entity(), target2.get_entity())); }
	template<typename T>
	FastVector<T> operator!=(FastVector<T>& target1, FastVector<T>& target2) { return FastVector<T>(Functions::not_equal(target1.get_entity(), target2.get_entity())); }
	template<typename T>
	FastVector<T> operator>(FastVector<T>& target1, FastVector<T>& target2) { return FastVector<T>(Functions::more(target1.get_entity(), target2.get_entity())); }
	template<typename T>
	FastVector<T> operator<(FastVector<T>& target1, FastVector<T>& target2) { return FastVector<T>(Functions::less(target1.get_entity(), target2.get_entity())); }
	template<typename T>
	FastVector<T> operator>=(FastVector<T>& target1, FastVector<T>& target2) { return FastVector<T>(Functions::not_less(target1.get_entity(), target2.get_entity())); }
	template<typename T>
	FastVector<T> operator<=(FastVector<T>& target1, FastVector<T>& target2) { return FastVector<T>(Functions::not_more(target1.get_entity(), target2.get_entity())); }

	template<typename T>
	FastVector<T> operator+(FastVector<T>& target, T value) { return FastVector<T>(Functions::add(target.get_entity(), value)); }
	template<typename T>
	FastVector<T> operator-(FastVector<T>& target, T value) { return FastVector<T>(Functions::sub(target.get_entity(), value)); }
	template<typename T>
	FastVector<T> operator*(FastVector<T>& target, T value) { return FastVector<T>(Functions::mul(target.get_entity(), value)); }
	template<typename T>
	FastVector<T> operator/(FastVector<T>& target, T value) { return FastVector<T>(Functions::div(target.get_entity(), value)); }
	template<typename T>
	FastVector<T> operator==(FastVector<T>& target, T value) { return FastVector<T>(Functions::equal(target.get_entity(), value)); }
	template<typename T>
	FastVector<T> operator!=(FastVector<T>& target, T value) { return FastVector<T>(Functions::not_equal(target.get_entity(), value)); }
	template<typename T>
	FastVector<T> operator>(FastVector<T>& target, T value) { return FastVector<T>(Functions::more(target.get_entity(), value)); }
	template<typename T>
	FastVector<T> operator<(FastVector<T>& target, T value) { return FastVector<T>(Functions::less(target.get_entity(), value)); }
	template<typename T>
	FastVector<T> operator>=(FastVector<T>& target, T value) { return FastVector<T>(Functions::not_less(target.get_entity(), value)); }
	template<typename T>
	FastVector<T> operator<=(FastVector<T>& target, T value) { return FastVector<T>(Functions::not_more(target.get_entity(), value)); }

	template<typename T>
	FastVector<T> operator+(T value, FastVector<T>& target) { return FastVector<T>(Functions::add(value, target.get_entity())); }
	template<typename T>
	FastVector<T> operator-(T value, FastVector<T>& target) { return FastVector<T>(Functions::sub(value, target.get_entity())); }
	template<typename T>
	FastVector<T> operator*(T value, FastVector<T>& target) { return FastVector<T>(Functions::mul(value, target.get_entity())); }
	template<typename T>
	FastVector<T> operator/(T value, FastVector<T>& target) { return FastVector<T>(Functions::div(value, target.get_entity())); }
	template<typename T>
	FastVector<T> operator==(T value, FastVector<T>& target) { return FastVector<T>(Functions::equal(value, target.get_entity())); }
	template<typename T>
	FastVector<T> operator!=(T value, FastVector<T>& target) { return FastVector<T>(Functions::not_equal(value, target.get_entity())); }
	template<typename T>
	FastVector<T> operator>(T value, FastVector<T>& target) { return FastVector<T>(Functions::more(value, target.get_entity())); }
	template<typename T>
	FastVector<T> operator<(T value, FastVector<T>& target) { return FastVector<T>(Functions::less(value, target.get_entity())); }
	template<typename T>
	FastVector<T> operator>=(T value, FastVector<T>& target) { return FastVector<T>(Functions::not_less(value, target.get_entity())); }
	template<typename T>
	FastVector<T> operator<=(T value, FastVector<T>& target) { return FastVector<T>(Functions::not_more(value, target.get_entity())); }

}
