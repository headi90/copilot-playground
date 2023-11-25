#include <iostream>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

// Define the User class
struct User
{
    std::string name;
    std::string surname;
    int age;
    std::string password;

    User(std::string name, std::string surname, int age, std::string password)
        : name(name), surname(surname), age(age), password(password)
    {
    }
};

// read data for class user from json file
std::vector<User> readData(const std::string &fileName)
{
    std::vector<User> users;
    std::ifstream file(fileName);
    json j;
    file >> j;
    for (auto &element : j)
    {
        users.push_back(User(element["name"], element["surname"], element["age"], element["password"]));
    }
    return users;
}

// write data for class user to json file
void writeData(const std::vector<User> &users, const std::string &fileName)
{
    nlohmann::json json_obj;
    for (const auto &user : users)
    {
        json_obj.push_back({{"name", user.name},
                            {"surname", user.surname},
                            {"age", user.age},
                            {"password", user.password}});
    }
    std::ofstream file(fileName);
    file << json_obj;
}

int main(int argc, char *argv[])
{
    try
    {

        if (argc < 2)
        {
            std::cout << "Please provide a file name as a command-line argument." << std::endl;
            return 1;
        }

        std::string fileName = argv[1];

        // write data to json file
        std::vector<User> users;
        users.emplace_back("name1", "surname1", 21, "password1");
        users.emplace_back("name2", "surname2", 22, "password2");
        users.emplace_back("name3", "surname3", 23, "password3");
        users.emplace_back("name4", "surname4", 24, "password4");
        users.emplace_back("name5", "surname5", 25, "password5"); // Add user 5
        users.emplace_back("name6", "surname6", 26, "password6"); // Add user 6
        users.emplace_back("name7", "surname7", 27, "password7"); // Add user 7
        users.emplace_back("name8", "surname8", 28, "password8"); // Add user 8
        writeData(users, fileName);

        // read data from json file
        std::vector<User> users2 = readData(fileName);
        for (const auto &user : users2)
        {
            std::cout << user.name << " " << user.surname << " " << user.age << " " << user.password << std::endl;
        }
    }
    catch (json::parse_error &e)
    {
        // output exception information
        std::cout << "message: " << e.what() << '\n'
                  << "exception id: " << e.id << std::endl;
    }
    catch (json::out_of_range &e)
    {
        // output exception information
        std::cout << "message: " << e.what() << '\n'
                  << "exception id: " << e.id << std::endl;
    }
    // other types of exceptions can be caught here...

    return 0;
}
