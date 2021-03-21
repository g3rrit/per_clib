#ifndef PER_LIST_H_
#define PER_LIST_H_

#include "per_util.h"

typedef struct per_list_t;

typedef struct per_list_iter_t;

per_rcode per_list_init(per_list_t * list);

void per_list_destroy(per_list_t * list);

uint per_list_len(per_list_t * list);

per_rcode per_list_push_back(per_list_t * list, void * data);

per_rcode per_list_push_front(per_list_t * list, void * data);

per_rcode per_list_pop_front(per_list_t * list, void ** res);

per_rcode per_list_pop_back(per_list_t * list, void ** res);

per_rcode per_list_at(per_list_t * list, uint i, void ** res);

per_rcode per_list_insert(per_list_t * list, uint i, void * data);

per_rcode per_list_remove(per_list_t * list, uint i);

per_rcode per_list_iter(per_list_t * list, per_list_iter_t ** iter);

per_rcode per_list_iter_next(per_list_iter_t ** iter, void ** data);

per_rcode per_list_iter_get(per_list_iter_t * iter, void ** data);

per_rcode per_list_iter_remove(per_list_iter_t ** iter);

#define PER_LIST_FOR_EACH(per_list_, data_)                                                                                                \
  for (struct {                                                                                                                            \
         uint init;                                                                                                                        \
         per_list_iter_t * iter;                                                                                                           \
         per_rcode rcode_init;                                                                                                             \
         per_rcode rcode_next;                                                                                                             \
       } tmp_ =                                                                                                                            \
           {                                                                                                                               \
               .rcode_init = PER_R_FAILURE,                                                                                                \
              .rcode_next  = PER_R_SUCCESS,                                                                                                \
           };                                                                                                                              \
       ((tmp_.rcode_init != PER_R_SUCCESS ? tmp_.rcode_init = per_list_iter((per_list_), &tmp_.iter) : PER_R_SUCCESS),                     \
        tmp_.rcode_init == PER_R_SUCCESS) &&                                                                                               \
       (tmp_.rcode_next == PER_R_SUCCESS);                                                                                                 \
       (tmp_.rcode_next = per_list_iter_next(&tmp_.iter, &(data_))))

#endif // PER_LIST_H_
