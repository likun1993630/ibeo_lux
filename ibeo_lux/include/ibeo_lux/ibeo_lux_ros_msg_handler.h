#ifndef IBEO_LUX_ROS_MSG_HANDLER_H
#define IBEO_LUX_ROS_MSG_HANDLER_H

#include <utils.h>
#include <ibeo_lux_common.h>

using namespace AS::Drivers::Ibeo;

namespace AS
{
namespace Drivers
{
namespace IbeoLux
{
  class IbeoLuxRosMsgHandler
  {
    public:
      IbeoLuxRosMsgHandler(ros::Publisher& pub, std::string frame_id);

      void fillAndPublish(unsigned short type_id, std::shared_ptr<IbeoTxMessage>& parser_class);
      void fillPointcloud(std::vector<Point3D>& points, pcl::PointCloud<pcl::PointXYZ>& new_msg);
      void fillContourPoints(std::vector<Point3D>& points, visualization_msgs::Marker& new_msg);
      void fillMarkerArray(std::vector<IbeoObject>& objects, visualization_msgs::MarkerArray& new_msg);

    private:
      ros::Publisher pub;
      std::string frame_id;

      ros::Time ntp_to_ros_time(NTPTime time);

      void fillIbeoHeader(IbeoDataHeader& class_header, ibeo_msgs::IbeoDataHeader& msg_header);
      void fill2030(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::ErrorWarning& new_msg);
      void fill2202(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::ScanData2202& new_msg);
      void fill2204(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::ScanData2204& new_msg);
      void fill2205(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::ScanData2205& new_msg);
      void fill2221(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::ObjectData2221& new_msg);
      void fill2225(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::ObjectData2225& new_msg);
      void fill2280(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::ObjectData2280& new_msg);
      void fill2403(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::CameraImage& new_msg);
      void fill2805(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::HostVehicleState2805& new_msg);
      void fill2806(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::HostVehicleState2806& new_msg);
      void fill2807(std::shared_ptr<IbeoTxMessage>& parser_class, ibeo_msgs::HostVehicleState2807& new_msg);
      visualization_msgs::Marker createWireframeMarker(const float& center_x,
                                                       const float& center_y,
                                                       float size_x,
                                                       float size_y,
                                                       const float& size_z);
  };
}
}
}

#endif