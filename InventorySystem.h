/**
 * @file InventorySystem.h
 * @brief Header-only class template for a fixed-capacity inventory container.
 */
#ifndef INVENTORYSYSTEM_H
#define INVENTORYSYSTEM_H

#include <iostream>
#include <stdexcept>

/**
 * @class InventorySystem
 * @brief Generic fixed-capacity inventory manager.
 * @tparam T Item type stored in the inventory.
 *
 * @details
 * Stores up to 20 items of type @p T. Supports adding, removing, searching,
 * sorting, printing, index-based access, and capacity/state checks.
 */
template <typename T>
class InventorySystem {
  private:
    T items[20];
    int count;

  public:
    /**
     * @brief Construct an empty inventory.
     */
    InventorySystem();

    /**
     * @brief Add an item if not full and not duplicate.
     * @param item Item to add.
     */
    void add(T item);

    /**
     * @brief Remove the first matching item.
     * @param target Item to remove.
     * @return true if removed, false if not found.
     */
    bool remove(T target);

    /**
     * @brief Find the first matching item.
     * @param target Item to search for.
     * @return Index of first match, or -1 if not found.
     */
    int search(T target) const;

    /**
     * @brief Sort items in ascending order using operator<.
     */
    void sort();

    /**
     * @brief Print all items and a count header.
     */
    void print() const;

    /**
     * @brief Access item by index with bounds checking.
     * @param index Index to access.
     * @return Reference to item at index.
     * @throws std::out_of_range if index is invalid.
     */
    T &operator[](int index);

    /**
     * @brief Get current number of stored items.
     * @return Item count.
     */
    int getCount() const;

    /**
     * @brief Check whether inventory is full.
     * @return true if count is 20.
     */
    bool isFull() const;

    /**
     * @brief Check whether inventory is empty.
     * @return true if count is 0.
     */
    bool isEmpty() const;
};

template <typename T>
InventorySystem<T>::InventorySystem() : count(0) {}

template <typename T>
void InventorySystem<T>::add(T item) {
    if (isFull()) {
        std::cout << "Error: inventory is full. Cannot add item.\n";
        return;
    }

    if (search(item) != -1) {
        std::cout << "Error: duplicate item. Not added.\n";
        return;
    }

    items[count] = item;
    count++;
}

template <typename T>
bool InventorySystem<T>::remove(T target) {
    int index = search(target);
    if (index == -1) {
        return false;
    }

    for (int j = index; j < count - 1; j++) {
        items[j] = items[j + 1];
    }

    count--;
    return true;
}

template <typename T>
int InventorySystem<T>::search(T target) const {
    for (int i = 0; i < count; i++) {
        if (items[i] == target) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void InventorySystem<T>::sort() {
    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (items[j] < items[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            T temp = items[i];
            items[i] = items[minIndex];
            items[minIndex] = temp;
        }
    }
}

template <typename T>
void InventorySystem<T>::print() const {
    std::cout << "Inventory (" << count << " items):\n";
    for (int i = 0; i < count; i++) {
        std::cout << "[" << i << "] " << items[i] << '\n';
    }
}

template <typename T>
T &InventorySystem<T>::operator[](int index) {
    if (index < 0 || index >= count) {
        throw std::out_of_range("index out of range");
    }
    return items[index];
}

template <typename T>
int InventorySystem<T>::getCount() const {
    return count;
}

template <typename T>
bool InventorySystem<T>::isFull() const {
    return count == 20;
}

template <typename T>
bool InventorySystem<T>::isEmpty() const {
    return count == 0;
}

#endif // INVENTORYSYSTEM_H
