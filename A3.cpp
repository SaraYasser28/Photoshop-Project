#include <iostream>
#include "Image_Class.h"
#include <fstream>
#include <string>
#include <limits>
using namespace std;

// Function prototypes
bool fileExists(const string& filename);
void flipHorizontal(unsigned char* imageData, int width, int height, int channels);
void flipVertical(unsigned char* imageData, int width, int height, int channels);
void blackAndWhite(Image& image);

int main() {
    string filename;
    Image image;
    bool imageLoaded = false; // Flag to track if an image is loaded

    // Menu
    while (true) {
        cout << "\nMenu:\n";
        cout << "\n1) Load Image\n2) Flip Image\n3) Apply Black and White Filter\n4) Save Image\n5) Exit\n";
        cout << "\nEnter your choice: ";

        int choice;
        cin >> choice;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                while (true) {
                    cout << "\nPlease enter the name of the colored image file with extension: ";
                    cin >> filename;

                    if (!fileExists(filename)) {
                        cout << "\n**File '" << filename << "' does not exist. Please enter a valid filename**\n";
                    } else {
                        image.loadNewImage(filename);
                        cout << "\nImage loaded successfully!!\n";
                        imageLoaded = true; // Set flag to true indicating image is loaded
                        break;
                    }
                }
                break;
            }
            case 2: {
                // Flip option
                if (!imageLoaded) {
                    cout << "\n**Please load an image first**\n";
                    break;
                }

                cout << "\nFlip options:\n";
                cout << "\n1) Flip Horizontal\n";
                cout << "2) Flip Vertical\n";
                cout << "\nEnter your choice: ";
                int flipChoice;
                cin >> flipChoice;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (flipChoice) {
                    case 1:
                        flipHorizontal(image.imageData, image.width, image.height, image.channels);
                        cout << "\nImage flipped horizontally!!\n";
                        break;
                    case 2:
                        flipVertical(image.imageData, image.width, image.height, image.channels);
                        cout << "\nImage flipped vertically!!\n";
                        break;
                    default:
                        cout << "\n**Invalid choice. Please enter '1' or '2'**\n";
                }
                break;
            }
            case 3: {
                // Black and white filter option
                if (!imageLoaded) {
                    cout << "\n**Please load an image first**\n";
                    break;
                }

                blackAndWhite(image);
                cout << "\nBlack and white filter applied!!\n";
                break;
            }
            case 4: {
                // Save image option
                if (!imageLoaded) {
                    cout << "\n**Please load an image first**\n";
                    break;
                }

                int saveOption;
                cout << "\n1) Save as " << filename << "\n2) Save as a new file\n";
                cout << "\nEnter your choice: ";
                cin >> saveOption;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                switch (saveOption)
                {
                case '1':
                    image.saveImage(filename);
                    cout << "\nImage saved as " << filename << "!!\n";
                case '2':
                    cout << "\nEnter the new image name: ";
                    cin >> filename;
                    image.saveImage(filename);
                    cout << "\nImage saved as " << filename << "!!\n";
                    break;
                default:
                    cout << "\n**Invalid choice. Please enter '1' or '2'**\n";
                    break;
                }
            }
            case 5:
                cout << "\nExiting program ...\n";
                return 0;
            default:
                cout << "\n**Invalid choice. Please enter a valid option**\n";
        }
    }

    return 0;
}

// checks for file existence
bool fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
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
