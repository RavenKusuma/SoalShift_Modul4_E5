#define FUSE_USE_VERSION 28
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>

static int xmp_getattr(const char *path, struct stat *stbuf)
{

}

static int xmp_readdir(const char *path, void *buff, fuse_full_dir_t filler, off_t offset, struct fuse_file_info *fi)
{
	
}
static struct fuse_operations xmp_oper = {
	.getattr	= xmp_getattr,
	.readdir	= xmp_readdir,
	.read		= xmp_read,
	.mkdir		= xmp_mkdir,
	.write 		= xmp_write,
	.open 		= xmp_open,
};
int main(int argc, char *argv[])
{

}