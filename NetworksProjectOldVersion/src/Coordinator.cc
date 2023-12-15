//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Coordinator.h"
#include "MyMessage_m.h"
#include "string.h"
#include <iostream>
#include <fstream>

Define_Module(Coordinator);

void Coordinator::initialize()
{
    // TODO - Generated method body
    // Read the coordinator.txt file
    std::ifstream file("coordinator.txt");
    std::string line;
        // Assuming the line contains two parameters separated by a space
    int nodeId ;
    double startTime;
    std::istringstream iss(line);
    iss >> nodeId >> startTime;


    // Close the file
    file.close();
    std::string msgsend = "You're the master";
    MyMessage_Base * nodeMessage = new MyMessage_Base(msgsend.c_str());
    nodeMessage->setM_Payload(msgsend.c_str());
    //0 for data, 1 for ACK, 2 for NAK, 3 for Coordinator initialize, think of this as part 2 of head
    nodeMessage->setM_Type(3);
    if (nodeId == 0)
    {
        //TODO: assuming sendDelayed takes delay parameter in seconds
        sendDelayed(nodeMessage,startTime,"out0");

    }
    else if(nodeId == 1)
    {
        sendDelayed(nodeMessage,startTime,"out1");
    }
}

void Coordinator::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
}
