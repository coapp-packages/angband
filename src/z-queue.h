#ifndef INCLUDED_Z_QUEUE_H
#define INCLUDED_Z_QUEUE_H

#include <h-basic.h>

#if (!defined(HAVE_STDINT_H))
/* MSVC doesn't have stdint.h (which is C99), so we'll just
 * create the right pointer manually. */

/* MSVC contains this type by default in Visual Studio 2003+.
 *   http://msdn.microsoft.com/en-us/library/323b6b3k(v=VS.71).aspx
 * Version macro returns 1300 for VS 2003.
 *
 * -Tim Rogers  (Microsoft)
 */
#ifdef _MSC_VER
#if (_MSC_VER < 1300)

typedef unsigned int * uintptr_t;
#endif
#endif
#endif

struct queue {
    uintptr_t *data;
    size_t size;
    int head;
    int tail;
};

struct queue *q_new(size_t size);
int q_len(struct queue *q);

void q_push(struct queue *q, uintptr_t item);
uintptr_t q_pop(struct queue *q);

void q_free(struct queue *q);

#define q_push_ptr(q, ptr) q_push((q), (uintptr_t)(ptr))
#define q_pop_ptr(q) (void *)q_pop((q))

#define q_push_int(q, i) q_push((q), (uintptr_t)(i))
#define q_pop_int(q) (int)q_pop((q))

#endif /* INCLUDED_Z_QUEUE_H */
