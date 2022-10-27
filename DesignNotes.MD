  - What classes are needed?
  - What functions are needed for those classes
  
# Program Components
  - Base Program
    - This includes all of the custom classes and data Structures we are desining for the project
  - Driver Program
    - Interactive Mode Driver
      * Add/delete/edit members
      * Add/delete/edit providers
      * Generate Reports
    - Acme Accounting Driver
      * Toggle member status (active/inactive)
    - Provider Terminal Driver
      1. Log in provider
      2. Validate member (does not exist, active, suspended)
      3. validate serviceID (that it is valid for that provider)
      4. generate a service record (given user input)

# Basic Classes
  - Member
  - Provider
  - Service Record
## Requirements
  - Each basic class has data associated with it
  - Needs functions to access and mutate that data
  - Needs to be able to write itself into JSON object string
    - persistance
## Member
### Data
  - name
  - memberID
  - accountActive(yes/no)
  - member street address
  - city
  - state
  - zipcode
### Interface (Public Methods)
  - Member()
    - CLI prompt for fields?
  - Member(name,id,active,address,city,state,zipcode)
    - initialized constructor
  - Member(string json)
    - takes in a string json object and initializes Member
  - display()
    - displays to CLI
  - toJSON()
    - returns a string json object representing the instance of Member
  - getters and setters for each data field
  - toggleActive()
    - toggles whether member is active
  - compareTo(Member toCompare)
    - this will help with alphabetizing
### Private Methods


## Provider
### Data
  - name
  - providerID
  - Service info (parallel arrays?)
    - list of services
    - list of serviceID
    - list of fees (up to 999.99)
### Interface (Public Methods)
- Provider()
  - CLI prompt for fields?
- Provider(name,id)
  - initialized constructor, still need to prompt for services offered
- Provider(string json)
  - takes in a string json object and initializes Provider instance
- display()
  - displays to CLI
- toJSON()
  - returns a string json object representing the instance of Provider
- getters and setters for each data field
  - how to edit services? CLI or by referencing the index?
- compareTo(Provider toCompare)
  - help with alphabetical
### Private Methods

## Service Record
### Data
- date record created "MM-DD-YYYY HH:MM:SS"
- date service provided "MM-DD-YYYY"
- provider number
- member number
- service code
- comments
### Interface (Public Methods)
- ServiceRecord()
  - CLI prompt to initialize the service record
- ServiceRecord(date,sDate,pID,mID,sID,comments)
  - initialized constructor
- ServiceRecord(string json)
  - takes in a string json object and initializes Provider instance
- display()
  - displays to CLI
- toJSON()
  - returns a string json object representing the instance of Provider\
- getters/setters
### Private Methods


# Databases
  - Provider Directory
  - Member Directory
  - Service Ledger
## Requirements
  - Each Data Structure class is a collection of references to data
  - We should pick the simplest solution to implement that meets requirements
    - which data structure to use for each database
  - Searchability?: What fields does this need to be searchable to
    - Use hash map or dictionary to match pID to provider and mID to Member
  - Needs to be able to create a JSON file consisting of data objects
    - needs to be able to reconstitute via JSON file
