/*
 * =====================================================================================
 *	Author: Christopher Schneider
 *	File Name: Vector.c
 *
 *	Description: A vector implementation in C
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "Vector.h"

//Prototypes
inline static int DoubleVectorSize(Vector *);
inline static void ReformVector(Vector *vector, void* item);

//Constants
const int DEFAULT_VECTOR_SIZE = 64;

/*
    FUNCTION: InitVector
    Allocates memory for a new vector
    @return Pointer to initialized vector
 */
Vector *InitVector()
{
    Vector * vector = malloc(sizeof(Vector));
    if(vector == NULL)
        return 0;
    else
    {
        vector->size = 0;
        vector->capacity = DEFAULT_VECTOR_SIZE;
        vector->items = malloc(sizeof(void*) * vector->capacity);
        return vector;
    }
}


/*  FUNCTION: AddToVector
    Adds a symbol to vector. On success, 1 is returned
    @param  item        -- item to add
    @param  vector      -- Vector to add item to
    @return             -- 1 on success, 0 on failure
*/
int AddToVector(Vector *vector, void *item)
{
    int success = 1; //Assume result
    if(vector->capacity == vector->size) //Increase size if full
    {
        success = DoubleVectorSize(vector);
    }
    vector->items[vector->size++] = item;
    return success;
}

/*  FUNCTION: DeleteByIndex
    Removes an item from the vector by its index.
    If no item is present in index, 0 is returned
    @param  index       -- index of item to delete
    @param  vector      -- Vector to add item to
    @return             -- 1 on success, 0 on failure
*/
int DeleteByIndex(Vector *vector, int index )
{
    void* item = GetFromVector(vector, index);
    if(item == NULL) return 0;  //Item doesn't exist
    ReformVector(vector, index, item);
    free(item);                 //Free the item
    return 1;
}

/*  FUNCTION: DeleteItem
    Checks if an item is present in vector then removes it.
    If the item was successfully located and removed, 1 is returned
    otherwise 0 is returned. If an unknown type is used, -1 is returned

    WIP!

    Acceptable string values for type:
    "short"
    "int"
    "long"
    "double"
    "float"
    "char*"
    "char"
    "pointer"
    @param  item        -- item to delete
    @param  vector      -- Vector to add item to
    @param  type        -- The data type of the item
    @return             -- 1 on success, 0 on failure, -1 if type not recognized
*/
int DeleteItem(Vector *vector, void *item, char* type)
{
    if(strcmp(type, "int") == 0)
    {

    }
    else if(strcmp(type, "long") == 0)
    {

    }
    else if(strcmp(type, "double") == 0)
    {

    }
    else if(strcmp(type, "float") == 0)
    {

    }
    else if(strcmp(type, "char*") == 0)
    {

    }
    else if(strcmp(type, "char") == 0)
    {

    }
    else if(strcmp(type, "pointer") == 0)
    {

    }
    else if(strcmp(type, "short") == 0)
    {

    }
    else //Type not recognized
    {
        return -1;
    }
    return 0;
}


/*  FUNCTION: DestroyVector
    Frees memory alloc'd to vector
    vector -- The vector table to free*/
void DestroyVector(Vector *vector)
{
    while(vector->size > 0) {
        DeleteByIndex(vector, vector->size - 1);
    }
    free(vector->items);
    free(vector);
}

/*
    FUNCTION: CharExistsInVector
    Checks if a specific char is present in the vector

    If item is found, its index is returned
    If item is not found, -1 is returned

    @param vector   --  The vector to examine
    @param item   --  The item to look for
    @return       -- The index of the item or -1 if it doesn't exist
 */
int CharExistsInVector(Vector *vector, void *item)
{
    int vectorSize = vector->size-1;
    int result = -1; //If not found, result is set -1
    while(vectorSize > 0)
    {
        char* str1 = (char*) GetFromVector(vector, vectorSize);
        if(strcmp(str1, (char*)item) == 0)
        {
            result = vectorSize;
            return result;
        }
        else
            vectorSize--;
    }
    return result;
}

/*FUNCTION: GetFromVector
    Returns a pointer to an item from a vector based on an index
    @param Vector to search
    @param Index to look into
    @return the item if exists, else returns NULL
 */
void* GetFromVector(Vector *vector, int index)
{
    if (index < 0 || index > vector->size)
    {
        return NULL;
    }
    else
    {
        return vector->items[index];
    }
}


/*FUNCTION: DoubleVectorSize
    Doubles a vector's size.
    @param Vector to double in size
    @return 1 on success, 0 on failure
 */
inline static int DoubleVectorSize(Vector *vector)
{
    void **symbols = realloc(vector->items, sizeof(void*) * vector->capacity * 2);
    if(symbols != NULL)
    {
        vector->items = symbols; //Assign realloc'd symbol table to new symbol table
        vector->capacity *= 2; //Double symbol table size
        return 1;
    }
    else
        return 0;
}


/*FUNCTION: ReformVector
    Moves all items up in the vector.
    All references to the item are overwritten
    @param Vector   -- The vector to reform
    @param index    -- Index of the item being removed
    @param item     -- The item being removed
 */
inline static void ReformVector(Vector *vector,void* item)
{
    int i = 0, j = 1;
    int removeCount = 1; //Number of items to be removed

    while(vector->items[i] != item)  //Find first instance of the item
    {
        i++;
        j++;
    }

    for(i; i < vector->size; i++, j++)
    {

        while(vector->items[j] == item)  //Check for multiple references to an item
        {
            if (vector->items[j] == item)
            {
                j++;
                removeCount++;
            }
        }
        vector->items[i] = vector->items[j];
    }
    vector->size -= removeCount;

    int temp = vector->size;
    for(i = 0; i < removeCount; i++)    //Set all removed references to NULL
        vector->items[temp++] = NULL;
}

