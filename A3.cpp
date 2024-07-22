/*FCAI - Structured Programming - 2024 - Assignment 3
Program Name: CS112_A3_Part2B_7-8_20230168_20230094_20230792.cpp
Program Description: This program includes 15 different filters
with loading image (has to be in the same path) and option to save the image.
Last Modification Date: 13/4/2024
Author 1 and ID and Group: Sara Yasser Ahmed Meshrif - 20230168 - S7
Author 2 and ID and Group: Omar Nour Al-Deen Al-Masri - 20230792 - S8
Author 3 and ID and Group: Bassant Ahmed Talaat Mohammed - 20230094 - S7
Teaching Assistant: Belal Tarek Hassan
Who did what: Sara Yasser did black and white filter  -
Sara Yasser did the base of the code and made doesFileExist and handleExtensionError functions
Sara Yasser did Resize Image filter - Sara Yasser did Crop Image filter - Sara Yasser did sunlight effect filter - flip image filter
Omar Nour did invert filter - Rotate Applying - Frame Adding - Blur Effect - Purple Conversion
Bassant Ahmed did : gray scale filter - merge images filter - Darken and Lighten Image - Detect Image Edges - Wano villagers TV image


GitHub Link: https://github.com/3omarmasri/babyPhotoshopProject.git*/
// Diagram : https://viewer.diagrams.net/?tags=%7B%7D&highlight=0000ff&edit=_blank&layers=1&nav=1&title=Copy%20of%20Untitled%20Diagram.jpg#R7Z1bc5s4FMc%2FjWd2H9zhjv2YezuT7nTWmXS3LzuqUWy6GLEgYruffoURBqQ4qDbBx8R5SRBCwJ%2BfbkfnKAPzarG6i1E0%2F0w8HAwMzVsNzOuBYRhjx2a%2FspR1nqLrzihPmcW%2Bx9PKhIn%2FE%2FNEjaemvoeTWkZKSED9qJ44JWGIp7SWhuKYLOvZnkhQv2uEZlhKmExRIKd%2B9T06L15D08oTH7E%2Fm%2FNbj2x%2BYoGKzDwhmSOPLCtJ5s3AvIoJoflfi9UVDjL1Cl3y6253nN0%2BWIxDqnLBM9EWk3%2Bcu4%2FRn863e4z8%2B%2BTbkJfyjIKUv%2FDAcAJW3uUTYcUywdA0P%2BH8l2ZPevmA5mSByuPszeg6qGfKLh4mm495wTKwx1xtspYXObPs9wL54W%2B%2FF7dkz57fNT%2FJZdsWbsQkDT2cvY7OTi%2FnPsWTKH%2B%2BJcOPpc3pIuCnUTzlNOnOtrCqWsWr45jiVSWJq3eHyQLTeM2yFGfNguYC5gKCZYWM4nPPK1BYPA1xGGfbssvvxf7gn%2BwXPp8pfb45Cr0A36woDhOfhDesCsSHCZl9kkJJux0lh45WV9J0XlBy1KWSlqSkR3By62da%2BgmFJ6E5VpCwUxhtSULkeX44u0XhdH0bowV%2BIA9z%2FMWf0jTG7SlqtaOoYQmKGi8oanSqqLNLUfhiGlazmPq4SzFdScwYZ13Up0U2BIBWvw3NURCwUxpHkoBs0LdOsrHSFQnZq2UdDjgSh7oKiXaXQo4lIf3kEQW%2B9ymMUnhdjT4aQUOxmB1UJPweoOm%2FF6H3NdMHHIW6Bk5CeeiPvB9pQu%2Bzm4c4SeCB6MJT0ZB7FUIRzXsVw9Wu8SzGGKCWlg2tg9bl2UxFSzYdAKsl6z%2Batex0OqPL85mKlmOwUo5Vuhq3UyXlac1T4EeP7JV8NvRpT8GWrBQjeG3kSBIJezM84YckpnMyIyEKbsrUy1JGjR2Vee4Jibh4PzCla64eSimpS4tXPv0ru%2FyDzY%2F%2Brpy5XvGSNwdrfrBT%2FoSkMbeD7XhHPlWjKJ5hqpAxU%2BDVzxnjAFH%2FuW6GbP3bGPJAKiDI%2BwMvYU6Lhha4saghN7Uy76F3kRmj2VFIQlyXqY460yZeV8DNDrfkZgclupujdQVkmXftjXgvFG7mXRH3yud7aS5WpCnXCn6HL8TfmLE5PpYwF7RcgYr8xflVJRhyQYKtyDKEgnJhpIIYBWhdyRZlGRKJwa0wB2ApzzIPwnIPvPZFeX8sRydJJatNgi1XpEkVS%2FZI9dbRhoalKXc4%2FcdSH58kl5IN19y3tRSw1MVm9%2FhYyvP4d4Cle5JYjnYsfB3cWI7BUSlbRN4BlcpTKVBUijagPmPZ8oxnj5n6Liy1t8NSlUoLFpZNI0JVLO2mMerxsZQtdWcsRTNm37B0xWUMcYx6fCxlL46DsNwTsY7toapYmv3EUvTOksyPx8dS9oc5Yyku6%2FYNS9F6bsNrLWUvozOWguNQ76gUXVk1cFS2bEzvFZU6sIn4m814dGhYFoOKM5a7%2FX17R6VoZwI3D7deCio6U1lz6e8dlUJBJriBpWW8QyqV3TSAGy1FE7gylqaA5Qgcli0v8ZwElqqNZU9tlrawrm6C89KwuvFpO00qi4U9IFg2OlcoY2k3rGAeH8uWV3hOAkvlPhycKf2DVvkRfYlEg7gqpUNpWg4P025WfGB5BOuqmMKyFlkiTftyKW1pAM6IaZ1N668MNWHZ1sVOfW9vIkcsCJy5SJcXIv0smrzFQGj3NYR%2BISZfYYOITiMm7fMw%2FZV8PTW16Y3RAsev0vIA6DNmz7SJKYMXdCpGBR0%2FpqwIGBCCTj%2BS2P%2FJ3h9g2KnYzxxfQ1vW8DtZXQZpDK5jMZX2KOl26yF5aXEak6jlqNCW4Cv3GYSjn7wIdo0pntKNglmkc4vtYFubNrmugoxmpzIakowPjy1D2FYlhrc7iSMvLkRpHL3Nfk0tdcamaN95UUarUxnlYXa%2BVc4kDYPN%2FcGJaILrjp2zv2lzbwFkriJudGqJnk%2FKSwpCQSa4wE%2FnbBRrbvigYCkMT6RNF5SxdKG7BThnh9PmQSEULAWnemvfMHlbjGwGF%2Fnpvplrn9sHLmGtwFqC85MutnL9WUNwZceABD23vbVvS9Nsc1TUazCDc%2Fcco9gMF5BqrUv1eu8gRcneA2547p7Wrt3iSsLWDfp4NbubgSQsXxRXeWMbWGuE23DMQ51R9o2oa6627LD8lzV59vI%2F%2F5g3%2FwM%3D


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
void MergeImages(Image& image ,Image& image2 ,int size);
void resizeImage(unsigned char* &imageData, int &width, int &height, int channels, int newWidth, int newHeight);
void cropImage(Image& image, int startX, int startY, int cropWidth, int cropHeight);
bool isValidInput(const string& input);
void adjustSunlight(Image& image);
void adjustLightness(Image& image, float factor);
void TVImage(Image& image);
void DetectImageEdges(Image& image);
void rotateImage90Degrees(Image& image);
void rotateImage180Degrees(Image& image);
void rotateImage270Degrees(Image& image);
void addingFrameToThePicture(Image& image);
void addingFancyFrameToThePicture(Image& image);
void purpleConversion(Image& image);
void boxBlur(Image& image);

