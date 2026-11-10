union ele {
    struct {
        long *p;
        long y;
    } e1;
    struct {
        long x;
        union ele *next;
    } e2;
};

/* A.What are the offsets (in bytes) of the following fields:
 * e1.p    0
 * e1.y    8
 * e2.x    0
 * e2.next 8
 */

/* B. How many total bytes does the structure require?
 * 16
 */

/* C. see 70.s
 * up->x = *(up->next->p) - up->next->y
 */
