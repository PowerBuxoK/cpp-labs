#include <fstream>
#include <iomanip>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <openssl/evp.h>

std::string sha256(unsigned const char* data, size_t size)
{
  unsigned char hash[EVP_MAX_MD_SIZE];
  unsigned int lengthOfHash = 0;

  EVP_MD_CTX* context = EVP_MD_CTX_new();
  EVP_DigestInit_ex(context, EVP_sha256(), nullptr);
  EVP_DigestUpdate(context, data, size);
  EVP_DigestFinal_ex(context, hash, &lengthOfHash);
  EVP_MD_CTX_free(context);

  std::stringstream ss;
  for(unsigned int i = 0; i < lengthOfHash; i++)
  {
    ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
  }
  return ss.str();
}

int main(int argc, char* argv[])
{
  cv::Mat image = cv::imread("./image.png");
  auto original = sha256(image.data, image.dataend - image.datastart);

  image.at<cv::Vec3b>(0, 0)[0] = 123;

  auto altered = sha256(image.data, image.dataend - image.datastart);
  std::cout << "Original SHA256 sum: " << original << std::endl;
  std::cout << "Altered SHA256 sum:  " << altered << std::endl;
  std::cout << (original == altered ? "Sums are equal" : "Sums are not equal") << std::endl;
  std::ofstream out("./output.txt");
  out << "Sums:\n"
      << original << "\n"
      << altered << "\n"
      << (original == altered ? "Sums are equal" : "Sums are not equal") << std::endl;
  return 0;
}
