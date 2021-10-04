#include "CommonFunctions.hpp"

namespace puzzled
{
void CommonFunctions::DisplayImage(const cv::Mat& aImg)
{
   cv::namedWindow(GENERIC_WINDOW, cv::WINDOW_NORMAL);
   cv::resizeWindow(GENERIC_WINDOW, WIDTH_640, HEIGHT_480);
   cv::imshow(GENERIC_WINDOW, aImg);
   cv::waitKey(0);
}

cv::Mat CommonFunctions::LoadImage(std::string& aFileName)
{
   cv::Mat ret;
   if ((ret = cv::imread(aFileName, 1)).empty())
   {
      throw std::runtime_error("Could not open file: " + aFileName);
   }
   return ret;
}

void CommonFunctions::CropImage(cv::Mat& aImg, cv::Rect aRoi)
{
   cv::Mat cropped(aImg, aRoi);
   aImg = cropped;
}
}