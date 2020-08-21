#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
    std::string image_path = "../randomFace.jpeg";
    
    
    Mat img;

    img = imread(image_path);
    //cap.read(img);
    if(img.empty())
    {
        std::cout << "Could not read the image: " << endl;
        return 1;
    }
    imshow("Display window", img);
    int k = waitKey(0); // Wait for a keystroke in the window
    if(k == 's')
    {
        imwrite("logo.png", img);
    }
    return 0;
}