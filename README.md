<img src="./images/scheme.png" >

# Argriculture Of Things

> Subtitle or Short Description Goes Here

> include terms/tags that can be searched
---

## Hardware

- 1 x Raspberry Pi 3 model B+
- 1 x Arduino Uno Rev3
- 2 x nRF27l01+
- 1 x Soil Moisture Capacitive Sensor
- 1 x DHT11
---

## What software you need for this project
- Arduino
  - Arduino IDE
  - <a href="https://tmrh20.github.io/RF24/">NRF24L01+</a> Library
- Raspberry Pi
  - Rasbian OS
  - <a href="https://tmrh20.github.io/RF24/">NRF24L01+</a> Library
  - NodeJS
  - Npm
- Machine Learning
  - 1
  - 2
- Android Application
  - Android Studio
---

## Clone
- Clone this repo to your local machine using `git clone https://github.com/open-aot/AgricultureOfThings`

## Installation

### Arduino
- Arduino-Sensors Pins Layout
<img src="./images/arduino_pin_layout.png" >

- Load Code to the board and start Transmitting
  - Open Arduino IDE
  - Open `Tools->Manage Libraries` and install the `RF24 by TMRh20` lirbary
  - Load the code from the file: `./arduino/transmitter.ino` to the Arduino

### Raspberry Pi

#### Receiver
- Raspberry-nRF27l01+ Pins Layout
<img src="./images/raspberry_pin_layout.png">

- Install the Library
> Download and install the RF24 library
```shell
$ git clone https://github.com/nRF24/RF24
$ cd ~/Downloads/RF24/
$ ./configure
$ make
```

- Start Receiving
> Compile and run the receiver.cpp
```shell
$ cd <this repo path>/raspberry-pi/rf24-receiver/
$ g++ receiver.cpp -o receiver -L/home/pi/Downloads/RF24 -lrf24
$ ./receiver & 
```
##### Server
Use your raspberry pi as server in your local network for the android application.
> Serve the data that received from the Arduino.
```shell
$ cd <this repo path>/raspberry-pi/android-app-server/
$ npm start 
```


### Machine Learning

### Android Application
- Open Android Studio
- Select `Import project (Gradle, Eclipse ADT, etc.)`
- Naviage to the folder `<this repo path>/android-app` and select `OpenAgriculture`
- Change `SERVER_LOCAL_IP` in the files bellow to your server's IP

./app/src/main/java/com/example/openagriculture/<a href="./android-app/OpenAgriculture/app/src/main/java/com/example/openagriculture/OApiService.kt">OApiService.kt</a>
```kotlin
private const val BASE_URL = "<SERVER_LOCAL_IP>";
```
./app/src/main/res/xml/<a href="./android-app/OpenAgriculture/app/src/main/res/xml/network_security_config.xml">network_security_config.xml</a>
```xml
<domain-config cleartextTrafficPermitted="true">
    <domain includeSubdomains="true">SERVER_LOCAL_IP</domain>
</domain-config>
```
- Follow this <a href="https://www.google.com/search?sxsrf=ACYBGNQKs0acHAsWa5DUQYUEpE2Wrcljtg%3A1571835012110&source=hp&ei=hEywXZPyA8-QkwXR4KOYBw&q=how+to+install+android+app&oq=how+to+install+android+app&gs_l=psy-ab.3..0l10.862.9140..9455...5.0..0.186.3477.10j21......0....1..gws-wiz.......0i131j0i13j0i22i30.tKcNbfmjLiY&ved=0ahUKEwiTxKjctbLlAhVPyKQKHVHwCHMQ4dUDCAU&uact=5">tutorial</a> to install the application to your smartphone

## License

[![License](http://img.shields.io/:license-mit-blue.svg?style=flat-square)](http://badges.mit-license.org)

- **[MIT license](http://opensource.org/licenses/mit-license.php)**
- Copyright 2015 © <a href="http://fvcproductions.com" target="_blank">FVCproductions</a>.


## Example (Optional)

```javascript
// code away!

let generateProject = project => {
  let code = [];
  for (let js = 0; js < project.length; js++) {
    code.push(js);
  }
};
```
---
## Table of Contents (Optional)

- [Installation](#installation)
- [Features](#features)
- [Contributing](#contributing)
- [Team](#team)
- [FAQ](#faq)
- [Support](#support)
- [License](#license)
---

## Features
## Usage (Optional)
## Documentation (Optional)
## Tests (Optional)

- Going into more detail on code and technologies used
- I utilized this nifty <a href="https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet" target="_blank">Markdown Cheatsheet</a> for this sample `README`.

---

## Contributing

> To get started...

### Step 1

- **Option 1**
    - 🍴 Fork this repo!

- **Option 2**
    - 👯 Clone this repo to your local machine using `https://github.com/joanaz/HireDot2.git`

### Step 2

- **HACK AWAY!** 🔨🔨🔨

### Step 3

- 🔃 Create a new pull request using <a href="https://github.com/joanaz/HireDot2/compare/" target="_blank">`https://github.com/joanaz/HireDot2/compare/`</a>.

---

## Team

> Or Contributors/People

| <a href="http://fvcproductions.com" target="_blank">**FVCproductions**</a> | <a href="http://fvcproductions.com" target="_blank">**FVCproductions**</a> | <a href="http://fvcproductions.com" target="_blank">**FVCproductions**</a> |
| :---: |:---:| :---:|
| [![FVCproductions](https://avatars1.githubusercontent.com/u/4284691?v=3&s=200)](http://fvcproductions.com)    | [![FVCproductions](https://avatars1.githubusercontent.com/u/4284691?v=3&s=200)](http://fvcproductions.com) | [![FVCproductions](https://avatars1.githubusercontent.com/u/4284691?v=3&s=200)](http://fvcproductions.com)  |
| <a href="http://github.com/fvcproductions" target="_blank">`github.com/fvcproductions`</a> | <a href="http://github.com/fvcproductions" target="_blank">`github.com/fvcproductions`</a> | <a href="http://github.com/fvcproductions" target="_blank">`github.com/fvcproductions`</a> |

- You can just grab their GitHub profile image URL
- You should probably resize their picture using `?s=200` at the end of the image URL.

---

## FAQ

- **How do I do *specifically* so and so?**
    - No problem! Just do this.

---

## Support

Reach out to me at one of the following places!

- Website at <a href="http://fvcproductions.com" target="_blank">`fvcproductions.com`</a>
- Twitter at <a href="http://twitter.com/fvcproductions" target="_blank">`@fvcproductions`</a>
- Insert more social links here.

---

## Donations (Optional)

- You could include a <a href="https://cdn.rawgit.com/gratipay/gratipay-badge/2.3.0/dist/gratipay.png" target="_blank">Gratipay</a> link as well.

[![Support via Gratipay](https://cdn.rawgit.com/gratipay/gratipay-badge/2.3.0/dist/gratipay.png)](https://gratipay.com/fvcproductions/)


---
