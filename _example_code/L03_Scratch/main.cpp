#include <iostream>


class MeineKlasse {
public:
    int ersterWert;
    int zweiterWert;
};



int main() {
    
    ///////////////////////////////////
    // Variablen, eingebaute Datentypen
    int other_var = my_var;
    float my_float = 3.141592f;
    double my_double = 3.141592;
    bool my_bool = true;
    my_bool = false;
    char my_char = 'A';

    ///////////////////////////////////
    // Zeiger (Pointer)
    int my_var = 42;
    int* p_my_var = &my_var;
    int b = *p_my_var;
    *p_my_var = 43;

    // Was steht in b?
    // Was steht in my_var?

    ///////////////////////////////////
    // Zeiger (Pointer) auf Objekte
    MeineKlasse mein_objekt;
    mein_objekt.ersterWert = 1;
    mein_objekt.zweiterWert = 2;

    MeineKlasse* p_mein_objekt = &mein_objekt;
    p_mein_objekt->ersterWert = 42;

    MeineKlasse* p_mein_neues_obj = new MeineKlasse();
    p_mein_neues_obj->ersterWert = 10;
    p_mein_neues_obj->zweiterWert = 20;

    // Was steht in ersterWert von meinobjekt?

    /////////////////////////////////////////
    // Arrays und Strings
    int my_int_array[5] = {1, 2, 3, 4, 5};
    char my_string[20] = "Hallo, Welt!";

    // Arrays und Strings SIND Zeiger (Pointer)
    int *p_ints = my_int_array;
    char *p_string = my_string;

    return 0;
}