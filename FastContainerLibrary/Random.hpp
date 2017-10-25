#pragma once

#include "FastContainerLibrary.hpp"

namespace FastContainer {
	namespace Functions {

		/*min～maxの乱数*/
		template<typename T>
		class RealRandom {
		public:
			RealRandom(T min = -1, T max = 1) { set_param(min, max); }
			T generate() {
				return random(mt);
			}
			void set_param(T min, T max) {
				FAST_CONTAINER_EXCEPTION_CHECK(min <= max, fast_container_exception());
				mt = std::mt19937(rnd());
				this->random = std::uniform_real_distribution<>(min, max);
			}
		private:
			std::random_device rnd;
			std::mt19937 mt;
			std::uniform_real_distribution<> random;
		};

		/*min～maxの乱数 int*/
		class IntRandom {
		public:
			IntRandom(int min = -1, int max = 1) { set_param(min, max); }
			int generate() {
				return random(mt);
			}
			void set_param(int min, int max) {
				FAST_CONTAINER_EXCEPTION_CHECK(min <= max, fast_container_exception());
				mt = std::mt19937(rnd());
				this->random = std::uniform_int_distribution<>(min, max);
			}
		private:
			std::random_device rnd;
			std::mt19937 mt;
			std::uniform_int_distribution<> random;
		};

		/*平均:mean, 標準偏差:sd の乱数*/
		template<typename T>
		class NormalRandom {
		public:
			NormalRandom(T mean = 0, T sd = 1) { set_param(mean, sd); }
			T generate() {
				return random(mt);
			}
			void set_param(T mean, T sd) {
				mt = std::mt19937(rnd());
				this->random = std::normal_distribution<>(mean, sd);
			}
		private:
			std::random_device rnd;
			std::mt19937 mt;
			std::normal_distribution<> random;
		};

		/*ランダムなstd::vectorを生成*/
		template<typename T>
		inline std::vector<T> real_random_com(int size, T min = -1, T max = 1) {
			std::vector<T> result(size);
			RealRandom<T> rnd(min, max);
			return apply_com_func<T>([&](T x) { return rnd.generate(); }, result);
		}

		/*ランダムなstd::vectorを生成 PPL実装*/
		template<typename T>
		inline std::vector<T> real_random_ppl(int size, T min = -1, T max = 1) {
			std::vector<T> result(size);
			RealRandom<T> rnd(min, max);
			return apply_ppl_func<T>([&](T x) { return rnd.generate(); }, result);
		}

		/*ランダムなstd::vectorを生成*/
		template<typename T>
		inline std::vector<T> int_random_com(int size, int min = -1, int max = 1) {
			std::vector<T> result(size);
			IntRandom rnd(min, max);
			return apply_com_func<T>([&](int x) { return rnd.generate(); }, result);
		}

		/*ランダムなstd::vectorを生成 PPL実装*/
		template<typename T>
		inline std::vector<T> int_random_ppl(int size, int min = -1, int max = 1) {
			std::vector<T> result(size);
			IntRandom rnd(min, max);
			return apply_ppl_func<T>([&](int x) { return rnd.generate(); }, result);
		}

		/*平均:mean, 標準偏差:sd ランダムなstd::vectorを生成*/
		template<typename T>
		inline std::vector<T> normal_random_com(int size, T mean = 0, T sd = 1) {
			std::vector<T> result(size);
			NormalRandom<T> rnd(mean, sd);
			return apply_com_func<T>([&](T x) { return rnd.generate(); }, result);
		}

		/*平均:mean, 標準偏差:sd ランダムなstd::vectorを生成 PPL実装*/
		template<typename T>
		inline std::vector<T> normal_random_ppl(int size, T mean = 0, T sd = 1) {
			std::vector<T> result(size);
			NormalRandom<T> rnd(mean, sd);
			return apply_ppl_func<T>([&](T x) { return rnd.generate(); }, result);
		}

		/*重複のないランダムなstd::vector<int>を生成*/
		inline std::vector<int> int_hash_random(int size, int min, int max) {
			FAST_CONTAINER_EXCEPTION_CHECK(min <= max, fast_container_exception());
			FAST_CONTAINER_EXCEPTION_CHECK(max - min + 1 >= size, fast_container_exception());
			std::vector<int> result(size);
			std::random_device rnd;
			auto mt = std::mt19937(rnd());
			std::unordered_map<int, int> map;
			int index = 0;
			for (int i = 0; i < size; ++i) {
				int val = std::uniform_int_distribution<>(min, max)(mt);
				std::unordered_map<int, int>::iterator itr = map.find(val);
				int replaced_val;
				std::unordered_map<int, int>::iterator replaced_itr = map.find(max);
				if (replaced_itr != map.end()) {
					replaced_val = replaced_itr->second;
				}
				else replaced_val = max;
				if (itr == map.end()) {
					result[index] = val;
					if (val != max) map.insert(std::make_pair(val, replaced_val));
				}
				else {
					result[index] = itr->second;
					itr->second = replaced_val;
				}
				index++;
				max--;
			}
			return result;
		}

	}
}
