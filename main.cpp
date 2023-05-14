#include <iostream>
#include <cmath>

// Function to convert a binary number to decimal
int binaryToDecimal(const std::string& binary) {
    int decimal = 0;
    int power = 0;

    for (int i = binary.length() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += std::pow(2, power);
        }
        power++;
    }

    return decimal;
}

// Function to convert a decimal number to binary
std::string decimalToBinary(int decimal) {
    std::string binary;

    while (decimal > 0) {
        binary = std::to_string(decimal % 2) + binary;
        decimal /= 2;
    }

    return binary;
}

// Function to convert a binary number to octal
std::string binaryToOctal(const std::string& binary) {
    std::string octal;
    std::string paddedBinary = binary;

    // Pad the binary number with leading zeros if needed
    int remainder = binary.length() % 3;
    if (remainder != 0) {
        paddedBinary = std::string(3 - remainder, '0') + paddedBinary;
    }

    for (int i = 0; i < paddedBinary.length(); i += 3) {
        std::string group = paddedBinary.substr(i, 3);
        int decimal = binaryToDecimal(group);
        octal += std::to_string(decimal);
    }

    return octal;
}

// Function to convert an octal number to binary
std::string octalToBinary(const std::string& octal) {
    std::string binary;

    for (char digit : octal) {
        int decimal = digit - '0';
        std::string group = decimalToBinary(decimal);

        // Pad the binary group with leading zeros if needed
        if (group.length() < 3) {
            group = std::string(3 - group.length(), '0') + group;
        }

        binary += group;
    }

    return binary;
}

// Function to convert a base 8 number to decimal
int octalToDecimal(const std::string& octal) {
    int decimal = 0;
    int power = 0;

    for (int i = octal.length() - 1; i >= 0; --i) {
        int digit = octal[i] - '0';
        decimal += digit * std::pow(8, power);
        power++;
    }

    return decimal;
}

// Function to convert a decimal number to base 8
std::string decimalToOctal(int decimal) {
    std::string octal;

    while (decimal > 0) {
        int remainder = decimal % 8;
        octal = std::to_string(remainder) + octal;
        decimal /= 8;
    }

    return octal;
}

int main() {
    int choice;

    std::cout << "1. Convert Binary to Decimal" << std::endl;
    std::cout << "2. Convert Decimal to Binary" << std::endl;
    std::cout << "3. Convert Binary to Octal" << std::endl;
    std::cout << "4. Convert Octal to Binary" << std::endl;
    std::cout << "5. Convert Decimal to Octal" << std::endl;
    std::cout << "6. Convert Octal to Decimal" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    std::string input;
    int decimalInt;

    switch (choice) {
        case 1:
            std::cout << "Enter a binary number: ";
            std::cin >> input;
            std::cout << "Decimal: " << binaryToDecimal(input) << std::endl;
            break;
        case 2:
            int decimal;
            std::cout << "Enter a decimal number: ";
            std::cin >> decimal;
            std::cout << "Binary: " << decimalToBinary(decimal) << std::endl;
            break;
        case 3:
            std::cout << "Enter a binary number: ";
            std::cin >> input;
            std::cout << "Octal: " << binaryToOctal(input) << std::endl;
            break;
        case 4:
            std::cout << "Enter an octal number: ";
            std::cin >> input;
            std::cout << "binary: " << octalToBinary(input) << std::endl;
            break;
        case 5:
            std::cout << "Enter a octal number: ";
            std::cin >> input;
            std::cout << "Decimal: " << octalToDecimal(input) << std::endl;
            break;
        case 6:
            std::cout << "Enter a decimal number: ";
            std::cin >> input;
            std::cout << "Octal: " << decimalToOctal(decimalInt) << std::endl;
    }
}
