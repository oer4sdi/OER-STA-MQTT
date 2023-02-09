# SensorThings API Data loading via MQTT

Welcome everyone. Today we will learn about how to use MQTT to load sensor data into SensorThings API.

## Prerequisites
You must have a basic understanding on all these concepts before moving any further:
+ SensorWeb 
+ SensorThings API entities
+ Internet Protocols

Time taken: mins

Now, I welcome you all for this journey.

## Chapter 1 : IoT
Kevin Ashton, a tech pioneer, coined the term "Internet of Things" in 1999. The Internet of Things (IoT) is a term used to refer to a network of physical objects, or "things," that are equipped with sensors, software, and other technologies in order to communicate and exchange data with other systems and devices over the internet. These gadgets include everything from common household items to high-tech industrial tools. We frequently think of IoT devices as smart objects that can interact and exchange data over the Internet. Therefore, every device requires an Internet Protocol address in order to be uniquely identified, just like every home requires a postal address. The introduction of IPv6, which provides an almost infinite supply of IP addresses, appears to reinforce this viewpoint.


### Internet Protocol:
The Internet Protocol (IP) is a protocol, or set of guidelines, for addressing and routing data packets so they can move between networks and reach their intended location. The Internet divides data into smaller units known as packets for transmission. Each packet contains IP information, which allows routers to send packets to the correct location. 

We will learn more about IP in the next chapter.

***Did You Know: One of the more obvious benefits of IoT is inventory tracking.***

### 'Thing' in IoT:
Any natural or artificial object that can be given an IP address and can transfer data over a network qualifies as a "thing" in the internet of things. As of right now, there are more than 9 billion "Things" (physical objects) connected to the Internet.

## How Stuff Works?
Individual devices, databases, and gateways that connect multiple networks comprise IoT systems. They communicate with the internet primarily wirelessly and can send and receive data as well as commands. During transmission, sensitive data is protected and secured in the background by security solutions.

### Main Components of IoT
<p align="center">
  <img src='svg/IoT_components.svg' width='650'>
</p>

This is made possible by the interaction of interconnected components like microcontrollers, sensors, and actuators that transform electrical impulses into pressure, movement, temperature, or other mechanical variables. 

#### 1) Sensor
Humans can understand their surroundings through their five senses; machines require sensors to do so. The sensor on an object measures the state of its surroundings, and the data is processed by the system's microcontroller. This could be a simple temperature reading or a complex video feed. The data is then transmitted to software via the network. Thus, they are the most important data suppliers throughout the IoT.

Quiz: Can you name some sensors?

#### 2) Gateway 
To send the collected data from the sensor to the cloud, we need a connection. Sensors/devices can be connected to the cloud via cellular, satellite, WiFi, Bluetooth, low-power wide-area networks (LPWAN), or by connecting directly to the internet via ethernet. These are called Gateways. The best connectivity option depends on the IoT application, but they all accomplish the same thing: getting data to the cloud.

#### 3) Data Analytics
After the data is transferred to the cloud, software processes it. This could be something as simple as ensuring that the temperature reading falls within an acceptable range. It could also be very complex, such as using computer vision to identify objects in video (such as intruders in your house)

#### 4) User Interface
The data is then made useful to the end user in some way. This could be accomplished through a user alert (email, text, notification, etc). For example, a text alert when the temperature in the company's cold storage exceeds a certain threshold. The user may also be able to perform an action and influence the system, depending on the IoT application. For example, the user could use an app on their phone to remotely adjust the temperature in the cold storage.

### How One or More IoT Devices communicate?
When two networks or more IoT devices from the same or different networks communicate with one another, this phenomenon is known as communication assistance. Various communication protocols, such as ZigBee, MQTT, Constrained Application Protocol, FTP, and HTTP, among others, can be used to accomplish this. We will look into some of the communication protocols mentioned here in the upcoming chapter.

Look into Geek for geeks working of IoT diagram: 

### To sum it up:
An IoT system is made up of sensors/devices that communicate to the cloud via some form of gateway. Once the data reaches the cloud, software processes it and may decide to take action, such as sending an alert or automatically adjusting the sensors/devices with/without the user's intervention depending on the use case.

### How does IoT fit with the SensorThings API?
IoT devices and their data can be connected in an open and simple manner thanks to the OGC (Open Geospatial Consortium) SensorThings API standard. IoT therefore requires spatial interoperability, which is made possible by the SensorThings API. This means that location data must be shared and/or combined with location data from other sources. SensorThings' API is specifically designed for IoT devices with constrained resources. The API uses an efficient and user-friendly RESTful design, JSON encoding, and the MQTT messaging transport. 

