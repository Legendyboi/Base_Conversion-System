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

// Function to convert a base 16 number to decimal
int hexToDecimal(const std::string& hex) {
    int decimal = 0;
    int power = 0;

    for (int i = hex.length() - 1; i >= 0; --i) {
        int digit;
        if (hex[i] >= '0' && hex[i] <= '9') {
            digit = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            digit = hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            digit = hex[i] - 'a' + 10;
        } else {
            // Invalid hexadecimal digit
            return -1;
        }

        decimal += digit * std::pow(16, power);
        power++;
    }

    return decimal;
}

// Function to convert a decimal number to base 16
std::string decimalToHex(int decimal) {
    std::string hex;

    while (decimal > 0) {
        int remainder = decimal % 16;
        char digit;
        if (remainder < 10) {
            digit = '0' + remainder;
        } else {
            digit = 'A' + (remainder - 10);
        }
        hex = digit + hex;
        decimal /= 16;
    }

    return hex;
}

// Function to convert a base 16 number to base 8
std::string hexToOctal(const std::string& hex) {
    int decimal = hexToDecimal(hex);
    return decimalToOctal(decimal);
}

// Function to convert a base 8 number to base 16
std::string octalToHex(const std::string& octal) {
    int decimal = octalToDecimal(octal);
    return decimalToHex(decimal);
}

// Function to convert a base 16 number to binary
std::string hexToBinary(const std::string& hex) {
    int decimal = hexToDecimal(hex);
    return decimalToBinary(decimal);
}

// Function to convert a binary number to base 16
std::string binaryToHex(const std::string& binary) {
    int decimal = binaryToDecimal(binary);
    return decimalToHex(decimal);
}

int main() {
    int choice;

    std::cout << "1. Convert Binary to Decimal" << std::endl;
    std::cout << "2. Convert Decimal to Binary" << std::endl;
    std::cout << "3. Convert Binary to Octal" << std::endl;
    std::cout << "4. Convert Octal to Binary" << std::endl;
    std::cout << "5. Convert Octal to Decimal" << std::endl;
    std::cout << "6. Convert Decimal to Octal" << std::endl;
    std::cout << "7. Convert Hex to Decimal" << std::endl;
    std::cout << "8. Convert Octal to Hex" << std::endl;
    std::cout << "9. Convert Hex to Octal" << std::endl;
    std::cout << "10. Convert Binary to Hex" << std::endl;
    std::cout << "11. Convert Hex to Binary" << std::endl;

    std::cout << "Enter your choice: ";
    std::cin >> choice;

    std::string input;
    int decimalInt;

    switch (choice) {
        case 1:
            std::cout << "Enter a Binary number: ";
            std::cin >> input;
            std::cout << "Decimal: " << binaryToDecimal(input) << std::endl;
            break;
        case 2:

            std::cout << "Enter a Decimal number: ";
            std::cin >> decimalInt;
            std::cout << "Binary: " << decimalToBinary(decimalInt) << std::endl;
            break;
        case 3:
            std::cout << "Enter a Binary number: ";
            std::cin >> input;
            std::cout << "Octal: " << binaryToOctal(input) << std::endl;
            break;
        case 4:
            std::cout << "Enter an Octal number: ";
            std::cin >> input;
            std::cout << "binary: " << octalToBinary(input) << std::endl;
            break;
        case 5:
            std::cout << "Enter a Octal number: ";
            std::cin >> input;
            std::cout << "Decimal: " << octalToDecimal(input) << std::endl;
            break;
        case 6:
            std::cout << "Enter a Decimal number: ";
            std::cin >> decimalInt;
            std::cout << "Octal: " << decimalToOctal(decimalInt) << std::endl;
            break;
        case 7:
            std::cout << "Enter a Hex code: ";
            std::cin >> input;
            std::cout << "Decimal: " << hexToDecimal(input) << std::endl;
            break;
        case 8:
            std::cout << "Enter a Octal Number: ";
            std::cin >> input;
            std::cout << "Hex: " << octalToHex(input) << std::endl;
            break;
        case 9:
            std::cout << "Enter a Hex code: ";
            std::cin >> input;
            std::cout << "Octal: " << hexToOctal(input) << std::endl;
            break;
        case 10:
            std::cout << "Enter a Binary Number: ";
            std::cin >> input;
            std::cout << "Hex: " << binaryToHex(input) << std::endl;
            break;
        case 11:
            std::cout << "Enter a Hex Code: ";
            std::cin >> input;
            std::cout << "Binary: " << hexToBinary(input) << std::endl;
            break;
    }
}
