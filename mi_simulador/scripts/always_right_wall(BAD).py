#!/usr/bin/env python
import rospy
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist

DIST_L = 1.0
DIST_FL = 1.0
DIST_F = 1.0
DIST_FR = 1.0
DIST_R = 1.0
D = 0.5

def callback_laser(data):
    global DIST_L
    global DIST_FL
    global DIST_F
    global DIST_FR
    global DIST_R

    DIST_L = min(data.ranges[len(data.ranges)*11/16+1:len(data.ranges)*13/16])
    DIST_FL = min(data.ranges[len(data.ranges)*9/16+1:len(data.ranges)*11/16-1])
    DIST_F = min(data.ranges[len(data.ranges)*7/16+1:len(data.ranges)*9/16-1])
    DIST_FR = min(data.ranges[len(data.ranges)*5/16+1:len(data.ranges)*7/16-1])
    DIST_R = min(data.ranges[len(data.ranges)*3/16:len(data.ranges)*5/16-1])


def follow_R_wall():
    rospy.init_node('controller', anonymous=False)
    rospy.Subscriber("/base_scan", LaserScan, callback_laser)
    pub = rospy.Publisher("/cmd_vel", Twist, queue_size=10)
    rate = rospy.Rate(10)

    PARED_INICIAL = False
    while not rospy.is_shutdown():
        move = Twist()

        while(not PARED_INICIAL):    #Bucle para encontrar la primera pared
            move.linear.x = 0.2

            if(DIST_F < D or DIST_FL < D or DIST_FR < D):
                PARED_INICIAL = True

            pub.publish(move)
            rate.sleep()

        if(DIST_F > D and DIST_FL > D and DIST_FR > D):      #encuentra pared
            move.linear.x = 0.2
            move.angular.z = -0.7
        elif(DIST_F > D and DIST_FL > D and DIST_FR < D):    #sigue pared
            move.linear.x = 0.5
        elif(DIST_F > D and DIST_FL < D and DIST_FR > D):    #encuentra pared
            move.linear.x = 0.2
            move.angular.z = -0.7
        elif(DIST_F > D and DIST_FL < D and DIST_FR < D):    #encuentra pared
            move.linear.x = 0.2
            move.angular.z = -0.7
        elif(DIST_F < D and DIST_FL > D and DIST_FR > D):    #gira izq
            move.angular.z = 0.4
        elif(DIST_F < D and DIST_FL > D and DIST_FR < D):    #gira izq
            move.angular.z = 0.4
        elif(DIST_F < D and DIST_FL < D and DIST_FR > D):    #gira izq
            move.angular.z = 0.4
        elif(DIST_F < D and DIST_FL < D and DIST_FR < D):    #gira izq
            move.angular.z = 0.4
        else:
            continue

        pub.publish(move)
        rate.sleep()

if __name__ == '__main__':
    follow_R_wall()