#include <stdexcept>
#include <string>
#include <iostream>

// Базовий клас для математичних винятків
class MathException : public std::runtime_error {
public:
    explicit MathException(const std::string& message) : std::runtime_error(message) {}
};

// Клас для обробки винятку ділення на нуль
class DivisionByZeroException : public MathException {
public:
    DivisionByZeroException() : MathException("Division by zero error.") {}
};

// Клас для обробки винятку переповнення
class OverflowException : public MathException {
public:
    OverflowException() : MathException("Overflow error.") {}
};

// Клас для обробки винятку невірних операцій
class InvalidOperationException : public MathException {
public:
    InvalidOperationException() : MathException("Invalid operation error.") {}
};

// Додаткові класи можуть бути додані для обробки інших математичних винятків

int main() {
    try {
        // Спроба виконати математичні операції
        // Якщо виникає помилка, викидається відповідний виняток
        throw DivisionByZeroException();
    }
    catch (const MathException& e) {
        // Обробка винятку
        // Виведення повідомлення про помилку
        std::cerr << "Math error occurred: " << e.what() << std::endl;
    }

    return 0;
}
