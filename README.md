Grayscale Image Converter
Grayscale Image Converter is a C++ application that reads a BMP image file, converts it to grayscale by processing its pixel data, and saves the output as a new BMP file.

Features
Reads BMP image files.
Converts the image to grayscale using the average of RGB values.
Saves the converted image in BMP format.
Lightweight and efficient implementation using standard C++ libraries.
How It Works
Input: The program reads the input BMP file and extracts its headers and pixel data.
Processing: Each pixel's RGB values are averaged to calculate a grayscale value, which is then applied to all three RGB channels.
Output: The modified pixel data is written back to a new BMP file while preserving the original headers.
File Structure
less
Copy code
GrayscaleImageConverter/  
├── BitmapHandler.h      // Header file for the BitmapHandler class  
├── BitmapHandler.cpp    // Implementation of BMP file handling and processing  
├── main.cpp             // Main program entry point  
How to Compile and Run
Prerequisites:

A C++ compiler (e.g., GCC, Clang, or MSVC).
Basic knowledge of working with the command line.
Compile:
Use the following command to compile the project:

bash
Copy code
g++ -o GrayscaleConverter main.cpp BitmapHandler.cpp  
Run:
Execute the program with:

bash
Copy code
./GrayscaleConverter  
Follow Prompts:

Enter the path to the BMP file you want to convert.
Enter the path where you want to save the grayscale image.
Example Usage
bash
Copy code
Enter the path to the input BMP file: input_image.bmp  
Enter the path to save the output BMP file: output_image.bmp  
Grayscale image saved successfully to output_image.bmp  
Future Enhancements
Support for additional image formats (e.g., PNG, JPG).
Add a graphical user interface (GUI).
Implement advanced image filters (e.g., sepia, edge detection).
Contributions
Feel free to open issues or submit pull requests to improve the project. Contributions are welcome!

License
This project is licensed under the MIT License.
