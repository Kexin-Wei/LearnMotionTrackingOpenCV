#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/video/tracking.hpp>

void copliotTest(cv::Mat image1, cv::Mat image2){
    // calculate the optical flow of two images
    // and display the optical flow in the first image
    cv::Mat flow;
    cv::calcOpticalFlowFarneback(image1, image2, flow, 0.5, 3, 15, 3, 5, 1.2, 0);
    cv::Mat flow_parts[2];
    cv::split(flow, flow_parts);
    cv::Mat magnitude, angle, magn_norm;
    cv::cartToPolar(flow_parts[0], flow_parts[1], magnitude, angle, true);
    cv::normalize(magnitude, magn_norm, 0.0f, 1.0f, cv::NORM_MINMAX);
    angle *= ((1.f / 360.f) * (180.f / 255.f));

    //display the optical flow in arrow form    
    cv::Mat _hsv[3], hsv, hsv8, bgr;
    _hsv[0] = angle;
    _hsv[1] = cv::Mat::ones(angle.size(), CV_32F);
    _hsv[2] = magn_norm;
    cv::merge(_hsv, 3, hsv);
    hsv.convertTo(hsv8, CV_8U, 255.0);
    cv::cvtColor(hsv8, bgr, cv::COLOR_HSV2BGR);
    cv::imwrite("flow_copliot.jpg", bgr);
}

void openaiTest(cv::Mat image1, cv::Mat image2){
    // calculate the optical flow of two images
    cv::Mat flow;
    cv::calcOpticalFlowFarneback(image1, image2, flow, 0.5, 3, 15, 3, 5, 1.2, 0);

    cv::Mat flow_color;
    cv::cvtColor(image1, flow_color, cv::COLOR_GRAY2BGR);

    for (int y = 0; y < flow_color.rows; y += 10) {
        for (int x = 0; x < flow_color.cols; x += 10) {
            cv::Point2f flow_at_point = flow.at<cv::Point2f>(y, x);
            cv::line(flow_color, cv::Point(x, y), cv::Point(x + flow_at_point.x, y + flow_at_point.y), cv::Scalar(0, 0, 255));
            cv::circle(flow_color, cv::Point(x, y), 1, cv::Scalar(0, 255, 0), -1);
        }
    }
    cv::imwrite("flow_openaiGPT4.jpg", flow_color);
}

// write a main function
int main(int argc, char** argv)
{
    // read the  two images
    // cv::Mat image1 = cv::imread("../pic_kidney_motion/fixed_case1.dcm.png");
    // cv::Mat image2 = cv::imread("../pic_kidney_motion/moving_case1.dcm.png");
    cv::Mat image1 = cv::imread("../pic_basketball/basketball1.png");
    cv::Mat image2 = cv::imread("../pic_basketball/basketball2.png");

    // check if the images are empty
    if (image1.empty() || image2.empty())
    {
        std::cout << "Could not read the image: " << std::endl;
        return 1;
    }
    // convert the images to grayscale
    cv::cvtColor(image1, image1, cv::COLOR_BGR2GRAY);
    cv::cvtColor(image2, image2, cv::COLOR_BGR2GRAY);

    copliotTest(image1,image2);
    openaiTest(image1,image2);

    // wait for the key to be pressed
    cv::waitKey();
    return 0;
}
