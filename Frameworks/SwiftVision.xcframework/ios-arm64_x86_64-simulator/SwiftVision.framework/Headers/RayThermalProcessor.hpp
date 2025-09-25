//
//  RayThermalProcessor.hpp
//  
//
//  Created by Zheng Liu on 2025-04-30.
//

#ifndef RayThermalProcessor_hpp
#define RayThermalProcessor_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <vector>
#include <map>
#include <cmath>
#include "analysis/Region.h"

#endif /* RayThermalProcessor_hpp */


class RayThermalProcessor {
public:
    
    // Member variables
    std::vector<double> pixelTemp;
    int thermalSonsorWidth;
    int thermalSonsorHeight;
    int thermalImageWidth;
    int thermalImageHeight;
    cv::Point referencePoint;
    float referenceTemp;
    cv::Mat thermalRaw;
    cv::Mat thermalGray;
    cv::Mat thermalJetMap;
    cv::Mat colorImage;
    cv::Mat thermalDifferencial;
    cv::Mat registeredThermalJetMap;
    cv::Mat registeredThermalDifferencial;

    RayThermalProcessor();
    // Unified constructor with default NULL/zero values
    RayThermalProcessor(const std::vector<double>& pixelTemp,
                    int sensorWidth,
                    int sensorHeight,
                    int imageWidth = 600,
                    int imageHeight = 800,
                    const cv::Mat& colorImg = cv::Mat());   // Default empty matrix
                   
    void getTempAt(const std::vector<double>& pixelTemp, const cv::Point& point, float& tempAt, int radius = 3);
    void getThermalDifferencial(const std::vector<double>& pixelTemp, float& referenceTemp, cv::Mat& diffImage);
    void getThermalDifferencial(const std::vector<double>& pixelTemp,const cv::Point& point, float& tempAt, cv::Mat& diffImage);
    void getAvgTempOfWoundBed(cv::Mat& thermalImage, Region &region, float& avgTemp);
    void rotate90(cv::Mat& img, int rotateAngle);



    // Member functions to access results
//    cv::Mat getColormappedThermal() const;
//    cv::Mat getGradientThermal() const;
//    cv::Mat getRegisteredImage() const;

private:
    void generateThermalImage();
//    void calculateGradient();
    void registerWithColor(cv::Mat& colorImage, cv::Mat& termalImage, cv::Mat& registeredImage);
    // Get temperature at specific point
    void calculateTemperatureAt(const std::vector<double>& pixelTemp, const cv::Point& point, float& outputTemp, int radius = 3);
    void generateThermalDifferencial(const std::vector<double>& pixelTemp,float& referenceTemp, cv::Mat& outputDiff);
    void calculateAvgTempOfWoundBed(cv::Mat& thermalImage, Region &region, float& avgTemp);

    
 
};

