#ifndef PER_STD_H_
#define PER_STD_H_

// ----- TYPES -----

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef signed char i8;
typedef signed short i16;
typedef signed long i32;
typedef signed long long i64;

typedef float f32;
typedef double f64;

typedef unsigned int uint;

// ----- ERROR CODES -----

typedef enum per_rcode {
    PER_R_SUCCESS = 0,
    PER_R_FAILURE
} per_rcode;

// ----- INITIALIZATION/CLEANUP -----

typedef struct per_config_t per_config_t;

/**
 * Initializes the library with a configuration.
 * 
 * This functions has to be called before any other function in the library is used.
 * 
 * @param[in] per_config The configuration that is used to initialize the libarary
 */
void per_init(per_config_t const * per_config);

/**
 * Cleans up internal things.
 * 
 * This function should be called at the end of the program.
 */
void per_cleanup();

// ----- MEMORY -----

/**
 * Allocates dynamic memory area.
 * 
 * Memory allocated by this function needs to subsequently be freed by @ref per_free.
 * 
 * @note
 * Similar to `malloc`.
 * 
 * @param[in] size The size in byte that the allocated memory is going to take up.
 * 
 * @returns        A pointer to the allocated memory area.
 */
void * per_alloc(uint size);

/**
 * Frees a dynamically allocated memory area previously allocated by @ref per_alloc.
 * 
 * Similar to `free`.
 * 
 * @param[in] ptr The pointer to the memory area that will be freed.
 */
void per_free(void * ptr);

/**
 * Creates a shallow copy of the pointer to a memory area previously allocated by @ref per_alloc.
 * 
 * This implies that the copy of this pointer that will be created also needs to be subsequently free by @ref per_free.
 * @n
 * Internally a reference counter is incremented.
 * 
 * @param[in] ptr Pointer to a memory area allocated by @ref per_alloc.
 * 
 * @returns A new copy of the pointer that has been passed to the function.
 */
void * per_share(void * ptr);


// ----- LIBC FUNCTIONS -----

/**
 * Copies @p size bytes from @p src to @p dst.
 * 
 * Similary to `memcpy`.
 * 
 * @param[out] dst Destination of the copy operation.
 * @param[in] src Source of the copy operation.
 * @param[in] size Amount of bytes that will be copied.
 */ 
void per_memcpy(void * dst, void * src, uint size);

#endif