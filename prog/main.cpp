#include <opencv2/core/core.hpp>
#include <opencv2/core/hal/interface.h>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

void sepia(cv::Mat img)
{
  using namespace cv;
  Mat res = img.clone();
  cvtColor(res, res, COLOR_BGR2RGB);
  transform(res, res, Matx33f(0.393, 0.769, 0.189, 0.349, 0.686, 0.168, 0.272, 0.534, 0.131));
  cvtColor(res, res, COLOR_RGB2BGR);
  imshow("original", img);
  imshow("Sepia", res);
  waitKey(0);
  destroyAllWindows();
}

int main(int argc, char* argv[])
{
  cv::Mat image = cv::imread("./image.png");
  cv::resize(image, image, cv::Size(960, 540), 0, 0, cv::INTER_LINEAR);

  sepia(image);
  return 0;
}
