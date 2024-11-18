#include "BitmapHandler.h"
#include <iostream>

int main() {
    std::string inputFile, outputFile;

    std::cout << "Enter the path to the input BMP file: ";
    std::cin >> inputFile;

    BitmapHandler bitmap(inputFile);

    if (!bitmap.readBitmap()) {
        return 1;
    }

    bitmap.convertToGrayscale();

    std::cout << "Enter the path to save the output BMP file: ";
    std::cin >> outputFile;

    if (!bitmap.saveBitmap(outputFile)) {
        return 1;
    }

    std::cout << "Grayscale image saved successfully to " << outputFile << std::endl;
    return 0;
}
