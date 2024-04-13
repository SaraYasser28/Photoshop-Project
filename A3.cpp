/*FCAI - Structured Programming - 2024 - Assignment 2
Program Name: CS112_A3_Part1_7-8_20230168_20230094_20230792.cpp
Program Description: This program includes 5 different filters
with loading image (has to be in the same path) and option to save the image.
Last Modification Date: 13/4/2024
Author 1 and ID and Group: Sara Yasser Ahmed Meshrif - 20230168 - S7
Author 2 and ID and Group: Omar Nour Al-Deen Al-Masri - 20230792 - S8
Author 3 and ID and Group: Bassant Ahmed Talaat Mohammed - 20230094 - S7
Teaching Assistant: Belal Tarek Hassan
Who did what: Sara Yasser did black and white filter  -
Omar Nour did invert filter - Sara Yasser did flip image filter -
Sara Yasser did the base of the code and made doesFileExist and handleExtensionError functions
Sara Yasser did Resize Image filter - Sara Yasser did Crop Image filter - Sara Yasser did sunlight effect filter
Bassant Ahmed did : gray scale filter - merge images filter - Darken and Lighten Image - Detect Image Edges - Wano villagers TV image


GitHub Link: https://github.com/SaraYasser28/Assignment-3*/


#include <iostream>
#include "Image_Class.h"
#include <fstream>
#include <string>
#include <limits>
#include <cctype>
#include <string>
using namespace std;

// Function prototypes
bool doesFileExist(const string& filename);
bool handleExtensionError(string& filename);
void flipHorizontal(unsigned char* imageData, int width, int height, int channels);
void flipVertical(unsigned char* imageData, int width, int height, int channels);
void blackAndWhite(Image& image);
void invert(Image& image);
void GrayscaleConversion(Image& image);
void MergeImages(Image& image ,Image& image2);
void resizeImage(unsigned char* &imageData, int &width, int &height, int channels, int newWidth, int newHeight);
void cropImage(Image& image, int startX, int startY, int cropWidth, int cropHeight);
bool isValidInput(const string& input);
void adjustSunlight(Image& image);
void adjustLightness(Image& image, float factor);
void TVImage(Image& image);
 