> SensorThings API is one of the open international standards in the OGC Sensor Web Enablement (SWE) suite. The OGC SWE standards are a well-integrated set of web service interfaces and data encoding specifications. SWE standards enable developers to discover, access, and use all types of sensors, transducers, and sensor data repositories via the Web.

The location-enabled models of the SensorThings API enable sensor feeds from multiple sources to be integrated/aggregated and used more effectively for analytics, modeling, simulations, and so on. IoT application developers can use the OGC SensorThings API to connect to various IoT devices over the Web and create applications without having to worry about the diverse protocols used by various IoT devices, gateways, and services. 

To know more about SensorThings API, look into this module to get an introduction.

## Chapter 2 : Internet Protocols

#### How do IoT devices communicate with the web?

A protocol is a set of rules that determines how specific tasks are carried out and how data is formatted in networking so that two or more devices can communicate and understand one another. Network protocols enable easy communication with people all over the world and thus play an important role in modern digital communications. 

Consider this example, speaking the same language simplifies communication between two people. In similar fashion, network protocols allow devices to interact with each other through predetermined rules built into devices' software and hardware. Without network protocols, neither local area networks (LAN) nor wide area networks (WAN) could function as they do today. 

Although there are countless different network protocols, they all generally carry out one of three tasks:
+ Communication 
+ Network Administration 
+ Security

TCP/IP is one among these network protocols. We have a lot of technical words going on so buckle up for a ride.

### What is an IP?
A protocol, or set of guidelines, called the Internet Protocol (IP) is used to address and route data packets so they can move between networks and reach their intended location. The Internet divides data into smaller units known as packets for transmission. Every packet has an IP address attached to it, which enables routers to send packets to the appropriate location. Every device or domain that connects to the Internet is assigned an IP address, and data arrives where it is needed as packets are directed to the IP address assigned to them.  Each IP packet will include both the IP address of the device  and the IP address of the intended recipient, similar to how a piece of mail includes both the destination and return address.

<p align="center">
  <img src='svg/IPaddress.svg' width='650'>
</p>

> Did you find out your IP Address?

Once at their destination, packets are handled differently depending on which transport protocol is used in conjunction with IP. TCP is the most widely used transport protocol, which governs how data is transmitted and received.. The first version of IP (Internet Protocol) was IPv4. After IPv4, IPv6 came into the market, which has been increasingly used on the public internet since 2006.

### TCP/IP model

<p align="center">
  <img src='svg/TCP.svg' width='650'>
</p>

The TCP/IP model is split into four distinct layers. Used together, they can also be referred to as a suite of protocols.

1. Datalink layer <br/>
The datalink layer (also known as the link layer, network interface layer, or physical layer) is responsible for the physical aspects of sending and receiving data via Ethernet cable, wireless network, network interface card, computer device driver, and so on.

2. Network layer <br/>
The network layer (also called the internet layer) controls the movement of data packets around the network.

3. Transport layer <br/>
The transport layer is responsible for establishing a secure data connection between two devices. It divides the data into packets, acknowledges packets received from the other device, and ensures that the other device acknowledges packets received from it. This is referred to as end-to-end communication.

4. Application layer <br/>
The application layer includes all applications that require network communication. It defines standard Internet services and network applications that can be used by anyone. This is where the user usually interacts, such as with email and messaging.

### To sum it up:
TCIP/IP is the Internet's backbone: We couldn't surf the Web without these protocols. TCP/IP refers to a set of rules for transferring data packets in a Local Area Network (LAN) or Wide Area Network (WAN). TCP/IP divides each message into packets, which are then reassembled on the other end. Furthermore, TCP/IP divides the various communication tasks into layers. Each layer serves a distinct purpose. Data passes through four distinct layers before arriving at the other end (as explained above). TCP/IP then traverses these layers backwards in order to reassemble the data and present it to the recipient. The layers' goal is to maintain consistency so that no one hardware or software vendor must handle communication on their own.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

IoT protocols are essential components of the IoT technology stack. Hardware would be useless without IoT protocols and standards. This is because IoT protocols enable communication—that is, the exchange of data or the sending of commands—among all of those various devices.  IoT protocols come in a variety of varieties that have been developed and optimised for specific uses. The type of IoT protocol required is determined by the system architecture layer through which the data will travel.

## IoT Data Communication Protocols

