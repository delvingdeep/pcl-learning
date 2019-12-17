#include <iostream>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int main(int argc, char** argv) {
    pcl::PointCloud<pcl::PointXYZ> cloud;

    // Point cloud data properties
    cloud.width     = 100000;
    cloud.height    = 1;        // unorganized point cloud
    cloud.is_dense  = false;
    cloud.points.resize(cloud.width * cloud.height);

    // Point cloud data value
    for(std::size_t i = 0; i < cloud.points.size(); ++i) {
        cloud.points[i].x = 1024 * rand() / (RAND_MAX + 1.0f);
        cloud.points[i].y = 1024 * rand() / (RAND_MAX + 1.0f);
        cloud.points[i].z = 1024 * rand() / (RAND_MAX + 1.0f);
    }

    pcl::io::savePCDFileASCII("test_pcd.pcd", cloud);
    std::cerr << "Saved " << cloud.points.size() << " data points to test_pcd.pcd" << std::endl;

    // for(std::size_t i = 0; i < cloud.points.size(); ++i) {
    //     std::cerr << "      " << cloud.points[i].x << "     " << cloud.points[i].y << "     " << cloud.points[i].z << std::endl;
    // }

    return(0); 
}