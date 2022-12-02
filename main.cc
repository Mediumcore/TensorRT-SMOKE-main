#include "smoke.hh"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <chrono>

using namespace std;
int main(int argc, char **argv)
{
    // cv::Mat kitti_img = cv::imread("../samples/kitti_000008.png");
    // cv::resize(kitti_img, kitti_img_resized, cv::Size(1242, 375));
    // cv::Mat intrinsic = (cv::Mat_<float>(3, 3) << 721.5377, 0.0, 609.5593, 0.0, 721.5377, 172.854, 0.0, 0.0, 1.0);
    // data: [1430.60137,    0.     ,  965.91782,
    //         0.     , 1442.80636,  574.60945,
    //         0.     ,    0.     ,    1.     ]
    cv::Mat intrinsic = (cv::Mat_<float>(3, 3) << 1430.60137, 0.0, 965.91782, 0.0, 1442.80636, 574.60945, 0.0, 0.0, 1.0);
    string image_dir = "/home/yankai/rtsp_ffmpeg_imgs/";
    string image_out_dir = "/home/yankai/rtsp_ffmpeg_imgs_detect/";

    // SMOKE smoke("../smoke_dla34_640*480.trt8", intrinsic);
    SMOKE smoke("../smoke_dla34_640*384.trt8", intrinsic);
    // SMOKE smoke("../smoke_dla34.trt8", intrinsic);
    for (size_t i = 1; i < 127; i++)
    {
        string image_path = image_dir + to_string(i * 10) + ".png";
        string image_out_path = image_out_dir + to_string(i * 10) + ".png";
        cv::Mat kitti_img = cv::imread(image_path);
        cv::Mat output_img;
        auto start = std::chrono::system_clock::now();
        smoke.Detect(kitti_img, output_img);
        auto end = std::chrono::system_clock::now();
        int tracking_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        printf("3d object Detect time: %d ms \n", tracking_time_ms);
        cv::imwrite(image_out_path, output_img);
    }

    return 0;
}
