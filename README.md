# C Perceptron — A Terminal Analog Perceptron Simulator

> A one-afternoon reimplementation of the analog perceptron concept, done for fun after watching a video about how the very first "AI" worked. Nothing serious, but actually a decent way to see the idea in action.

---

## What is this?

This is a minimal C program that simulates the core logic of a **perceptron** — the building block behind the first generation of artificial neural networks, originally proposed by Frank Rosenblatt in 1958.

The idea is simple: you have a set of binary inputs (called *levers* here), each with a weight (*importance*). You train the system by deciding which inputs matter and how much. Then you present it with a test pattern and it tells you whether that pattern is recognised or not, based on a weighted sum compared to a threshold.

No libraries, no frameworks. Just C, a terminal, and a 4×4 grid of levers.

---

## How it works

The program walks you through three phases:

### 1. Training — set the levers
You activate the inputs that define your "known" pattern. The levers are displayed as a 4×4 grid (16 total). You flip them on or off one at a time.

```
lever
0 0 0 0
0 1 0 0
0 0 1 0
0 0 0 0
```

### 2. Training — assign weights
For each lever, you assign an *importance* value. A lever that matters a lot gets a high weight; one that's irrelevant gets 0 (or just don't touch it).

```
importance
0  0  0  0
0  8  0  0
0  0  5  0
0  0  0  0
```

### 3. Testing — present a new pattern
Now you set the *check* pattern — the input you want to test. The system computes:

```
output = sum of weights for each active check input + bias
```

Then it compares that output against the **activation threshold**, which is calculated as the average of all weights.

- `output < threshold` → **Pattern recognised**
- `output >= threshold` → **Pattern not recognised**

---

## Running it

Requires Windows (uses `windows.h` and `system("cls")`).

```bash
gcc perceptron.c -o perceptron -lm
./perceptron
```

Follow the prompts. At the end you can choose to test again with a different check pattern without re-training.

---

## Known limitations / honest notes

This was a quick experiment, not production code. A few things worth knowing:

- **Global state accumulates** — `value[]` and `check[]` use `+=` instead of `=`, so running multiple sessions in a row without restarting can give unexpected results. Resetting them to 0 before each loop would fix it.
- **`output` and `n` are not reset** when you choose to test again (`goto start`), which can throw off results on repeated runs.
- **Windows only** — `windows.h` and `system("cls")` make this non-portable. Replacing `cls` with `clear` and removing the Windows header would make it work on Linux/macOS.
- **No learning loop** — this is a *single-pass* perceptron, not a trainable one. Weights are set manually by the user, not adjusted automatically. That's intentional — the point is to show the concept, not train an actual model.
- **16 inputs hardcoded** — the grid is fixed at 4×4. Changing the `16` constants and the `%4==3` display logic would make it scalable.

---

## The concept behind it

A perceptron takes a vector of binary inputs **x**, multiplies each by a weight **w**, sums them up, adds a bias **b**, and passes the result through a step function:

```
output = Σ(xᵢ · wᵢ) + b

if output < threshold  →  class A (pattern recognised)
if output ≥ threshold  →  class B (pattern not recognised)
```

In this program, the threshold is dynamically computed as the average of all weights, which is a rough but functional approximation for demonstration purposes.

It's the same principle behind every modern neural network layer — just without the backpropagation, matrix ops, and GPU clusters on top.

---

## Files

```
perceptron.c    — everything, in one file
```

---

## Why

Saw a video about how the original Rosenblatt perceptron worked with physical switches and dials. Spent an afternoon translating that into C to see if the logic actually held up in code. It does.
