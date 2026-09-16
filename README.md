## See the project presentation with images in Project Documentation > Coffee_Tea Cooled Notification System.pptx


## LinkedIn Description:
A system using two independent Arduino boards connected via Bluetooth to transmit and process temperature sensor data, to detect and alert the user when a coffee or tea mug gets too cold from another room.

- Engineered a system to transmit sensor data between Arduino units using Bluetooth modules
- Processed and optimized data for detailed on-device analysis and reliable, real-time interpretation


## Objectives:
- Needs to alert me when the tea is cooled
  - Need to define what "cooled" means experimentally
  - Need to detect when the tea is cooled
- Signal needs to travel a long distance
  - Making a loud annoying noise is too easy, plus I have neighbors
- Alert needs to be obvious
  - Audible signals are not ideal because I use earbuds
  - Visual indicators would work great
 

## Development Notes:
- This was made for my Electronics course final project, and meant to be a pair project
- Partner was reached out to by both myself an the TAs to no success, so the project was fully developed alone
- AT commands for HC-05 communication and a significant portion of the code structure was learned from a YouTube tutorial:
  - https://www.youtube.com/watch?v=U8ogrhu3qWo
  - Channel name is "Ralph S Bacon", video title is "#196 Two-Way Bluetooth Serial Comms for Arduino and other µControllers"
 

## Setup Description:
- Board 1 is connected to DHT11 and HC-05, continuously reads sensor data and writes to Bluetooth serial connection
- Board 1 receives power from a USB power bank in my setup, sensor is positioned over tea using a stapler and tape
- Board 2 is connected to HC-05 and a few lasers, continually processes Bluetooth serial connection readings until a threshold is reached
- Board 2 code contains a rolling average value list that is updated every time a new reading is detected
- Board 2 processes the average of the rolling average list and checks if this average is greater than a threshold
- Board 2 activates a laser array when the threshold is reached
- Board 2 receives power from a computer USB port in my setup, lasers are positioned using a Lego Wall-e and tape in my setup


## Personal notes:
- I made this project because I drink a lot of tea, but often times I'm tired when I start the tea so I forget about it and it becomes cold
- Very barebones in terms of visual appeal, simply meant to work on a predefined budget
- Bluetooth configuration using the HC-05 modules was difficult to learn but straightforward once set up
- Rolling average database track a high amount of values to compensate for inconsistent temperature/humidity readings
- Lots of alternative ways to accomplish this, such as a timer but that's way less cool
