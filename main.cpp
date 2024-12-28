#include <iostream>
#include <string>

class User
{
private:
    std::string username = "";
    std::string pass = "";

public:
    int age = 0;
    bool gender = 0;
    std::string country = "";

    User() {}
    User(std::string username, std::string pass, int age, bool gender, std::string country)
    {
        this->username = username;
        this->pass = pass;
        this->age = age;
        this->gender = gender;
        this->country = country;
    }
    void setUsername(std::string name)
    {
        username = name;
    }
    void setPass(std::string password)
    {
        pass = password;
    }
    std::string getUsername()
    {
        return this->username;
    }
    std::string getPass()
    {
        return this->pass;
    }
};

int main()
{
    int counter = 0;
    const int size = 10;
    User user1(" ", " ", 0, 0, " ");
    User users[size];
    for (int i = 0; i < size; i++)
    {
        users[i] = user1;
    }

    std::string selection;
    std::cout << "********************************************" << '\n';
    std::cout << "******** Welcome to our application ********" << '\n';

    do
    {
        std::cout << "  Please ENTER 1 or 2" << '\n'
                  << "  1. Sign Up" << '\n'
                  << "  2. Sign In" << '\n';
        std::cin >> selection;
        char s = selection[0] - '0';

        if (s == 1)
        {
            bool cont = true;
            std::string userName;
            std::string passWord1;
            std::string passWord2;
            int Age;
            char Gender;
            bool Gen;
            std::string Country;
            std::cout << "******** Sign Up ********" << '\n';

            do
            {
                cont = true;
                std::cout << "Please enter Username (at least 6 characters)." << '\n';
                std::getline(std::cin >> std::ws, userName);
                for (int x = 0; x < userName.size(); x++)
                {
                    if (userName[x] < 48 || (57 < userName[x] && userName[x] < 65) || (90 < userName[x] && userName[x] < 97) || 122 < userName[x])
                    {
                        std::cout << "Your username must ONLY contain numbers and letters." << '\n';
                        cont = false;
                        break;
                    }
                };
                for (int j = 0; j < size; j++)
                {
                    if (userName == users[j].getUsername())
                    {
                        std::cout << "This username is being used by another user. PLEASE try another username." << '\n';
                        cont = false;
                        break;
                    }
                }
            } while ((userName.size() < 6) || (cont == false));
            do
            {
                std::cout << "Please enter Password (at least 8 characters)." << '\n';
                std::getline(std::cin >> std::ws, passWord1);
            } while (passWord1.size() < 8);
            do
            {
                std::cout << "Please re-enter Password to confirm" << '\n';
                std::getline(std::cin >> std::ws, passWord2);
                if (passWord2 == passWord1)
                {
                    break;
                }
                std::cout << "Please make sure that your password confirmation matches your initial password" << '\n';
            } while (true);
            do
            {
                std::cout << "Please enter Age in numbers" << '\n';
                std::cin >> Age;
                if (Age)
                {
                    break;
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please only use valid numbers" << '\n';
            } while (true);
            do
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please select Gender ** M ** for male, ** F ** for female" << '\n';
                std::cin >> Gender;
            } while (Gender != 'M' && Gender != 'm' && Gender != 'F' && Gender != 'f');
            if (Gender == 'M' || Gender == 'm')
            {
                Gen = 1;
            }
            else
            {
                Gen = 0;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter Country of residence" << '\n';
            std::getline(std::cin >> std::ws, Country);

            users[counter].setUsername(userName);
            users[counter].setPass(passWord1);
            users[counter].age = Age;
            users[counter].gender = Gen;
            users[counter].country = Country;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "You have been registered successfully!" << '\n'
                      << "Your data is:" << '\n'
                      << "      Username: " << users[counter].getUsername() << '\n'
                      << "      Age: " << users[counter].age << '\n'
                      << "      Gender: " << (users[counter].gender ? "Male" : "Female") << '\n'
                      << "      Current location: " << users[counter].country << '\n'
                      << "************************************************************" << '\n'
                      << "************************************************************" << '\n';
            counter += 1;
        }
        else if (s == 2)
        {
            std::string userName;
            std::string passWord1;
            std::string passWord2;
            std::string Country;
            int matching = size + 1;
            int trials = 3;
            std::cout << "******** Sign In ********" << '\n';
            do
            {
                std::cout << "Please enter your username:" << '\n';
                std::getline(std::cin >> std::ws, userName);
                for (int j = 0; j < size; j++)
                {
                    if (userName == users[j].getUsername())
                    {
                        matching = j;
                        break;
                    }
                }
                if (matching == size + 1)
                {
                    std::cout << "This username is not found." << '\n';
                }
            } while (matching == size + 1);
            do
            {
                int choose;
                std::cout << "Please enter your password:" << '\n';
                std::getline(std::cin >> std::ws, passWord1);
                if (passWord1 == users[matching].getPass())
                {
                    std::cout << "Welcome back!" << '\n'
                              << "Your data is:" << '\n'
                              << "      Username: " << users[matching].getUsername() << '\n'
                              << "      Age: " << users[matching].age << '\n'
                              << "      Gender: " << (users[matching].gender ? "Male" : "Female") << '\n'
                              << "      Current location: " << users[matching].country << '\n'
                              << "Choose an option:" << '\n'
                              << "      1. Change password" << '\n'
                              << "      2. Edit current location" << '\n';
                    std::cin >> choose;
                    if (choose == 1)
                    {
                        do
                        {
                            std::cout << "Please enter Password (at least 8 characters)." << '\n';
                            std::getline(std::cin >> std::ws, passWord1);
                        } while (passWord1.size() < 8);
                        do
                        {
                            std::cout << "Please re-enter Password to confirm" << '\n';
                            std::getline(std::cin >> std::ws, passWord2);
                            if (passWord2 == passWord1)
                            {
                                break;
                            }
                            std::cout << "Please make sure that your password confirmation matches your initial password" << '\n';
                        } while (true);
                        users[matching].setPass(passWord1);
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Your password has been changed successfully!" << '\n';
                    }
                    else if (choose == 2)
                    {
                        std::cout << "Please enter your new location." << '\n';
                        std::getline(std::cin >> std::ws, Country);
                        users[matching].country = Country;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Your current location has been changed to " << users[matching].country << '\n';
                    }
                    else
                    {
                        std::cout << "Wrong choice!";
                    }
                    std::cout << "***************************************************" << '\n'
                              << "***************************************************" << '\n';
                    break;
                }
                else
                {
                    trials -= 1;
                    std::cout << "This password is not correct. " << trials << " trials left." << '\n';
                }
            } while (trials);
        }
        else
        {
            std::cout << "Please Enter ONLY 1 or 2" << '\n';
        }
    } while (true);

    return 0;
}
