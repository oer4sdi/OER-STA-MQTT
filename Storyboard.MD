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

## To sum it up:
An IoT system is made up of sensors/devices that communicate to the cloud via some form of gateway. Once the data reaches the cloud, software processes it and may decide to take action, such as sending an alert or automatically adjusting the sensors/devices with/without the user's intervention depending on the use case.

## How does IoT fit with the SensorThings API?
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


## To sum it up:
TCIP/IP is the Internet's backbone: We couldn't surf the Web without these protocols. TCP/IP refers to a set of rules for transferring data packets in a Local Area Network (LAN) or Wide Area Network (WAN). TCP/IP divides each message into packets, which are then reassembled on the other end. Furthermore, TCP/IP divides the various communication tasks into layers. Each layer serves a distinct purpose. Data passes through four distinct layers before arriving at the other end (as explained above). TCP/IP then traverses these layers backwards in order to reassemble the data and present it to the recipient. The layers' goal is to maintain consistency so that no one hardware or software vendor must handle communication on their own.



