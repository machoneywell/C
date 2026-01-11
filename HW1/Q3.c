/*
You will have to implement bubble sort to sort a doubly-linked list of integers in ascending
order. As a starting point, I’m providing list_template.c. The template provides build_list,
Revised 09/26/2024 which takes as an argument the length of the list to be generated. The function generates a
sequence of random numbers that are to be sorted. The print_list function is a utility that
prints the list. You have to implement two approaches to perform bubble sort.
• In bubble_sort_copy_value, you have to implement bubble sort by manipulating the
value field in the linked list. So, you can perform the bubble sort by swapping the
values of two consecutive elements. This function should be easier to implement
since you do not have to reorganize the list.
• In the bubble_sort_copy_ref, you must implement bubble sort without modifying the
value fields (you can read the values and do not write to them). The function has to
be implemented by manipulating the pointers of the elements in the linked list. This
will require some careful consideration of how pointers must be assigned.
Output: The output of the code should be the sorted array.
Hint: For the bubble_sort_copy_ref, I found the following illustration useful. Originally, we
need to consider four variables before_a, a, b, after_b that refer to elements in the list. I’m
allowing for prev_a and next_b to be pontetially NULL (which happens in the
beginning/end of the list). The next and prev pointers for these are as follows:
before_a ===(next)==> a ===(next)==> b ===(next)==> after_b
before_a <==(prev)=== a <==(prev)=== b <==(prev)=== after_b
If we need to switch the values of a and b, we need to switch the pointer around so that we
end up with the following organization:
before_a ===(next)==> b ===(next)==> a ===(next)==> after_b
before_a <==(prev)=== b <==(prev)=== a <==(prev)=== after_b
Now, you need to think about changing the pointers of before_a, a, b, and after_b according
to the illustrations shown above. Be careful about when before_a and after_b are NULL. If
the list has at least two elements, a and b cannot be NULL.
Drawing the relationships between variables as you step through code is quite useful to
debug. Remember gdb (or CLion’s debugger) and Valgrind are your friends. Use them in
times of trouble!
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef struct elem {
    int value;
    struct elem *next;
    struct elem *prev;
} elem_t;

void print_list(elem_t *head) {
    elem_t *elem;
    elem = head;
    
    while (elem != NULL) {
        printf("%d ", elem->value);
        elem = elem->next;
    }
    printf("\n");
}

void bubble_sort_copy_value(elem_t **head) {
    bool swapped;
    elem_t *current;
    elem_t *last;

    if (head == NULL || *head == NULL) {
        return;
    }

    last = NULL;
    do {
        swapped = false;
        current = *head;

        while (current->next != last) {
            if (current->value > current->next->value) {
                int temp;
                temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;

                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

void bubble_sort_copy_ref(elem_t **head) {
    bool swapped;
    elem_t *current;
    elem_t *last;

    if (head == NULL || *head == NULL) {
        return;
    }

    last = NULL;
    do {
        swapped = false;
        current = *head;

        while (current->next != last) {
            elem_t *next_node;
            next_node = current->next;

            if (current->value > next_node->value) {
                elem_t *before_current;
                elem_t *after_next;

                before_current = current->prev;
                after_next = next_node->next;

                if (before_current != NULL) {
                    before_current->next = next_node;
                } else {
                    *head = next_node;
                }

                if (after_next != NULL) {
                    after_next->prev = current;
                }

                next_node->prev = before_current;
                next_node->next = current;
                current->prev = next_node;
                current->next = after_next;

                swapped = true;
            } else {
                current = current->next;
            }
        }
        last = current;
    } while (swapped);
}

elem_t *build_list(int num_elements) {
    int i;
    elem_t *head;
    
    head = NULL;
    srand(1234);

    for (i = 0; i < num_elements; i++) {
        elem_t *e;
        e = (elem_t *)malloc(sizeof(elem_t));

        e->value = random() % 100;
        e->next = NULL;
        e->prev = NULL;

        if (head == NULL) {
            head = e;
        } else {
            e->next = head;
            head->prev = e;
            head = e;
        }
    }
    return head;
}

int main() {
    elem_t *head;
    
    head = build_list(100);
    print_list(head);
    printf("==================================\n");
    
    bubble_sort_copy_value(&head);
    bubble_sort_copy_ref(&head);
    
    print_list(head);

    return 0;
}
