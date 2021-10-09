#include "MatFunctions.hpp"

namespace puzzled
{
void MatFunctions::DisplayImage(const cv::Mat& aImg, const std::string aWindowName, const int aWidth, const int aHeight)
{
   cv::namedWindow(aWindowName, cv::WINDOW_NORMAL);
   cv::resizeWindow(aWindowName, aWidth, aHeight);
   cv::imshow(aWindowName, aImg);
   cv::waitKey(0);
}

std::unique_ptr<cv::Mat> MatFunctions::LoadImage(const std::string& aFileName)
{
   cv::Mat img_in;
   if ((img_in = cv::imread(aFileName, 1)).empty())
   {
      throw std::runtime_error("Could not open file: " + aFileName);
   }
   return std::make_unique<cv::Mat>(img_in);
}

void MatFunctions::CropImage(cv::Mat& aImg, const cv::Rect& aRoi)
{
   cv::Mat cropped(aImg, aRoi);
   aImg = cropped;
}

void MatFunctions::RotateImageCCW(std::unique_ptr<cv::Mat>& aImg, const std::unique_ptr<cv::Mat>& aRotationMatrix)
{
   cv::warpAffine(*aImg, *aImg, *aRotationMatrix, aImg->size());
}

std::unique_ptr<cv::Mat> MatFunctions::GetRotationMatrix90(const std::unique_ptr<cv::Mat>& aImg)
{
   cv::Point2f center((aImg->cols - 1) / 2.0, (aImg->rows - 1) / 2.0);
   return std::make_unique<cv::Mat>(cv::getRotationMatrix2D(center, 90, 1.0));
}

void MatFunctions::SquareImage(std::unique_ptr<cv::Mat>& aImg)
{

   auto dimension = (aImg->rows < aImg->cols) ? aImg->rows : aImg->cols;
   cv::Rect roi(0, 0, dimension, dimension);
   *aImg = (*aImg)(roi);
}
}