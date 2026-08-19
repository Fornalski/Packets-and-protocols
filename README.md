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
Packets-and-protocols/
├── README.md
├── LICENSE 
├── .gitignore
├── docs/
│   ├── reference.md        # Python/C important commands/syntax required to create implementation
│   └── resources.md        # optional: books, RFC-s, articles, blogs I've used in learning process
├── ch01-<topic-name>/
│    └── [chapter sturc described bolow]
└── requirements.txt      

## Per-chapter folder structure
Every chapter follows the same layout:

    ch0X-<topic>/
    ├── README.md              # what this chapter covers, how to run it
    ├── notes/
    │   └── understanding.md   # the topic explained in my own words
    ├── python/                # Python implementation
    ├── c/                     # C implementation
    ├── SOLUTION.md            # what was built, design decisions, limitations
    ├── DELTA.md                # what's changed since the book (modern context, RFCs)
    ├── pcap/                  # captured traffic relevant to this chapter (if any)
    └── diagrams/               # supporting sketches/diagrams (if any)

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

Every new chapter template available in: `docs/chapter-template/`

## License
MIT
