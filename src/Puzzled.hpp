#pragma once
#include <opencv2/opencv.hpp>
#include "definitions.hpp"
#include "CommonFunctions.hpp"
namespace puzzled
{
class Puzzled
{
   public:
      // Default constructor
      Puzzled() = default;
      // Load the puzzle that needs to be searched for
      void LoadPiece(const std::string& aFilePath);
      // Load the picture of the whole puzzle
      void LoadTemplate(const std::string& aFilePath);

      // Find the location of the piece in the puzzle
      void Solve();


   private:
      // Crop the puzzle piece from an irregular shape to a rectangle
      void CropPiece();
      // Callback function fore mouse event
      static void OnMouseHandle(int event, int x, int y, int flags, void* param);
      // Draw a rectangle on an image
      static void Puzzled::DrawRectangle(cv::Mat& img, cv::Rect box);

      // This stores the image of the entire finished puzzle
      cv::Mat mTemplate;
      // This stores the image of the puzzle piece to find
      cv::Mat mPuzzlePiece;
      // Used to exit the while loop in CropPiece when the puzzle piece image has been cropped
      static bool sIsPieceCropped;
      // Rectangle to be drawn by the mouse callback for croppng the puzzle piece image
      static cv::Rect sRectangle;
      // Event variable for mouse callback event move. True when the left button is pressed
      static bool sDrawingBox;
      // Common Function object
      CommonFunctions* mFunctions;

};
} // namespace puzzled