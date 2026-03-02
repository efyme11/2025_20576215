#pragma once

#ifdef maths_STATIC
#define maths_API
#else
#ifdef maths_EXPORTS
#define maths_API __declspec(dllexport)
#else
#define maths_API __declspec(dllimport)
#endif
#endif

maths_API int add(int a, int b);
