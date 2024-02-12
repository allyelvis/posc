#include <iostream>
#include <string>
#include <map>

std::map<std::string, std::string> userDatabase;

void addUser(const std::string &username, const std::string &password) {
    userDatabase[username] = password;
}

bool authenticateUser(const std::string &username, const std::string &password) {
    if (userDatabase.find(username) != userDatabase.end()) {
        return userDatabase[username] == password;
    }
    return false;
}

int main() {
    addUser("user1", "password1");
    addUser("user2", "password2");

    std::cout << "Authentication for user1: " << authenticateUser("user1", "password1") << std::endl;
    std::cout << "Authentication for user2: " << authenticateUser("user2", "wrongpassword") << std::endl;

    return 0;
}
