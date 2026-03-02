#ifdef maths_EXPORTS
#define maths_API __declspec(dllexport)
#else
#define maths_API __declspec(dllimport)
#endif

maths_API int add(int a, int b);
