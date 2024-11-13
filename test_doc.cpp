#include <math.h>

//@T add
//@U template <typename T, typename T2> auto add(T &a, T2 &b)
//@D Returns a + b.
//@A x : is an int, float or double 
//@A y : is an int, float or double
//@X
//@E int a = 2;
//@E int b = 8;
//@E fun(a, b) 
//@E 10
//@X

template <typename T, typename T2> auto add(T &a, T2 &b) {
  return a + b;
};

//@L0 zone1

//@T subs
//@U template <typename T, typename T2> auto subs(T &a, T2 &b)
//@D Returns a - b.
//@A x : is an int, float or double 
//@A y : is an int, float or double
//@X
//@E int a = 7;
//@E int b = 4;
//@E subs(a, b) 
//@E 3
//@X

template <typename T, typename T2> auto subs(T &a, T2 &b) {
  return a - b;
};

//@T mult
//@U template <typename T, typename T2> auto mult(T &a, T2 &b)
//@D Returns a - b.
//@A x : is an int, float or double 
//@A y : is an int, float or double
//@X
//@E int a = 7;
//@E int b = 4;
//@E subs(a, b) 
//@E 28
//@X

template <typename T, typename T2> double mult(T &a, T2 &b) {
  return a * b;
};

//@J0

//@T div
//@U template <typename T, typename T2> double div(T &a, T2 &b)
//@D Returns a / b.
//@A x : is an int, float or double
//@A y : is an int, float or double
//@X
//@E int a = 3;
//@E int b = 2;
//@E div(a, b) 
//@E 1.5
//@X

template <typename T, typename T2> double div(T &a, T2 &b) {
  return a / b;
};

//@L1 zone2
//@L2 more precision

//@T powr
//@U template <typename T, typename T2> auto powr(T &a, T2 &b)
//@D Returns a**b
//@A x : is an int, float or double
//@A y : is an int, float or double
//@X
//@E int a = 2;
//@E int b = 3;
//@E powr(a, b) 
//@E 8
//@X

template <typename T, typename T2> auto powr(T &a, T2 &b) {
  return std::pow(a, b);
};

//@L2 more precision2

//@T switchr
//@U template <typename T, typename T2> void switchr(T &a, T2 &b)
//@D Switched 2 variables of any type
//@A x : is any type
//@A y : is any type
//@X
//@E int a = 4;
//@E int b = 1;
//@E switchr(a, b) 
//@E std::cout << "a: " << a << " b: " << b << "\n";
//@E a: 1 b: 4
//@X

template <typename T, typename T2> void switchr(T &a, T2 &b) {
  T v = a;
  a = b;
  b = v;
};

//@J0

//@T mean
//@U template <typename T, typename T2> auto mean(T &a, T2 &b)
//@D Calculates the mean of two variables of any type (float, int, double)
//@A x : is an float, int or double
//@A y : is an float, int or double
//@X
//@E int a = 5;
//@E b = 1;
//@E mean(a, b) 
//@E 3
//@X

template <typename T, typename T2> auto mean(T &a, T2 &b) {
  return (a + b) / 2;
};




