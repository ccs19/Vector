/*
 * =====================================================================================
 *	Author: Christopher Schneider
 *	File Name: Vector.h
 *
 *	Description: A vector implementation in C
 *
 * =====================================================================================
 */

#ifndef VECTOR_H
#define VECTOR_H


typedef struct{
    int size;       //Number of items currently in symbol table
    int capacity;   //Max size of symbol table
    void** items;   //Item in vector
} Vector;

/*
    FUNCTION: InitVector
    Allocates memory for a new vector
    @return Pointer to initialized vector
 */
Vector *InitVector();


/*  FUNCTION: AddToVector
    Adds a symbol to vector. On success, 1 is returned
    @param  item        -- item to add
    @param  vector      -- Vector to add symbol to
    @return             -- 1 on success
*/
int AddToVector(Vector*, void*);


/*  FUNCTION: DeleteByIndex
    Removes an item from the vector by its index.
    If no item is present in index, 0 is returned
    @param  index       -- index of item to delete
    @param  vector      -- Vector to add item to
    @return             -- 1 on success, 0 on failure
*/
int DeleteByIndex(Vector *vector, int index );


//Not implemented
int DeleteItem(Vector *vector, void *item, char* type);


/*  FUNCTION: DestroyVector
    Frees memory alloc'd to vector
    vector -- The vector table to free*/
void DestroyVector(Vector*);


/*
    FUNCTION: CharExistsInVector
    Checks if a specific char* is present in the vector

    If item is found, its index is returned
    If item is not found, -1 is returned

    @param vector   --  The vector to examine
    @param item   --  The item to look for
    @return       -- The index of the item or -1 if it doesn't exist
 */
int CharExistsInVector(Vector*, void*);


/*FUNCTION: GetFromVector
    Returns a pointer to an item from a vector based on an index
    @param Vector to search
    @param Index to look into
    @return the item on success, 0 on failure
 */
void *GetFromVector(Vector*, int);

#endif
