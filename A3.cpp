#include <iostream>
#include "Image_Class.h"
#include <fstream>
#include <string>
using namespace std;

// Function prototypes
bool fileExists(const string& filename);
void flipHorizontal(unsigned char* imageData, int width, int height, int channels);
void flipVertical(unsigned char* imageData, int width, int height, int channels);
void blackAndWhite(Image& image);

int main() {
    string filename;
    Image image;
    bool imageLoaded = false;

    // Menu loop
    while (true) {
        cout << "\nMenu:\n";
        cout << "\n1) Load Image\n2) Flip Image\n3) Apply Black and White Filter\n4) Save Image\n5) Exit\n";
        cout << "\nEnter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                while (true) {
                    cout << "\nPlease enter the name of the colored image file with extension: ";
                    cin >> filename;

                    if (!fileExists(filename)) {
                        cout << "\n**File '" << filename << "' does not exist. Please enter a valid filename**\n";
                    } else {
                        image.loadNewImage(filename);
                        cout << "\nImage loaded successfully.\n";
                        imageLoaded = true;
                        break;
                    }
                }
                break;
            }
            case 2: {
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
                if (!imageLoaded) {
                    cout << "\n**Please load an image first**\n";
                    break;
                }

                blackAndWhite(image);
                cout << "\nBlack and white filter applied!!\n";
                break;
            }
            case 4: {
                if (!imageLoaded) {
                    cout << "\n**Please load an image first.**\n";
                    break;
                }

                string saveOption;
                cout << "\n1) Save as " << filename << "\n2) Save as a new file\n";
                cout << "\nEnter your choice: ";
                cin >> saveOption;

                if (saveOption == "1") {
                    image.saveImage(filename);
                    cout << "\nImage saved as " << filename << ".\n";
                } else if (saveOption == "2") {
                    cout << "\nEnter the new image name: ";
                    cin >> filename;
                    image.saveImage(filename);
                    cout << "\nImage saved as " << filename << ".\n";
                } else {
                    cout << "\n**Invalid choice. Please enter '1' or '2'**\n";
                }
                break;
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

// Flip image horizontally
void flipHorizontal(unsigned char* imageData, int width, int height, int channels) {
    unsigned char temp;
    for (int row = 0; row < height; ++row) {
        for (int column = 0; column < width / 2; ++column) {
            for (int c = 0; c < channels; ++c) {
                temp = imageData[(row * width + column) * channels + c];
                imageData[(row * width + column) * channels + c] = imageData[(row * width + (width - 1 - column)) * channels + c];
                imageData[(row * width + (width - 1 - column)) * channels + c] = temp;
            }
        }
    }
}

// Flip image vertically
void flipVertical(unsigned char* imageData, int width, int height, int channels) {
    unsigned char temp;
    for (int row = 0; row < height / 2; ++row) {
        for (int column = 0; column < width; ++column) {
            for (int c = 0; c < channels; ++c) {
                temp = imageData[(row * width + column) * channels + c];
                imageData[(row * width + column) * channels + c] = imageData[((height - 1 - row) * width + column) * channels + c];
                imageData[((height - 1 - row) * width + column) * channels + c] = temp;
            }
        }
    }
}

// Black and white filter
void blackAndWhite(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for(int k = 0; k < 3; ++k){
                if(image(i, j, k) > 127){
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 255;
                }
                else{
                    image(i, j, 0) = 0;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 0;
                }
            }
        }
    }
}
