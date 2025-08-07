define kinect ranger
(
  sensor
  (
    range_max 6.5
    fov 58.0
    samples 640
  )
  # generic model properties
  color "black"
  size [ 0.06 0.15 0.03 ]
)

define hokuyo ranger
(
  sensor(
    range [0.02 4.0]
    fov 360.0
    samples 682
  )
  block(
    points 4
    point[0] [0 1]
    point[1] [1 1]
    point[2] [1 0]
    point[3] [0 0]
    z [0 1]
  )
  color "black"
  size [0.05 0.05 0.1]
  interval_sim 100
)

define turtlebot position
(
  block
  (
    points 16
    point[0] [0.225 0.000]
    point[1] [0.208 0.086]
    point[2] [0.159 0.159]
    point[3] [0.086 0.208]
    point[4] [0.000 0.225]
    point[5] [-0.086 0.208]
    point[6] [-0.159 0.159]
    point[7] [-0.208 0.086]
    point[8] [-0.225 0.000]
    point[9] [-0.208 -0.086]
    point[10] [-0.159 -0.159]
    point[11] [-0.086 -0.208]
    point[12] [-0.000 -0.225]
    point[13] [0.086 -0.208]
    point[14] [0.159 -0.159]
    point[15] [0.208 -0.086]
    z [0 1]
  )
  size [0.33 0.33 0.1]

  odom_error [0.03 0.03 999999 999999 999999 0.02]

  size [ 0.2552 0.2552 0.40 ]
  origin [ 0.0 0.0 0.0 0.0 ]
  gui_nose 1
  drive "diff"
  color "gray"
  
  kinect(pose [-0.1 0.0 -0.11 0.0])
  hokuyo(pose [0.0 0.0 0.0 0.0])
)
