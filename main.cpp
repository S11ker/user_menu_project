#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

using str = std::string;

class User {
private:
    str _password;
    str _login;

public:

    User(const str &login, const str &password) {
        this->_login = login;
        this->_password = password;
    }

    void ChangePassword() { // For old users
        str current_psswrd, new_psswrd;
        cout << "Введите старый пароль: ";
        cin >> current_psswrd;

        while (current_psswrd != this->_password) {
            cout << "Ваши пароли не совпадают" << endl
                 <<"Введите старый пароль: ";
            cin >> current_psswrd;
        }

        cout << "Пароли успешно совпали. Введите новый пароль: ";
        cin >> new_psswrd;
        this->_password = new_psswrd;
    }

    void ViewLoginAndPassword() {
        cout << "================================="
             << "\nЛогин: " << this->_login << endl
             << "Пароль: " << this->_password << endl
             << "=================================" << endl;
    }
};

enum class Menu : int8_t {
    GET_LOGIN_AND_PASSWORD = 1,
    CHANGE_PASSWORD,
    EXIT_PROGRAM
};

inline void ShowMenu() {
    cout << "\nМеню пользователя: " << endl
         << "1. Посмотреть логин и пароль аккаунта" << endl
         << "2. Изменить свой пароль" << endl
         << "3. Выйти из программы" << endl;
}

void ExitOrBack(int &answer_menu) {
    char answer;
    cout << "Вы хотите вернуться назад?\n"
         << "Enter - да, n - нет. Завершение работы.\n"
         << "Я выбираю - ";
    cin >> answer;
    if (answer == 'n') {
        answer_menu = static_cast<int>(Menu::EXIT_PROGRAM);
    }
}

auto main() -> int
{

    str password, login;

    cout << "Здравствуй, пользователь! Пройди регистрацию: " << endl
         << "Введите логин: ";
    cin >> login;
    cout << "Введите пароль: ";
    cin >> password;

    User user(login, password);

    int answer_for_menu{};

    while (answer_for_menu != static_cast<int>(Menu::EXIT_PROGRAM)) {
        ShowMenu();

        cin >> answer_for_menu;

        switch (answer_for_menu) {
            case static_cast<int>(Menu::GET_LOGIN_AND_PASSWORD):

                user.ViewLoginAndPassword();
                ExitOrBack(answer_for_menu);
                break;

            case static_cast<int>(Menu::CHANGE_PASSWORD):

                user.ChangePassword();
                ExitOrBack(answer_for_menu);
                break;

            case static_cast<int>(Menu::EXIT_PROGRAM):
                cout <<"\nПрограмма завершила работу.";
                return 0;

            default:
                cout << "Вы ввели неправильное значение из меню!" << endl;
                break;
        }
    }
}