
A C Vector class. Supports any data type through the use of void pointers.

Malloc'd and non-malloc items are supported through use of a flag when adding an item to the vector. Items are removable from the vector only by index. Items are automatically free'd when they are removed from the vector or the vector is destroyed. DestroyVector() must be called when finished with the vector or there will be memory leaks.

It is safe to add the same allocated item multiple times. Calling the remove function will safely remove all references to the item and fill in any gaps with existing items while preserving order.
