#define FUSE_USE_VERSION 28
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>

static const char *dirpath = "/home/RavenKusuma/Documents";

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

static int xmp_readdir(const char *path, void *buff, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi)
{
	char fpath[1000];
    if(strcmp(path,"/")==0)
    {
        path = dirpath;
        sprintf(fpath, "%s", path);
    }
    else
        sprintf(fpath, "%s%s", dirpath, path);
		int res = 0;

	DIR *dp;
	struct dirent *de;

	(void) offset;
	(void) fi;

	dp = opendir(fpath);
	if (dp == NULL)
		return -errno;

	while ((de = readdir(dp)) != NULL) 
	{
		struct stat st;
		memset(&st, 0, sizeof(st));
		st.st_ino = de->d_ino;
		st.st_mode = de->d_type << 12;
		res = (filler(buf, de->d_name, &st, 0));
			if(res!=0) break;
	}

	closedir(dp);
	return 0;
}

static int xmp_read(const char *path, char *buf, size_t size,off_t offset,struct fuse_file_info *pusing)
{
	int x,harga,temp;
	int res = 0;
  	int fd = 0 ;
	char fpath[1000];
	if(strcmp(path,"/") == 0)
	{
		path=dirpath;
		sprintf(fpath,"%s",path);
	}
	else sprintf(fpath, "%s%s",dirpath,path);
	temp=3;
	char curr[5];
	for(x=strlen(fpath)-1,harga=1;harga<=4;x--,harga++)
	{
		curr[temp--]=fpath[x];
	}
	
	if(strcmp(curr,".pdf")==0 || strcmp(curr,".doc")==0 || strcmp(curr,".txt")==0)
	{
		char y;
		char perintah[2002],sumber[2002],target[2002];
		sprintf(sumber,"%s",fpath);
		sprintf(target,"%s.ditandai",fpath);
		sprintf(perintah,"chmod 000 %s.ditandai",fpath);
		system(perintah);
		system("zenity =\"Terjadi Kesalahan! File berisi konten berbahaya.\n\" =\"Warning!\"");
		return -errno;
	}
}

static struct fuse_operations xmp_oper = 
{
	.getattr	= xmp_getattr,
	.readdir	= xmp_readdir,
	.read		= xmp_read,
	
};

int main(int argc, char *argv[])
{
	umask(0);
	return fuse_main(argc, argv, &xmp_oper, NULL);
}