To connect low-power IoT devices, IoT data protocols are used. They allow users to communicate with hardware without the need for an internet connection. In IoT data protocols and standards, connectivity is accomplished via a wired or cellular network. Here are some examples of IoT data protocols:

### HTTP
> The Hypertext Transfer Protocol (HTTP) is an application-layer protocol used to send hypermedia documents like HTML. It was created to facilitate communication between web browsers and web servers, but it can be used for other purposes as well. 

HTTP follows the traditional client-server model, with a client opening a connection to make a request and then waiting for a response. HTTP is a stateless protocol, which means that the server stores no data (state) between requests. However, in the context of IoT applications, HTTP has a number of disadvantages. For instance, this protocol creates a synchronous connection between two devices in order to transfer data, which poses several difficulties for IoT deployments because devices and endpoints might not be online simultaneously and connections might be unreliable due to network issues.

We transferred our sensor data using HTTP application protocol in the previous course. In this module let’s use another application protocol which is MQTT

### MQTT
> MQTT (MQ Telemetry Transport) is a lightweight messaging protocol designed for Internet of Things (IoT) devices. MQTT is based on the publisher/subscriber model and is managed by a central broker. This means that there is no direct connection between the sender and the receiver. The data sources publish their data, and all recipients with an interest in specific messages receive the data because they have registered as subscribers.

The MQTT protocol is supported by the SensorThings API in addition to the HTTP protocol, which improves the publish and subscribe capabilities of the SensorThings service. SensorThings MQTT adds the ability to create Observation entities via the MQTT protocol. Additionally, a client can send  a MQTT Subscribe request to sign up for notifications when certain entities are updated. MQTT publishers and subscribers are called MQTT clients.

### What’s an MQTT Topic?
MQTT topics are a type of addressing that allows MQTT clients to exchange data. MQTT Topics are organised in a hierarchical structure similar to folders and files in a file system, with the forward slash (/) serving as a delimiter.
+ The topics are case-sensitive. For instance, myhome/temperature and MyHome/temperature are two distinct topics. Furthermore, the slash is a topic in and of itself. 
+ Users can subscribe to a specific hierarchy level of a topic or use a wildcard (#) character to subscribe to multiple levels. For example, myhome/#
+ Topics that start with $ are not part of subscription

### MQTT Client and Broker
An MQTT client is any device that runs a MQTT library, ranging from a server to a microcontroller. One of the reasons MQTT is ideal for small devices is its ease of client implementation. The heart of every Publish/Subscribe protocol is the MQTT broker. A broker can manage thousands of MQTT clients at the same time, depending on the implementation. The functions of the broker are manifold:
+ The broker is in charge of receiving all messages, filtering them, determining who subscribed to each message, and sending the message to those clients who have subscribed. 
+ The Broker keeps track of all persistent clients' sessions, including subscriptions and missed messages. 
+ The Broker is also responsible for client authentication and authorization.
Since, MQTT Broker handles a lot of clients and are frequently exposed to the internet, it is critical that any MQTT broker be highly scalable, easily integrated into backend systems, easy to monitor, and fail-safe.

<p align="center">
  <img src='svg/MQTT.svg' width='650'>
</p>

### MQTT Connection
TCP/IP is the foundation of the MQTT protocol. A TCP/IP stack is required for both the client and the broker.
The MQTT connection is always established between a single client and the broker. Clients are never directly connected to one another. A MQTT client can be a publisher as well as a subscriber depending on the use case.

<p align="center">
  <img src='svg/MQTT-msg.svg' width='650'>
</p>

The client sends a CONNECT message to the broker to initiate a connection. A CONNACK message and a status code are returned by the broker. Once the connection is established, the broker maintains it until the client sends a disconnect command or the connection is terminated. As soon as the client connects to a broker, a client can publish/subscribe to a topic. When a client sends a message to a MQTT broker for publication(PUBLISH), the broker reads it, acknowledges it by sending a PUBACK message to the client (based on the QoS Level), and processes it.

Note: No information is provided to the publishing client by the broker regarding the number of clients who have seen the message or whether anyone is interested in it. It is the broker's responsibility to deliver the message to every subscriber after receiving the PUBLISH message.

The client sends a SUBSCRIBE message to the MQTT broker to receive messages on topics of interest. This subscribe message is very straightforward; it includes a unique packet identifier as well as a list of subscriptions. As an acknowledgement for each subscription, the broker sends the client a SUBACK message. 

We will look into the message workflows in more detail in the coming chapters.

### How to publish/subscribe to a topic?

MQTT employs topic-based message filtering on the broker. Each message must include a topic on which the broker can forward the message to interested clients. Each message typically has a payload that contains the data to be transmitted in byte format. Since, MQTT is data-independent, the sending client (publisher) chooses whether to send binary data, text data, or full-fledged XML or JSON. Messages can be sent with varying levels of Quality of Service (QoS):

<p align="center">
  <img src='svg/QoS.svg' width='650'>
</p>

### To sum it up:
+ While HTTP is an excellent choice for transferring website data, it is not a good choice for an IoT application in general.
+ An MQTT broker's job is to filter messages by topic and then distribute them to subscribers.
+ A client can receive these messages by subscribing to the same broker's topic.
+ A publisher and a subscriber do not have a direct relationship.
+ All clients have the ability to publish (broadcast) and subscribe (receive).
+ Messages are not typically stored by MQTT brokers.

## Chapter 3: Connecting Raspberry Pi with a Sensor using Node-Red
Let us first create an IoT device that can sense temperature and humidity. For that we will use Node-Red software.

### Material Required
+ Laptop or PC system (main computer)
+ Raspberry Pi 3 with Raspbian OS installed
+ DHT11 Sensor

### Software Required
+ Rapsberry pi Imager
+ Node-Red
+ VNC software

In this tutorial we will use Rapsberry Pi 3 has our microcomputer. You can also use other versions of Raspberry Pi as well.

### Step 1: How to setup Raspberry Pi 3
Raspberry Pis are great because they're cheap and small, but connecting one to its own monitor, keyboard, and mouse takes up a lot more space and money. Since we are just trying to program on the Pi with sensors, there's no need to connect it to a display or input devices because you can control the system remotely from your main computer using a VNC or SSH client. This screenless installation is known as a **headless Raspberry Pi** setup. But first let's install the Rasbian OS for your Raspberry Pi.

a) Watch this easy tutorial to setup Raspberry Pi 3 by M Heidenreich

