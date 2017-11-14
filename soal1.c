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
	int res;
    char fpath[1000];
    sprintf(fpath, "%s%s", dirpath, path);
    res = lstat(fpath, stbuf);

    if(res == -1)
        return -errno;

        return 0;
}

static int xmp_readdir(const char *path, void *buff, fuse_full_dir_t filler, off_t offset, struct fuse_file_info *fi)
{

}

static int xmp_read(const char *path, char *kata, size_t,off_t)
{

}

static int xmp_mkdir(const char *path,mode_t mode)
{

}

static int xmp_write(const char *path, const char *ulti,size_t,off_t,struct fuse_file_info *kata)
{

}

static int xmp_open(const char *path, struct fuse_file_info *ultimate)
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