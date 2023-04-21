#define FUSE_USE_VERSION 31

#include <fuse.h>
#include <iostream>

static void *hello_init(struct fuse_conn_info *conn, struct fuse_config *cfg) {
  return nullptr;
}

static struct vmem_operations : fuse_operations {
  vmem_operations() { init = hello_init; }
} operations;

/**
 *
 * Prints help information of utility to stdout
 */
void print_help(const char *progname) {
  // Prints base usage help
  printf("Usage: %s [options] <mountpoint>\n\n", progname);
  printf("File-system specific options:\n"
         "<>"
         "\n\n");
  // Prints help for fuse args
  printf("FUSE options:\n");
  fuse_lib_help(nullptr);
}

int main(int argc, char *argv[]) {
  int ret;
  struct fuse_args args = FUSE_ARGS_INIT(argc, argv);

  /* Parse options */
  if (false) {
    printf("Error: invalid usage.\n\n");
    print_help(argv[0]);
    return 1;
  }

  // Prints help
  if (false) {
    print_help(argv[0]);
    return 0;
  }

  return fuse_main(args.argc, args.argv, &operations, NULL);
}