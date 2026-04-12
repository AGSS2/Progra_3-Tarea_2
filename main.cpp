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
    { a / n } -> same_as <T >;
};

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
    template <Divisible T>
        double mean(const vector<T>& v) {
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
    requires Iterable<M> && Divisible<typename M::value_type>
        double max(const M& v){
            return *max_element(v.begin(),v.end());
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
    requires (Addable<A> && ...) && (Divisible<A> && ...)
        auto sum_variadic(A... args) {
            return (args + ...);
        }
}


int main() {
    vector <double> v {1.0 ,2.0 ,3.0};
    auto m = core_numeric :: mean ( v ) ; // usar ’namespace ’
    // para ’ core_numeric ’
    cout << m << endl;

    vector <double > data {1.0 , 2.0 , 3.0};
    auto vi = core_numeric :: variance ( data ) ; // Compila
    cout << vi << endl;

    //vector <string > dat {"a", "b", "c"};
    //auto va = core_numeric :: variance ( dat ) ;

    vector <double > maximo {1 , 2.7 , 0.3};
    auto v_max = core_numeric :: max ( maximo ) ;
    cout << v_max << endl;

    //std :: vector < std :: string > fail {"a", "b", "c"};
    //auto v_fail = core_numeric :: max ( fail ) ;

    auto r = core_numeric :: transform_reduce (v , []( double x ) {
        return x * x ;
    }) ;
    cout << r << endl;

    auto s1 = core_numeric :: sum_variadic (1 ,2 ,33 ,4) ;
    auto s2 = core_numeric :: mean_variadic (0.1 ,2 ,3 ,4) ;
    auto s3 = core_numeric :: variance_variadic (1 ,2 ,3 ,4) ;
    auto s4 = core_numeric :: max_variadic (1 ,2.7 ,3 ,4) ;

    return 0;
}