int main() {
    string filename, filename2;
    Image image;
    bool imageLoaded = false; // Flag to track if an image is loaded

    // Menu
    while (true) {
        cout << "\nMenu:\n";
        cout << "\n1) Load a new image\n2) Filter 1: Gray Scale Conversion\n3) Filter 2: Black And White\n4) Filter 3: Invert Image";
        cout << "\n5) Filter 4: Merge Images\n6) Filter 5: Flip Image\n7) Filter 6: \n8) Filter 7: Darken and Lighten Image ";
        cout << "\n9) Filter 8: Resize Image\n10) Filter 9: \n11) Filter 10: Detect Image Edges \n12) Filter 11: Crop Image";
        cout << "\n13) Filter 12: \n14) Filter 13: Sunlight Effect\n15) Filter 14: \n16) Filter 15: Wano villagers TV image";
        cout << "\n17) Save Image\n18)Exit\n\nEnter your choice: ";

        int choice;
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            while (true) {
                cout << "\nPlease enter the name of the colored image file with extension: ";
                getline(cin, filename);

                if (!handleExtensionError(filename)) {
                    continue;
                }

                if (!doesFileExist(filename)) {
                    cout << "\n**File '" << filename << "' does not exist. Please enter a valid filename**\n";
                } else {
                    image.loadNewImage(filename);
                    cout << "\nImage loaded successfully!!\n";
                    imageLoaded = true; // Set flag to true indicating image is loaded
                    break;
                }
            }

        } else if (choice == 2) {
            if (!imageLoaded) {
                cout << "\n**Please load an image first**\n";
            } else {
                GrayscaleConversion(image);
                cout << "\nGray Scale filter applied!!\n";
            }

        } else if (choice == 3) {
            // Black and white filter option
            if (!imageLoaded) {
                cout << "\n**Please load an image first**\n";
            } else {
                blackAndWhite(image);
                cout << "\nBlack and white filter applied!!\n";
            }

        } else if (choice == 4) {
            // Invert Filter option
            if (!imageLoaded) {
                cout << "\n**Please load an image first**\n";
            } else {
                invert(image);
                cout << "\ninvert filter applied!!\n";
            }

         } else if (choice == 5) {
            // Merge Images Filter option
            Image image2;
            if (!imageLoaded) {
                cout << "\n**Please load an image first**\n";
            }else{
                while (true) {
                    cout << "\nPlease enter the name of the colored image_2 file with extension: ";
                    cin >> filename2;

                    if (!handleExtensionError(filename2)) {
                        continue;
                    }

                    if (!doesFileExist(filename2)) {
                        cout << "\n**File '" << filename2 << "' does not exist. Please enter a valid filename**\n";
                    } else {
                        image2.loadNewImage(filename2);
                        cout << "\nImage loaded successfully!!\n";
                        imageLoaded = true; // Set flag to true indicating image is loaded
                        break;
                    }
                }

                if (!imageLoaded) {
                    cout << "\n**Please load an image first**\n";
                } else {
                    MergeImages(image , image2);
                    cout << "\nMerge Images filter applied!!\n";
                }
            }

        } else if (choice == 6) {
            // Flip option
            if (!imageLoaded) {
                cout << "\n**Please load an image first**\n";
            } else {
                while(true){
                    cout << "\nFlip options:\n";
                    cout << "\n1) Flip Horizontal\n";
                    cout << "2) Flip Vertical\n";
                    cout << "\nEnter your choice: ";
                    int flipChoice;
                    cin >> flipChoice;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (flipChoice == 1) {
                        flipHorizontal(image.imageData, image.width, image.height, image.channels);
                        cout << "\nImage flipped horizontally!!\n";
                        break;
                    } else if (flipChoice == 2) {
                        flipVertical(image.imageData, image.width, image.height, image.channels);
                        cout << "\nImage flipped vertically!!\n";
                        break;
                    } else {
                        cout << "\n**Invalid choice. Please enter '1' or '2'**\n";
                    }
                }
            }
        } else if (choice == 8){
            // adjustLightness (Darken and Lighten Image)
            if (!imageLoaded) {
                cout << "\n**Please load an image first**\n";
            } else {
                while(true){
                    int lighten;
                    cout << "1)Darken\n2)Lighten\n";
                    cout << "enter your choice: ";
                    cin >> lighten;
                    if (lighten == 1){
                        adjustLightness(image, 0.5);
                    }else if(lighten == 2){
                        adjustLightness(image, 1.5);
                    }else{
                        cout << "\n**This is not valid**\n";
                        continue;
                    }
                    cout << "\nAdjust Lightness Image filter applied!!\n";
                    break;
                }
            }
        } else if (choice == 9){
            // Resize Image option
            if (!imageLoaded) {
                cout << "\n**Please load an image first**\n";
            } else {
                unsigned char *imageData;
                int newWidth, newHeight, width, height, channels;
                string input;

                // Get new width
                do {
                    cout << "Enter the new width for resizing: ";
                    cin >> input;
                } while (!isValidInput(input) || stoi(input) <= 0);

                newWidth = stoi(input);

                // Get new height
                do {
                    cout << "Enter the new height for resizing: ";
                    cin >> input;
                } while (!isValidInput(input) || stoi(input) <= 0);

                newHeight = stoi(input);
                resizeImage(image.imageData, image.width, image.height, image.channels, newWidth, newHeight);
                cout << "\nResize Image filter applied!!\n";
            }

        }else if (choice == 12){
            if (!imageLoaded) {
                cout << "\n**Please load an image first**\n";
            } else {
                int startX, startY, cropWidth, cropHeight;
                cout << "Enter the starting X coordinate for cropping: ";
                cin >> startX;
                cout << "Enter the starting Y coordinate for cropping: ";
                cin >> startY;
                cout << "Enter the width for cropping: ";
                cin >> cropWidth;
                cout << "Enter the height for cropping: ";
                cin >> cropHeight;

                if (startX < 0 || startY < 0 || cropWidth <= 0 || cropHeight <= 0 ||
                    startX + cropWidth > image.width || startY + cropHeight > image.height) {
                    cout << "Invalid cropping dimensions or starting point. Please ensure cropping area is within the bounds of the original image." << endl;
                }

                cropImage(image, startX, startY, cropWidth, cropHeight);
                cout << "\nCrop Image filter applied!!\n";
            }

        }else if (choice == 14){
            if (!imageLoaded) {
                cout << "\n**Please load an image first**\n";
            } else {
                adjustSunlight(image);
                cout << "\nSunlight effect filter applied!!\n";
            }
        }else if (choice == 16) {
            // TV image
            if (!imageLoaded) {
                cout << "\n**Please load an image first**\n";
            } else {
                TVImage(image);
                cout << "\nTV Image effect filter applied!!\n";
            }
        }else if (choice == 17) {
            // Save image option
            if (!imageLoaded) {
                cout << "\n**Please load an image first**\n";
            } else {
                while(true){
                    int saveOption;
                    cout << "\n1) Save as " << filename << "\n2) Save as a new file\n";
                    cout << "\nEnter your choice: ";
                    cin >> saveOption;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (saveOption == 1) {
                        image.saveImage(filename);
                        cout << "\nImage saved as " << filename << "!!\n";
                        break;
                    } else if (saveOption == 2) {
                        while(true) {
                            cout << "\nEnter the new image name: ";
                            getline(cin, filename);
                            if (!handleExtensionError(filename)) {
                                continue;
                            }
                            // Save the image
                            image.saveImage(filename);
                            cout << "\nImage saved as " << filename << "!!\n";
                            break;
                        }
                        break;
                    } else {
                        cout << "\n**Invalid choice. Please enter '1' or '2'**\n";
                    }
                }
            }
        } else if (choice == 18) {
            cout << "\nExiting program ...\n";
            return 0;
        } else {
            cout << "\n**Invalid choice. Please enter a valid option**\n";
        }
    }

    return 0;
}