[![Untitled presentation](https://user-images.githubusercontent.com/94603960/217582355-4291c209-45ca-4e1b-940d-1681f25d21b0.svg)](https://www.youtube.com/watch?v=u8bbp79haN4)

b) You can refer to this Official [Guide](https://www.instructables.com/How-to-Setup-Raspberry-Pi-Without-Monitor-and-Keyb/) by Raspberry Pi to setup your Raspberry Pi 3 for indepth understanding. <br/>
c) If you already configured Raspberry Pi without OS installed, with the help of Raspberry Pi [Imager](https://www.youtube.com/watch?v=ntaXWS8Lk34) you can install the OS

### Step 2: Connect Raspberry Pi 3 with DHT11 Sensor

https://user-images.githubusercontent.com/94603960/217584942-37875d8e-d7ef-4dd5-a67e-de3b9ecbd9da.mp4

Now your Raspberry Pi is linked to the DHT11 temperature and humidity sensor. The sensor collects the data and sends it to the Raspberry Pi.

### Step 3: Install Node Red in Raspberry Pi 3
Previously we learned how to access Raspberry Pi using headless setup. This is made possible by VNC and SSH.

1. VNC installation

For the next step, we will use VNC to install nodered. You can remotely control your Raspberry Pi from any location using VNC (Virtual Network Computing), which eliminates the need for a monitor and lets you control the desktop interface from another computer or mobile device. SSH, on the other hand, only allows access via the terminal. 

Follow this Official guide from VNC on how to [install and connect](https://raspberrypi-guide.github.io/networking/connecting-via-VNC) VNC with Raspberry Pi from your PC.

You can now view your Raspberry Pi in your main computer.

Node-RED is a powerful tool for developing Internet of Things (IoT) applications, with the goal of making the programming component as simple as possible. It employs visual programming, which enables you to connect nodes, to perform a task.

2. Node-Red installation

To install the Node-Red on Raspberry Pi, Open the Terminal and execute the below command.

```
bash <(curl -sL https://raw.githubusercontent.com/node-red/linux-installers/master/deb/update-nodejs-and-nodered)
```
When the installation is finished, you should see the Node-Red icon in your menu's programming apps list. You can start your node-red using the command: **node-red-start**

**Node-red commands** <br/>
+ node-red-start
+ node-red-stop
+ node-red-log(to view the recent log output)
+ sudo systemctl enable nodered.service (to autostart Node-RED at every boot)
+ sudo systemctl disable nodered.service(to disable autostart on boot)

For accessing the Node-Red portal using on the browser in your main computer, it should be connected to the same network as Raspberry Pi is connected. Open the Node-Red dashboard by typing this address in the browser
> http://your_Raspberrypi_ip:1880/

**add node palette**

### Step 4: Setup Node-Red in Raspberry Pi 3

Locate and click on Manage Palette once the Node-RED portal has been opened. 

![manage_palatte](https://user-images.githubusercontent.com/94603960/217740799-719df3c0-cf3f-4f5f-aa45-0632e25e7624.png)

Click on install to download the necessary nodes. You can install them by searching the name shown below.

+ Node-red-contrib-dht-sensor

It will ask for permission to install. Just click on Install.

![install_node](https://user-images.githubusercontent.com/94603960/217741069-92491d5b-1350-4457-a852-a26d9e85fa81.png)

**Creating flows** <br/>
Different nodes are listed on the left hand side. Drag and drop the nodes listed below.

![node](https://user-images.githubusercontent.com/94603960/217738635-0c421e0a-7c96-4f1f-951c-63f977a76587.png)

This `inject node` is used to control the interval of sensing data from the sensor.

https://user-images.githubusercontent.com/94603960/217738847-b5bed5bc-13a7-41b9-8ac3-d555befc58b6.mp4

## Chapter 4: Data loading via MQTT with Node-Red tutorial

Now that we have a functioning sensor data, let's learn how to load the data to our local SensorThings API (STA) via MQTT. Before any data loading, we need to understand how the STA works. In order to upload the observation, we need to have these entities: things, datastreams, location, observed property, feature of interest. Please see Chapter 4 of our module **'SensorWeb'** to understand the data model in which we used postman to create all of the entities mentioned above. Since Nodered has an inbuilt MQTT client, it’s easier to connect with the MQTT broker of STA. 

Let’s connect to the STA broker running in our PC to Raspberry Pi using Node-Red. 

**Step 1:** start the docker container of STA in your PC. <br/>
**Step 2:** drag and drop these nodes into the flow region
+ MQTT out
+ Function node

**Step 3:** double click the `MQTT out node`.

![Untitled presentation (1)](https://user-images.githubusercontent.com/94603960/217739297-189bd183-20e7-4fc9-bb48-19665a36dbba.svg)

Click add

![mqttnode](https://user-images.githubusercontent.com/94603960/217739547-29db8053-8090-47ba-98da-ed837cbe241c.png)

**Step 4:** for example, I have used tommy as my Client ID. Now, add the topic in the `MQTT out node` (remember that MQTT has a hierarchy based system for its data communication)

**Step 5:** specify the Quality of Service(Qos). I have selected QoS 1(for most of the projects, QoS 1 is best suited). Click done.

Whew, that's a hefty amount of work. Pat yourself in the back. Now, let’s load our sensor data into STA Observations.

**Step 6:** double click the `function node`. Edit the name with your choice of label(here, temperature). Since, the STA Observation entity has some mandatory properties to be filled. Let’s create the json structure in the function payload.

![Untitled presentation (2)](https://user-images.githubusercontent.com/94603960/217739848-4711a300-b93b-4870-994b-9c627c252bc8.svg)

From Observation UML diagram, the resultQuality, validTime and parameters are the optional properties of the observation entity. 

**Step 7:** connect the `function  node` with the `rpi node` and connect the  `mqtt out node` with the `function  node`. Click `deploy`.

Now, open the browser of your PC and type this address: 
> localhost/8081/v1.1

If everything works fine, you can already see your observations getting loaded into your STA.

The entire flow should look like this:

![workflow1](https://user-images.githubusercontent.com/94603960/217740006-e0e50a02-2de3-4dd3-8c31-0eceb2bbf28b.png)

Now, let’s do the same with humidity. For the humidity `function  node` json format: use `humidity datastreams id `and remember how the sensor gives the data(see the debug message from the sensor).

![humidity_fn](https://user-images.githubusercontent.com/94603960/217740204-6496d24a-74b5-42fd-ac33-b024eb1e4a27.png)

Now, the flow will look like this

![workflow2](https://user-images.githubusercontent.com/94603960/217740346-23295d74-dce5-4465-982d-44fefab042ad.png)

### Errors:

If you want to stop your MQTT upload, you can do so by disabling the `MQTT out node`. The flows are saved and you can stop the Node-Red by stopping Node-Red in the cmd.

![mqttnode_disabled](https://user-images.githubusercontent.com/94603960/217740502-207d4a5f-3595-4eb5-a749-aef961e72d25.png)

You have successfully uploaded your sensor data into STA via MQTT using Node-Red. Congratulations for finishing up this practical module



