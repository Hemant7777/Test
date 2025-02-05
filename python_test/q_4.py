from collections import Counter

def count_characters(s):
    counts = Counter(s)
    for char, count in counts.items():
        print(f"'{char}': {count}", end=", ")
    print()

def run_test_cases():
    test_cases = ["hello", "world", "Python", "aabbcc", "12345"]
    for test in test_cases:
        print(f"Input: '{test}' → Output: ", end="")
        count_characters(test)

def get_valid_input():
    while True:
        user_input = input("Enter a string to count character occurrences: ")
        if user_input.strip():  # Ensure non-empty string
            print(f"Character counts for '{user_input}': ", end="")
            count_characters(user_input)
            break
        else:
            print("Error: Please enter a non-empty string.")

def main():
    # Run test cases
    print("Running default test cases...\n")
    run_test_cases()

    # Ask for user input
    print("\nNow, let's count character occurrences for your input:")
    get_valid_input()

if __name__ == "__main__":
    main()

