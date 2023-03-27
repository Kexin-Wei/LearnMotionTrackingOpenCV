#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main() {
    // Read an image
    cv::Mat input_image = cv::imread("../index.jpg", cv::IMREAD_COLOR);
    if (input_image.empty()) {
        std::cerr << "Error: Could not read the image." << std::endl;
        return 1;
    }

    // Convert the image to grayscale
    cv::Mat gray_image;
    cv::cvtColor(input_image, gray_image, cv::COLOR_BGR2GRAY);

    // Save the grayscale image
    cv::imwrite("gray_image.jpg", gray_image);

    // Display the input and grayscale images
    cv::imwrite("Input Image.jpg", input_image);
    cv::imwrite("Grayscale Image.jpg", gray_image);

    // Wait for a key press and close the windows
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
