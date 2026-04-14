#include <iostream>
#include <vector>
#include "main.cpp"

int test(){

    //Mean - Compila
    vector <double> v_media {1.0 ,2.0 ,3.0};
    auto med = core_numeric :: mean ( v_media) ;
    cout << med << endl;

    vector <int> v_media2 {12 ,20 ,44};
    auto med2 = core_numeric :: mean ( v_media2) ;
    cout << med2 << endl;

    //Mean - No compila (Falla en el concept "Divisible")
    /*
    vector <string> fail {"a" ,"b" , "c"};
    auto med3 = core_numeric :: mean (fail) ;
    cout << med3 << endl;

    vector <char> fail {'a' ,'b' , 'c'};
    auto med3 = core_numeric :: mean (fail) ;
    cout << med3 << endl;
    */

    //Mean - No compila (Falla en el concept "Iterable")
    /*
    int n_med = 3;
    auto med3 = core_numeric :: mean ( n_med) ;
    */

    //Variance - Compila
    vector <double> v_var {1.0 ,2.0 ,3.0};
    auto var = core_numeric :: variance( v_media) ;
    cout << var << endl;

    vector <int> v_var2 {12 ,20 ,44};
    auto var2 = core_numeric :: variance( v_var2) ;
    cout << var2 << endl;

    //Variance - No compila (Falla en el concept "Divisible")
    /*
    vector <string> fail {"a" ,"b" , "c"};
    auto med3 = core_numeric :: variance (fail) ;
    cout << med3 << endl;

    vector <char> fail {'a' ,'b' , 'c'};
    auto med3 = core_numeric :: variance (fail) ;
    cout << med3 << endl;
    */

    //Variance - No compila (Falla en el concept "Iterable")
    /*
    int n_var = 3;
    auto var3 = core_numeric :: variance ( n_var) ;
    */

    //Max - Compila
    vector <double> v_max {1.0 ,2.0 ,3.0};
    auto maximo = core_numeric :: max( v_max) ;
    cout << maximo << endl;

    vector <int> v_max2{12 ,20 ,44};
    auto maximo2 = core_numeric :: max( v_max2) ;
    cout << maximo2 << endl;

    //Max - No compila (Falla en el concept "Divisible")
    /*
    vector <string> fail {"a" ,"b" , "c"};
    auto max3 = core_numeric :: max (fail) ;
    cout << max3 << endl;

    vector <char> fail {'a' ,'b' , 'c'};
    auto max3 = core_numeric :: max (fail) ;
    cout << max3 << endl;
    */

    //Mean - No compila (Falla en el concept "Iterable")
    /*
    int n_max = 3;
    auto max3 = core_numeric :: max ( n_max) ;
    */

    return 0;
}
