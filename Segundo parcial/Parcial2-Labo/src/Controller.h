int controller_loadBookText(char* path , LinkedList* pArrayListBook);
int controller_loadEditorialText(char* path , LinkedList* pArrayListEditorial);

int controller_List(LinkedList* pArrayListBook, LinkedList* pArrayListEditorial);
int controller_sortBooks(LinkedList* pArrayListBook);
int controller_saveAsText(char* path , LinkedList* pArrayListBook);

//int controller_LoadNextId(LinkedList* pArrayListBook);
//int controller_LastIdSaved(char* path);
//int controller_saveLastIdAsText(char* path, int id);

int controller_getEditorialNameById(LinkedList* pArrayEditorial, int id, char* nombreEditorial);
int controller_listEditorialMinotauro(LinkedList* pArrayBookList, LinkedList* pArrayEditorialList);
int FindMinotauro( void* element );
