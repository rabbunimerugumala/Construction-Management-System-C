# C Construction Management System

A console-based construction management application written in C, featuring project tracking, worker management, financial transactions, and attendance recording — all persisted via binary file storage.

## Features

- **Project Module** — Create, update, display, and close projects; track project-level transactions
- **Worker Module** — Register workers (senior/junior), manage profiles, record wage transactions (credit/debit)
- **Attendance Module** — Log daily worker attendance (Present/Absent) per project
- **Auto-generated IDs** — Projects (`CMP####`), Workers (`CMW####`), Transactions (timestamp-based)
- **Binary File Persistence** — Data stored in `.dat` files, no external database required
- **Menu-driven CLI** — Interactive console interface

## Project Structure

```
├── code/
│   ├── main.c              # Entry point & menu routing
│   ├── models.h            # Data structures (Project, Worker, Transaction, Attendance)
│   ├── project.h           # Project & project-transaction CRUD
│   ├── workers.h           # Worker & worker-transaction CRUD
│   ├── attendance.h        # Attendance CRUD
│   └── utils.h             # ID validation utilities
├── data/                   # Binary data files (.dat)
└── README.md
```

## Data Model

| Entity | Key Fields |
|--------|------------|
| **Project** | ID, name, type (contract/material/non-contract), status, budget, dates, owner info |
| **Transaction** | ID, project_id, date, amount |
| **Worker** | ID, name, type (senior/junior), wage, advance, contact info |
| **WorkerTransaction** | ID, worker_id, type (credit/debit), amount, date |
| **Attendance** | project_id, worker_id, date, status (P/A) |

## Build & Run

```bash
# Compile
gcc code/main.c -o construction-manager -I code

# Run
./construction-manager
```

*Requires: GCC / any C99-compatible compiler*

## Usage

1. Run the executable
2. Navigate menus via numeric options (1-4 for main modules)
3. Data auto-saves to `data/` directory

## Design Highlights

- **Modular headers** — Separation of concerns per domain
- **Fixed-size structs** — Direct binary `fread`/`fwrite` for simplicity
- **Seek-based updates** — In-place record modification via `fseek`
- **Validation layer** — ID existence checks before create/update

## Limitations / Future Improvements

- `fflush(stdin)` usage (Windows-specific) → replace with portable input clearing
- No input sanitization on `scanf` → add robust parsing
- Global struct instances → encapsulate in functions
- Hardcoded file paths → config file or CLI args
- No indexing — linear scans on all lookups

## License

MIT — free to use, modify, distribute.

---

**Built with C** | **Console Application** | **File-based Storage**