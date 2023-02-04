#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import Float64

def talker():
    pubij5 = rospy.Publisher('/anael/ij5_position_controller/command', Float64, queue_size=10)
    pubij4 = rospy.Publisher('/anael/ij4_position_controller/command', Float64, queue_size=10)
    pubij3 = rospy.Publisher('/anael/ij3_position_controller/command', Float64, queue_size=10)
    pubij1 = rospy.Publisher('/anael/ij1_position_controller/command', Float64, queue_size=10)

    puboj5 = rospy.Publisher('/anael/oj5_position_controller/command', Float64, queue_size=10)
    puboj4 = rospy.Publisher('/anael/oj4_position_controller/command', Float64, queue_size=10)
    puboj3 = rospy.Publisher('/anael/oj3_position_controller/command', Float64, queue_size=10)
    puboj1 = rospy.Publisher('/anael/oj1_position_controller/command', Float64, queue_size=10)

    pubyj5 = rospy.Publisher('/anael/yj5_position_controller/command', Float64, queue_size=10)
    pubyj4 = rospy.Publisher('/anael/yj4_position_controller/command', Float64, queue_size=10)
    pubyj3 = rospy.Publisher('/anael/yj3_position_controller/command', Float64, queue_size=10)
    pubyj1 = rospy.Publisher('/anael/yj1_position_controller/command', Float64, queue_size=10)

    pubsj5 = rospy.Publisher('/anael/sj5_position_controller/command', Float64, queue_size=10)
    pubsj4 = rospy.Publisher('/anael/sj4_position_controller/command', Float64, queue_size=10)
    pubsj3 = rospy.Publisher('/anael/sj3_position_controller/command', Float64, queue_size=10)
    pubsj1 = rospy.Publisher('/anael/sj1_position_controller/command', Float64, queue_size=10)

    pubbasj4 = rospy.Publisher('/anael/basj4_position_controller/command', Float64, queue_size=10)
    pubbasj3 = rospy.Publisher('/anael/basj3_position_controller/command', Float64, queue_size=10)
    pubbasj2 = rospy.Publisher('/anael/basj2_position_controller/command', Float64, queue_size=10)
    pubbasj1 = rospy.Publisher('/anael/basj1_position_controller/command', Float64, queue_size=10)

    rospy.init_node('V_talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
	positionij5 = -0.08
	positionij4 = -0.08
	positionij3 = -0.08
	positionij1 = -0.15

	positionoj5 = -0.08
	positionoj4 = -0.08
	positionoj3 = -0.08
	positionoj1 = 0.15

	positionyj5 = -1.4
	positionyj4 = -1.4
	positionyj3 = -1.1
	positionyj1 = 0.0

	positionsj5 = -1.4
	positionsj4 = -1.4
	positionsj3 = -1.4
	positionsj1 = 0.0

	positionbasj4 = -0.08
	positionbasj3 = -1.0
	positionbasj2 = 1.4
	positionbasj1 = -0.24

        #rospy.loginfo(position9)
        pubij1.publish(positionij1)
	pubij3.publish(positionij3)
	pubij4.publish(positionij4)
	pubij5.publish(positionij5)

        puboj1.publish(positionoj1)
	puboj3.publish(positionoj3)
	puboj4.publish(positionoj4)
	puboj5.publish(positionoj5)

        pubyj1.publish(positionyj1)
	pubyj3.publish(positionyj3)
	pubyj4.publish(positionyj4)
	pubyj5.publish(positionyj5)

        pubsj1.publish(positionsj1)
	pubsj3.publish(positionsj3)
	pubsj4.publish(positionsj4)
	pubsj5.publish(positionsj5)

        pubbasj1.publish(positionbasj1)
	pubbasj2.publish(positionbasj2)
	pubbasj3.publish(positionbasj3)
	pubbasj4.publish(positionbasj4)

        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
