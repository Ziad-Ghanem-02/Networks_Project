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

//
// TODO generated message class
//
cplusplus {{
#include <bitset>
typedef  std::bitset<8> bits;
}}
class bits { @existingclass; }

packet MyMessage {
    @customize(true);  // see the generated C++ header for more info
    int Seq_Num; //think of this as part 1 of header
    int M_Type; //0 for data, 1 for ACK, 2 for NAK, 3 for Coordinator initialize, think of this as part 2 of header
    int Ack_Num; //ack no
    string M_Payload; 
    bits mycheckbits; //think of this as trailer
}