// checks for file existence
bool doesFileExist(const string& filename) {
    ifstream file(filename);
    return file.good();
}

bool handleExtensionError(string& filename) {
    // Check if the filename has an extension
    size_t dotPosition = filename.find_last_of(".");
    if (dotPosition == string::npos) {
        cout << "\n**File extension not found. Please include the file extension (e.g., .png, .jpg) in the filename**\n";
        return false;
    }
    string extension = filename.substr(dotPosition);
    // Check if the extension is supported
    if (extension != ".jpg" && extension != ".jpeg" && extension != ".bmp" && extension != ".png" && extension != ".tga") {
        cout << "\n**Unsupported file extension. Please use .jpg, .jpeg, .bmp, .png or .tga**\n";
        return false;
    }
    return true;
}


// Function to apply the gray scale filter to the image
void GrayscaleConversion(Image& image){
    // Iterate over each pixel in the image
    for (int i = 0; i < image.width; i++){
        for (int k = 0; k < image.height; k++){
            unsigned int average = 0;
            for (int j = 0; j < image.channels; j++){
                average += image(i,k,j);
            }
            // Get average (RGB channels) values for each pixel
            for (int j = 0; j < image.channels; j++){
                image(i,k,j) = average/3;
            }
        }
    }
}

// Function to apply the black and white filter to the image
void blackAndWhite(Image& image) {
    // Iterate over each pixel in the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Iterate over each color channel (RGB channels)
            for(int k = 0; k < 3; ++k){
                // If the pixel value is greater than 127, set it to white (255)
                if(image(i, j, k) > 127){
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 255;
                }
                    // Otherwise, set it to black (0)
                else{
                    image(i, j, 0) = 0;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 0;
                }
            }
        }
    }
}

