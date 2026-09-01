"""
Chapter 0X — <Topic Name>
Python implementation.

Run: python3 implementation.py
"""
import ipaddress 

def main():

    addresses = [
    "127.0.0.1",
    "192.168.1.100",
    "8.8.8.8",
    "255.255.255.255",
    "::1",
    "2001:4860:4860::8888",
    "999.999.999.999",
    "hello"
    ]      
    network = ipaddress.ip_network("192.168.1.0/24")
    for address in addresses:
        try:
            ip = ipaddress.ip_address(address)
            print(f"\nIp address {address}")
            print(f"Version: IPv{ip.version} ")
            print(f"Is private: {ip.is_private}")
            if( ip in network):
                print(f"Also belongs to the network: {network}")


        except ValueError:
            print(f"\nInput: {address}: Invalid IP address")    
        
if __name__ == "__main__":
    main()
