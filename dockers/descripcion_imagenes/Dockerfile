FROM mjenz/ros-kinetic-desktop-full
RUN mkdir -p ~/catkin_ws/src
RUN /bin/bash -c '. /opt/ros/kinetic/setup.bash; cd  ~/catkin_ws; catkin_make'
RUN echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc
RUN /bin/bash -c "source ~/.bashrc"