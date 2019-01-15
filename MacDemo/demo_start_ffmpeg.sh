mkdir -p log

nohup ./ffserver -f ../FFServer/ffserver_webcam.conf > log/ffserver_webcam.log &
nohup ./ffserver -f ../FFServer/ffserver_screen.conf > log/ffserver_screen.log &
nohup ./ffmpeg -f avfoundation -framerate 30 -pixel_format yuyv422 -i "0:0" http://localhost:8090/camera.ffm > log/ffmpeg_camera.log &
nohup ./ffmpeg -f avfoundation -framerate 30 -pixel_format yuyv422 -i "1" http://localhost:8091/screen.ffm > log/ffmpeg_screen.log &
