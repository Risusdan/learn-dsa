# Arrays & Hashing

## Arrays

### What is array

An array is a collection of same-type data stored in contiguous memory locations.

### Things I should know about array

- The index of the array starts from 0.
- The address of the array is continuous.
- The elements of an array can not be deleted, but can be overridden.

#### Pros

- Fast access to elements (O(1))
- Cache-friendly due to contiguous memory allocation

> Cache-friendly means data is stored in consecutive memory locations, so when the CPU loads one piece of data, it automatically loads nearby data into its fast memory (cache), making subsequent data access much faster.

#### Cons

- Hard to insert or delete elements (requires shifting elements) (O(n))
- Size must be determined at compile time
- No range checking (can lead to buffer overflows)

## Hashing

### What is hash table

A hash table is a data structure that allows direct access based on the value of a key.

### Things I should know about hash table

- Generally, hash tables are used to quickly determine whether an element appears in a set, or to check the existence of an element.
- The time complexity of inserting, deleting, and searching for an element in a hash table is O(1).

#### Hash Function

- A *hash function* is used to map the key (no matter it is a string, integer, or other type) to a specific index in the hash table.
- There are many hash functions, but the most common one is the *modulo operation*.
- The hash function should be consistent, meaning the same key should always map to the same index.
- If the result of the hash function is bigger than the size of the hash table, we need to use a modulo operation to map the key to a valid index.

#### Collision

- A collision occurs when two different keys map to the same index.
- A good hash function should have low collision rate.
- There are many ways to handle collisions, but the most common one is the *chaining method*.
- The chaining method is to use a linked list to store the elements that map to the same index.

#### Implementations

- In Python, the hash table is usually implemented as a dictionary.
- In C++, the hash table is usually implemented as an unordered_map.
