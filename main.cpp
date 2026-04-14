#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

template < typename C >
concept Iterable = requires ( C c ) {
    begin ( c ) ;
    end ( c ) ;
};

template < typename T >
concept Addable = requires ( T a , T b ) {
    { a + b } -> same_as <T >;
};

template < typename T >
concept Divisible = requires ( T a , size_t n ) {
    { a / n } -> convertible_to <T >;
};

//Concept adicional
template < typename T >
concept Numero = integral<T> or floating_point<T>;


template < Iterable C >
requires Addable < typename C :: value_type >
auto sum ( const C & container )
{
    using T = typename C :: value_type ;

    T result {}; // Para tipos numericos (int , double , float )
                 // se inicializa en 0.
                 // Para clases se llama al constructor por defecto
    for ( const auto & value : container )
        result = result + value ;
    return result ;
}

namespace core_numeric {
    template <typename T>
    requires Iterable<T> && Divisible<typename T::value_type>
        double mean(const T& v) {
            double suma = sum(v);
            return suma / v.size();
        }
    template <typename C>
    requires Iterable<C> && Addable<typename C::value_type>
        double variance(const C& v){
            double sumatoria = 0.0;
            double media = mean(v);
            for (int i=0; i<v.size();i++){
                sumatoria += pow(v[i] - media,2);
            }
            return sumatoria / v.size();
        }
    template <typename M>
    requires Iterable<M> && Numero<typename M::value_type>
        auto max(const M& v) {
            using T = typename M::value_type;
            if constexpr (is_integral_v<T>) {
                T result = *max_element(v.begin(), v.end());
                return result;
            } else {
                T result = *max_element(v.begin(), v.end());
                return result;
            }
        }

    template <Iterable C, typename Func>
    requires Addable<typename C::value_type>
        auto transform_reduce(const C& v, Func f) {
        using T = typename C::value_type;
        T result{};
        for (const auto &x: v) {
            result += f(x);
        }
        return result;
        }
    template <typename... A>
    requires (Addable<A> && ...)
        auto sum_variadic(A... args) {
            return (args + ...);
        }
    template <typename... A>
    requires (Addable<A> && ...)
        auto mean_variadic(A... args){
            return (args + ...) / sizeof...(args);
        }
    template <typename... A>
    requires (Addable<A> && ...)
        auto variance_variadic(A... args){
            size_t n = sizeof...(args);
            auto med = (args + ...) / static_cast<double>(n);
            return (((args - med) * (args - med)) + ...) / n;
        }
    template <typename... A>
    requires (Addable<A> && ...)
        auto max_variadic(A... args){
            using T = common_type_t<A...>;
            auto arr = {static_cast<T>(args)...};
            return *max_element(arr.begin(), arr.end());
        }
}


int main() {
    vector <double> v {1.0 ,2.0 ,3.0};

    auto r = core_numeric :: transform_reduce (v , []( double x ) {
        return x * x ;
    }) ;
    cout << r << endl;

    auto s1 = core_numeric :: sum_variadic (1 ,2 ,33 ,4) ; //parameter packs
    auto s2 = core_numeric :: mean_variadic (0.1 ,2 ,3 ,4) ;
    auto s3 = core_numeric :: variance_variadic (1 ,2 ,3 ,4) ;
    auto s4 = core_numeric :: max_variadic (1 ,2.7 ,3 ,4) ;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;

    return 0;
}
