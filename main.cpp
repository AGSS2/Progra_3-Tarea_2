#include <iostream>
#include <concepts>
#include <iterator>
#include <vector>

using namespace std;

namespace core_numeric {
    double mean(const std::vector<double>& v) {
        double sum = 0;
        for (double x : v) sum += x;
        return sum / v.size();
    }
}


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


int main() {
    vector <double> v {1.0 ,2.0 ,3.0};
    auto m = core_numeric :: mean ( v ) ; // usar ’namespace ’
    // para ’ core_numeric ’


    return 0;
}
