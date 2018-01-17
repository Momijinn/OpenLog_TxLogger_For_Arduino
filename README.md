OpenLog_TxLogger_For_Arduino
====
OpenLogで使用するシリアル通信でログデータを収集するプログラム

## Description
[OpenLog](https://www.switch-science.com/catalog/2716/)でシリアル通信で受け取った文字列をSDカードへ書き込むプログラム

Arduino言語でコーディングしている

## Requirement
* SdFat.h

    [OpenLogのGitHub](https://github.com/sparkfun/OpenLog)をクローンし、libraryにある"SdFat"と"SerialPort"をローカルのArduinoに入れる

## Usage
シリアルコンソールにて文字を打ち込むと打ち込んだ文字列をSDカードへ保存する

打ち込む時に\r\n(CR LF)を入れること(入れないとタイムアウト(1sec待ち)が発生する)

マイコンに接続する場合はSerial.println()等の改行付きシリアル出力で一気に持ってくること(改行付きにしない(Serial.print()等)とタイムアウト(1sec待ち)が発生してしまう)

## Install
OpenLogUSBシリアル変換キットでパソコンと接続し、TxRxDataLogger.inoを書き込む

書き込む時にボードは"Arduino/Genuino Uno"にする

## Licence
This software is released under the MIT License, see LICENSE.

## Author
[Twitter](https://twitter.com/momijinn_aka)

[Blog](http://www.autumn-color.com/)