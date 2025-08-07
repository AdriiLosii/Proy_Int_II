#!/usr/bin/env python
import rospy
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist
from std_msgs.msg import Empty


D_LIDER = 1.0
DIST_FL = 1.0
DIST_FR = 1.0
DIST_R = 1.0
D_D = 1.0

def callback_laser(data):
    global D_LIDER
    global DIST_FL
    global DIST_FR
    global DIST_R

    D_LIDER = min(data.ranges[len(data.ranges)*7/16:len(data.ranges)*9/16])
    DIST_FL = min(data.ranges[len(data.ranges)*8/16:len(data.ranges)*9/16])
    DIST_FR = min(data.ranges[len(data.ranges)*7/16:len(data.ranges)*8/16])
    DIST_R = min(data.ranges[len(data.ranges)*2/16:len(data.ranges)*6/16])


def follow_leader():
    rospy.init_node("follower_node")
    rospy.Subscriber("/robot_1/base_scan_1", LaserScan, callback_laser)
    pub = rospy.Publisher("/robot_1/cmd_vel", Twist, queue_size=10)
    pub_start = rospy.Publisher("/start", Empty, queue_size=10)
    rate = rospy.Rate(10)
    signal = Empty()

    while(not rospy.is_shutdown()):
        move = Twist()

        # Condicion de avance:
        if(D_LIDER > 0.3):          # Lider cerca
            move.linear.x = 0.2
            if(D_LIDER > 0.5):      # Lider lejos
                move.linear.x = 0.3
        else:
            pub_start.publish(signal)   # Indicamos al robot lider que estamos listos para que empiece el movimiento
            move.linear.x = 0.0

        # Condicion de giro:
        if(DIST_FL < DIST_FR):    # Gira izquierda
            move.angular.z = 0.7
        elif(DIST_FL > DIST_FR):  # Gira derecha
            move.angular.z = -0.7
            if(DIST_R < 0.2):    # Si se encuentra muy proximo a la pared de su derecha
                move.angular.z = -0.4
        else:
            move.angular.z = 0.0

        pub.publish(move)
        rate.sleep()


if __name__ == '__main__':
    follow_leader()