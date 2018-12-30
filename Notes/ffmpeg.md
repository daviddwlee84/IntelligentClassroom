# ffmpeg

```sh
# Compile the old version which contain ffserver
git clone https://git.ffmpeg.org/ffmpeg.git ffmpeg
cd ffmpeg
git checkout 2ca65fc7b74444edd51d5803a2c1e05a801a6023
./configure
# if you get an error: nasm/yasm not found or too old. Use --disable-x86asm for a crippled build.
# just install yasm: brew install yasm
make -j4

# You would like to export PATH to the folder to lead to the executable binary
```

Using Homebrew

[options](https://sites.duke.edu/ddmc/2013/12/30/install-ffmpeg-on-a-mac/)

```sh
# The newest version doesn't include ffserver
brew install ffmpeg
```

[Compile with OpenH264](VideoEncoding.md#H264)

```sh
./configure --enable-libopenh264
# if you didn't install OpenH264 will get the error
# ERROR: openh264 not found using pkg-config
```

## CLI

[link](https://trac.ffmpeg.org/wiki/Capture/Webcam#OSX)

### Avfoundation

[example](https://ffmpeg.org/ffmpeg-devices.html#Examples)

List the devices (ID)

```sh
# To list the supported, connected capture devices:
$ ffmpeg -f avfoundation -list_devices true -i ""
dation -list_devices true -i ""
ffmpeg version 4.1 Copyright (c) 2000-2018 the FFmpeg developers
  built with Apple LLVM version 10.0.0 (clang-1000.11.45.5)
  configuration: --prefix=/usr/local/Cellar/ffmpeg/4.1_1 --enable-shared --enable-pthreads --enable-version3 --enable-hardcoded-tables --enable-avresample --cc=clang --host-cflags= --host-ldflags= --enable-ffplay --enable-gpl --enable-libmp3lame --enable-libopus --enable-libsnappy --enable-libtheora --enable-libvorbis --enable-libvpx --enable-libx264 --enable-libx265 --enable-libxvid --enable-lzma --enable-opencl --enable-videotoolbox
  libavutil      56. 22.100 / 56. 22.100
  libavcodec     58. 35.100 / 58. 35.100
  libavformat    58. 20.100 / 58. 20.100
  libavdevice    58.  5.100 / 58.  5.100
  libavfilter     7. 40.101 /  7. 40.101
  libavresample   4.  0.  0 /  4.  0.  0
  libswscale      5.  3.100 /  5.  3.100
  libswresample   3.  3.100 /  3.  3.100
  libpostproc    55.  3.100 / 55.  3.100
[AVFoundation input device @ 0x7ff431c004c0] AVFoundation video devices:
[AVFoundation input device @ 0x7ff431c004c0] [0] FaceTime HD Camera
[AVFoundation input device @ 0x7ff431c004c0] [1] Capture screen 0
[AVFoundation input device @ 0x7ff431c004c0] AVFoundation audio devices:
[AVFoundation input device @ 0x7ff431c004c0] [0] Built-in Microphone
: Input/output error
```

Record from screen (in this case)

```sh
ffmpeg -f avfoundation -i "1" out.mpg
# Ctrl C to terminate

# Check the result
open out.mpg
```

Record from webcam (in this case)

```sh
# Record from webcam (in this case)
# 0:0 === video:audio
ffmpeg -f avfoundation -framerate 30 -i "0:0" out.mpg
```

> must specify framerate or you'll get the error `Selected framerate (29.970030) is not supported by the device`

### ffserver

[ffserver wiki](https://trac.ffmpeg.org/wiki/ffserver)

```sh
cd FFServer
# Starting the server
ffserver -f ffserver.conf
# (all the following settings depends on ffserver.conf)

# Starting FFMpeg (under macOS)
ffmpeg -f avfoundation -framerate 30 -pixel_format yuyv422 -i "0" http://localhost:8090/camera.ffm
# Press [q] to stop, [?] for help

# Play in VLC
http://localhost:8090/camera.mjpeg
```

Example settings

* [GithubGist - peterhellberg/ffserver.conf](https://gist.github.com/peterhellberg/ebfc72147c2009ee720aafe57ce9c141)
* [Official](https://ffmpeg.org/sample.html)

## Links

* [leandromoreira/ffmpeg-libav-tutorial](https://github.com/leandromoreira/ffmpeg-libav-tutorial) - [WIP] Learn FFmpeg libav the Hard Way
* [GithubGist - tomasinouk/ffmpeg_examples.md](https://gist.github.com/tomasinouk/8415acb4e2f86d54fcb9)

With Qt

* [wang-bin/QtAV](https://github.com/wang-bin/QtAV) - A cross-platform multimedia framework based on Qt and FFmpeg
* [Using FFMPEG in C++ with Qt Creator](https://infernusweb.altervista.org/wp/?p=553)
  * [pdf](https://infernusweb.altervista.org/wp/download/HMI/UsingFFMPEGinCwithQtCreator.pdf)

## Trouble shooting

ffserver? -> can't find in brew -> ffserver was removed from FFmpeg on 2018-01-06 ([link](https://superuser.com/questions/1296377/why-am-i-getting-an-unable-to-find-a-suitable-output-format-for-http-localho/1297419#1297419))

> without ffserver you can't output to an URL and will get the error
>
> `[NULL @ 0x7fd92a000000] Unable to find a suitable output format for 'http://localhost:8090/camera.ffm'`

There is a wierd thing. I've accidentally set format setting to *mpjpeg* and it should be *mjpeg*. But if I change to *mjpeg* or *avi* (I think any other correct format setting), when I open the URL it won't stream the video. Instead, it will pop out the download video message.