int main() {
    string filename, filename2;
    Image image;
    bool imageLoaded = false; // Flag to track if an image is loaded

    // Menu
    while (true) {
        cout << "\nMenu:\n";
        cout << "\n1) Load a new image\n2) Filter 1: Gray Scale Conversion\n3) Filter 2: Black And White\n4) Filter 3: Invert Image";
        cout << "\n5) Filter 4: Merge Images\n6) Filter 5: Flip Image\n7) Filter 6: Rotate Applying \n8) Filter 7: Darken and Lighten Image ";
        cout << "\n9) Filter 8: Resize Image\n10) Filter 9: Adding Frame To The Picture \n11) Filter 10: Detect Image Edges \n12) Filter 11: Crop Image";
        cout << "\n13) Filter 12: Blur Effect \n14) Filter 13: Sunlight Effect\n15) Filter 14: Purple Conversion \n16) Filter 15: Wano villagers TV image";
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
        }
        else if (choice == 2) {
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
                        cout << "\nImage loaded successfully!!\n\n";
                        imageLoaded = true; // Set flag to true indicating image is loaded
                        break;
                    }
                }
                if (!imageLoaded) {
                    cout << "\n**Please load an image first**\n";
                } else {
                    while(true){
                        int size;
                        cout << "1) merge the common area\n2) resize the smaller image\n";
                        cout << "Enter your choice: ";
                        cin >> size;
                        if (size == 1 || size == 2){
                            MergeImages(image , image2 , size);
                            cout << "\nMerge Images filter applied!!\n";
                        }else{
                            cout << "\n**This is not a valid**\n";
                            continue;
                        }
                        break;
                    }

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
        }
        else if (choice == 7){
            // Rotate Options
            if (!imageLoaded) {
                cout << "\n**Please load an image first**\n";
            }
            else {
                cout << "1. Rotate 90 degrees" << endl;
                cout << "2. Rotate 180 degrees" << endl;
                cout << "3. Rotate 270 degrees" << endl;
                cout << "Enter your choice: ";
                int choice;
                cin >> choice;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                switch (choice) {
                    case 1:
                        rotateImage90Degrees(image);
                        cout << "\nRotate Image applied!!\n";
                        break;
                    case 2:
                        rotateImage180Degrees(image);
                        cout << "\nRotate Image applied!!\n";
                        break;
                    case 3:
                        rotateImage270Degrees(image);
                        cout << "\nRotate Image applied!!\n";
                        break;
                    default:
                        cout << "Invalid choice, Please Try Again" << endl;
                }
            }
        }
        else if (choice == 8){
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
        }
        else if (choice == 10){
            // Adding Frame To The Picture
            if (!imageLoaded) {
                cout << "\n**Please load an image first**\n";
            } else {
                cout << "1. Add a simple frame" << endl;
                cout << "2. Add a fancy frame" << endl;
                cout << "3. Back to Main Menu" << endl;
                cout << "Enter your choice: ";
                int choice;
                cin >> choice;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                switch (choice) {
                    case 1:
                        addingFrameToThePicture(image);
                        cout << "\nFrame added to the picture!!\n";
                        break;
                    case 2:
                        addingFancyFrameToThePicture(image);
                        cout << "\nFrame added to the picture!!\n";
                        break;
                    case 3:
                        main();
                    default:
                        cout << "Invalid choice, Please Try Again" << endl;
                }
            }
        }
        else if (choice == 11){
            // Detect Image Edges
            if (!imageLoaded) {
                cout << "\n**Please load an image first**\n";
            } else {
                DetectImageEdges(image);
                cout << "\nDetect Image Edges filter applied!!\n";
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

        }
        else if (choice == 13){
            // Blur Effect
            if (!imageLoaded) {
                cout << "\n**Please load an image first**\n";
            } else {
                boxBlur(image);
                cout << "\nBlur Effect filter applied!!\n";
            }
        }
        else if (choice == 14){
            if (!imageLoaded) {
                cout << "\n**Please load an image first**\n";
            } else {
                adjustSunlight(image);
                cout << "\nSunlight effect filter applied!!\n";
            }
        }
        else if (choice == 15){
            // purple conversion
            if (!imageLoaded) {
                cout << "\n**Please load an image first**\n";
            } else {
                purpleConversion(image);
                cout << "\nPurple Conversion filter applied!!\n";
            }
        }
        else if (choice == 16) {
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
void MergeImages(Image& image ,Image& image2 ,int size){
    int NewWidth, NewHeight;
    if (size == 1){
        NewWidth = min(image.width, image2.width);
        NewHeight = min(image.height, image2.height);
    }
    if (size == 2){
        NewWidth = max(image.width, image2.width);
        NewHeight = max(image.height, image2.height);
        resizeImage(image.imageData, image.width, image.height, image.channels, NewWidth,NewHeight);
        resizeImage(image2.imageData, image2.width, image2.height, image.channels, NewWidth,NewHeight);
    }

    for(int i = 0; i < image.width; i++){
        for(int j = 0; j < image.height; j++){
            for(int k = 0; k < image.channels; k++){
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
void DetectImageEdges(Image& image) {
    for (int i = 0; i < image.width; i++){
        for (int k = 0; k < image.height; k++){
            unsigned int average = 0;
            unsigned int average2 = 0;
            for (int j = 0; j < image.channels; j++){
                average += image(i , k , j);
                average2 += image(i+1 , k , j);
            }
            if (average - average2 < 80 || average - average2 > -80 ){
                for (int j = 0; j < image.channels; j++){
                    image(i , k , j) = 225;
                }
            }else{
                for (int j = 0; j < image.channels; j++){
                    image(i , k , j) = 0;
                }
            }
        }
    }
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
    // I make a pixel gray and next pixel normal with colored //the same with all pixel
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

void rotateImage90Degrees(Image& image) {
    Image newImage(image.height, image.width); // Create a copy of the image
    for(int i = 0; i < image.width; ++i) {
        for(int j = 0; j < image.height; ++j) {
            for(int k = 0; k < 3; ++k) {
                newImage(image.height - 1 - j, i, k) = image(i, j, k);
            }
        }
    }
    image = newImage;
}

void rotateImage180Degrees(Image& image) {
    Image newImage(image.width, image.height); // Create a copy of the image
    for(int i = 0; i < image.width; ++i) {
        for(int j = 0; j < image.height; ++j) {
            for(int k = 0; k < 3; ++k) {
                newImage(image.width - 1 - i, image.height - 1 - j, k) = image(i, j, k);
            }
        }
    }
    image = newImage;
}

void rotateImage270Degrees(Image& image) {
    Image newImage(image.height, image.width); // Create a copy of the image
    for(int i = 0; i < image.width; ++i) {
        for(int j = 0; j < image.height; ++j) {
            for(int k = 0; k < 3; ++k) {
                newImage(j, image.width - 1 - i, k) = image(i, j, k);
            }
        }
    }
    image = newImage;
}

void addingFrameToThePicture(Image& image) {
    int frameSize = 50;
    // Iterate over each pixel in the image
    for(int i = 0; i < image.width; ++i) {
        for(int j = 0; j < image.height; ++j) {
            // Check if the pixel is in the frame
            if(i < frameSize || i >= image.width - frameSize || j < frameSize || j >= image.height - frameSize) {
                // Set the color of the frame to blue
                image(i, j, 0) = 13;    // Red channel
                image(i, j, 1) = 119;    // Green channel
                image(i, j, 2) = 255;  // Blue channel
            }
        }
    }
}

void addingFancyFrameToThePicture(Image& image) {
    int frameSize = 50;
    // Iterate over each pixel in the image
    for(int i = 0; i < image.width; ++i) {
        for(int j = 0; j < image.height; ++j) {
            // Check if the pixel is in the frame
            if(i < frameSize || i >= image.width - frameSize || j < frameSize || j >= image.height - frameSize) {
                // Set the color of the frame based on the position of the pixel
                image(i, j, 0) = (i + j) % 256;    // Red channel
                image(i, j, 1) = (2 * i + j) % 256;    // Green channel
                image(i, j, 2) = (i + 2 * j) % 256;  // Blue channel
            }
        }
    }
}

void purpleConversion(Image& image){
    // Iterate over each pixel in the image
    for (int i = 0; i < image.width; i++){
        for (int k = 0; k < image.height; k++){
            unsigned int average = 0;
            // Calculate the average of RGB channels
            for (int j = 0; j < image.channels; j++){
                average += image(i,k,j);
            }
            // Set RGB values to create a subtle purple tint
            unsigned int red = image(i,k,0) + average/8; // Add a fraction of average to the red channel
            unsigned int blue = image(i,k,2) + average/8; // Add a fraction of average to the blue channel
            // Ensure that the values do not exceed 255
            image(i,k,0) = red > 255 ? 255 : red;
            image(i,k,1) = image(i,k,1); // Keep the green channel unchanged
            image(i,k,2) = blue > 255 ? 255 : blue;
        }
    }
}

void boxBlur(Image& image) {
    // Create a copy of the image
    Image newImage(image.width, image.height);
    // Define the radius
    int radius = 7;
    // Iterate over each pixel in the image
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            // Iterate over each color channel (RGB channels)
            for (int k = 0; k < 3; k++) {
                // Calculate the average of the pixel and its neighbors
                int sum = 0;
                int count = 0;
                for (int x = -radius; x <= radius; x++) {
                    for (int y = -radius; y <= radius; y++) {
                        if (i + x >= 0 && i + x < image.width && j + y >= 0 && j + y < image.height) {
                            sum += image(i + x, j + y, k);
                            count++;
                        }
                    }
                }
                newImage(i, j, k) = sum / count;
            }
        }
    }
    image = newImage;
}
