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

package networksproject;

//
// TODO auto-generated module
//
simple Node
{
    parameters:
        int WS = default(3); //sender window size
        int WR = default(3); //receiver window size
        double TO = default(10); //sender timeout
        double TD = default(1.0); //transmission delay
        double PT = default(0.5); //processing time
        double ED = defualt(4.0); //error delay
        double DD = default (0.1) //duplication delay
        
    gates:
        output out;
        input inC;
        input inN;
    
}
