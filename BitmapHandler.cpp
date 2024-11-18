#include "BitmapHandler.h"
#include <fstream>
#include <iostream>

BitmapHandler::BitmapHandler(const std::string& filePath) : filePath(filePath) {}

bool BitmapHandler::readBitmap() {
    // Open file in binary mode
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Unable to open file " << filePath << std::endl;
        return false;
    }

    // Read headers
    fileHeader.resize(14);
    infoHeader.resize(40);
    file.read(reinterpret_cast<char*>(fileHeader.data()), 14);
    file.read(reinterpret_cast<char*>(infoHeader.data()), 40);

    // Extract width and height
    width = *reinterpret_cast<int*>(&infoHeader[4]);
    height = *reinterpret_cast<int*>(&infoHeader[8]);

    calculatePadding();

    // Read pixel data
    int dataSize = (width * 3 + rowPadding) * height;
    pixelData.resize(dataSize);
    file.read(reinterpret_cast<char*>(pixelData.data()), dataSize);

    file.close();
    return true;
}

void BitmapHandler::convertToGrayscale() {
    for (size_t i = 0; i < pixelData.size(); i += 3) {
        unsigned char gray = static_cast<unsigned char>(
            0.299 * pixelData[i + 2] + 0.587 * pixelData[i + 1] + 0.114 * pixelData[i]
        );
        pixelData[i] = gray;      // Blue
        pixelData[i + 1] = gray;  // Green
        pixelData[i + 2] = gray;  // Red
    }
}

bool BitmapHandler::saveBitmap(const std::string& outputPath) {
    std::ofstream file(outputPath, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Unable to save file " << outputPath << std::endl;
        return false;
    }

    // Write headers and pixel data
    file.write(reinterpret_cast<char*>(fileHeader.data()), fileHeader.size());
    file.write(reinterpret_cast<char*>(infoHeader.data()), infoHeader.size());
    file.write(reinterpret_cast<char*>(pixelData.data()), pixelData.size());

    file.close();
    return true;
}

void BitmapHandler::calculatePadding() {
    rowPadding = (4 - (width * 3) % 4) % 4;
}
