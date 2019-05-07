using value_t = unsigned long long int;

struct zero {
  static constexpr value_t value = 0;

  using type = zero;
};

template <typename T>
struct succ {
    static constexpr value_t value = 1 + T::value;

    using pred = typename T::type;

    using type = succ<typename T::type>;
};

template <typename S, typename T>
struct add: succ<typename add<S, typename T::pred>::type>::type {};

template <typename S>
struct add<S, zero>: S::type {};

template <typename S, typename T>
struct mul: add<typename mul<S, typename T::pred>::type, S>::type {};

template <typename S>
struct mul<S, zero>: zero {};

template <typename S>
struct factorial: mul<S, typename factorial<typename S::pred>::type>::type {};

template <>
struct factorial<zero>: succ<zero>::type {};

// constants
using _0 = zero;
using _1 = succ<_0>::type;
using _2 = succ<_1>::type;
using _3 = succ<_2>::type;
using _4 = succ<_3>::type;
using _5 = succ<_4>::type;
using _6 = succ<_5>::type;
using _7 = succ<_6>::type;
using _8 = succ<_7>::type;
using _9 = succ<_8>::type;

