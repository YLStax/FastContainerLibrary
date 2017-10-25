#pragma once

#include "FastContainerLibrary.hpp"

#ifdef FAST_CONTAINER_NO_EXCEPTION

#define	FAST_CONTAINER_EXCEPTION_CHECK(expression, e)

#else

#define	FAST_CONTAINER_EXCEPTION_CHECK(expression, e) \
	if (!(expression)) { \
		std::cerr << "Check failed in file " << __FILE__ << " at line " << __LINE__ << ":" << std::endl; \
		std::cerr << #expression << std::endl; \
		e.raise(); \
	}

#endif

namespace FastContainer {

	/*—áŠOˆ—*/
	struct fast_container_exception
#if ! defined FAST_CONTAINER_NO_EXCEPTION
		: public std::exception {
		explicit fast_container_exception(const char *s = "fast_container_exception") : std::exception(s) {}
		void raise() { throw *this; }
	};
#else
	{
		fast_container_exception() {}
		explicit fast_container_exception(const char *) {}
		void raise() { std::abort(); }
	};
#endif

}
