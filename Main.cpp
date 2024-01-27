#include <stdexcept>
#include <string>
#include <iostream>

// ������� ���� ��� ������������ �������
class MathException : public std::runtime_error {
public:
    explicit MathException(const std::string& message) : std::runtime_error(message) {}
};

// ���� ��� ������� ������� ������ �� ����
class DivisionByZeroException : public MathException {
public:
    DivisionByZeroException() : MathException("Division by zero error.") {}
};

// ���� ��� ������� ������� ������������
class OverflowException : public MathException {
public:
    OverflowException() : MathException("Overflow error.") {}
};

// ���� ��� ������� ������� ������� ��������
class InvalidOperationException : public MathException {
public:
    InvalidOperationException() : MathException("Invalid operation error.") {}
};

// �������� ����� ������ ���� ����� ��� ������� ����� ������������ �������

int main() {
    try {
        // ������ �������� ���������� ��������
        // ���� ������ �������, ���������� ��������� �������
        throw DivisionByZeroException();
    }
    catch (const MathException& e) {
        // ������� �������
        // ��������� ����������� ��� �������
        std::cerr << "Math error occurred: " << e.what() << std::endl;
    }

    return 0;
}
