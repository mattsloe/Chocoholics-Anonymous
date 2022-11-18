# Using JSON in your Classes
This will help me explain how I used the nlohmann/json library to import and export data from my Member class. 

# The JSON data format
It's important to have an idea of what your JSON format is going to look like. For the Member object, it looks like this:
```
{
  "name":,
  "mid":,
  "address":,
  "city":,
  "state":,
  "zip":,
  "accountActive":,
  "serviceRecords":[

  ]
}
```
* Each entry is a key-value pair
* "key":"value"
* I named each entry after each data field in my class

# Understanding the nlohmann/json library
* The library is used by simply including `#include "json.hpp"` in the header
* the json object is located withing the *nlohmann* namespace, so I like to put `using nlohmann::json = json` to make things easier.
* First you create a json object, then you can load it up with data. Afterwards, you can get data from a json object using the array access operator (`j["name"].get<string>()`), or by using the .value() method (`j.value("name","not found"` will return the value associated with the "name" key as a string)
  * The second parameter in the .value() function is the default value if the key is not found. This is useful for validation.

# Outputting from Member
* I used the method `to_string_exp()` to return a string formatted for export to a JSON text file

```
std::string Member::to_string_exp()const {
    using json = nlohmann::json;
    std::string  s;

    //create json object
    json  j = {
            {"name",name},
            {"mid",mid},
            {"address",address},
            {"city",city},
            {"state",state},
            {"zip",zip},
            {"accountActive",accountActive}
    };
    s = j.dump(2); // the 2 is number of spaces for indent
    return s;
}
```
* Notice that creating a json object looks very similar to the text format of a json file. 
* j.dump(int) returns a string representation of the json object. The parameter is the number of spaces for indent.

# Creating a constructor that takes a json object as parameter
* If another module can handle opening the file, the json object can be used as a constructor for the Member object
```
Member::Member(nlohmann::json j) {
name = j.value("name","not found"); //second param is the default value
mid = j.value("mid","not found");
address = j.value("address","not found");
city = j.value("city","not found");
state = j.value("state","not found");
zip = j.value("zip","not found");
accountActive = j["accountActive"].get<bool>(); //extracts bool from accountActive
}
```
* I use the .value() method when extracting a string so I can get "not found" for validation purposes
* I use `j["accountActive"].get<bool>()` to extract the value from "accountActive" as a bool to match the datatype of my object's accountActive field. 

## Testing the Initialized Constructor
```
bool test5(Member* mPtr){

    //create a testfile
    Member* test;
    createMemberInstance(test);
    ofstream out("member.json");
    out << test->to_string_exp() << endl;

    //initialize using json object
    ifstream in("member.json");
    nlohmann::json  j = nlohmann::json ::parse(in); //instantiate object using parse with the infile stream
    mPtr = new Member(j);
    cout << endl << *mPtr << endl;
    return true;
}
```
* I plan on using the MemberDB to handle file I/O so that the Member class only needs to worry about taking in a json object.
1. I create a Member object with dummy data
1. I create an ostream to "member.json"
1. I call the `to_string_exp()` function to export to the ofstream.
1. I create an ifstream *in* to "member.json"
1. I create json object *j*, and call the `parse(in)` method to load the json data from the ifstream.
1. Now, when I instantiate a Member object using Member(j), it will automatically load the info from the json object
