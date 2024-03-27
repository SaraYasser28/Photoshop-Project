/*FCAI - Structured Programming - 2024 - Assignment 2
Program Name: CS112_A3_Part1_7-8_20230168_20230094_20230792.cpp
Program Description: This program includes 5 different filters
with loading image (has to be in the same path) and option to save the image.
Last Modification Date: 27/3/2024
Author 1 and ID and Group: Sara Yasser Ahmed Meshrif - 20230168 - S7
Author 2 and ID and Group: Omar Nour Al-Deen Al-Masri - 20230792 - S8
Author 3 and ID and Group: Bassant Ahmed Talaat Mohammed - 20230094 - S7
Teaching Assistant: Belal Tarek Hassan
Who did what: Sara Yasser did black and white filter - Bassant Ahmed did gray scale filter -
Omar Nour did invert filter - Sara Yasser did flip image filter - bassant ahmed did merge images filter
Sara Yasser did the base of the code and made doesFileExist and handleExtensionError functions*/


#include <iostream>
#include "Image_Class.h"
#include <fstream>
#include <string>
#include <limits>
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

int main() {
    string filename , filename2;
    Image image;
    bool imageLoaded = false; // Flag to track if an image is loaded

    // Menu
    while (true) {
        cout << "\nMenu:\n";
        cout << "\n1) Load a new image\n2) Filter 1: Gray Scale Conversion\n3) Filter 2: Black And White\n4) Filter 3: Invert Image";
        cout << "\n5) Filter 4: Merge Images\n6) Filter 5: Flip Image\n7) Save Image\n8)Exit\n";
        cout << "\nEnter your choice: ";

        int choice;
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            while (true) {
                cout << "\nPlease enter the name of the colored image file with extension: ";
                cin >> filename;

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
        }  else if (choice == 7) {
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
                            cin >> filename;
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
        } else if (choice == 8) {
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
