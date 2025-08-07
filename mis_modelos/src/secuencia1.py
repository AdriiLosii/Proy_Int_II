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

time.sleep(2)   # Espero 2 segundos

# Defino las variables de control para cada articulacion
base = Float64()
link1 = Float64()
link2 = Float64()
link3 = Float64()
cabeza = Float64()

## Primer movimiento:
# Defino los valores de cada variable para crear la secuencia deseada
base.data = -3.14
link2.data = -1.5708

# Publicamos los valores en los topics de movimiento de cada articulacion
pub_base.publish(base)
pub_link1.publish(link1)
pub_link2.publish(link2)
pub_link3.publish(link3)
pub_cabeza.publish(cabeza)

time.sleep(10)   # Espero 5 segundos


## Segundo movimiento:
# Defino los valores de cada variable para crear la secuencia deseada
link1.data = 1.5708
link3.data = 1.5708

# Publicamos los valores en los topics de movimiento de cada articulacion
pub_base.publish(base)
pub_link1.publish(link1)
pub_link2.publish(link2)
pub_link3.publish(link3)
pub_cabeza.publish(cabeza)

time.sleep(10)   # Espero 5 segundos


## Tercer movimiento:
# Defino los valores de cada variable para crear la secuencia deseada
base.data = 0.0
link1.data = 0.0
link3.data = 0.0

# Publicamos los valores en los topics de movimiento de cada articulacion
pub_base.publish(base)
pub_link1.publish(link1)
pub_link2.publish(link2)
pub_link3.publish(link3)
pub_cabeza.publish(cabeza)

time.sleep(10)   # Espero 5 segundos


## Cuarto movimiento:
# Defino los valores de cada variable para crear la secuencia deseada
link1.data = 1
link2.data = -1
link3.data = 1.5708

# Publicamos los valores en los topics de movimiento de cada articulacion
pub_base.publish(base)
pub_link1.publish(link1)
pub_link2.publish(link2)
pub_link3.publish(link3)
pub_cabeza.publish(cabeza)