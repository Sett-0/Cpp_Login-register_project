#include <iostream>
#include <fstream>
#include <string>

bool TryLogIn() {
	std::string username, password, un, pw;
	std::cout << "Enter your username: "; std::cin >> username;
	std::cout << "Enter your password: "; std::cin >> password;

	std::ifstream read("./data/" + username + ".txt");
	if (!read) {
		return false;
	}

	std::getline(read, un);
	std::getline(read, pw);

	read.close();
	if (username == un && password == pw) return true;
	else return false;
}

int main() {
	int choice;

	std::cout << "1: Register\n2: Login\nYour Choice: "; std::cin >> choice;
	switch (choice) {
	case 1:
	{
		std::string username, password, password_check;

		std::cout << "Select a username: "; std::cin >> username;

		do { std::cout << "Select a password: "; std::cin >> password; } while (!password.length());
		std::cout << "Please, repeat your password: "; std::cin >> password_check;

		if (!(password == password_check)) {
			std::cout << "Passwords do not match! Please, repeat the registration process.";
			return -2;
		}

		std::ofstream write("./data/" + username + ".txt");
		if (!write) {
			std::cout << "Error while creating the file";
			return -3;
		}

		write << username << '\n' << password;
		write.close();

		std::cout << "Registration successful! You can log in now.";

		break;
	}
	case 2:
	{
		if (TryLogIn()) 
			std::cout << "Log in successful!";
		else 
			std::cout << "Incorrect username or password.";
		break;
	}
	default:
		std::cout << "Incorrect input!";
		return -1;
	}

	return 0;
}