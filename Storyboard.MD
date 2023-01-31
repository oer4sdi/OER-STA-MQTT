## IoT
The Internet of Things (IoT) is a term used to refer to a network of physical objects, or "things," that are equipped with sensors, software, and other technologies in order to communicate and exchange data with other systems and devices over the internet. These gadgets include everything from common household items to high-tech industrial tools.

### Internet Protocol:
The Internet Protocol (IP) is a protocol, or set of guidelines, for addressing and routing data packets so they can move between networks and reach their intended location. The Internet divides data into smaller units known as packets for transmission. Each packet contains IP information, which allows routers to send packets to the correct location. 

We will learn more about IP in the next chapter.

***Did You Know: One of the more obvious benefits of IoT is inventory tracking.***

### Thing in IoT:
Any natural or artificial object that can be given an IP address and can transfer data over a network qualifies as a "thing" in the internet of things. As of right now, there are more than 9 billion "Things" (physical objects) connected to the Internet.

## How Stuff Works?
Individual devices, databases, and gateways that connect multiple networks comprise IoT systems. They communicate with the internet primarily wirelessly and can send and receive data as well as commands. During transmission, sensitive data is protected and secured in the background by security solutions.

### Main Components of IoT
Diagram done in Slides with brief explanation

This is made possible by the interaction of interconnected components like microcontrollers, sensors, and actuators that transform electrical impulses into pressure, movement, temperature, or other mechanical variables. 

#### Why are sensors so important for the Internet of Things?
Humans can understand their surroundings through their five senses; machines require sensors to do so. The sensor on an object measures the state of its surroundings, and the data is processed by the system's microcontroller. This could be a simple temperature reading or a complex video feed. The data is then transmitted to software via the network. Thus, they are the most important data suppliers throughout the IoT.

Quiz: Can you name some sensors?

#### Gateway 
To send the collected data from the sensor to the cloud, we need a connection. Sensors/devices can be connected to the cloud via cellular, satellite, WiFi, Bluetooth, low-power wide-area networks (LPWAN), or by connecting directly to the internet via ethernet. These are called Gateways. The best connectivity option depends on the IoT application, but they all accomplish the same thing: getting data to the cloud.

#### Data Analytics
After the data is transferred to the cloud, software processes it. This could be something as simple as ensuring that the temperature reading falls within an acceptable range. It could also be very complex, such as using computer vision to identify objects in video (such as intruders in your house)

#### User Interface
The data is then made useful to the end user in some way. This could be accomplished through a user alert (email, text, notification, etc). For example, a text alert when the temperature in the company's cold storage exceeds a certain threshold. The user may also be able to perform an action and influence the system, depending on the IoT application. For example, the user could use an app on their phone to remotely adjust the temperature in the cold storage.

#### How One or More IoT Devices communicate?
When two networks or more IoT devices from the same or different networks communicate with one another, this phenomenon is known as communication assistance. Various communication protocols, such as ZigBee, MQTT, Constrained Application Protocol, FTP, and HTTP, among others, can be used to accomplish this. We will look into some of the communication protocols mentioned here in the upcoming chapter.

Look into Geek for geeks working of IoT diagram: 

## To sum it up:
An IoT system is made up of sensors/devices that communicate to the cloud via some form of gateway. Once the data reaches the cloud, software processes it and may decide to take action, such as sending an alert or automatically adjusting the sensors/devices with/without the user's intervention depending on the use case.

## How does IoT fit with the SensorThings API?

