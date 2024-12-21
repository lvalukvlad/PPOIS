#include <iostream>
#include "BigInteger.h"
#include <string>

int test_main(int argc, char** argv);

int main() {
    setlocale(0, "");
    std::string input_num1;
    std::cout << "������� ������ ������� ����� �����:\t";
    std::getline(std::cin, input_num1);
    BigInteger num1(input_num1);
    std::cout << "�� ����� ������ �����:\t" << num1 << '\n';
    std::string input_num2;
    std::cout << "������� ������ ������� ����� �����:\t";
    std::getline(std::cin, input_num2);
    BigInteger num2(input_num2);
    std::cout << "�� ����� ������ �����:\t" << num2 << '\n';

    bool flagToMenageOperation{ true };
    int choice;
    do {
        std::cout << "\n�������� ��������:\n";
        std::cout << "1. �������� ���� ������� �����\n";
        std::cout << "2. �������� �������� ������ � �����\n";
        std::cout << "3. ��������� ���� ������� �����\n";
        std::cout << "4. ��������� �� �������� ������ ������\n";
        std::cout << "5. ������������ ���� ������� �����\n";
        std::cout << "6. ������������ �������� ������ � ������\n";
        std::cout << "7. ������� ���� ������� �����\n";
        std::cout << "8. ������� �������� ������ �� �����\n";
        std::cout << "9. ���- � �������������\n";
        std::cout << "10. ���- � �������������\n";
        std::cout << "11. ��������� ���� ������� �����\n";
        std::cout << "12. ��������� �������� ������ � �����\n";
        std::cout << "13. �����\n";
        std::cout << "������� ��� �����: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "���������: " << (num1 + num2) << std::endl;
            break;
        case 2:
            std::cout << "������� ����� �����: ";
            int intNum;
            std::cin >> intNum;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "���������: " << (num1 + intNum) << std::endl;
            break;
        case 3:
            std::cout << "���������: " << (num1 - num2) << std::endl;
            break;
        case 4:
            std::cout << "������� ����� �����: ";
            std::cin >> intNum;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "���������: " << (num1 - intNum) << std::endl;
            break;
        case 5:
            std::cout << "���������: " << (num1 * num2) << std::endl;
            break;
        case 6:
            std::cout << "������� ����� �����: ";
            std::cin >> intNum;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "���������: " << (num1 * intNum) << std::endl;
            break;
        case 7:
            try {
                std::cout << "���������: " << (num1 / num2) << std::endl;
            }
            catch (const std::invalid_argument& e) {
                std::cout << "������: " << e.what() << std::endl;
            }
            break;
        case 8:
            std::cout << "������� ����� �����: ";
            std::cin >> intNum;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            try {
                std::cout << "���������: " << (num1 / intNum) << std::endl;
            }
            catch (const std::invalid_argument& e) {
                std::cout << "������: " << e.what() << std::endl;
            }
            break;
        case 9:
            std::cout << "������������: " << ++num1 << std::endl;
            std::cout << "�������������: " << num1++ << std::endl;
            std::cout << "����� ��������������: " << num1 << std::endl;
            break;
        case 10:
            std::cout << "������������: " << --num1 << std::endl;
            std::cout << "�������������: " << num1-- << std::endl;
            std::cout << "����� ��������������: " << num1 << std::endl;
            break;
        case 11:
            if (num1 < num2) {
                std::cout << num1 << " ������ " << num2 << std::endl;
            }
            else if (num1 > num2) {
                std::cout << num1 << " ������ " << num2 << std::endl;
            }
            else {
                std::cout << num1 << " ����� " << num2 << std::endl;
            }
            break;
        case 12:
            std::cout << "������� ����� �����: ";
            std::cin >> intNum;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            if (num1 < intNum) {
                std::cout << num1 << " ������ " << intNum << std::endl;
            }
            else if (num1 > intNum) {
                std::cout << num1 << " ������ " << intNum << std::endl;
            }
            else {
                std::cout << num1 << " ����� " << intNum << std::endl;
            }
            break;
        case 13:
            std::cout << "����� �� ���������..." << std::endl;
            flagToMenageOperation = false;
            break;
        default:
            std::cout << "�������� �����. ���������� �����." << std::endl;
        }
    } while (flagToMenageOperation);

    return 0;
}