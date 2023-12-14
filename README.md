# Cairo University Computer Networks - Fall 2023

## Data Link Layer Protocols Simulation

This repository contains the source code and documentation for the term project of the Computer Networks course at Cairo University, Faculty of Engineering, Fall 2023. The project involves the development, simulation, and testing of data link layer protocols between two nodes connected by a noisy channel.

### Project Overview

In this project, you will implement a simulation of data link layer protocols using the Selective Repeat algorithm. The communication takes place between two nodes ([Node0, Node1]) connected through a noisy channel, where packets may experience various errors such as corruption, duplication, delay, or loss.
### System Inputs

1. Each node reads its list of messages from a specific input text file (`input0.txt` for Node0 and `input1.txt` for Node1).
2. Messages are formatted with a 4-bits binary prefix indicating the possibility of [Modification, Loss, Duplication, Delay].
3. Errors are applied to the message itself, and Checksum is applied to the original message before framing.


### Error Codes

Errors are represented in a binary format (4 bits). Table 1 provides details about error codes and their effects.

#### Table 1: Error Codes and Their Meanings

| Error Code | Effect                                      |
|------------|---------------------------------------------|
| 0000       | No error                                    |
| 0001       | Delay                                       |
|            |   For example, using the default delays:     |
|            |   @t=0 read line                             |
|            |   @t=0.5 end processing time                 |
|            |   @t=5.5 the message is received.           |
| 0010       | Duplication                                 |
|            |   For example, using the default delays:     |
|            |   @t=0 read line                             |
|            |   @t=0.5 end processing time                 |
|            |   @t=1.5 version 1 of the message is received.|
|            |   @t=1.6 version 2 of the message is received.|
| 0011       | Make two versions of the message and add to their|
|            | sending time the delay error.                |
|            |   For example, using the default delays:     |
|            |   @t=0 read line                             |
|            |   @t=0.5 end processing time                 |
|            |   @t=5.5 version 1 of the message is received.|
|            |   @t=5.6 version 2 of the message is received.|
| 0100       | Loss                                        |
|            |   For example, using the default delays:     |
|            |   @t=0 read line                             |
|            |   @t=0.5 end processing time                 |
|            |   @t=0.5 read the next line.                 |
| 0101       | Loss                                        |
|            |   For example, using the default delays:     |
|            |   @t=0 read line                             |
|            |   @t=0.5 end processing time                 |
|            |   @t=0.5 read the next line.                 |
| 0110       | Loss of the both messages                   |
|            |   For example, using the default delays:     |
|            |   @t=0 read line                             |
|            |   @t=0.5 end processing time                 |
|            |   @t=0.5 read the next line.                 |
| 0111       | Loss of both messages                        |
|            |   For example, using the default delays:     |
|            |   @t=0 read line                             |
|            |   @t=0.5 end processing time                 |
|            |   @t=0.5 read the next line.                 |
| 1000       | Modification                                |
|            |   For example, using the default delays:     |
|            |   @t=0 read line                             |
|            |   @t=0.5 end processing time                 |
|            |   @t=1.5 the modified message is received.  |
| 1001       | Modification and delay                      |
|            |   For example, using the default delays:     |
|            |   @t=0 read line                             |
|            |   @t=0.5 end processing time                 |
|            |   @t=5.5 the modified message is received.  |
| 1010       | Modification and Duplication                |
|            |   For example, using the default delays:     |
|            |   @t=0 read line                             |
|            |   @t=0.5 end processing time                 |
|            |   @t=1.5 version 1 of the modified message is received.|
|            |   @t=1.6 version 2 of the modified message is received.|
| 1011       | Modification and Duplication and Delay      |
|            |   For example, using the default delays:     |
|            |   @t=0 read line                             |
|            |   @t=0.5 end processing time                 |
|            |   @t=5.5 version 1 of the modified message is received.|
|            |   @t=5.6 version 2 of the modified message is received.|
| 1100       | Loss                                        |
|            |   For example, using the default delays:     |
|            |   @t=0 read line                             |
|            |   @t=0.5 end processing time                 |
|            |   @t=0.5 read the next line.                 |
| 1101       | Loss                                        |
|            |   For example, using the default delays:     |
|            |   @t=0 read line                             |
|            |   @t=0.5 end processing time                 |
|            |   @t=0.5 read the next line.                 |
| 1110       | Loss for both messages                      |
|            |   For example, using the default delays:     |
|            |   @t=0 read line                             |
|            |   @t=0.5 end processing time                 |
|            |   @t=0.5 read the next line.                 |
| 1111       | Loss for both messages                      |
|            |   For example, using the default delays:     |
|            |   @t=0 read line                             |
|            |   @t=0.5 end processing time                 |
|            |   @t=0.5 read the next line.                 |


### Coordinator

A coordinator initializes the communication, choosing the starting node and time. Information is read from the `coordinator.txt` file.

### Parameters

Parameters are set in the `.ini` file and include window sizes, timeout intervals, processing times, and various delays in the system.

### Delays in the System

The system introduces processing delays, transmission delays, error delays, and duplication delays.

### System Outputs

The system generates a log file (`output.txt`) containing detailed information for each message transmission from both nodes. The console also displays the same information.

### Messages

Each message contains a header, frame type, ACK/NACK number, payload, and trailer. Framing is done using the byte stuffing algorithm with starting and ending flags.

### Error Detection

Checksum is used for error detection, checking the payload before applying byte stuffing. ACK/NACK numbers are set based on the sequence number of the next expected frame or the erroneous frame.

### Selective Repeat Protocol

The simulation implements the Selective Repeat protocol, considering timeout, window size, and a noisy channel. The coordinator initializes communication, and the starting node sends messages, receiving ACK or NACK from the receiver.

### Simulation Completion

The simulation ends when the sender node finishes sending all messages and receives all corresponding ACKs.

### Project Delivery

The project delivery and discussion time is scheduled for Wednesday of week 13. Teams can have a maximum of four members.

### Getting Started

1. Clone this repository.
2. Set parameters in the `.ini` file.
3. Run the simulation.

Feel free to reach out if you have any questions or need further clarification.

**Note:** Assumptions should be communicated via the classroom if any detail is missing from the project document about the protocol.

*Visualization of the Selective Repeat algorithm can be found [here](https://www.baeldung.com/cs/selective-repeat-protocol#example).*
