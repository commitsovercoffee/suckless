/* user and group to drop privileges to */
static const char *user  = "hope";
static const char *group = "hope";

static const char *colorname[NUMCOLS] = {
    [INIT] =   "#222222",   /* after initialization */
    [INPUT] =  "#4F6F52",   /* during input */
    [FAILED] = "#DC8686",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;
