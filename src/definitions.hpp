#pragma once
#include <string>

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
// Generic display window name
const std::string GENERIC_WINDOW = "Display";
// ROI for a puzzle piece iamge from a sccanner
const cv::Rect SCANNER_CROP(0, 0, 700, 700);
// Scalar between box cover and actual puzzle
const float BUBBLE_PUZZLE_SCALE = 0.3;

} // namespace puzzled