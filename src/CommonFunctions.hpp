#pragma once
#include <opencv2/opencv.hpp>
#include <memory>
#include "definitions.hpp"
namespace puzzled
{
class CommonFunctions
{
   public:
      void DisplayImage(const cv::Mat& aImg);
      cv::Mat LoadImage(std::string& aFileName);
      void CropImage(cv::Mat& aImg, cv::Rect aRoi);
      void RotateImageCCW90(cv::Mat& aImg);
   private:

};
} //namespace puzzled