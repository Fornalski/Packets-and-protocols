#Packets-and-protocols

Notes and small implementations built while working through **TCP/IP Illustrated, Vol. 1 (2nd edition)**, chapter by chapter.

## Status
🟡 Just started — structure is set up, first chapters in progress.

## Plan
- One folder per chapter: hand notes scanned showing my way of understanding the process, short C/Python implementation, and some more described in details below
- Chapters covered so far: project in preparation stage
- Not limited to the book's original 2000s-era content — I'm cross-referencing modern RFCs and protocol extensions where relevant

## Why
Long-term goal is a networking-focused career (network admin, eventually protocol/standards work). This repo is where the reading turns into something I actually built, not just read about.

## Repo sturcture
```
packets-and-protocols/
├── README.md
├── LICENSE
├── .gitignore
├── requirements.txt
├── docs/
│   ├── reference.md              # Python/C commands & syntax used across implementations
│   ├── resources.md              # books, RFCs, articles, blogs used in the learning process
│   └── chapter-template/         # skeleton copied into every new ch0X folder
│       ├── README.md
│       ├── notes/
│       │   └── understanding.md
│       ├── python/
│       ├── c/
│       ├── SOLUTION.md
│       ├── DELTA.md
│       ├── pcap/
│       └── diagrams/
└── ch01-<topic-name>/
    └── [chapter structure as defined in docs/chapter-template/]
```
## ch0X - Chapter layout
**What to expect from each file:**

| File | Purpose |
|------|---------|
| `README.md` | Entry point — summary + how to run the code |
| `notes/understanding.md` | Concept explained in plain language in the way I understood the topic |
| `python/` | Working Python implementation of the chapter's concept (if python relevant) |
| `c/` | Working C implementation of the chapter's concept (if C relevant) |
| `SOLUTION.md` | What the implementation does, why it's built that way, what it doesn't handle |
| `DELTA.md` | Since the book is from 2000s-era standards, this covers what's changed since — modern extensions, RFCs, current practice |
| `pcap/` | Real captured packets illustrating the chapter's protocol in action |
| `diagrams/` | Visual aids for anything sequential (handshakes, state machines, flows) |

## Implementations

| # | Fragment | Language(s) | What it does | Code |
|---|----------|-------------|---------------|------|
| 01 | Byte Order | Network vs host byte order conversion, round-trip verified | [C](ch01-.../fragments/01_byte_order/c) · [Python](ch01-.../fragments/01_byte_order/python) |
| 02 | Number Base Converter  | Bin/hex/dec conversion for reading raw header fields | [C](...) · [Python](...) |
| 03 | IP Address Tools | Validation and manipulation of IPv4/IPv6 addresses | [C](...) · [Python](...) |
| 04 | CIDR Calculator | Network/broadcast address and usable range from prefix | [C](...) · [Python](...) |
| 05 | Hex Dump | Raw byte buffer → readable hex+ASCII view | [C](...) · [Python](...) |
| 06 | Checksum | IP/TCP/UDP checksum, verified against RFC 1071 example | [C](...) · [Python](...) |
| 07 | TCP Client/Server | Minimal socket boilerplate | [C](...) · [Python](...) |
| 08 | MAC Address Tools | Formatting and validation | [C](...) · [Python](...) |
| 09 | Struct Formats | Header struct ↔ Python struct format string mapping | [C](...) · [Python](...) |

## License
MIT
