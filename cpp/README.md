## C++ Basic Concepts

### Output: `cout`

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

### Input: `cin`

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

### Initialization with `{}` (Brace Initialization)

In C++, brace initialization (`{}`) is a type of initialization that ensures type safety and helps avoid issues such as narrowing conversions. It will cause an error if the type of the variable does not match the type of the initializer.

#### Example:
```cpp
int num{10};    // Valid initialization
double pi{3.14}; // Valid initialization

int a{3.5}; // Error: narrowing conversion from double to int
```

With `{}`, there is no implicit type conversion, meaning any incompatible type assignments will result in an error.

---

### Functional Initialization

Functional initialization, which uses parentheses `()`, can be used to initialize variables as well. However, it behaves differently from brace initialization in some cases, particularly when it involves type conversions.

#### Example:
```cpp
int num(10);   // Valid initialization
double pi(3.14); // Valid initialization

int a(3.5); // This will truncate the value, resulting in a value of 3
```

Unlike `{}`, functional initialization can result in truncation of values if there's a type mismatch (e.g., `3.5` becomes `3` when assigned to an `int`).

---

### `sizeof()`

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

### `unsigned` and `signed`

In C++, the `signed` and `unsigned` keywords modify the behavior of integer types.

- **`signed`**: A signed type allows both positive and negative values. The default for integer types is `signed` unless specified otherwise.
- **`unsigned`**: An unsigned type only allows non-negative values (positive numbers and zero). This effectively doubles the range of positive numbers that can be represented, since no bits are used for the sign.

#### Example:
```cpp
unsigned int u = 10;  // 10 is stored as an unsigned integer
signed int s = -10;   // -10 is stored as a signed integer
```

---

### `short` and `long` Data Types

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

---

### `auto` Keyword

In C++, the `auto` keyword is used to automatically deduce the type of a variable from its initializer expression. This simplifies code by removing the need to explicitly specify the type, especially when dealing with complex types such as iterators.

#### Example:
```cpp
#include <iostream>

int main() {
    auto x = 10;    // Automatically deduced as int
    auto y = 3.14;  // Automatically deduced as double
    std::cout << "x: " << x << ", y: " << y << std::endl;
    return 0;
}
```

In the above example, the `auto` keyword allows the compiler to automatically determine that `x` is of type `int` and `y` is of type `double`.

---

### Prefix and Postfix Operators

In C++, prefix and postfix operators are used with increment (`++`) and decrement (`--`) operators to modify the value of a variable. These operators differ in when the operation occurs relative to the value of the expression.

- **Prefix (`++x` or `--x`)**: The value of the variable is modified before it is used in an expression.
- **Postfix (`x++` or `x--`)**: The value of the variable is modified after it is used in an expression.

#### Example:
```cpp
#include <iostream>

int main() {
    int x = 5;
    int y = ++x;  // Prefix: x is incremented first, then assigned to y (x becomes 6, y becomes 6)
    std::cout << "x: " << x << ", y: " << y << std::endl;
    
    int z = 5;
    int w = z++;  // Postfix: z is assigned to w first, then incremented (z becomes 6, w becomes 5)
    std::cout << "z: " << z << ", w: " << w << std::endl;
    
    return 0;
}
```

In the example above:
- In the prefix example (`++x`), `x` is incremented first, then its value is assigned to `y`.
- In the postfix example (`z++`), `z` is assigned to `w` first, then `z` is incremented.

---

### Boolean Operators

Boolean operators are used to perform logical operations, often in conditions such as `if` statements or loops. C++ provides the following Boolean operators:

- **`&&` (Logical AND)**: Returns `true` if both operands are true.
- **`||` (Logical OR)**: Returns `true` if at least one of the operands is true.
- **`!` (Logical NOT)**: Returns `true` if the operand is false, and `false` if the operand is true.

#### Example:
```cpp
#include <iostream>

int main() {
    bool a = true;
    bool b = false;

    std::cout << "a && b: " << (a && b) << std::endl;  // Logical AND: false
    std::cout << "a || b: " << (a || b) << std::endl;  // Logical OR: true
    std::cout << "!a: " << !a << std::endl;            // Logical NOT: false

    return 0;
}
```

In the example above:
- `a && b` evaluates to `false` because both operands are not true.
- `a || b` evaluates to `true` because at least one operand is true.
- `!a` evaluates to `false` because `a` is `true`.

---

### Relational and Logical Operators

#### Relational Operators

Relational operators are used to compare two values. These operators return a Boolean result (`true` or `false`) based on the comparison.

- **`==`**: Equal to. Returns `true` if both operands are equal.
- **`!=`**: Not equal to. Returns `true` if both operands are not equal.
- **`>`**: Greater than. Returns `true` if the left operand is greater than the right operand.
- **`<`**: Less than. Returns `true` if the left operand is less than the right operand.
- **`>=`**: Greater than or equal to. Returns `true` if the left operand is greater than or equal to the right operand.
- **`<=`**: Less than or equal to. Returns `true` if the left operand is less than or equal to the right operand.

