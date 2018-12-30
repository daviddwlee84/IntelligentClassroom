# Other notes

## nohup

```sh
# ex1
nohup command-with-options &

# ex2
nohup sh custom-script.sh > custom-out.log &
```

* [Understanding Shell Script's idiom: 2>&1](https://www.brianstorti.com/understanding-shell-script-idiom-redirect/)
* [Unix Nohup: Run a Command or Shell-Script Even after You Logout](https://linux.101hacks.com/unix/nohup-command/)

## pkg-config

* [pkg-config - Unix, Linux Command](https://www.tutorialspoint.com/unix_commands/pkg-config.htm)
* [Guide to pkg-config](https://people.freedesktop.org/~dbn/pkg-config-guide.html)

The `.pc` file will be store in `/usr/lib/pkgconfig`

Regular usage

* `pkg-config --cflags <library>` - list header file dir to be include
* `pkg-config --libs <library>` - list library

Example of OpenCV

```sh
$ pkg-config --cflags opencv
-I/usr/local/include/opencv -I/usr/local/include

$ pkg-config --libs opencv
-L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core
```