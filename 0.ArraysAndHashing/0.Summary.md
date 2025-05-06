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

#### Pros

- Fast search, insert, and delete (O(1))
- Can use various types as keys (integer, string, etc.)
- Maintains fast performance even when the size of the data is large

#### Cons

- May need to allocate more memory than actually used to prevent collisions
- Performance heavily depends on the quality of the hash function
- Need collision resolution strategies

#### Implementations

- In Python, the hash table is usually implemented as a dictionary.
- In C++, the hash table is usually implemented as an unordered_map.

```cpp
std::unordered_set<T> set;

// 1. Insertion
set.insert(value);      // Insert element
set.emplace(value);     // Construct and insert

// 2. Search
set.count(value);       // Returns 1 if exists, 0 if not
set.find(value);        // Returns iterator to element or set.end()
set.contains(value);    // C++20: Returns true if exists (bool)

// 3. Deletion
set.erase(value);       // Remove element
set.clear();            // Remove all elements

// 4. Size Operations
set.size();            // Number of elements
set.empty();           // Check if empty
```

```cpp
std::unordered_map<Key, Value> map;

// 1. Insertion
map[key] = value;                // Insert or update
map.insert({key, value});        // Insert only
map.emplace(key, value);         // Construct and insert
map.try_emplace(key, value);     // More efficient insert

// 2. Access/Search
map[key];                        // Access or create
map.at(key);                     // Access (throws if not found)
map.count(key);                  // Returns 1 if exists, 0 if not
map.find(key);                   // Returns iterator
map.contains(key);               // C++20: Returns bool

// 3. Deletion
map.erase(key);                  // Remove element
map.clear();                     // Remove all elements

// 4. Size Operations
map.size();                      // Number of elements
map.empty();                     // Check if empty
```

Common use cases:

```cpp
// Using unordered_set for unique collections (just values)
std::unordered_set<int> seen;
if (seen.count(value) > 0) {     // Check duplicate
    // Found duplicate
}
seen.insert(value);              // Add new value

// Using unordered_map for key-value associations (when you need to map keys to values)
std::unordered_map<string, int> freq;
freq["word"]++;                    // Increment count
if (freq.find("word") != freq.end()) {  // Check if exists
    // "word" exists
}
```
