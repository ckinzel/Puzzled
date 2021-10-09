//Uncomment the following line if you are compiling this code in Visual Studio
//#include "stdafx.h"
#include <iostream>
#include "Puzzled.hpp"
#include "MatFunctions.hpp"

int main(int argc, char** argv)
{
   // Path to data
   std::string FilePath = "../../data/";
   //Templates
   std::string BoxCoverImg = "BoxCoverCropped.jpg";
   std::string Poster = "PosterCropped.jpg";
   // Search images
   std::string FaceImg = "FacePieceCropped.jpg";
   std::string Cheating = "face_from_box.jpg";
   // Waldo test
   std::string tem = "where.jpg";
   std::string fin = "find.jpg";
   // Raw Puzzle pieces
   std::string raw = "FacePiece.jpg";
   std::string bubble = "BubbleBottomPiece.jpg";
   std::string fish = "fish_scales.jpg";
   std::string center = "center_bubble.jpg";

   puzzled::Puzzled crop;
   puzzled::MatFunctions func;

   //crop.LoadTemplate(FilePath + BoxCoverImg);
   // crop.LoadPiece(FilePath + center;
   //crop.Solve();

   cv::Mat white(400, 400, CV_8UC1, puzzled::WHITE);
   cv::rectangle(white, cv::Point(0, 0), cv::Point(200, 200), puzzled::BLACK, -1);
   std::string file = "white.jpg";
   //func.DisplayImage(white, "test", 640, 480);
   //cv::imwrite("white.jpg", white);

   return 0;
}
