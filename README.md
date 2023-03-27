Learn Image Processing Algorithms Using OpenCV
===
# 1. test Opencv in Docker container
- build docker image: `docker build -t ubuntu-20-opencv .` or pull from hub `vac611/ubuntu-20-opencv`
- run it with current folder attached inside as `gitrepo`: `docker run -it -v /Users/yourusername/GitRepos/ImageProcessingOpenCV/:/gitrepo vac611/ubuntu-20-opencv`
    - in winodws, you need to use `docker run -it -v "D:/GitRepos/MotionTrackingOpenCV":/gitrepo vac611/ubuntu-20-opencv:v1.1-pycv`
