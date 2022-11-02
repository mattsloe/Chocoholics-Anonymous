// main.cpp
// This is the main driver code of our code
// Kobe Norcross
// Add your name below here for PR Test`
// Ashton Sawyer

#include "provider.h"

int main()
{
    Provider prov;
    Address address;
    address.street = "street";
    address.city = "city";
    address.state = "OR";
    address.zip = 97203;
    prov.init_provider("Greg", 999999999, address);
    prov.print_provider();
    return 0;
}