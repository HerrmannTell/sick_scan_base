#ifndef ROSCONSOLE_SIMU_HPP
#define ROSCONSOLE_SIMU_HPP

#pragma warning(disable: 4996)
#pragma warning(disable: 4267)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ros/ros.h>

int fork();
void sleep(int secs);

namespace ros
{
	namespace console
	{
		//bool g_initialized = true;
#undef ROS_WARN
#undef ROS_INFO
#undef ROS_DEBUG
#undef ROS_FATAL
#undef ROS_ERROR
#undef ROS_ERROR_THROTTLE
#undef ROS_WARN_ONCE
#define ROS_WARN(...) fprintf(stderr,"ROS_WARN: "); fprintf (stderr, __VA_ARGS__); fprintf (stderr,"\n") 
#define ROS_INFO(...) fprintf(stderr,"ROS_INFO: "); fprintf (stderr, __VA_ARGS__); fprintf (stderr,"\n") 
#define ROS_DEBUG(...) fprintf(stderr,"ROS_DEBUG: "); fprintf (stderr, __VA_ARGS__); fprintf (stderr,"\n")
#define ROS_FATAL(...)
#define ROS_ERROR(...)  fprintf (stderr, __VA_ARGS__); fprintf (stderr,"\n") // #define eprintf(format, �) fprintf (stderr, format, __VA_ARGS__)

#define ROS_ERROR_THROTTLE(...)
#define ROS_WARN_ONCE(...)
		// #define ROS_WARN(...) ROS_LOG(::ros::console::levels::Warn, ROSCONSOLE_DEFAULT_NAME, __VA_ARGS__)
	}
}

int rossimu_error(const char *format, ...);
int rossimu_settings(ros::NodeHandle& nhPriv);
#endif