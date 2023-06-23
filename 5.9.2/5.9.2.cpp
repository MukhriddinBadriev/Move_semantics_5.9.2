#include <iostream>
#include <string>

#define MAX_SIZE 100

class big_integer {
public:
    big_integer(std::string _number) {
        string_number = _number;
        int_number = string_number[0] - '0';
    }

    big_integer(int num) :int_number(num) {};

    big_integer(big_integer&& other) noexcept {                   //конструктор перемещения
        *this = std::move(other.string_number);
    }

    big_integer& operator=(big_integer&& other) noexcept {        //перемещающий оператор присваивания
        string_number = std::move(other.string_number);
        return *this;
    }

    big_integer operator+(big_integer& other) {                   //оператор сложения двух больших чисел
   
        int res1 = 0;
        int res2 = 0;
        int res = 0;
        std::string result="";
        std::cout << result.length();
        int size1 = string_number.length();
        int size2 = other.string_number.length();
        int difference = abs(size1 - size2);
        if (size1 >= size2) {
            result = string_number;
            for (int i = size1-1; i >= 0; i--) {
                res1 =res+ string_number[i] - '0';
                res2 = other.string_number[i-difference] - '0';
                res = res1 + res2;
                if (res >= 10) {
                    res = res - 10;
                    son[i] = res;
                    res = 1;
                }
                else {
                    son[i] = res;
                    res = 0;
                }                                
            }
        }
        else {
            for (int i = size2-1; i >= 0; i--) {
                res1 = res + string_number[i] - '0';
                res2 = other.string_number[i - difference] - '0';
                res = res1 + res2;
                if (res >= 10) {
                    res = res - 10;
                    son[i] = res;
                    res = 1;
                }
                else {
                    son[i] = res;
                    res = 0;
                }
            }
        }
            return result;
    }

    big_integer operator*(int number) {                            //оператор умножения на число

    }

    friend std::ostream& operator<<(std::ostream& os, const big_integer& dt);

private:
    std::string string_number;
    int int_number;
    char son[MAX_SIZE];
};

std::ostream& operator<<(std::ostream& os, const big_integer& fr)
{
    os << fr.int_number;
    return os;
}


int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result;

    return 0;
}