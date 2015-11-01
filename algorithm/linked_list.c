#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct test_struct
{
    int val
    struct test_struct *next;
};

struct test_truct *head = NULL;
struct test_struct *curr = NULL;

stuct test_struct* create_list(int val)
{
    print("\n creating list with headnode as [%d]\n", val);
    struct test_struct *ptr = 
        (struct test_struct*)malloc(sizeof(struct test_struct));

    if (NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }

    ptr->val = val;
    ptr->next = NULL;

    head = curr = ptr;
    return ptr;
}

struct test_struct* add_to_list(int val, bool add_to_end)
{
    if (NULL == head)
    {
        return (create_list(val));
    }

    if (add_to_end)
    {
        printf("\n Adding node to end of list with value [%d]\n", val);
    }
    else
    {
        printf("\n Adding node to beginnig of list with value [%d]\n", val);
    }

    struct test_struct *ptr = (struct test_struct*)malloc(sizeof(struct test_struct));

    if (NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }

    ptr->val = val;
    ptr->next = NULL;

    if (add_to_end)
    {
        curr->next = ptr;
        curr = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }

    return ptr;
}

struct test_struct* search_in_list(int val, struct test_struct **prev)
{
    struct test_struct *ptr = head;
    struct test_struct *tmp = NULL;
    bool found = false;

    printf("\n Searching the list for value [%d] \n", val);

    while (ptr != NULL)
    {
        if (ptr->val == val)
        {
            found = true;
            break;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }

        if (true == found)
        {
            if (prev)
            {
                *prev = tmp;
            }
            return ptr;
        }
        else
        {
            return NULL;
        }
    }

    int delete_from_list(int val)
    {
        struct test_struct *prev = NULL;
        struct test_struct *del = NULL;

        printf("\n Deleting value [%d] form list\n", val);

        del = search_in_list(val, &prev);

        if (del == NULL)
        {
            return -1;
        }
        else
        {
            if (prev != NULL)
            {
                prev ->next = del->next;
            }
        }

        free(del);
        del = NULL;

        return 0;
}

int main(void)
{
    int i = 0;
    int ret = 0;
    struct test_struct *ptr = NULL;

    print_list();

    for (i = 5; i < 10; i++)
    {
        add_to_list(i, true);
    }

    print_list();

    for (i = 4; i > 0; i--)
    {
        add_to_list(i, false);
    }

    print_list();

    for (i = 1; i < 10; i += 4)
    {
        ptr - search_in_list(i, NULL)
        
        if (NULL == ptr)
        {
            printf("\n Search [val = %d] failed, no such element found\n", i);
        }
        else
        {
            printf("\n Search passed [val = %d]\n", ptr->val);
        }

        print_list();

        ret = delete_from_list(i);

        if (ret != 0)
        {
            printf("\n delete [val = %d] failed, no such element found\n", i);
        }
        else
        {
            printf("\n delete [val = %d] passed \n", i);
        }

        print_list();
    }

    return 0;
}
