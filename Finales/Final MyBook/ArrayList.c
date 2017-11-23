#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* pList);
int resizeDown(ArrayList* pList);
int expand(ArrayList* pList,int index);
int contract(ArrayList* pList,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements. (1)
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* pList;
    ArrayList* returnAux = NULL;
    void** pElements;
    pList=(ArrayList *)malloc(sizeof(ArrayList));

    if(pList != NULL)
    {
        pElements = (void**)malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            pList->size=0;
            pList->pElements=pElements;
            pList->reservedSize=AL_INITIAL_VALUE;
            pList->add=al_add;
            pList->len=al_len;
            pList->set=al_set;
            pList->remove=al_remove;
            pList->clear=al_clear;
            pList->clone=al_clone;
            pList->get=al_get;
            pList->contains=al_contains;
            pList->push=al_push;
            pList->indexOf=al_indexOf;
            pList->isEmpty=al_isEmpty;
            pList->pop=al_pop;
            pList->subList=al_subList;
            pList->containsAll=al_containsAll;
            pList->deleteArrayList = al_deleteArrayList;
            pList->sort = al_sort;
            returnAux = pList;
        }
        else
        {
            free(pList);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is  (2)
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* pList,void* pElement)
{
    int returnAux = -1;

    if(pList!=NULL && pElement != NULL)
    {
        pList->pElements[pList->size] = pElement;
        pList->size++;
        returnAux = resizeUp(pList);
    }


    return returnAux;
}

/** \brief  Delete arrayList (3)
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* pList)
{
    int returnAux = -1;

    if(pList!=NULL)
    {
        free(pList->pElements);
        free(pList);
        returnAux = 0;

    }
    return returnAux;
}

/** \brief  Delete arrayList (4)
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* pList)
{
    int returnAux = -1;

    if(pList != NULL)
    {
        returnAux = pList->size;
    }

    return returnAux;
}


/** \brief  Get an element by index (5)
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* pList , int index)
{
    void* returnAux = NULL;

    if(pList != NULL && index <= pList->size )
    {
        returnAux = pList->pElements[index];
    }

    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement (6)
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* pList, void* pElement)
{
    int returnAux = -1;
    int i;

    if(pList!=NULL && pElement != NULL)
    {
        returnAux = 0;
        for(i=0; i<pList->size;i++)
        {
            if(al_get(pList, i) == pElement)
            {
                returnAux = 1;
                break;
            }
        }

    }

    return returnAux;
}


/** \brief  Set a element in pList at index position (7)
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* pList, int index,void* pElement)
{
    int returnAux = -1;

    if(pList != NULL && pElement != NULL && index < pList->size && index >= 0)
    {
        pList->pElements[index] = pElement;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief  Remove an element by index (8)
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* pList,int index)
{
    int returnAux = -1;
    if(pList != NULL && index < pList->size && index >= 0)
    {
        returnAux = contract(pList, index);
        returnAux = 0;
    }

    return returnAux;
}



/** \brief Removes all of the elements from this list (9)
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* pList)
{
    int returnAux = -1;
    void** arrayAux;

    if(pList!=NULL )
    {
        pList->reservedSize = AL_INCREMENT;
        pList->size = 0;

        arrayAux = (void**)realloc(pList->pElements,sizeof(void*)*(pList->reservedSize));

        if(arrayAux != NULL)
        {
            pList->pElements = arrayAux;
            returnAux = 0;
        }
    }
    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence (10)
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* pList)
{
    ArrayList* returnAux = NULL;
    int i;
    if(pList != NULL )
    {
        returnAux = al_newArrayList();
        for(i=0; i < pList->size; i++)
        {
            al_add(returnAux, al_get(pList,i));
        }
    }

    return returnAux;
}




/** \brief Inserts the element at the specified position (11)
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* pList, int index, void* pElement)
{
    int returnAux = -1;

    if(pList!=NULL && index <= pList->size && index >= 0 && pElement != NULL)
    {
        if(index == pList->size)
        {
            al_add(pList,pElement);
            returnAux = 0;
        }
        else
        {
            if(expand(pList, index)==0)
            {
                returnAux = al_set(pList,index,pElement);
            }
        }

    }

    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element (12)
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* pList, void* pElement)
{
    int returnAux = -1;
    int i;

    if(pList != NULL && pElement != NULL)
    {
        for(i=0; i<pList->size;i++)
        {
            if(al_get(pList,i) == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}



/** \brief Returns true if this list contains no elements. (13)
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* pList)
{
    int returnAux = -1;
    if(pList != NULL )
    {

        if(pList->size == 0)
            returnAux = 1;
        else
            returnAux = 0;
    }

    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it. (14)
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* pList,int index)
{
    void* returnAux = NULL;

    if(pList!=NULL && index >= 0 && index <= pList->size)
    {
        returnAux = al_get(pList,index);
        al_remove(pList,index);
    }

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified (15)
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* pList,int from,int to)
{
    void* returnAux = NULL;

    //ArrayList* returnAux = NULL;
    int i;
    if(pList!=NULL && from >= 0 && from < pList->size && to >= 0 && to <= pList->size && from < to)
    {
        returnAux = al_newArrayList();
        for(i=from; i<to; i++)
        {
            al_add(returnAux, al_get(pList,i));
        }
    }

    return returnAux ;
}

/** \brief Returns true if pList list contains all of the elements of pList2 (16)
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                   - (0) if Not contains All
 *                   - (1) if is contains All
 */
int al_containsAll(ArrayList* pList,ArrayList* pList2)
{
    int returnAux = -1;
    int i;

    if(pList != NULL && pList2 != NULL)
    {
        for(i=0; i<pList->size; i++)
        {
            if(al_contains(pList,al_get(pList2,i)) == 1)
            {
                returnAux = 1;
            }
            else
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc (17)
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* pList, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1, i, j;
    void* aux;

    if(pList != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        returnAux = 0;
        for(i=0;i<pList->size-1;i++)
        {
            for(j=i+1;j<pList->size;j++)
            {
                if(order == 0) //DOWN - De Mayor a menor
                {
                    if(pFunc(al_get(pList,i),al_get(pList,j)) == -1) //-1 A < B
                    {
                        aux = al_get(pList,i);
                        al_set(pList,i,al_get(pList,j));
                        al_set(pList,j,aux);
                    }
                }
                else //UP - De Menor a Mayor
                {
                    if(pFunc(pList->pElements[i],pList->pElements[j]) == 1) // 1 A > B
                    {
                        aux = al_get(pList,i);
                        al_set(pList,i,al_get(pList,j));
                        al_set(pList,j,aux);
                    }
                }
            }
        }
    }
    return returnAux;
}

/***************************************************************************
         FUNCIONES PRIVADAS
****************************************************************************/

/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* pList)
{
    int returnAux = -1;
    void** arrayAux;

    if(pList != NULL)
    {
        returnAux = 0;
        if(pList->size == pList->reservedSize)
        {
            pList->reservedSize += AL_INCREMENT;
            arrayAux = (void**)realloc(pList->pElements,sizeof(void*)*(pList->reservedSize));

            if(arrayAux != NULL)
            {
                pList->pElements = arrayAux;
                returnAux = 0;
            }
        }
    }
    return returnAux;
}


/** \brief Decrement the number of elements in pList in AL_INCREMENT elements.
 *
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeDown(ArrayList* pList)
{
    int returnAux = -1;
    void** arrayAux;

    if(pList != NULL)
    {
        returnAux = 0;
        if(pList->size == pList->reservedSize - AL_INCREMENT)
        {

            pList->reservedSize -= AL_INCREMENT;
            arrayAux = (void**)realloc(pList->pElements,sizeof(void*)*(pList->reservedSize));

            if(arrayAux!=NULL)
            {
                pList->pElements = arrayAux;
            }
            else
            {
                returnAux = -1;
            }
        }
    }
    return returnAux;

}



/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* pList,int index)
{
    int
    returnAux = -1,
    i;

    if(pList != NULL && index < pList->size && index >= 0)
    {
        if(resizeUp(pList) == 0)
        {
            for(i=pList->size; i>index; i--)
            {
                al_set(pList,i,al_get(pList,i-1));
            }
            returnAux = 0;
            pList->size++;
        }
    }
    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* pList,int index)
{
    int returnAux = -1;
    int i;


    if(pList==NULL || index > pList->size || index < 0)
        return returnAux;

    for(i=index; i < pList->size-1; i++)
    {
        al_set(pList, i,pList->pElements[i+1]);
    }

    pList->size--;

    return resizeDown(pList);
}
