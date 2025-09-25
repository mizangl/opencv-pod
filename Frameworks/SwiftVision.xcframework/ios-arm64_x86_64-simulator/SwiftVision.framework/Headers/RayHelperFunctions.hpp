//
//  RayHelperFunctions.hpp
//  
//
//  Created by Zheng Liu on 2025-05-30.
//


#include <opencv2/opencv.hpp>
#include <vector>
#include <cmath>
#include <stdio.h>

struct CircleParams {
    int centerX;
    int centerY;
    int radius;
    int diameter;
    bool isValid() const {
        return radius > 0; // Or: `centerX != -1 && centerY != -1`
    }
};

double rayGetCameraDistance(float fov, float  height);
// getThermalROI function
std::vector<float> rayGetThermalROI(float distance, int width, int height, float vfov);
double rayGetHeightOfImageInCm(float heightPixels, float radiusPixels);
CircleParams rayFindCirclesRingedInImage(const cv::Mat& inputImage);

// Helper function to calculate average intensity of an image
double rayCalculateAverageIntensity(const cv::Mat& image) ;
// Shift image by dx, dy pixels
cv::Mat rayShiftImage(const cv::Mat& image, int dx, int dy);

// Combine RGB channels
cv::Mat rayCombineChannels(const cv::Mat& red, const cv::Mat& green, const cv::Mat& blue);
// Subtract ambient image
cv::Mat raySubtractImages(const cv::Mat& image, const cv::Mat& ambient);
// Apply Gaussian blur
cv::Mat rayBlurImage(const cv::Mat& image, int sigmaX, int sigmaY);
// Rotate image by specified degrees
cv::Mat rayRotateImage(const cv::Mat& image, double degrees) ;
// Create circular mask
cv::Mat rayCreateCircleMask(const cv::Mat& image, int x, int y, int radius);
// Crop image
cv::Mat rayCropImage(const cv::Mat& image, int x, int y, int width, int height) ;
// Calculate average pixel value
cv::Scalar averagePixels(const cv::Mat& image) ;
// Check if image is overexposed
bool rayIsOverLit(const cv::Mat& image, float threshold);
// Check if channels are properly lit
bool rayCheckChannelsLit(const std::vector<cv::Mat>& images);

// Add color bar to image
cv::Mat rayAddColorBar(const cv::Mat& image, const cv::Mat& colorBar);
cv::Mat rayDrawText(const std::string& text, const cv::Mat& image, const cv::Point& point);

 // Resize image
cv::Mat resizeImage(const cv::Mat& originalImage, const cv::Size& size) ;

// Helper function for angle calculation
double rayAngle(cv::Point pt1, cv::Point pt2, cv::Point pt0);

// Skin masking
cv::Mat rayMaskSkin(const cv::Mat& img);

 // Detect erythema (redness)
cv::Mat rayDetectErythema(const cv::Mat& image, float zScore);

 // Calculate average temperature in region
float rayCalculateAvgTemp(const cv::Mat& thermalImage, const std::vector<cv::Point>& region);

 // Get single channel from image
cv::Mat rayGetChannel(const cv::Mat& image, int channel);

// Rotate image by 90 degree increments
void rayRotate90(cv::Mat& img, int rotateAngle);


