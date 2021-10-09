#include "gtest/gtest.h"
#include "definitions.hpp"
#include "Puzzled.hpp"

TEST(PUZZLED_CLASS, LOAD_PIECE)
{
   // Flags to indicate if an exception has been thrown
   bool load_piece_exception = false;
   // File name to create a saved image for testing
   std::string file_name = "test_img.jpg";
   // Create a white image matrix
   cv::Mat test_img(1000, 1000, CV_8UC1, puzzled::WHITE);
   // Add a black rectangle to the white image
   cv::rectangle(test_img, cv::Point(100, 100), cv::Point(200, 200), puzzled::BLACK, -1);
   // Write some directions onto the image
   cv::putText(test_img, "Draw a box around the black box, 'd' to start over 's' to save",
               cv::Point(10, 10), // Text location
               cv::FONT_HERSHEY_PLAIN, // Font
               1.0, // Scale
               CV_RGB(118, 185, 0), //font color
               2); // Thckness
   // Save the file to disk so we can read it in
   cv::imwrite(file_name, test_img);
   // Create test object
   puzzled::Puzzled test_obj;

   try
   {
      // Load the test file into the mPuzzlePiece data member of test_obj
      test_obj.LoadPiece(file_name);
   }
   catch (std::exception& e)
   {
      // Catch any exception
      load_piece_exception = true;;
   }

   // Delete the test file from disk
   remove(file_name.c_str());

   // Was an exception thrown?
   EXPECT_EQ(load_piece_exception, false);
}

TEST(PUZZLED_CLASS, LOAD_TEMPLATE)
{
   // Flags to indicate if an exception has been thrown
   bool load_template_exception = false;
   // File name to create a saved image for testing
   std::string file_name = "test_img.jpg";
   // Create a white image matrix
   cv::Mat test_img(1000, 1000, CV_8UC1, puzzled::WHITE);

   // Save the file to disk so we can read it in
   cv::imwrite(file_name, test_img);
   // Create test object
   puzzled::Puzzled test_obj;

   try
   {
      // Load the test file into the mTemplate data member of test_obj
      test_obj.LoadTemplate(file_name);
   }
   catch (std::exception& e)
   {
      // Catch any exception
      load_template_exception = true;
   }

   // Delete the test file from disk
   remove(file_name.c_str());

   // Was an exception thrown?
   EXPECT_EQ(load_template_exception, false);
}

TEST(MAT_FUNCTIONS, DISPLAY_IMAGE)
{
   // Flag to indicate if an exception has been thrown
   bool display_image_exception = false;
   // Create a white image matrix
   cv::Mat test_img(1000, 1000, CV_8UC1, puzzled::WHITE);
   // Write some directions onto the image
   cv::putText(test_img, "Press any key...",
               cv::Point(10, 10), // Text location
               cv::FONT_HERSHEY_PLAIN, // Font
               1.0, // Scale
               CV_RGB(118, 185, 0), //font color
               2); // Thckness
   // Create test object
   puzzled::MatFunctions func;
   try
   {
      // Display an image in a named window
      func.DisplayImage(test_img, puzzled::CROP_WINDOW, puzzled::WIDTH_640, puzzled::HEIGHT_480);
   }
   catch (std::exception& e)
   {
      // catch any exception
      display_image_exception = true;
   }

   // Was an exception thrown?
   EXPECT_EQ(display_image_exception, false);
}

TEST(MAT_FUNCTIONS, LOAD_IMAGE)
{
   // Flag to indicate if an exception has been thrown
   bool load_image_exception = false;
   // File name to create a saved image for testing
   std::string file_name = "test_img.jpg";
   // Create a white image matrix
   cv::Mat test_img(1000, 1000, CV_8UC1, puzzled::WHITE);

   // Save the file to disk so we can read it in
   cv::imwrite(file_name, test_img);

   // Create test objects
   puzzled::MatFunctions func;
   std::unique_ptr<cv::Mat> mat;
   try
   {
      // Load the image
      mat = func.LoadImage(file_name);
   }
   catch (std::exception& e)
   {
      // Catch any exception
      load_image_exception = true;;
   }
   // Delete the file from disk
   remove(file_name.c_str());

   // Did any exception get thrown?
   EXPECT_EQ(load_image_exception, false);
   // Is the image matrix empty?
   EXPECT_EQ(mat->empty(), false);
}

TEST(MAT_FUNCTIONS, ROTATE_IMAGE)
{

   // Create a white image matrix
   std::unique_ptr<cv::Mat> img_ptr = std::make_unique<cv::Mat>(400, 400, CV_8UC1, puzzled::WHITE);
   // Add a black square in top-left quadrant
   cv::rectangle(*img_ptr, cv::Point(0, 0), cv::Point(199, 199), puzzled::BLACK, -1);

   // Create test object
   puzzled::MatFunctions func;

   // Get the transformation matrix
   std::unique_ptr<cv::Mat> rotation_matrix = func.GetRotationMatrix90(img_ptr);

   // Rotate the image 90 degrees counter clockwise
   func.RotateImageCCW(img_ptr, rotation_matrix);

   // Get the black square now in the bottom-left quadrant
   cv::Rect roi(0, 200, 200, 200);
   // Create a matrix from that quadrant
   cv::Mat result(*img_ptr, roi);
   // How many black pixels are there?
   EXPECT_EQ(cv::countNonZero(result), 0);
}

TEST(MAT_FUNCTIONS, SQAURE_IMAGE)
{

   // Create a white image matrix
   std::unique_ptr<cv::Mat> img_ptr = std::make_unique<cv::Mat>(400, 300, CV_8UC1, puzzled::WHITE);

   // Create test object
   puzzled::MatFunctions func;

   func.SquareImage(img_ptr);

   // Is the image square?
   EXPECT_EQ(img_ptr->rows, img_ptr->cols);
}