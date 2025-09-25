#ifndef BACTERIAL_PROCESSOR_HPP
#define BACTERIAL_PROCESSOR_HPP

#include <opencv2/opencv.hpp>
#include <vector>

class RayBacterialProcessor {
public:
    
    int ambientImageIndex;
    float lowestAmbientIntensity;
    
    int FluoroImageIndex;
    float highestFluoroIntensity;
    
    float bacterailEnhanceScale;
    cv::Mat bacterialImage;
    
    // Constructor ensures initialization
    RayBacterialProcessor();
    // Process images and return results by reference to avoid copies
    void process(const std::vector<cv::Mat>& images);
    void getBestIntensityImages(const std::vector<cv::Mat>& images,
                                std::vector<cv::Mat>& selectedImages,
                                int count);
    void getFluorescence(const cv::Mat& fluo, const cv::Mat& amb, cv::Mat& bacterial);

private:
    // Helper functions
    void selectBestIntensityImages(const std::vector<cv::Mat>& images,
                                 std::vector<cv::Mat>& selectedImages,
                                 int count);
    void produceFluorescence(const cv::Mat& fluo, const cv::Mat& amb, cv::Mat& bacterial);
    // In-place rotation to avoid temporary copies
    void rotate90(cv::Mat& image);
};
#endif // BACTERIAL_PROCESSOR_HPP

