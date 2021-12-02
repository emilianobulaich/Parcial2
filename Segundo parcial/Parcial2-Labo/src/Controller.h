int controller_loadBookText(char* path , LinkedList* pArrayListBook);
int controller_loadEditorialText(char* path , LinkedList* pArrayListEditorial);

int controller_saveBookAsText(char* path, LinkedList* pArrayListLibro);
int controller_saveEditorialAsText(char* path, LinkedList* pArrayListEditorial);

int controller_List(LinkedList* pArrayListBook, LinkedList* pArrayListEditorial);
int controller_sortBooks(LinkedList* pArrayListBook);

int controller_getEditorialNameById(LinkedList* pArrayEditorial, int id, char* nombreEditorial);
int controller_listEditorialMinotauro(LinkedList* pArrayBookList, LinkedList* pArrayEditorialList);

int controller_FindMinotauro( void* element );
int controller_countMayorA500( void* element);
void* controller_buscarPosicionDescuento( void* element );
float controller_buscarPrecioPearson( void* element );

int controller_descuento(LinkedList* pArrayListLibro, LinkedList* pArrayListEditorial);
int controller_mostrarMayorA500(LinkedList* pArrayBookList);
float controller_SumaPearson(LinkedList* pArrayBookList );