#### Example:
```cpp
#include <iostream>

int main() {
    int a = 5;
    int b = 10;
    
    std::cout << "a == b: " << (a == b) << std::endl;  // False
    std::cout << "a != b: " << (a != b) << std::endl;  // True
    std::cout << "a > b: " << (a > b) << std::endl;    // False
    std::cout << "a < b: " << (a < b) << std::endl;    // True
    std::cout << "a >= b: " << (a >= b) << std::endl;  // False
    std::cout << "a <= b: " << (a <= b) << std::endl;  // True
    
    return 0;
}
```

In the example above, the relational operators compare `a` and `b` and print the results:
- `a == b` is `false` because `5` is not equal to `10`.
- `a != b` is `true` because `5` is not equal to `10`.
- `a > b` is `false` because `5` is less than `10`.
- `a < b` is `true` because `5` is less than `10`.
- `a >= b` is `false` because `5` is not greater than or equal to `10`.
- `a <= b` is `true` because `5` is less than or equal to `10`.

---

### Summary Table

| Operator  | Description           | Example                     | Result   |
|-----------|-----------------------|-----------------------------|----------|
| `&&`      | Logical AND           | `true && false`              | `false`  |
| `||`      | Logical OR            | `true || false`              | `true`   |
| `!`       | Logical NOT           | `!true`                      | `false`  |
| `==`      | Equal to              | `5 == 10`                    | `false`  |
| `!=`      | Not equal to          | `5 != 10`                    | `true`   |
| `>`       | Greater than          | `5 > 10`                     | `false`  |
| `<`       | Less than             | `5 < 10`                     | `true`   |
| `>=`      | Greater than or equal to | `5 >= 10`                  | `false`  |
| `<=`      | Less than or equal to | `5 <= 10`                    | `true`   |

--- 

### `std::endl`

In C++, `std::endl` is an I/O manipulator used to insert a newline character into the output stream and flush the output buffer. It is defined in the `<iostream>` library. The primary difference between `std::endl` and the newline character (`\n`) is that `std::endl` not only inserts a newline but also forces a flush of the output buffer, ensuring that the data is written immediately to the output (console, file, etc.).

#### Example:
```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;  // Prints "Hello, World!" and inserts a newline
    std::cout << "This is a new line." << std::endl; // Inserts another newline
    
    return 0;
}
```

In this example:
- `std::endl` adds a newline after the string "Hello, World!" and flushes the output buffer.
- The second use of `std::endl` similarly adds a newline after the string "This is a new line."

#### Key Points:
- `std::endl` is often used when you need a newline and to ensure the output is immediately written to the console or a file.
- Flushing the buffer can be useful in situations where you want to make sure the output appears in real-time, such as in debugging or logging.

---

### `std::flush`

`std::flush` is another I/O manipulator used to flush the output buffer of an output stream. Unlike `std::endl`, `std::flush` does not insert a newline character. It simply forces the output buffer to be written to the console or file, ensuring that all buffered data is output immediately.

#### Example:
```cpp
#include <iostream>

int main() {
    std::cout << "Processing..." << std::flush;  // Prints "Processing..." and flushes the buffer
    // The output will be immediately visible in the console without a newline.
    
    return 0;
}
```

In this example:
- The text "Processing..." is printed without a newline, and the output buffer is flushed immediately to ensure it is visible.
- The program does not add a newline, unlike `std::endl`.

#### Key Points:
- `std::flush` is useful when you want to ensure that output is immediately visible but do not want to add a newline.
- It is especially helpful for situations where you need to update the output incrementally or show real-time progress in a long-running process.

---

### Difference Between `std::endl` and `std::flush`

| Feature           | `std::endl`                       | `std::flush`                     |
|-------------------|-----------------------------------|----------------------------------|
| Inserts Newline   | Yes                               | No                               |
| Flushes Buffer    | Yes                               | Yes                              |
| Usage             | Typically used when a newline is needed along with flushing | Used when only flushing is needed without a newline |

--- 

### `std::setw`

`std::setw` is an I/O manipulator used to set the width of the next input/output field. It is part of the `<iomanip>` library. The `setw` manipulator specifies the width of the field in which the next value will be printed. If the value is shorter than the specified width, it will be padded with spaces (by default). If the value is longer than the specified width, the output will not be truncated.

#### Example:
```cpp
#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::setw(10) << 42 << std::endl;   // Output: "        42"
    std::cout << std::setw(10) << 12345 << std::endl; // Output: "     12345"
    
    return 0;
}
```

In this example:
- `std::setw(10)` sets the width of the output field to 10 characters.
- The value `42` is printed in a field of 10 characters, so it is padded with spaces on the left.
- The value `12345` is printed in a field of 10 characters as well, with spaces padding it on the left.

#### Key Points:
- The width set by `std::setw` is used only for the next output, not for subsequent ones.
- It is used primarily for formatting output in tabular data or aligning output.

---

### Right and Left Justified

By default, output is right-justified when using `std::setw`. However, you can change the justification using the manipulators `std::left` and `std::right`.

- **`std::right`**: Right-aligns the output (default behavior).
- **`std::left`**: Left-aligns the output.

#### Example:
```cpp
#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::setw(10) << std::right << 42 << std::endl;  // Output: "        42"
    std::cout << std::setw(10) << std::left << 42 << std::endl;   // Output: "42        "
    
    return 0;
}
```

In this example:
- `std::right` aligns the number `42` to the right of a 10-character wide field.
- `std::left` aligns the number `42` to the left of a 10-character wide field.

#### Key Points:
- `std::right` is the default justification.
- `std::left` can be used to align the output to the left.

---

### `std::boolalpha` and `std::noboolalpha`

In C++, the `std::boolalpha` manipulator is used to control the output format of boolean values (`true` or `false`). By default, boolean values are printed as `1` (true) or `0` (false). When `std::boolalpha` is used, `true` and `false` are printed as strings instead.

- **`std::boolalpha`**: Causes boolean values to be printed as `true` or `false`.
- **`std::noboolalpha`**: Restores the default behavior of printing `1` for `true` and `0` for `false`.

#### Example:
```cpp
#include <iostream>

int main() {
    bool flag = true;

    std::cout << std::boolalpha << flag << std::endl;    // Output: true
    std::cout << std::noboolalpha << flag << std::endl;  // Output: 1
    
    return 0;
}
```

In this example:
- `std::boolalpha` prints the boolean value `true` as `true`.
- `std::noboolalpha` prints the boolean value `true` as `1` (default behavior).

#### Key Points:
- `std::boolalpha` and `std::noboolalpha` control how boolean values are displayed.
- Use `std::boolalpha` for more readable boolean output when printing `true` or `false`.

---

### `std::scientific` and `std::fixed`

The `std::scientific` and `std::fixed` manipulators are used to control the format of floating-point numbers. These manipulators ensure that the numbers are displayed in either scientific or fixed-point notation.

- **`std::scientific`**: Forces the output to be in scientific notation (e.g., `1.23e+03`).
- **`std::fixed`**: Forces the output to be in fixed-point notation (e.g., `1234.56`).

#### Example:
```cpp
#include <iostream>
#include <iomanip>

int main() {
    double pi = 3.14159;

    std::cout << std::scientific << pi << std::endl;  // Output: 3.141590e+00
    std::cout << std::fixed << pi << std::endl;       // Output: 3.141590
    
    return 0;
}
```

In this example:
- `std::scientific` prints the number in scientific notation with an exponent.
- `std::fixed` prints the number in standard decimal notation, without using scientific notation.

#### Key Points:
- Use `std::scientific` when you want floating-point numbers to be printed in scientific notation.
- Use `std::fixed` when you want to display floating-point numbers in fixed-point notation (i.e., normal decimal format).

---

### `limits` Library

The `limits` library in C++ provides predefined constants and functions that allow you to retrieve the minimum and maximum values for various data types (e.g., integers, floating-point types).

- The main class in this library is `std::numeric_limits`.
- You can use `std::numeric_limits<T>::min()` and `std::numeric_limits<T>::max()` to get the minimum and maximum values for a data type `T`.

#### Example:
```cpp
#include <iostream>
#include <limits>

int main() {
    std::cout << "Min int: " << std::numeric_limits<int>::min() << std::endl; // Output: -2147483648
    std::cout << "Max int: " << std::numeric_limits<int>::max() << std::endl; // Output: 2147483647
    
    std::cout << "Min double: " << std::numeric_limits<double>::min() << std::endl; // Output: 2.22507e-308
    std::cout << "Max double: " << std::numeric_limits<double>::max() << std::endl; // Output: 1.79769e+308
    
    return 0;
}
```

In this example:
- `std::numeric_limits<int>::min()` retrieves the minimum value that an `int` can hold.
- `std::numeric_limits<int>::max()` retrieves the maximum value that an `int` can hold.
- Similarly, the minimum and maximum values for `double` are also retrieved.

#### Key Points:
- `std::numeric_limits<T>::min()` and `std::numeric_limits<T>::max()` are used to find the range of a specific data type.
- Useful when you need to know the limits of a data type for validating inputs or performing calculations.

---

### Summary Table

| Manipulator         | Description                          | Example                               |
|---------------------|--------------------------------------|---------------------------------------|
| `std::setw`          | Sets width of the next field         | `std::setw(10) << 42`                 |
| `std::left`          | Left justifies the output            | `std::left << 42`                     |
| `std::right`         | Right justifies the output (default) | `std::right << 42`                    |
| `std::boolalpha`     | Prints `true` and `false` for booleans| `std::boolalpha << true`              |
| `std::noboolalpha`   | Prints `1` and `0` for booleans      | `std::noboolalpha << true`            |
| `std::scientific`    | Prints floating point in scientific notation | `std::scientific << 123.45`        |
| `std::fixed`         | Prints floating point in fixed-point notation | `std::fixed << 123.45`            |
| `std::numeric_limits`| Provides the limits for data types   | `std::numeric_limits<int>::max()`     |
