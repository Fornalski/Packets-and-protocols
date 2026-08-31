"""
Chapter 0X — <Topic Name>
Python implementation.

Run: python3 implementation.py
"""


def main():
    number = 2005
    print("Start value: ", number)

    print("Binary: ", bin(number))
    print("Hexadecimal: ", hex(number))
    print("Decimal: ", int(number))

    print("It is also possible to print like in C:\n0x",format(number,"08x"))
    
if __name__ == "__main__":
    main()
