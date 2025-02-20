## C++ Basic Concepts

### 1. Output: `cout`

In C++, the `cout` object is used to output data to the standard output (usually the console). It is part of the `<iostream>` library and works with the insertion operator (`<<`).

#### Example:
```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

This will output `Hello, World!` to the console.

---

### 2. Input: `cin`

The `cin` object is used for input, also part of the `<iostream>` library. It works with the extraction operator (`>>`) and is commonly used to get data from the user through the console.

#### Example:
```cpp
#include <iostream>

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "You entered: " << num << std::endl;
    return 0;
}
```

This allows the user to input a number, which is stored in the variable `num`.

---

### 3. Initialization with `{}` (Brace Initialization)

In C++, brace initialization (`{}`) is a type of initialization that ensures type safety and helps avoid issues such as narrowing conversions. It will cause an error if the type of the variable does not match the type of the initializer.

#### Example:
```cpp
int num{10};    // Valid initialization
double pi{3.14}; // Valid initialization

int a{3.5}; // Error: narrowing conversion from double to int
```

With `{}`, there is no implicit type conversion, meaning any incompatible type assignments will result in an error.

---

### 4. Functional Initialization

Functional initialization, which uses parentheses `()`, can be used to initialize variables as well. However, it behaves differently from brace initialization in some cases, particularly when it involves type conversions.

#### Example:
```cpp
int num(10);   // Valid initialization
double pi(3.14); // Valid initialization

int a(3.5); // This will truncate the value, resulting in a value of 3
```

Unlike `{}`, functional initialization can result in truncation of values if there's a type mismatch (e.g., `3.5` becomes `3` when assigned to an `int`).

---

### 5. `sizeof()`

The `sizeof()` operator is used to determine the size, in bytes, of a variable or data type. It is a compile-time operator, meaning it is evaluated at compile time and does not require the program to execute.

#### Example:
```cpp
#include <iostream>

int main() {
    int num;
    std::cout << "Size of int: " << sizeof(num) << " bytes" << std::endl;
    std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;
    return 0;
}
```

This will print the size of the `int` and `double` types in bytes, depending on your system's architecture.

---

### 6. `unsigned` and `signed`

In C++, the `signed` and `unsigned` keywords modify the behavior of integer types.

- **`signed`**: A signed type allows both positive and negative values. The default for integer types is `signed` unless specified otherwise.
- **`unsigned`**: An unsigned type only allows non-negative values (positive numbers and zero). This effectively doubles the range of positive numbers that can be represented, since no bits are used for the sign.

#### Example:
```cpp
unsigned int u = 10;  // 10 is stored as an unsigned integer
signed int s = -10;   // -10 is stored as a signed integer
```

---

### 7. `short` and `long` Data Types

C++ provides several integer types that represent different ranges of values. The `short` and `long` keywords are used to modify the size of an integer.

- **`short`**: Typically, a `short` integer takes 2 bytes of memory and represents values from `-32,768` to `32,767` (for `signed short`).
- **`long`**: A `long` integer typically takes 4 bytes (on most systems) and represents a larger range of values compared to `int`.

#### Example:
```cpp
short short_num = 32767;  // Maximum value for short
long long_num = 2147483647; // Maximum value for long (on most systems)
```

Note: The size of `short`, `long`, and other integer types may vary depending on the system architecture.

---

### Summary Table

| Type           | Size (typical) | Range (signed)            | Range (unsigned)          |
|----------------|----------------|---------------------------|---------------------------|
| `char`         | 1 byte         | -128 to 127               | 0 to 255                  |
| `short`        | 2 bytes        | -32,768 to 32,767         | 0 to 65,535               |
| `int`          | 4 bytes        | -2,147,483,648 to 2,147,483,647 | 0 to 4,294,967,295 |
| `long`         | 4 bytes        | -2,147,483,648 to 2,147,483,647 | 0 to 4,294,967,295 |
| `long long`    | 8 bytes        | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 | 0 to 18,446,744,073,709,551,615 |
| `float`        | 4 bytes        | 1.2E-38 to 3.4E+38        | N/A                       |
| `double`       | 8 bytes        | 2.3E-308 to 1.7E+308      | N/A                       |
| `long double`  | 16 bytes       | 3.4E-4932 to 1.1E+4932    | N/A                       |

(Note: Sizes and ranges can vary based on system architecture.)

