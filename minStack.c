#include <stdio.h>
#include <stdlib.h>
struct list_head {
		struct list_head *next, *prev;
};


typedef int ElemType;
typedef struct {
		ElemType elem;
		struct list_head list;

} MinStack;
#define __DEBUG
#ifdef __DEBUG
#define PRINT(info) printf(info)
#else
#define PRINT(info)
#endif


#undef offsetof
#ifdef __compiler_offsetof
#define offsetof(TYPE,MEMBER) __compiler_offsetof(TYPE,MEMBER)
#else
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

#define typeof __typeof__

#define list_entry1(ptr, type, member) ({			\
		const struct list_head *__mptr = (ptr);		\
			(type *)( (char *)__mptr - offsetof(type,member) );})

#define list_entry(ptr, type, member) ({			\
		const typeof( ((type *)0)->member )*__mptr = (ptr);		\
			(type *)( (char *)__mptr - offsetof(type,member) );})





#define LIST_HEAD_INIT(name) {&(name), &(name)}
#define LIST_HEAD(name) \
		struct list_head name = LIST_HEAD_INIT(name)

static inline void INIT_LIST_HEAD(struct list_head *list)
{
		list->next = list;
		list->prev = list;
}

static inline void __list_add(struct list_head *new, struct list_head *prev, struct list_head *next)
{
		next->prev = new;
		new->next = next;

		new->prev = prev;
		prev->next = new;
}

static inline void list_add(struct list_head *new, struct list_head *head)
{
		__list_add(new, head, head->next);
}

static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
		__list_add(new, head->prev, head);
}

static inline void __list_del(struct list_head *prev, struct list_head *next)
{
		next->prev = prev;
		prev->next = next;
}

static inline void __list_del_entry(struct list_head *entry)
{
		__list_del(entry->prev, entry->next);
}
static inline void list_del(struct list_head *entry)
{
		__list_del(entry->prev, entry->next);
		
		//entry->next = LIST_POISON1;
		//entry->prev = LIST_POISON2;

		entry->next = NULL;
		entry->prev = NULL;
}

static inline void list_replace(struct list_head *old, struct list_head *new)
{
		new->next = old->next;
		new->next->prev = new;
		new->prev = old->prev;
		new->prev->next = new;
}

static inline void list_replace_init(struct list_head *old, struct list_head *new)
{
		list_replace(old, new);
		INIT_LIST_HEAD(old);
}

static inline void list_del_init(struct list_head *entry)
{
		__list_del_entry(entry);
		INIT_LIST_HEAD(entry);
}

static inline void list_move(struct list_head *list, struct list_head *head)
{
		__list_del_entry(list);
		list_add(list, head);
}

static inline void list_move_tail(struct list_head *list, struct list_head *head)
{
		__list_del_entry(list);
		list_add_tail(list, head);
}

static inline int list_is_last(const struct list_head *list, const struct list_head *head)
{
		return list->next == head;
}

static inline int list_empty(const struct list_head *head)
{
		return head->next == head;
}

static inline int list_empty_careful(const struct list_head *head)
{
		struct list_head *next = head->next;
		return (next == head) && (next == head->prev);
}

static inline void list_rotate_left(struct list_head *head)
{
		struct list_head *first;
		
		if (!list_empty(head)) {
				first = head->next;
				list_move_tail(first, head);
		}
}

static inline int list_is_singular(const struct list_head *head)
{
		return !list_empty(head) && (head->next == head->prev);
}

static inline void __list_cut_position(struct list_head *list, struct list_head *head, struct list_head *entry)
{
		struct list_head *new_first = entry->next;
		list->next = head->next;
		list->next->prev = list;
		list->prev = entry;
		entry->next = list;
		head->next = new_first;
		new_first->prev = head;
}

static inline void list_cut_position(struct list_head *list, struct list_head *head, struct list_head *entry)
{
		if (list_empty(head))
				return;
		if (list_is_singular(head) && (head->next != entry && head != entry))
				return;
		if (entry == head)
				INIT_LIST_HEAD(list);
		else
				__list_cut_position(list, head, entry);
}

static inline void __list_splice(const struct list_head *list, struct list_head *prev, struct list_head *next)
{
		struct list_head *first = list->next;
		struct list_head *last = list->prev;

		first->prev = prev;
		prev->next = first;

		last->next = next;
		next->prev = last;
}

static inline void list_splice(const struct list_head *list, struct list_head *head)
{
		if (!list_empty(list))
				__list_splice(list, head, head->next);
}

static inline void list_splice_tail(struct list_head *list, struct list_head *head)
{
		if (!list_empty(list))
				__list_splice(list, head->prev, head);
}

static inline void list_splice_init(struct list_head *list, struct list_head *head) 
{
		if (!list_empty(list)) {
				__list_splice(list, head, head->next);
				INIT_LIST_HEAD(list);
		}
}

static inline void list_splice_tail_init(struct list_head *list, struct list_head *head) 
{
		if (!list_empty(list)) {
				__list_splice(list, head->prev, head);
				INIT_LIST_HEAD(list);
		}
}

