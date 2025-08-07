#!/usr/bin/env python
import rospy
from std_msgs.msg import Float64
import time


rospy.init_node('nodo_posicion_inicial')
# Defino los publicadores
pub_base = rospy.Publisher('/brazo/joint_base/command', Float64, queue_size=10)
pub_link1 = rospy.Publisher('/brazo/joint_link1/command', Float64, queue_size=10)
pub_link2 = rospy.Publisher('/brazo/joint_link2/command', Float64, queue_size=10)
pub_link3 = rospy.Publisher('/brazo/joint_link3/command', Float64, queue_size=10)
pub_cabeza = rospy.Publisher('/brazo/joint_cabeza/command', Float64, queue_size=10)

time.sleep(5)   # Espero 5 segundos

msg = Float64()
msg.data = 0.0

#Mandamos el robot a la posicion inicial
pub_base.publish(msg)
pub_link1.publish(msg)
pub_link2.publish(msg)
pub_link3.publish(msg)
pub_cabeza.publish(msg)