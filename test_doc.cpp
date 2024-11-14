#include <math.h>

//@I ghujgujgg
//@L3 Manifesto
//@I uyujgjgtuitggt
//@I uytguyjgfyujhf
//@X

//@T add
//@U template &lt;typename T, typename T2&gt; add(
//@U T &a, 
//@U T2 &b)
//@X
//@D Returns a + b.
//@A a : is an int, float or double 
//@A b : is an int, float or double
//@X
//@E int a = 2;
//@E int b = 8;
//@E fun(a, b) 
//@E 10
//@M out.jpg
//@E between 2 medias
//@V out.mp4
//@E after video
//@O out.mp3
//@E here after audio
//@X

template <typename T, typename T2> auto add(T &a, T2 &b) {
  return a + b;
};

//@L1 zone1

//@T subs
//@U template &lt;typename T, typename T2&gt; auto subs(T &a, T2 &b)
//@X
//@D Returns a - b.
//@M out.jpg
//@D after cat
//@A a : is an int, float or double 
//@A b : is an int, float or double
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
//@U template &lt;typename T, typename T2&gt; auto mult(T &a, T2 &b)
//@X
//@D Returns a - b.
//@A a : is an int, float or double 
//@A b : is an int, float or double
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
//@U template &lt;typename T, typename T2&gt; double div(T &a, T2 &b)
//@X
//@D Returns a / b.
//@A a : is an int, float or double
//@A b : is an int, float or double
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
//@U template &lt;typename T, typename T2&gt; auto powr(T &a, T2 &b)
//@X
//@D Returns a**b
//@A a : is an int, float or double
//@A b : is an int, float or double
//@X
//@E int a = 2;
//@E int b = 3;
//@E powr(a, b) 
//@E 8
//@X

template <typename T, typename T2> auto powr(T &a, T2 &b) {
  return std::pow(a, b);
};

//@L3 more precision2

//@T switchr
//@U template &lt;typename T, typename T2&gt; void switchr(T &a, T2 &b)
//@X
//@D Switched 2 variables of any type
//@A a : is any type
//@A b : is any type
//@X
//@E int a = 4;
//@E int b = 1;
//@E switchr(a, b) 
//@E std::cout &lt;&lt; "a: " &lt;&lt; a &lt;&lt; " b: " &lt;&lt; b &lt;&lt; "\n";
//@E a: 1 b: 4
//@X

template <typename T, typename T2> void switchr(T &a, T2 &b) {
  T v = a;
  a = b;
  b = v;
};

//@J0

//@T mean
//@U template &lt;typename T, typename T2&gt; auto mean(T &a, T2 &b)
//@X
//@D Calculates the mean of two variables of any type (float, int, double)
//@A a : is an float, int or double
//@A b : is an float, int or double
//@X
//@E int a = 5;
//@E b = 1;
//@E mean(a, b) 
//@E 3
//@X

template <typename T, typename T2> auto mean(T &a, T2 &b) {
  return (a + b) / 2;
};




