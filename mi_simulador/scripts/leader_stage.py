#!/usr/bin/env python
import rospy
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist
from std_msgs.msg import Empty


START = False

def callback_start(msg):
    global START

    START = True

DIST_FL = 1.0
DIST_F = 1.0
DIST_FR = 1.0
D = 0.5

def callback_laser(data):
    global DIST_FL
    global DIST_F
    global DIST_FR

    DIST_FL = min(data.ranges[len(data.ranges)*9/16+1:len(data.ranges)*11/16-1])
    DIST_F = min(data.ranges[len(data.ranges)*7/16+1:len(data.ranges)*9/16-1])
    DIST_FR = min(data.ranges[len(data.ranges)*5/16+1:len(data.ranges)*7/16-1])

def follow_R_wall():
    rospy.init_node('leader_node')
    rospy.Subscriber("/robot_0/base_scan_1", LaserScan, callback_laser)
    pub = rospy.Publisher("/robot_0/cmd_vel", Twist, queue_size=10)
    rospy.Subscriber("/start", Empty, callback_start)
    rate = rospy.Rate(10)

    PARED_INICIAL = False
    while not rospy.is_shutdown():
        if(START):                      # Espera hasta que el follower le mande la orden de empezar el movimiento
            move = Twist()

            while(not PARED_INICIAL):   # Bucle para encontrar la primera pared
                move.linear.x = 0.2

                if(DIST_F < D or DIST_FL < D or DIST_FR < D):   # Si se detecta alguna distancia por debajo del umbral
                    PARED_INICIAL = True

                pub.publish(move)
                rate.sleep()


            # Una vez encontrada la primera pared de referencia:
            if(DIST_F > D and DIST_FL > D and DIST_FR > D):     # Encuentra pared
                move.linear.x = 0.2
                move.angular.z = -0.5
            elif(DIST_F > D and DIST_FL > D and DIST_FR < D):   # Sigue pared
                move.linear.x = 0.2
            elif(DIST_F > D and DIST_FL < D and DIST_FR > D):   # Encuentra pared
                move.linear.x = 0.2
                move.angular.z = -0.5
            elif(DIST_F > D and DIST_FL < D and DIST_FR < D):   # Encuentra pared
                move.linear.x = 0.2
                move.angular.z = -0.5
            elif(DIST_F < D and DIST_FL > D and DIST_FR > D):   # Gira izquierda
                move.angular.z = 0.6
            elif(DIST_F < D and DIST_FL > D and DIST_FR < D):   # Gira izquierda
                move.angular.z = 0.6
            elif(DIST_F < D and DIST_FL < D and DIST_FR > D):   # Gira izquierda
                move.angular.z = 0.6
            elif(DIST_F < D and DIST_FL < D and DIST_FR < D):   # Gira izquierda
                move.angular.z = 0.6
            else:
                continue

            pub.publish(move)
            rate.sleep()


if __name__ == '__main__':
    follow_R_wall()