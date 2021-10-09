#pragma once
#include <string>
#include <opencv2/opencv.hpp>
namespace puzzled
{
// Window size constants
const int WIDTH_640 = 640;
const int HEIGHT_480 = 480;
const int WIDTH_1920 = 1920;
const int HEIGHT_1080 = 1080;
// Initial crop size from a desktop scanner for mPuzzlePiece before passing it to Crop()
const int WIDTH_SCANNER_CROP = 700;
const int HEIGHT_SCANNER_CROP = 700;
// Name of the display window for cropping a puzzle piece
const std::string CROP_WINDOW = "Crop Puzzle Piece";
// Complete puzzle display window name
const std::string TEMPLATE_DISPLAY = "Full Puzzle Picture";
// ROI for a puzzle piece iamge from a sccanner
const cv::Rect SCANNER_CROP(0, 0, 700, 700);
// Scalar between box cover and actual puzzle
const float BUBBLE_PUZZLE_SCALE = 0.3;
// Radius of the circle around the place on the template that the search piece is found
const int RESULT_CIRCLE_RADIUS = 30;
// Offset of the detetion circle to line it up exactly where it goes
const int DETECTION_OFFSET = 20;
// Colors
const cv::Scalar GREEN(0, 255, 0);
const cv::Scalar BLACK(0, 0, 0);
const cv::Scalar WHITE(255, 255, 255);
} // namespace puzzled