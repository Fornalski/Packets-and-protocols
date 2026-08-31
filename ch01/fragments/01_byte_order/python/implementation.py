"""
Chapter 0X — <Topic Name>
Python implementation.

Run: python3 implementation.py
"""
import struct
import numpy as np


def main():


    number = np.uint32(0x00345678)

    network = struct.pack("!I", number)
    little = struct.pack("<I", number)

    print("Network:", network.hex())
    print("Little: ", little.hex())

    print("Network length:", len(network))
    print("Little length: ", len(little))
    print("!H for uint16\n!I for uint32\n !Q for uint64\n")
    print("! or > for Network oreder\n< for host order")




if __name__ == "__main__":
    main()
