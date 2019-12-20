#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int main(int argc, char** argv) {
    
    // create a PointCloud<PointXYZ> boost shared ptr and initialize it
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

    if(pcl::io::loadPCDFile<pcl::PointXYZ> ("../sample.pcd", *cloud) == -1) {
        PCL_ERROR("Couldn't read PCD file \n");
        return(-1);
    }

    /*
    ** Alternative method to read point cloud into binary blob due to it's dynamic nature
       
       pcl::PCLPointCloud2 cloud_blob;
       pcl::io::loadPCDFile("file_name", cloud_blob);
       pcl::fromPCLPointCloud2(cloud_blob, *cloud)  // convert from pcl/PCLPointCloud2 to pcl::PointCloud<T>     
    
    **
    */

    std::cout << "Loaded "
              << cloud->width * cloud->height
              << " data points from the PCD with following fields: "
              << std::endl;

    for(std::size_t i = 0; i < cloud->points.size(); ++i) {
        std::cout << "      " << cloud->points[i].x
                  << "      " << cloud->points[i].y
                  << "      " << cloud->points[i].z
                  << std::endl;
        }

    return(0);
}