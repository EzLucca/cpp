#include "Serializer.hpp"

/**
 * @brief Serializes a pointer to a Data object.
 * 
 * This function takes a pointer to a Data object and converts it into
 * an integer type (`uintptr_t`) using reinterpret_cast. This can be
 * useful for storing or transmitting pointers in a form that can
 * later be deserialized back into the original pointer.
 * 
 * @param ptr Pointer to the Data object to serialize.
 * @return The serialized representation of the pointer as uintptr_t.
 */
uintptr_t Serializer::serialize(Data* ptr) {
    std::cout << "The serialize was called.\n";
    return reinterpret_cast<std::uintptr_t>(ptr);
}

/**
 * @brief Deserializes a uintptr_t back into a Data pointer.
 * 
 * This function takes a serialized integer representation of a pointer
 * (as returned by `serialize`) and converts it back into a pointer to
 * a Data object using reinterpret_cast. The returned pointer should
 * only be used if it was originally serialized by this Serializer.
 * 
 * @param raw The serialized uintptr_t representation of a Data pointer.
 * @return Pointer to the original Data object.
 */
Data* Serializer::deserialize(uintptr_t raw){
    std::cout << "The deserialize was called.\n";
    return reinterpret_cast<Data *>(raw);
}
