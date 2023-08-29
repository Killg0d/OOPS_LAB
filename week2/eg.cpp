#include <iostream>

int countOnes(int num) {
    int count = 0;
    while (num > 0) {
        if (num % 2 == 1) {
            count++;
        }
        num /= 2;
    }
    return count;
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    std::cout << "The first " << n << " decimal numbers whose binary equivalent "
              << "contains an even number of ones are:\n";

    int i = 1;
    while (n > 0) {
        if (countOnes(i) % 2 == 0) {
            std::cout << i << " (Binary: ";
            
            int binary[32];
            int j = 0;
            int num = i;
            while (num > 0) {
                binary[j] = num % 2;
                num /= 2;
                j++;
            }
            
            for (int k = j - 1; k >= 0; k--) {
                std::cout << binary[k];
            }
            
            std::cout << ")\n";
            
            n--;
        }
        
        i++;
    }

    return 0;
}
