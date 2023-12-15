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

#ifndef __NETWORKSPROJECT_NODE_H_
#define __NETWORKSPROJECT_NODE_H_

#include <omnetpp.h>
#include <bitset>
#include <vector>
#include "string.h"

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Node : public cSimpleModule
{
  protected:
    int sender = -1; //if 1 then I'm the sender, if 0 I'm the receiver, if -1 then still unset
    int buffersUsed; //number of buffers that I've used so far
    int frameNumber; //for setting sequence numbers
    int frameExpected; //lower edge of receiver window
    int tooFar; //upper edge of receiver window PLUS ONE (3ashan between function is implemented be tare2a weird kda)
    int ackExpected; //lower edge of sender window
    int nextFrameToSend; //upper edge of sender window PLUS ONE (3ashan between function is implemented be tare2a weird kda)
    int nodeNumber; //if I'm Node0 then nodeNumber=0, if I'm Node1 then nodeNumber=1
    double processingTime;
    bool noNak;
    bool arrived[par("WR").intValue()]; // Used by receiver to check if it has received frame "i"//TODO: check if this creates error cuz I'm not using dynamic allocation
    int WR;
    int WS;
    int TO;
    //TODO: string buffers for sender and receiver
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif
