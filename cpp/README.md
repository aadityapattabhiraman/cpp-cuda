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

### 1. **`auto` Keyword**

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

### 2. **Prefix and Postfix Operators**

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

### 3. **Boolean Operators**

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

### 4. **Relational and Logical Operators**

#### **Relational Operators**

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

