# PGC-Ex-3-Synchronization Mechanisms in Parallel Programming

## Aim
To study and implement different synchronization mechanisms in parallel programming using OpenMP and POSIX Threads (Pthreads), and understand how they prevent race conditions and ensure correct execution of multithreaded programs.

## Overview
Synchronization is an important concept in parallel programming. When multiple threads access shared resources simultaneously, incorrect results may occur due to race conditions.

This experiment demonstrates different synchronization techniques and compares the execution time of Critical Section and Atomic Operations using different numbers of threads.

## Technologies Used
- **Programming Language:** C
- **Compiler:** GCC
- **Parallel Programming:** OpenMP
- **Thread Library:** POSIX Threads (Pthreads)
- **Operating System:** Ubuntu Linux
- **Code Editor:** Nano / VS Code

## Concepts Explained

### 1. Race Condition
A race condition occurs when multiple threads access and modify the same shared variable simultaneously without proper synchronization.

In this experiment, four threads increment a shared counter. Since there is no synchronization, some updates may be lost.

**File:** `race_condition.c`

### 2. Critical Section
A critical section is a portion of code that must be executed by only one thread at a time when accessing shared data.

OpenMP provides the `critical` directive to protect this section and prevent simultaneous access.

**Syntax:**
```c
#pragma omp critical
{
    counter++;
}
```

**File:** `critical_section.c`

### 3. Atomic Operation
An atomic operation ensures that a specific memory operation is performed safely without interference from other threads.

OpenMP provides the `atomic` directive for simple operations such as incrementing a shared counter.

**Syntax:**
```c
#pragma omp atomic
counter++;
```

**File:** `atomic_operation.c`

### 4. Barrier Synchronization
A barrier is a synchronization point where every thread must wait until all threads have reached that point.

OpenMP provides the `barrier` directive to coordinate the execution of multiple threads.

**Syntax:**
```c
#pragma omp barrier
```

**File:** `barrier.c`

### 5. Semaphore
A semaphore is a synchronization mechanism used to control access to shared resources.

This program uses a semaphore initialized to 1, allowing only one thread at a time to access the protected resource.

Important functions:
- `sem_init()` – Initializes the semaphore.
- `sem_wait()` – Waits for permission to access the resource.
- `sem_post()` – Releases the resource.
- `sem_destroy()` – Destroys the semaphore.

**File:** `semaphore.c`

### 6. Performance Comparison
This program compares Critical Section and Atomic Operations using different thread counts:

- 1 thread
- 2 threads
- 4 threads
- 8 threads

It measures execution time using `omp_get_wtime()` and checks the final counter value.

**File:** `comparison.c`

## Project Structure

```text
Experiment-5-Synchronization/
│
├── README.md
├── race_condition.c
├── critical_section.c
├── atomic_operation.c
├── barrier.c
├── semaphore.c
├── comparison.c
│
└── screenshots/
    ├── 02-openmp-check-and-project-folder.png
    ├── 03-race-condition-output.png
    ├── 04-critical-section-output.png
    ├── 05-atomic-operation-output.png
    ├── 06-barrier-output.png
    ├── 07-semaphore-output.png
    ├── 08-performance-comparison.png
    └── 09-project-files.png
```

## Installation and Compilation

### Step 1: Install GCC

```bash
sudo apt update
sudo apt install build-essential -y
```

### Step 2: Verify OpenMP

```bash
echo '#include <omp.h>' | gcc -E -fopenmp -xc - > /dev/null && echo "OpenMP OK"
```

### Step 3: Compile and Execute Programs

**Race Condition**
```bash
gcc -fopenmp race_condition.c -o race_condition
./race_condition
```

**Critical Section**
```bash
gcc -fopenmp critical_section.c -o critical_section
./critical_section
```

**Atomic Operation**
```bash
gcc -fopenmp atomic_operation.c -o atomic_operation
./atomic_operation
```

**Barrier Synchronization**
```bash
gcc -fopenmp barrier.c -o barrier
./barrier
```

**Semaphore**
```bash
gcc -pthread semaphore.c -o semaphore
./semaphore
```

**Performance Comparison**
```bash
gcc -fopenmp comparison.c -o comparison
./comparison
```

## Expected Observations

| Mechanism | Purpose | Expected Behaviour |
|---|---|---|
| Race Condition | Demonstrates unsynchronized shared access | Counter result may be incorrect |
| Critical Section | Protects a block of code | Correct counter |
| Atomic Operation | Protects a specific operation | Correct counter |
| Barrier | Coordinates thread execution | Threads wait for one another |
| Semaphore | Controls resource access | One thread accesses the resource at a time |
| Performance Comparison | Measures execution time | Compares Critical and Atomic operations |

**Note:** Actual execution times and race-condition results depend on the processor, operating system and scheduling. Record the results obtained on your own system.

## Screenshots and Execution Evidence

### 1. OpenMP Verification and Project Folder
(<img width="735" height="142" alt="02-openmp-check-and-project-folder" src="https://github.com/user-attachments/assets/180aa583-d2b6-4b74-bf6e-419439a68fa7" />
)

### 2. Race Condition Output
<img width="630" height="185" alt="03-race-condition-output" src="https://github.com/user-attachments/assets/c6aa1532-3db3-474a-aee2-9b47e71875dd" />


### 3. Critical Section Output
<img width="632" height="187" alt="04-critical-section-output" src="https://github.com/user-attachments/assets/3bec43a2-3e32-4725-beac-d96b63527043" />


### 4. Atomic Operation Output
<img width="633" height="167" alt="05-atomic-operation-output" src="https://github.com/user-attachments/assets/e0fa3a36-2c07-4c90-8007-ad838b813d62" />


### 5. Barrier Synchronization Output
<img width="642" height="310" alt="06-barrier-output" src="https://github.com/user-attachments/assets/a3631183-5781-48a5-b6c8-dc6504b951cf" />


### 6. Semaphore Output
<img width="647" height="210" alt="07-semaphore-output" src="https://github.com/user-attachments/assets/0f68d599-4066-443c-9874-af711cc1e49e" />


### 7. Performance Comparison

<img width="643" height="372" alt="08-performance-comparison" src="https://github.com/user-attachments/assets/fdd61217-37a7-4c56-9647-c7d3d457d4d2" />


### 8. Project Files
<img width="635" height="323" alt="09-project-files" src="https://github.com/user-attachments/assets/f817e038-fe21-4ce2-a94d-111e0e36b1d7" />


## Conclusion

In this experiment, different synchronization mechanisms were implemented using OpenMP and POSIX Threads.

We studied how Race Conditions occur and how Critical Sections, Atomic Operations, Barriers and Semaphores help coordinate multithreaded execution.

The performance comparison helped us understand the execution-time differences between Critical Section and Atomic Operations for different thread counts.

Thus, synchronization plays an important role in maintaining data correctness and coordination in parallel programs.

---
**Experiment:** 3 – Synchronization Mechanisms  
**Language:** C  
**Platform:** Ubuntu Linux
