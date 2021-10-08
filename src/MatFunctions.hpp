#pragma once
#include <opencv2/opencv.hpp>
#include <memory>
#include "definitions.hpp"
namespace puzzled
{
class MatFunctions
{
   public:
      // Display an image in a generic named window
      void DisplayImage(const cv::Mat& aImg, const std::string aWindowName, const int aWidth, const int aHeight);
      // Returns a cv::Mat from a path to an image file
      cv::Mat LoadImage(const std::string& aFileName);
      // Crop an image given input cv::Mat and region of interest. Pass by reference
      void CropImage(cv::Mat& aImg, const cv::Rect& aRoi);
      // Rotate a matrix counter clockwise
      void RotateImageCCW(std::unique_ptr<cv::Mat> aImg, const std::unique_ptr<cv::Mat> aRotationMatrix);
      // Get a 90 degree rotation matrix to pass to RotateImageCCW
      const std::unique_ptr<cv::Mat> GetRotationMatrix90(const cv::Mat& aImg);
   private:

};
} //namespace puzzled