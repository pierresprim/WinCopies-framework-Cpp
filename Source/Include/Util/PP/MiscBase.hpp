#ifndef WINCOPIES_MISC_BASE_HPP
#define WINCOPIES_MISC_BASE_HPP

#define CONCATENATE(value, ...) value##__VA_ARGS__
#define SINGLE_ARG(...) __VA_ARGS__

#define FIRST_ARG(first, ...) first
#define THIRD_ARG(first, second, third, ...) third

#define _HAS_VA_OPT(...) THIRD_ARG(__VA_OPT__(,), 1, 0, )
#define HAS_VA_OPT _HAS_VA_OPT()

#endif // WINCOPIES_MISC_BASE_HPP