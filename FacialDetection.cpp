#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void detectAndDisplay( Mat frame );
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

void findAndContour(Mat img1, Mat img);

int main( int argc, const char** argv )
{

    String face_cascade_name = "../../../../../../../usr/local/share/opencv4/haarcascades/haarcascade_frontalface_alt.xml"; 
    
    
    std::string image_path = "../randomFace.jpeg"; 
    
    if( !face_cascade.load( face_cascade_name ) )
    {
        cout << "can't open the face cascade\n";
        return -1;
    };

    Mat img;

    //pull the image from the file
    img = imread(image_path);
    
    if(img.empty())
    {
        std::cout << "Could not read the image: " << endl;
        return 1;
    }

    Mat imGray;
    cvtColor(img, imGray, COLOR_BGR2GRAY);
    equalizeHist(imGray, imGray);
    
    findAndContour(imGray, img);

    imshow("Display window", img);
    //imshow("gray image", imGray);
    
    int k = waitKey(0); // Wait for a keystroke in the window
    if(k == 's')
    {
        imwrite("FoundFaces.png", img);
    }
    return 0;
}

void findAndContour(Mat img1, Mat img){

    std::vector<Rect> faces;

    face_cascade.detectMultiScale(img1, faces);
    
    
    //put the rectangle on the faces
    for(size_t i=0; i<faces.size();i++){
              
        rectangle(img,faces[i],Scalar(255,0,0),4,0,0);

    }

}