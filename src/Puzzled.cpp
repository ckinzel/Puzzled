#include "Puzzled.hpp"

cv::Rect Puzzled::sRectangle;
bool Puzzled::sDrawingBox = false;
bool Puzzled::sIsPieceCropped = false;

void Puzzled::LoadPiece(const std::string& aFilePath)
{
   if ((mPuzzlePiece = cv::imread(aFilePath, 1)).empty())
   {
      throw std::runtime_error("Could not open file: " + aFilePath);
   }
}

void Puzzled::LoadTemplate(const std::string& aFilePath)
{
   if ((mTemplate = cv::imread(aFilePath, 1)).empty())
   {
      throw std::runtime_error("Could not open file: " + aFilePath);
   }
}

void Puzzled::DrawRectangle(cv::Mat& img, cv::Rect box)
{
   //Draw a rectangle
   rectangle(img, box.tl(), box.br(), cv::Scalar(0, 255, 0));
}

void Puzzled::OnMouseHandle(int event, int x, int y, int flags, void* param)
{
   cv::Mat& image = *(cv::Mat*)param;
   switch (event)
   {
      case cv::EVENT_MOUSEMOVE:      // When mouse moves, get the current rectangle's width and height
      {
         if (sDrawingBox)
         {
            sRectangle.width = x - sRectangle.x;
            sRectangle.height = y - sRectangle.y;
         }
      }
      break;
      case cv::EVENT_LBUTTONDOWN:    // when the left mouse button is pressed down,
      {
         //get the starting corner's coordinates of the rectangle
         sDrawingBox = true;
         sRectangle = cv::Rect(x, y, 0, 0);
      }
      break;
      case cv::EVENT_LBUTTONUP:     //when the left mouse button is released,
      {
         //draw the rectangle
         sDrawingBox = false;
         if (sRectangle.width < 0)
         {
            sRectangle.x += sRectangle.width;
            sRectangle.width *= -1;
         }

         if (sRectangle.height < 0)
         {
            sRectangle.y += sRectangle.height;
            sRectangle.height *= -1;
         }
         if (cv::waitKey(0) == 's')
         {
            DrawRectangle(image, sRectangle);
            image = image(sRectangle);
            sIsPieceCropped = true;
         }
         else
         {
            break;
         }
      }
      break;
   }
}

void Puzzled::CropPiece()
{
   cv::Mat tempImage;
   //srcImage = Scalar::all(0);
   cv::namedWindow(CROP_WINDOW);
   cv::setMouseCallback(CROP_WINDOW, OnMouseHandle, (void*)&mPuzzlePiece);
   while (1)
   {
      // If the user saved the cropped piece break out of the while loop
      if (sIsPieceCropped == true)
      { break; }
      // Write a temporary image with a movable rectangle
      mPuzzlePiece.copyTo(tempImage);
      if (sDrawingBox)
      {
         DrawRectangle(tempImage, sRectangle);
      }
      imshow(CROP_WINDOW, tempImage);
      if (cv::waitKey(10) == 27)  // stop drawing rectanglge if the key is 'ESC'
      {
         break;
      }
   }
}

void Puzzled::Solve()
{
   const int WIDTH = 640;
   const int HEIGHT = 480;

   cv::Mat ftmp[6];   // ftmp is what to display on

   // Read in the template to be used for matching:
   for (int i = 0; i < 6; ++i)
   {
      cv::matchTemplate(mPuzzlePiece, mTemplate, ftmp[i], i);
      cv::normalize(ftmp[i], ftmp[i], 1, 0, cv::NORM_MINMAX);
   }

   cv::namedWindow("Template", cv::WINDOW_NORMAL);
   cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);

   cv::resizeWindow("Template", WIDTH, HEIGHT);

   // Display
   //
   //cv::imshow("Template", templ);


   double minVal; double maxVal; cv::Point minLoc; cv::Point maxLoc;
   minMaxLoc(ftmp[5], &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat());

   rectangle(mTemplate, cv::Point(maxLoc.x, maxLoc.y), cv::Point(maxLoc.x + 50, maxLoc.y + 50), cv::Scalar::all(0), 2, 8, 0);
   //rectangle(result, maxLoc, Point(maxLoc.x, maxLoc.y), Scalar::all(0), 2, 150, 0);
   // Let user view results:
   //
   //rectangle(templ, Point(100, 100), Point(200, 200);
   cv::imshow("Template", mTemplate);
   cv::imshow("Image", mPuzzlePiece);
   cv::waitKey(0);
}