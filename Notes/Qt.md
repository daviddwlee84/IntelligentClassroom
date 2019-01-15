# Qt

## Random stuff

* What is ProjectName.pro.user?

    .user files are specific to one setup of Qt Creator. They can not be shared between workstations or developers. Please do not check them into your version control system.

## [Signals and Slots](https://doc.qt.io/archives/qt-4.8/signalsandslots.html)

In Qt, we have an alternative to the callback technique: signals and slots

### Signal

A signal is emitted when a particular event occurs. Qt's widgets have many predefined signals, but we can always subclass widgets to add our own signals to them

### Slot

A slot is a function that is called in response to a particular signal. Qt's widgets have many pre-defined slots, but it is common practice to subclass widgets and add your own slots so that you can handle the signals that you are interested in.

## Link

* [Getting Started With Qt and Qt Creator on MacOS](https://www.ics.com/blog/getting-started-qt-and-qt-creator-macos)

### Qt Usage

WebPage

* [Youtube - QT C++ GUI Tutorial 29- How to use QWebView and Open Web Page in QWebView](https://www.youtube.com/watch?v=nN85QMYZzQQ)

Open Link

* [How to open a link in a default user browser in Qt?](https://stackoverflow.com/questions/10250332/how-to-open-a-link-in-a-default-user-browser-in-qt)

Messenger

* [**Network Chat Example (P2P)**](http://doc.qt.io/qt-5/qtnetwork-network-chat-example.html)
* [Tutorial Qt Creator - Messenger en C++](https://www.youtube.com/watch?v=JjJpSdutyzk) - with client and server (in Spanish)

TCP Server

* [C++ Qt 67 - QTCPServer - a basic TCP server application](https://www.youtube.com/watch?v=BSdKkZNEKlQ)

Deployment

* [Deploying Qt Applications](https://doc.qt.io/qt-5/deployment.html)
  * [Qt for macOS - Deployment](https://doc.qt.io/qt-5/macos-deployment.html)
* [probonopd/linuxdeployqt](https://github.com/probonopd/linuxdeployqt) - Makes Linux applications self-contained by copying in the libraries and plugins that the application uses, and optionally generates an AppImage. Can be used for Qt and other applications