// Function to apply the invert filter to the image
void invert(Image& image) {
    // Iterate over each pixel in the image
    for(int i = 0; i < image.width; ++i) {
        for(int j = 0; j < image.height; ++j) {
            // Iterate over each color channel (RGB channels)
            for(int k = 0; k < 3; ++k) {
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }
}

// Function to merge two images together
void MergeImages(Image& image ,Image& image2){
    int MinWidth = min(image.width, image2.width);
    int Minheight = min(image.height, image2.height);
    Image Merge(MinWidth,Minheight);

    for(int i = 0; i < Merge.width; i++){
        for(int j = 0; j < Merge.height; j++){
            for(int k = 0; k < Merge.channels; k++){
                image(i,j,k) = (image(i,j,k) + image2(i,j,k)) /2;
            }
        }
    }
}


// Function to flip the image horizontally
void flipHorizontal(unsigned char* imageData, int width, int height, int channels) {
    unsigned char temp;
    // Iterate over each row of the image
    for (int row = 0; row < height; ++row) {
        // Iterate over each column up to the middle of the image width
        for (int column = 0; column < width / 2; ++column) {
            // Swap corresponding pixels from left and right sides of the image
            for (int c = 0; c < channels; ++c) {
                temp = imageData[(row * width + column) * channels + c];
                imageData[(row * width + column) * channels + c] = imageData[(row * width + (width - 1 - column)) * channels + c];
                imageData[(row * width + (width - 1 - column)) * channels + c] = temp;
            }
        }
    }
}

// Function to flip the image vertically
void flipVertical(unsigned char* imageData, int width, int height, int channels) {
    unsigned char temp;
    // Iterate over each row up to the middle of the image height
    for (int row = 0; row < height / 2; ++row) {
        // Iterate over each column of the image
        for (int column = 0; column < width; ++column) {
            // Swap corresponding pixels from top and bottom sides of the image
            for (int c = 0; c < channels; ++c) {
                temp = imageData[(row * width + column) * channels + c];
                imageData[(row * width + column) * channels + c] = imageData[((height - 1 - row) * width + column) * channels + c];
                imageData[((height - 1 - row) * width + column) * channels + c] = temp;
            }
        }
    }
}
void adjustLightness(Image& image, float factor) {
    // Iterate over each pixel in the image
    for (int i = 0; i < image.width; i++) {
        for (int k = 0; k < image.height; k++) {
            for (int j = 0; j < image.channels; j++) {
                // Get the original pixel value
                unsigned char& pixelValue = image(i, k, j);

                // Adjust the pixel value based on the factor
                pixelValue = (unsigned char) min(255, max(0, (int)(pixelValue * factor)));
            }
        }
    }
}
void resizeImage(unsigned char* &imageData, int &width, int &height, int channels, int newWidth, int newHeight) {
    // Allocate memory for the resized image data
    unsigned char* resizedImageData = new unsigned char[newWidth * newHeight * channels];

    // Calculate scaling factors
    float scaleX = (float)width / newWidth;
    float scaleY = (float)height / newHeight;

    for (int y = 0; y < newHeight; ++y) {
        for (int x = 0; x < newWidth; ++x) {
            for (int c = 0; c < channels; ++c) {
                int sourceX = (int)(x * scaleX);
                int sourceY = (int)(y * scaleY);
                // Clamp to the original image boundaries
                sourceX = min(max(sourceX, 0), width - 1);
                sourceY = min(max(sourceY, 0), height - 1);
                // Copy pixel value from the original image to the resized image
                resizedImageData[(y * newWidth + x) * channels + c] = imageData[(sourceY * width + sourceX) * channels + c];
            }
        }
    }
    // Free the memory allocated for the original image data
    delete[] imageData;

    // Update the image properties with the new dimensions and data
    width = newWidth;
    height = newHeight;
    imageData = resizedImageData;
}


void cropImage(Image& image, int startX, int startY, int cropWidth, int cropHeight) {
    unsigned char* croppedImageData = new unsigned char[cropWidth * cropHeight * image.channels];

    for (int y = 0; y < cropHeight; ++y) {
        for (int x = 0; x < cropWidth; ++x) {
            for (int c = 0; c < image.channels; ++c) {
                croppedImageData[(y * cropWidth + x) * image.channels + c] =
                    image.imageData[((startY + y) * image.width + startX + x) * image.channels + c];
            }
        }
    }

    delete[] image.imageData;

    image.width = cropWidth;
    image.height = cropHeight;
    image.imageData = croppedImageData;
}


bool isValidInput(const string& input) {
    // Check if input is a positive integer
    for (char c : input) {
        if (!isdigit(c)) {
            cout << "**Please enter a valid positive number**" << endl;
            return false;
        }
    }
    return true;
}

void adjustSunlight(Image& image) {
    // Iterate over each pixel in the image
    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            // Iterate over each color channel (RGB channels)
            for (int c = 0; c < image.channels; ++c) {
                // Adjust pixel value for warm sunlight effect
                int newValue = image(x, y, c);

                // Apply different adjustments to different channels
                if (c == 0 || c == 1) { // Red and Green channels
                    newValue += 40; // Increase red and green for warm sunlight effect
                } else if (c == 2) { // Blue channel
                    newValue -= 25; // Decrease blue for warm sunlight effect
                }

                // Ensure the pixel value remains within the range [0, 255]
                newValue = max(0, min(255, newValue));

                // Update the pixel value
                image(x, y, c) = newValue;
            }
        }
    }

}
void TVImage(Image& image) {
    // i make a pixel gray and next pixel normal with colored //the same with all pixel
    for(int i = 0; i < image.width; i++){
        for(int j = 0; j < image.height; j++){
            for(int k = 0; k < image.channels; k++){
                image(i,j,k) = 124/2;
            }
            j++; 
        }
        i++;
    }
}
