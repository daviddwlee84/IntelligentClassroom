# WebRTC

RTC stands for Real Time Communication

* [Official Website](https://webrtc.org/)
* [Getting Started](https://webrtc.org/start/)
    * [Google I/O 2013](https://youtu.be/p2HzZkd2A40)
* [Github](https://github.com/webrtc)
    * [webrtc/samples](https://github.com/webrtc/samples)
* [Native Code](https://webrtc.org/native-code/) - The WebRTC Native Code package is meant for browser developers who want to integrate WebRTC.
    * [repository](https://webrtc.googlesource.com/src) - `git clone https://webrtc.googlesource.com/src`
    * [WebRTC Native APIs](https://webrtc.org/native-code/native-apis/)

## API

Three main tasks of WebRTC

* Acquiring audio and video
* Communicating audio and video
* Communicating arbitrary data

JavaScript API

Native API (C++)

* [WebRTC API](https://w3c.github.io/webrtc-pc/) - Application developers are encouraged to use the WebRTC API instead.

## Compile WebRTC

[Prerequisite Software](https://webrtc.org/native-code/development/prerequisite-sw/)

[chromium / chromium / tools / depot_tools](https://chromium.googlesource.com/chromium/tools/depot_tools) ([Install depot_tools](https://www.chromium.org/developers/how-tos/install-depot-tools), [Using depot_tools](https://www.chromium.org/developers/how-tos/depottools))

[Install depot_tools](https://chromium.googlesource.com/chromium/src/+/HEAD/docs/mac_build_instructions.md#install)

```sh
# Install depot_tools
git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git
# Add path
export PATH="$PATH:/path/to/depot_tools"
```

* **fetch** - A gclient wrapper to checkout a project.

### From original Google git repository

### Use libwebrtc

#### Compile on MacOS

```sh
$ git clone https://github.com/vsimon/webrtcbuilds.git
$ cd webrtc-builds
$ ./build.sh

...

[6:13:25] Still working on:
[6:13:25]   src/third_party/icu
Syncing projects: 100% (35/35), done.
Running: git submodule foreach 'git config -f $toplevel/.git/config submodule.$name.ignore all'
Running: git config --add remote.origin.fetch '+refs/tags/*:refs/tags/*'
Running: git config diff.ignoreSubmodules all
Syncing projects: 100% (35/35), done.

...

Packaging WebRTC
Build successful
```

This will build

* `src/` - 16.09GB
* `webrtcbuilds-26099-7e0978c-mac-x64/` - 1.26GB
  * `include/` - 38.7MB
  * `lib/` - 1.22GB
* `webrtcbuilds-26099-7e0978c-mac-x64.zip` - 274.8MB

#### Cross compile

```sh
# Corss compile on cloud server (because it really take lots of time)
# but this project doesn't work for me
$ git clone https://github.com/sourcey/webrtc-builds.git
$ cd webrtcbuilds
$ ./build.sh -t mac # default target cpu is x64
```

## Links

### Example

* [brkho/client-server-webrtc-example](https://github.com/brkho/client-server-webrtc-example) - An example for using WebRTC to communicate between a JavaScript client and a C++ server.
  * [blog](http://blog.brkho.com/2017/03/15/dive-into-client-server-web-games-webrtc/)
* [llamerada-jp/webrtc-cpp-sample](https://github.com/llamerada-jp/webrtc-cpp-sample) - Sample program for using WebRTC on C++. (didn't work)
* [Github - anyRTC-RTMP-OpenSource](https://github.com/anyRTC/anyRTC-RTMP-OpenSource)
  * [anyRTC official website](https://www.anyrtc.io/)

### WebRTC building helper

* [vsimon/webrtcbuilds](https://github.com/vsimon/webrtcbuilds) - Getting started with WebRTC natively is no easy picnic. The goal of webrtcbuilds is to provide a single standalone WebRTC static library and package.
* [sourcey/webrtc-builds](https://github.com/sourcey/webrtc-builds)
* [llamerada-jp/libwebrtc](https://github.com/llamerada-jp/libwebrtc.git)
* [aisouard/libwebrtc](https://github.com/aisouard/libwebrtc) - Google's WebRTC implementation in a single static library.

build script

* [pristineio/webrtc-build-scripts](https://github.com/pristineio/webrtc-build-scripts) - A set of build scripts useful for building WebRTC libraries for Android and iOS.