def factorial(n):
    if n == 0 or n == 1:
        return 1
    result = 1
    for i in range(2, n + 1):
        result *= i
    return result

def get_valid_input():
    while True:
        try:
            num = int(input("Enter a non-negative integer: "))
            if num < 0:
                print("Error: Please enter a non-negative integer.")
            else:
                return num
        except ValueError:
            print("Error: Invalid input. Please enter a valid integer.")

def run_test_cases():
    test_cases = [0, 1, 5, 7, 10]
    for num in test_cases:
        print(f"Factorial of {num}: {factorial(num)}")

def main():
    # Run test cases
    print("Running default test cases...\n")
    run_test_cases()

    # Ask for user input
    print("\nNow, Please enter a vaild no  input:")
    user_input = get_valid_input()
    print(f"Factorial of {user_input}: {factorial(user_input)}")

if __name__ == "__main__":
    main()

