# Summary: Introduction
## Primaly goals when creating internet
- Internet communiation must continue despite loss of networks or gateaways
- The Internet must support moltiple types of communication services
- The Internet architecture must accommodate a variety of networks
- The Internet architecture must be cost-effective
- The Internet architecture must prmit host attachment with a low level of effort
- The resources in the Internet must be accountable

## End to End and fate sharing
- __End to End__ (E2E):principle that states all of advanced features like reliability or security should be perform by the end points of communication instead of the network itself. It means that we treat systems as "smart" and the network itself as "dumb" This solution increases reliability and security itself, because systems (application layer)  has much more power then the network (network layer and below)
- __Fate sharing__: It is a consequence of E2E requireing to keep critical session data by hosts instead of network.

## Layering
__Layering__ - concept of splitting complex implementation into smaller chunks (layers in this case) that are easier to manage, undestand and implement

### ISO layers
__Host part__
- 7 - Application - The interactive element of the software used by the human.
- 6 - Presentation - The way of displaying sofware results (for example using ASCII standard for letters)
- 5 - Session - Working with sessions - closing, opening etc.
- 4 - Transport - Process-to-precess comunication acress the network, uses port numbers to multiplex/demultiplex data between apps on different hosts
__Network__
- 3 - Network - Decides about the packets format, and describes how comuniataion will be performed in defferent types of networks
- 2 - Link - Errors detection and methods for communiacation
- 1 - Physical - Is all about moveing data (bits) over the medium like wifi/ethernet cable.

### TCP/IP suite
- 5-7 Application - Interacts with user and other programs using protocols like HTTP, DNS or FTP
- 4 Transport - Responsible for data transfer between devices using TCP or UDP
- 3.5 Network - logic IPv4/IPv6 addressing and routing
- 2.5 - Link - mapping addresses, and transfering packets uses protocols like ARP

## forwarding types
_unicast_ - for a single host
_broadcast_ - for all hosts in specyfic network
_multicast_ - for set of hosts belonging to multicast group

## Ports
__Port numbers__: 16-bit intiger. In some way extension to the IP address. There are 65,536 ports that are forwarding the data to the transport protocols. first 1024 portr counting from 0 called "well know" ports are reserved for the specyfic protocols, range between 1024 and 49,151 are registered ports, and the remaining one belongs to the dynamic/private group.

## Tricky definitions
_internet_ (with lowercase "i") - aggregate network resulting from the interconnection of constituent networks over time
_Internet_ (with uppercase "I") - a network only hosts around the world that can connect with each other using TCP/IP
_Intranet_ - local private network used for instance by companies with firewalls guarding the local network from milicious data
_Extranet_ - Intranet but expended by accessing external hosts using VPNs. 

## Comunication types

_Client-server_ - there is specyfied client and server, and always the client aks server for some data, after processing the request server returns information, and wait for next request.
_Peer-to-peer_ - comunication between two hosts, where both of therm can be either server or host. 
