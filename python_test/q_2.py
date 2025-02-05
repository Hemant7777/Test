def string_to_int(s):
    try:
        return int(s)
    except ValueError:
        return f"Error: Invalid literal for int()"

def run_test_cases():
    test_cases = ["123", "abc", "456", "78.9", "1000"]
    for test in test_cases:
        result = string_to_int(test)
        print(f"Input: '{test}', Output: {result}")

def get_valid_input():
    while True:
        user_input = input("Enter a string to convert to integer: ")
        result = string_to_int(user_input)
        print(f"Output: {result}")
        if isinstance(result, int):
            break  # Exit after valid integer input
        else:
            print("Please try again with a valid string.")

def main():
    # Run test cases
    print("Running default test cases...\n")
    run_test_cases()

    # Ask for user input
    print("\nNow, let's try with your input:")
    get_valid_input()

if __name__ == "__main__":
    main()

