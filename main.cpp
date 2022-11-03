// FILE: main.cpp
// Authors: 
    // Nathaniel Waggoner
    // Kobe Norcross
    // Ashton Sawyer
    // Matt Loera
    // Yuki Yamada

#include "provider.h"

int main()
{
    //test defualt constructor
    Provider prov;
    prov.print_provider();

    //test init_provider
    Address address;
    address.street = "street";
    address.city = "city";
    address.state = "OR";
    address.zip = "97203";
    prov.init_provider("Greg", "999999999", address);
    prov.print_provider();

    //test init constructor
    Provider prov1("man", "999999999", address);
    prov1.print_provider();

    //test copy constructor
    Provider prov2(prov);
    prov2.print_provider();
    return 0;
}