#define list_first_entry(ptr, type, member) \
		list_entry((ptr)->next, type, member)

#define list_for_each(pos, head) \
		for (pos = (head)->next; pos != (head); pos = pos->next)
#define __list_for_each(pos, head) \
		for (pos = (head)->next; pos != (head); pos = pos->next)

#define list_for_each_prev(pos, head) \
		for (pos = (head)->prev; pos != (head); pos = pos->prev)

#define list_for_each_safe(pos, n, head) \
		for (pos = (head)->next, n = pos->next; pos != (head); \
		     pos = n, n = pos->next)

#define list_for_each_prev_safe(pos, n, head) \
	   for (pos = (head)->prev, n = pos->prev; \
			pos != (head); \
			pos = n, n = pos->prev)	

#define list_for_each_entry(pos, head, member) \
		for (pos = list_entry((head)->next, typeof(*pos), member); \
		     &pos->member != (head); \
		     pos = list_entry(pos->member.next, typeof(*pos), member))

#define list_for_each_entry_reverse(pos, head, member) \
		for (pos = list_entry((head)->prev, typeof(*pos), member); \
		     &pos->member != (head); \
		     pos = list_entry(pos->member.prev, typeof(*pos), member))

#define list_prepare_entry(pos, head, member) \
		((pos) ? : list_entry(head, typeof(*pos), member))

#define list_for_each_entry_continue(pos, head, member) 	\
		for (pos = list_entry(pos->member.next, typeof(*pos), member); \
			 &pos->member != (head);	\
			 pos = list_entry(pos->member.next, typeof(*pos), member))


#define list_for_each_entry_continue_reverse(pos, head, member) 	\
		for (pos = list_entry(pos->member.prev, typeof(*pos), member); \
			 &pos->member != (head);	\
			 pos = list_entry(pos->member.prev, typeof(*pos), member))

#define list_for_each_entry_from(pos, head, member)		\
		for (; &pos->member != (head);	\
			 pos = list_entry(pos->member.next, typeof(*pos), member))

#define list_for_each_entry_safe(pos, n, head, member)	\
		for (pos = list_entry((head)->next, typeof(*pos), member),	\
			 n = list_entry(pos->member.next, typeof(*pos), member);\
			 &pos->member != (head);	\
			 pos = n, n = list_entry(n->member.next, typeof(*n), member))

#define list_for_each_entry_safe_continue(pos, n, head, member) \
		for (pos = list_entry(pos->member.next, typeof(*pos), member), \
			n = list_entry(pos->member.next, typeof(*pos), member); \
			&pos->member != (head); \
			pos = n, n = list_entry(n->member.next, typeof(*n), member))

#define list_for_each_entry_safe_from(pos, n, head, member) \
		for (n = list_entry(pos->member.next, typeof(*pos), member); \
			&pos->member != (head); \
			pos = n, n = list_entry(n->member.next, typeof(*n), member))

#define list_for_each_entry_safe_reverse(pos, n, head, member) \
		for (pos = list_entry((head)->prev, typeof(*pos), member), \
			n = list_entry(pos->member.prev, typeof(*pos), member); \
			&pos->member != (head); \
			pos = n, n = list_entry(n->member.prev, typeof(*n), member))

#define list_safe_reset_next(pos, n, member) \
		n = list_entry(pos->member.next, typeof(*pos), member)



/** initialize your data structure here. */

MinStack* minStackCreate() {
		MinStack *S;
		if (!(S = (MinStack *)malloc(sizeof(MinStack))))
				return NULL;
				//error
		PRINT("minStackcreate malloc success\n");
		INIT_LIST_HEAD(&S->list);
		return S;
    
}

void minStackPush(MinStack* obj, int x) {
		MinStack *new;
		if (!(new = (MinStack *)malloc(sizeof(MinStack))))
				return;
		PRINT("minStackPush malloc success\n");
		new->elem = x;
		list_add(&new->list, &obj->list);

}

int minStackEmpty(MinStack* obj)
{
		return list_empty(&obj->list);
}
void minStackPop(MinStack* obj) {
		if (minStackEmpty(obj))
				return;
		MinStack *e;
		e = list_entry(obj->list.next, MinStack, list);
		list_del(obj->list.next);
		free(e);

}

int minStackTop(MinStack* obj) {
		if (minStackEmpty(obj))
				return;

		MinStack *e;
		e = list_entry(obj->list.next, MinStack, list);
		return e->elem;
  
}

int minStackGetMin(MinStack* obj) {
		ElemType min;
		MinStack *cur;
		if (minStackEmpty(obj))
				return 0;//error
		cur = list_entry(obj->list.next, MinStack, list);
		min = cur->elem;
		list_for_each_entry(cur, &obj->list, list)
				if (min > cur->elem)
						min = cur->elem;
		return min;


  
}

void minStackFree(MinStack* obj) {
		MinStack *cur, *n;

		list_for_each_entry_safe(cur, n, &obj->list, list)
		{

				list_del(&cur->list);
				free(cur);
		}
		free(obj);
    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

