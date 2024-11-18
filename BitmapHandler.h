#ifndef BITMAP_HANDLER_H
#define BITMAP_HANDLER_H

#include <string>
#include <vector>

class BitmapHandler {
public:
    BitmapHandler(const std::string& filePath);
    bool readBitmap();
    void convertToGrayscale();
    bool saveBitmap(const std::string& outputPath);

private:
    std::string filePath;
    std::vector<unsigned char> fileHeader;
    std::vector<unsigned char> infoHeader;
    std::vector<unsigned char> pixelData;

    int width;
    int height;
    int rowPadding;

    void calculatePadding();
};

#endif // BITMAP_HANDLER_H
