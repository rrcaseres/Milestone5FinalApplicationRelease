union question {
    int id;
    struct index {
        char Q[120];
        char A[1];
    } index;
} question;

struct category {
    struct questions {
        union question Q[5];
    } questions;
} category;