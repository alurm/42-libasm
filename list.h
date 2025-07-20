typedef struct s_list {
  void *data;
  struct s_list *next;
} t_list;

// I prefer this way.
typedef t_list list_t;
