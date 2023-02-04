#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

int main (int argc, char **argv)
{
  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher ij5_pub = n.advertise<std_msgs::Float64>("/anael/ij5_position_controller/command", 1000);
  ros::Publisher ij4_pub = n.advertise<std_msgs::Float64>("/anael/ij4_position_controller/command", 1000);
  ros::Publisher ij3_pub = n.advertise<std_msgs::Float64>("/anael/ij3_position_controller/command", 1000);
  ros::Publisher ij1_pub = n.advertise<std_msgs::Float64>("/anael/ij1_position_controller/command", 1000);

  ros::Publisher oj5_pub = n.advertise<std_msgs::Float64>("/anael/oj5_position_controller/command", 1000);
  ros::Publisher oj4_pub = n.advertise<std_msgs::Float64>("/anael/oj4_position_controller/command", 1000);
  ros::Publisher oj3_pub = n.advertise<std_msgs::Float64>("/anael/oj3_position_controller/command", 1000);
  ros::Publisher oj1_pub = n.advertise<std_msgs::Float64>("/anael/oj1_position_controller/command", 1000);

  ros::Publisher yj5_pub = n.advertise<std_msgs::Float64>("/anael/yj5_position_controller/command", 1000);
  ros::Publisher yj4_pub = n.advertise<std_msgs::Float64>("/anael/yj4_position_controller/command", 1000);
  ros::Publisher yj3_pub = n.advertise<std_msgs::Float64>("/anael/yj3_position_controller/command", 1000);
  ros::Publisher yj1_pub = n.advertise<std_msgs::Float64>("/anael/yj1_position_controller/command", 1000);

  ros::Publisher sj5_pub = n.advertise<std_msgs::Float64>("/anael/sj5_position_controller/command", 1000);
  ros::Publisher sj4_pub = n.advertise<std_msgs::Float64>("/anael/sj4_position_controller/command", 1000);
  ros::Publisher sj3_pub = n.advertise<std_msgs::Float64>("/anael/sj3_position_controller/command", 1000);
  ros::Publisher sj1_pub = n.advertise<std_msgs::Float64>("/anael/sj1_position_controller/command", 1000);

  ros::Publisher basj4_pub = n.advertise<std_msgs::Float64>("/anael/basj4_position_controller/command", 1000);
  ros::Publisher basj3_pub = n.advertise<std_msgs::Float64>("/anael/basj3_position_controller/command", 1000);
  ros::Publisher basj2_pub = n.advertise<std_msgs::Float64>("/anael/basj2_position_controller/command", 1000);
  ros::Publisher basj1_pub = n.advertise<std_msgs::Float64>("/anael/basj1_position_controller/command", 1000); 

  ros::Publisher bilekyaj_pub = n.advertise<std_msgs::Float64>("/anael/bilekyaj_position_controller/command", 1000);
  ros::Publisher bilekssj_pub = n.advertise<std_msgs::Float64>("/anael/bilekssj_position_controller/command", 1000);  

  std_msgs::Float64 position_ij5; std_msgs::Float64 position_ij4; std_msgs::Float64 position_ij3; std_msgs::Float64 position_ij1;
  std_msgs::Float64 position_oj5; std_msgs::Float64 position_oj4; std_msgs::Float64 position_oj3; std_msgs::Float64 position_oj1;
  std_msgs::Float64 position_yj5; std_msgs::Float64 position_yj4; std_msgs::Float64 position_yj3; std_msgs::Float64 position_yj1;
  std_msgs::Float64 position_sj5; std_msgs::Float64 position_sj4; std_msgs::Float64 position_sj3; std_msgs::Float64 position_sj1;
  std_msgs::Float64 position_basj4; std_msgs::Float64 position_basj3; std_msgs::Float64 position_basj2; std_msgs::Float64 position_basj1;
  std_msgs::Float64 position_bilekyaj; std_msgs::Float64 position_bilekssj;

  char alphabet[200];
  int working=1,i=0,r=0;  

  startline:

  cout<<"Please enter any sentence or enter 1 for exit"<<endl;
  cin>>alphabet;	

  r=strlen(alphabet);

  cout<<r<< " letters" <<endl;

  for(i=0; i < strlen(alphabet); i++){

  position_ij5.data = -0.1; position_ij4.data = -0.1; position_ij3.data = -0.1; position_ij1.data = 0.0;
  position_oj5.data = -0.1; position_oj4.data = -0.1; position_oj3.data = -0.1; position_oj1.data = 0.0;
  position_yj5.data = -0.1; position_yj4.data = -0.1; position_yj3.data = -0.1; position_yj1.data = 0.0;
  position_sj5.data = -0.1; position_sj4.data = -0.1; position_sj3.data = -0.1; position_sj1.data = 0.0;
  position_basj4.data = -0.1; position_basj3.data = -0.1; position_basj2.data = 0.0; position_basj1.data = 0.0;
  position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

  basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
  bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);
  sleep(1); ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
  oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
  yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
  sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);

  sleep(3);


  switch ( alphabet[i] )
  {
    case 'v':
    case 'V': {
      position_ij5.data = -0.08; position_ij4.data = -0.08; position_ij3.data = -0.08; position_ij1.data = -0.15;
      position_oj5.data = -0.08; position_oj4.data = -0.08; position_oj3.data = -0.08; position_oj1.data = 0.15;
      position_yj5.data = -1.4; position_yj4.data = -1.4; position_yj3.data = -1.1; position_yj1.data = 0.0;
      position_sj5.data = -1.4; position_sj4.data = -1.4; position_sj3.data = -1.4; position_sj1.data = 0.0;
      position_basj4.data = -0.08; position_basj3.data = -1.0; position_basj2.data = 1.4; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);

      break;
    }

    case 'c':
    case 'C': {
      position_ij5.data = -0.5; position_ij4.data = -0.8; position_ij3.data = -0.6; position_ij1.data = 0.1;
      position_oj5.data = -0.5; position_oj4.data = -0.8; position_oj3.data = -0.6; position_oj1.data = 0.0;
      position_yj5.data = -0.5; position_yj4.data = -0.8; position_yj3.data = -0.6; position_yj1.data = -0.05;
      position_sj5.data = -0.5; position_sj4.data = -0.8; position_sj3.data = -0.6; position_sj1.data = -0.1;
      position_basj4.data = -0.8; position_basj3.data = -0.3; position_basj2.data = 1.0; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);

      break;
    }

    case 'a':
    case 'A': {
      position_ij5.data = -0.2; position_ij4.data = -1.4; position_ij3.data = -1.4; position_ij1.data = 0.0;
      position_oj5.data = -0.2; position_oj4.data = -1.4; position_oj3.data = -1.4; position_oj1.data = 0.0;
      position_yj5.data = -0.2; position_yj4.data = -1.4; position_yj3.data = -1.4; position_yj1.data = 0.0;
      position_sj5.data = -0.2; position_sj4.data = -1.4; position_sj3.data = -1.4; position_sj1.data = 0.0;
      position_basj4.data = -0.08; position_basj3.data = -0.08; position_basj2.data = 1.3; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      sleep(1);      
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1);yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sleep(1);oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      sleep(1);ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      sleep(2); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);

      break;
    }

    case 'b':
    case 'B': {
      position_ij5.data = -0.08; position_ij4.data = -0.08; position_ij3.data = -0.08; position_ij1.data = 0.05;
      position_oj5.data = -0.08; position_oj4.data = -0.08; position_oj3.data = -0.08; position_oj1.data = 0.0;
      position_yj5.data = -0.08; position_yj4.data = -0.08; position_yj3.data = -0.08; position_yj1.data = -0.05;
      position_sj5.data = -0.08; position_sj4.data = -0.08; position_sj3.data = -0.08; position_sj1.data = -0.05;
      position_basj4.data = -0.2; position_basj3.data = -1.4; position_basj2.data = 1.5; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);

      break;
    }

    case 'd':
    case 'D': {
      position_ij5.data = -0.1; position_ij4.data = -0.1; position_ij3.data = -0.1; position_ij1.data = 0.1;
      position_oj5.data = -0.7; position_oj4.data = -0.8; position_oj3.data = -1.0; position_oj1.data = 0.0;
      position_yj5.data = -0.7; position_yj4.data = -0.8; position_yj3.data = -1.0; position_yj1.data = 0.0;
      position_sj5.data = -0.7; position_sj4.data = -0.8; position_sj3.data = -1.0; position_sj1.data = 0.0;
      position_basj4.data = -0.08; position_basj3.data = -1.4; position_basj2.data = 1.2; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);

      break;
    }

    case 'e':
    case 'E': {
      position_ij5.data = -1.2; position_ij4.data = -1.4; position_ij3.data = -0.5; position_ij1.data = 0.0;
      position_oj5.data = -1.2; position_oj4.data = -1.4; position_oj3.data = -0.5; position_oj1.data = 0.0;
      position_yj5.data = -1.2; position_yj4.data = -1.4; position_yj3.data = -0.5; position_yj1.data = 0.0;
      position_sj5.data = -1.2; position_sj4.data = -1.4; position_sj3.data = -0.5; position_sj1.data = 0.0;
      position_basj4.data = -0.6; position_basj3.data = -1.4; position_basj2.data = 1.5; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      sleep(1);
      ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);
      sleep(2);

      break;
    }

    case 'f':
    case 'F': {
      position_ij5.data = -0.7; position_ij4.data = -0.8; position_ij3.data = -0.8; position_ij1.data = 0.05;
      position_oj5.data = -0.08; position_oj4.data = -0.08; position_oj3.data = -0.08; position_oj1.data = 0.0;
      position_yj5.data = -0.08; position_yj4.data = -0.08; position_yj3.data = -0.08; position_yj1.data = 0.0;
      position_sj5.data = -0.08; position_sj4.data = -0.08; position_sj3.data = -0.08; position_sj1.data = 0.15;
      position_basj4.data = -1.0; position_basj3.data = -0.1; position_basj2.data = 1.0; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);
      sleep(1);

      break;
    }

    case 'g':
    case 'G': {
      position_ij5.data = -0.08; position_ij4.data = -0.08; position_ij3.data = -0.4; position_ij1.data = 0.0;
      position_oj5.data = -1.4; position_oj4.data = -1.4; position_oj3.data = -1.4; position_oj1.data = 0.0;
      position_yj5.data = -1.4; position_yj4.data = -1.4; position_yj3.data = -1.4; position_yj1.data = 0.0;
      position_sj5.data = -1.4; position_sj4.data = -1.4; position_sj3.data = -1.4; position_sj1.data = 0.0;
      position_basj4.data = -0.08; position_basj3.data = -0.08; position_basj2.data = 0.7; position_basj1.data = -0.24;
      position_bilekyaj.data = -1.48; position_bilekssj.data = 0.78;

      ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);

      break;
    }
    
    case 'h':
    case 'H': {
      position_ij5.data = -0.08; position_ij4.data = -0.08; position_ij3.data = -0.08; position_ij1.data = 0.1;
      position_oj5.data = -0.08; position_oj4.data = -0.08; position_oj3.data = -0.08; position_oj1.data = 0.1;
      position_yj5.data = -0.2; position_yj4.data = -1.4; position_yj3.data = -1.4; position_yj1.data = 0.0;
      position_sj5.data = -0.2; position_sj4.data = -1.4; position_sj3.data = -1.4; position_sj1.data = 0.0;
      position_basj4.data = -0.08; position_basj3.data = -0.6; position_basj2.data = 1.57; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 1.4;

      sleep(1);
      ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);
      
      break;
    }

    case 'i':
    case 'I': {
      position_ij5.data = -0.3; position_ij4.data = -1.4; position_ij3.data = -1.4; position_ij1.data = 0.0;
      position_oj5.data = -0.3; position_oj4.data = -1.4; position_oj3.data = -1.4; position_oj1.data = 0.0;
      position_yj5.data = -0.3; position_yj4.data = -1.4; position_yj3.data = -1.4; position_yj1.data = 0.0;
      position_sj5.data = -0.08; position_sj4.data = -0.08; position_sj3.data = -0.08; position_sj1.data = 0.1;
      position_basj4.data = -0.6; position_basj3.data = -1.0; position_basj2.data = 1.57; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      sleep(1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      sleep(1); ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      sleep(3); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);

      break;
    }

    case 'j':
    case 'J': {
      position_ij5.data = -0.3; position_ij4.data = -1.4; position_ij3.data = -1.4; position_ij1.data = 0.0;
      position_oj5.data = -0.3; position_oj4.data = -1.4; position_oj3.data = -1.4; position_oj1.data = 0.0;
      position_yj5.data = -0.3; position_yj4.data = -1.4; position_yj3.data = -1.4; position_yj1.data = 0.0;
      position_sj5.data = -0.08; position_sj4.data = -0.4; position_sj3.data = -0.08; position_sj1.data = 0.0;
      position_basj4.data = -0.6; position_basj3.data = -1.0; position_basj2.data = 1.57; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.78;

      sleep(1);
      ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekssj_pub.publish(position_bilekssj);

      sleep(2); position_bilekyaj.data = -1.2; bilekyaj_pub.publish(position_bilekyaj);
      sleep(2); position_bilekssj.data = 0.0; bilekssj_pub.publish(position_bilekssj);
      sleep(2); position_bilekyaj.data = -0.6; bilekyaj_pub.publish(position_bilekyaj);
      
      break;
    }

    case 'k':
    case 'K': {
      position_ij5.data = -0.08; position_ij4.data = -0.08; position_ij3.data = -0.2; position_ij1.data = 0.0;
      position_oj5.data = -0.08; position_oj4.data = -0.08; position_oj3.data = -1.4; position_oj1.data = 0.0;
      position_yj5.data = -1.48; position_yj4.data = -1.48; position_yj3.data = -1.48; position_yj1.data = 0.0;
      position_sj5.data = -1.48; position_sj4.data = -1.48; position_sj3.data = -1.48; position_sj1.data = 0.0;
      position_basj4.data = -0.08; position_basj3.data = -0.2; position_basj2.data = 1.57; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);

      break;
    }

    case 'l':
    case 'L': {
      position_ij5.data = -0.08; position_ij4.data = -0.08; position_ij3.data = -0.08; position_ij1.data = 0.0;
      position_oj5.data = -0.1; position_oj4.data = -1.4; position_oj3.data = -1.4; position_oj1.data = 0.0;
      position_yj5.data = -0.1; position_yj4.data = -1.4; position_yj3.data = -1.4; position_yj1.data = 0.0;
      position_sj5.data = -0.1; position_sj4.data = -1.4; position_sj3.data = -1.4; position_sj1.data = 0.0;
      position_basj4.data = -0.08; position_basj3.data = -0.08; position_basj2.data = 0.0; position_basj1.data = 0.0;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      sleep(1);
      ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);
      sleep(2);

      break;
    }

    case 'm':
    case 'M': {
      position_ij5.data = -0.08; position_ij4.data = -1.2; position_ij3.data = -1.3; position_ij1.data = 0.0;
      position_oj5.data = -0.08; position_oj4.data = -1.2; position_oj3.data = -1.3; position_oj1.data = 0.15;
      position_yj5.data = -0.08; position_yj4.data = -1.1; position_yj3.data = -1.3; position_yj1.data = 0.34;
      position_sj5.data = -0.3; position_sj4.data = -1.4; position_sj3.data = -1.4; position_sj1.data = 0.34;
      position_basj4.data = -0.08; position_basj3.data = -0.08; position_basj2.data = 1.57; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;
      
      sleep(1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);
      sleep(3); ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      sleep(1); oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);  
      sleep(1); yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      
      break;
    }

    case 'n':
    case 'N': {
      position_ij5.data = -0.08; position_ij4.data = -1.2; position_ij3.data = -1.2; position_ij1.data = 0.0;
      position_oj5.data = -0.08; position_oj4.data = -1.2; position_oj3.data = -1.2; position_oj1.data = 0.15;
      position_yj5.data = -0.4; position_yj4.data = -1.48; position_yj3.data = -1.48; position_yj1.data = 0.34;
      position_sj5.data = -0.4; position_sj4.data = -1.48; position_sj3.data = -1.48; position_sj1.data = 0.34;
      position_basj4.data = -0.08; position_basj3.data = -0.08; position_basj2.data = 1.57; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      sleep(1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);
      sleep(3); ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      sleep(1); oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);

      break;
    }

    case 'o':
    case 'O': {
      position_ij5.data = -0.7; position_ij4.data = -0.8; position_ij3.data = -0.6; position_ij1.data = 0.0;
      position_oj5.data = -0.7; position_oj4.data = -0.8; position_oj3.data = -0.6; position_oj1.data = 0.0;
      position_yj5.data = -0.7; position_yj4.data = -0.8; position_yj3.data = -0.6; position_yj1.data = 0.0;
      position_sj5.data = -0.7; position_sj4.data = -0.8; position_sj3.data = -0.6; position_sj1.data = 0.0;
      position_basj4.data = -0.1; position_basj3.data = -0.3; position_basj2.data = 1.57; position_basj1.data = 0.0;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);  

      break;
    }

    case 'p':
    case 'P': {
      position_ij5.data = -0.08; position_ij4.data = -0.08; position_ij3.data = -0.2; position_ij1.data = 0.0;
      position_oj5.data = -0.08; position_oj4.data = -0.08; position_oj3.data = -1.48; position_oj1.data = 0.0;
      position_yj5.data = -1.48; position_yj4.data = -1.48; position_yj3.data = -1.48; position_yj1.data = 0.0;
      position_sj5.data = -1.48; position_sj4.data = -1.48; position_sj3.data = -1.48; position_sj1.data = 0.0;
      position_basj4.data = -0.08; position_basj3.data = -0.2; position_basj2.data = 1.57; position_basj1.data = 0.0;
      position_bilekyaj.data = -1.2; position_bilekssj.data = 0.0;

      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);     
      ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1); 
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);  

      break;
    }

    case 'q':
    case 'Q': {
      position_ij5.data = -0.08; position_ij4.data = -0.08; position_ij3.data = -1.4; position_ij1.data = 0.0;
      position_oj5.data = -1.4; position_oj4.data = -1.4; position_oj3.data = -1.4; position_oj1.data = 0.0;
      position_yj5.data = -1.4; position_yj4.data = -1.4; position_yj3.data = -1.4; position_yj1.data = 0.0;
      position_sj5.data = -1.4; position_sj4.data = -1.4; position_sj3.data = -1.4; position_sj1.data = 0.0;
      position_basj4.data = -0.08; position_basj3.data = -0.08; position_basj2.data = 1.57; position_basj1.data = 0.0;
      position_bilekyaj.data = -1.4; position_bilekssj.data = 0.0;

      ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);

      break;
    }

    case 'r':
    case 'R': {
      position_ij5.data = -0.08; position_ij4.data = -0.08; position_ij3.data = -0.08; position_ij1.data = 0.2;
      position_oj5.data = -0.08; position_oj4.data = -0.08; position_oj3.data = -0.08; position_oj1.data = -0.15;
      position_yj5.data = -1.48; position_yj4.data = -1.4; position_yj3.data = -1.1; position_yj1.data = 0.0;
      position_sj5.data = -1.48; position_sj4.data = -1.4; position_sj3.data = -1.4; position_sj1.data = 0.0;
      position_basj4.data = -0.08; position_basj3.data = -1.0; position_basj2.data = 1.57; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      sleep(2); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      sleep(3); ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);     
      sleep(1); oj5_pub.publish(position_oj5); 
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);

      break;
    }

    case 's':
    case 'S': {
      position_ij5.data = -1.4; position_ij4.data = -1.4; position_ij3.data = -1.4; position_ij1.data = 0.0;
      position_oj5.data = -1.4; position_oj4.data = -1.4; position_oj3.data = -1.4; position_oj1.data = 0.0;
      position_yj5.data = -1.4; position_yj4.data = -1.4; position_yj3.data = -1.4; position_yj1.data = 0.0;
      position_sj5.data = -1.4; position_sj4.data = -1.4; position_sj3.data = -1.4; position_sj1.data = 0.0;
      position_basj4.data = -1.0; position_basj3.data = -1.0; position_basj2.data = 1.57; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      sleep(1);sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1);yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sleep(1);oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      sleep(1);ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);     
      sleep(1.5); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);

      break;
    }

    case 't':
    case 'T': {
      position_ij5.data = -0.4; position_ij4.data = -1.4; position_ij3.data = -1.4; position_ij1.data = 0.0;
      position_oj5.data = -0.4; position_oj4.data = -1.4; position_oj3.data = -1.4; position_oj1.data = 0.0;
      position_yj5.data = -1.4; position_yj4.data = -1.4; position_yj3.data = -1.4; position_yj1.data = 0.0;
      position_sj5.data = -1.4; position_sj4.data = -1.4; position_sj3.data = -1.4; position_sj1.data = 0.0;
      position_basj4.data = -0.08; position_basj3.data = -0.08; position_basj2.data = 1.57; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      sleep(2.5); ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);

      break;
    }

    case 'u':
    case 'U': {
      position_ij5.data = -0.08; position_ij4.data = -0.08; position_ij3.data = -0.08; position_ij1.data = 0.0;
      position_oj5.data = -0.08; position_oj4.data = -0.08; position_oj3.data = -0.08; position_oj1.data = 0.0;
      position_yj5.data = -1.4; position_yj4.data = -1.4; position_yj3.data = -1.1; position_yj1.data = 0.0;
      position_sj5.data = -1.4; position_sj4.data = -1.4; position_sj3.data = -1.4; position_sj1.data = 0.0;
      position_basj4.data = -0.08; position_basj3.data = -1.0; position_basj2.data = 1.4; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);

      break;
    }

    case 'w':
    case 'W': {
      position_ij5.data = -0.08; position_ij4.data = -0.08; position_ij3.data = -0.08; position_ij1.data = -0.15;
      position_oj5.data = -0.08; position_oj4.data = -0.08; position_oj3.data = -0.08; position_oj1.data = 0.0;
      position_yj5.data = -0.08; position_yj4.data = -0.08; position_yj3.data = -0.08; position_yj1.data = 0.15;
      position_sj5.data = -0.3; position_sj4.data = -1.4; position_sj3.data = -1.4; position_sj1.data = 0.34;
      position_basj4.data = -0.08; position_basj3.data = -1.48; position_basj2.data = 1.57; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);

      break;
    }

    case 'x':
    case 'X': {
      position_ij5.data = -0.4; position_ij4.data = -0.6; position_ij3.data = -0.4; position_ij1.data = 0.0;
      position_oj5.data = -1.4; position_oj4.data = -1.4; position_oj3.data = -1.1; position_oj1.data = 0.0;
      position_yj5.data = -1.4; position_yj4.data = -1.4; position_yj3.data = -1.2; position_yj1.data = 0.0;
      position_sj5.data = -1.4; position_sj4.data = -1.4; position_sj3.data = -1.4; position_sj1.data = 0.0;
      position_basj4.data = -0.2; position_basj3.data = -1.0; position_basj2.data = 1.57; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);

      break;
    }

    case 'y':
    case 'Y': {
      position_ij5.data = -0.4; position_ij4.data = -1.4; position_ij3.data = -1.4; position_ij1.data = 0.0;
      position_oj5.data = -0.4; position_oj4.data = -1.4; position_oj3.data = -1.4; position_oj1.data = 0.0;
      position_yj5.data = -0.4; position_yj4.data = -1.4; position_yj3.data = -1.4; position_yj1.data = 0.0;
      position_sj5.data = -0.08; position_sj4.data = -0.08; position_sj3.data = -0.4; position_sj1.data = 0.0;
      position_basj4.data = -0.08; position_basj3.data = -0.08; position_basj2.data = 0.0; position_basj1.data = 0.0;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      sleep(2);     
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      sleep(1);ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);

      break;
    }

    case 'z':
    case 'Z': {
      position_ij5.data = -0.08; position_ij4.data = -0.08; position_ij3.data = -0.08; position_ij1.data = 0.0;
      position_oj5.data = -1.4; position_oj4.data = -1.4; position_oj3.data = -1.4; position_oj1.data = 0.0;
      position_yj5.data = -1.4; position_yj4.data = -1.4; position_yj3.data = -1.4; position_yj1.data = 0.0;
      position_sj5.data = -1.4; position_sj4.data = -1.4; position_sj3.data = -1.4; position_sj1.data = 0.0;
      position_basj4.data = -0.2; position_basj3.data = -1.1; position_basj2.data = 1.57; position_basj1.data = -0.24;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      sleep(3); ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);

      sleep(2); position_bilekssj.data = 0.35; bilekssj_pub.publish(position_bilekssj); sleep(2);
      sleep(3); position_bilekyaj.data = -1.0; bilekyaj_pub.publish(position_bilekyaj); sleep(4);
      sleep(2); position_bilekssj.data = 0.78; bilekssj_pub.publish(position_bilekssj); sleep(2);

      break;
    }

    case ' ': {
      position_ij5.data = -0.1; position_ij4.data = -0.1; position_ij3.data = -0.1; position_ij1.data = 0.0;
      position_oj5.data = -0.1; position_oj4.data = -0.1; position_oj3.data = -0.1; position_oj1.data = 0.0;
      position_yj5.data = -0.1; position_yj4.data = -0.1; position_yj3.data = -0.1; position_yj1.data = 0.0;
      position_sj5.data = -0.1; position_sj4.data = -0.1; position_sj3.data = -0.1; position_sj1.data = 0.0;
      position_basj4.data = -0.1; position_basj3.data = -0.1; position_basj2.data = 0.0; position_basj1.data = 0.0;
      position_bilekyaj.data = 0.0; position_bilekssj.data = 0.0;

      ij5_pub.publish(position_ij5); ij4_pub.publish(position_ij4); ij3_pub.publish(position_ij3); ij1_pub.publish(position_ij1);
      oj5_pub.publish(position_oj5); oj4_pub.publish(position_oj4); oj3_pub.publish(position_oj3); oj1_pub.publish(position_oj1);
      yj5_pub.publish(position_yj5); yj4_pub.publish(position_yj4); yj3_pub.publish(position_yj3); yj1_pub.publish(position_yj1);
      sj5_pub.publish(position_sj5); sj4_pub.publish(position_sj4); sj3_pub.publish(position_sj3); sj1_pub.publish(position_sj1);
      sleep(1); basj4_pub.publish(position_basj4); basj3_pub.publish(position_basj3); basj2_pub.publish(position_basj2); basj1_pub.publish(position_basj1);
      bilekyaj_pub.publish(position_bilekyaj); bilekssj_pub.publish(position_bilekssj);

      break;
    }

    case '1': {
      cout<<"Closing the alphabet\n";
      working=0;
      break;
    }

    default: {
      cout << "please enter the correct letter or enter 1 for exit\n";
      goto startline;
    }

  } 

    sleep(4);

  }

  if (ros::ok() && working!=0)
  {

    cout<<"working "<<working<<endl;

    goto startline;

  } 
  else{
    cout<<"Closing the code, working "<<working<<endl;
  }

  return 0;
}
