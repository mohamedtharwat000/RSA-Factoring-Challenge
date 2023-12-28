# RSA Factoring Challenge

This project aims to solve the RSA Factoring Challenge by implementing a Python script that factors given numbers using a brute-force approach. The goal is to find the prime factors of each number and print the factorization in the format `number=prime_factor_1*prime_factor_2`.

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The RSA Factoring Challenge is a cryptographic challenge that involves factoring large composite numbers. This project provides a Python script to factor numbers using a simple brute-force algorithm. It reads numbers from a file and finds their prime factors, printing the factorization for each number.

## Installation

To use the RSA Factoring Challenge script, follow these steps:

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/rsa-factoring-challenge.git
   ```

2. Navigate to the project directory:

   ```
   cd rsa-factoring-challenge
   ```

3. Run the script:
   ```
   python3 factors.py input_file.txt
   ```

## Usage

The script reads numbers from an input file and factors each number using a brute-force approach. The factorization is printed in the format
`number=prime_factor_1*prime_factor_2`

To use the script, follow these steps:

1. Prepare an input file containing the numbers to factor, with each number on a separate line.

2. Run the script using the following command:

   ```
   python3 factors.py input_file.txt
   ```

3. The script will iterate through the numbers, find their prime factors, and print the factorization for each number.

## Examples

Here are some examples of how to use the script:

Suppose you have an input file named numbers.txt with the following contents:

```plaintext
15
21
35
```

To factor the numbers in the file, run the script as follows:

```bash
python3 factors.py numbers.txt
```

The output will be:

```plaintext
15=3*5
21=3*7
35=5*7
```

For more examples, refer to the code files.

## Contributing

Contributions are welcome! Here are some ways you can contribute to this project:

- Report bugs and issues
- Fix bugs and issues
- Add new validation functionality
- Improve styling and overall UX
- Refactor code to improve quality
- Write documentation and improve existing docs

To contribute:

1. Fork the repository
2. Create a new branch
3. Make your changes and commit them
4. Push your branch and submit a pull request

I will review pull requests and provide feedback.

## License

This project is open source and available under the [MIT License](LICENSE).

## Credits

created by [Mohamed Tharwat](https://github.com/mohamedtharwat000)
