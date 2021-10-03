//Uncomment the following line if you are compiling this code in Visual Studio
//#include "stdafx.h"

#include <opencv2/opencv.hpp>
#include <iostream>
#include "Puzzled.hpp"
using namespace cv;
using namespace std;


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

   //search(FilePath + BoxCoverImg, FilePath + Cheating, foo);
   Puzzled crop;

   crop.LoadTemplate(FilePath + BoxCoverImg);
   crop.LoadPiece(FilePath + Cheating);
   crop.Solve();
   //crop.CropPiece();
   return 0;
}
