/////////////////////////////////////////////////////////////////
//
//    Header File Inclusion
//
/////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<string.h>

/////////////////////////////////////////////////////////////////
//
//    User Defined Macros
//
/////////////////////////////////////////////////////////////////

// Maximum file size that we allow in the project
#define MAXFILESIZE 50

#define MAXOPENFILES 20

#define MAXINODE 5

#define READ 1
#define WRITE 2             //  3 for Read and Write both Operation
#define EXECUTE 4

#define START 0
#define CURRENT 1
#define END 2

#define EXECUTE_SUCCESS 0

/////////////////////////////////////////////////////////////////
//
//    User Desfined Structure
//
/////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////
//
//    Structure Name : BootBlock
//    Description    : Holds the information to boot the OS
//
/////////////////////////////////////////////////////////////////

struct BootBlock
{
    char Information[100];
};

/////////////////////////////////////////////////////////////////
//
//    Structure Name : SuperBlock
//    Description    : Holds the information about the file System
//
/////////////////////////////////////////////////////////////////

struct SuperBlock
{
    int TotalInodes;
    int FreeInodes;
};

/////////////////////////////////////////////////////////////////
//
//    Structure Name : Inode
//    Description    : Holds the information about the file
//
/////////////////////////////////////////////////////////////////

#pragma pack(1)
struct Inode
{
    char FileName[20];
    int InodeNumber;
    int FileSize;
    int ActualFilesize;
    int ReferenceCount;             // how many time we can opened file
    int Permission;                 // how many permission use (read write) we used
    char *Buffer;                   //actual file data strore
    struct Inode *next;             // point to next
};

typedef struct Inode INODE;
typedef struct Inode * PINODE;
typedef struct Inode ** PPINODE; 


/////////////////////////////////////////////////////////////////
//
//    Structure Name : FileTable
//    Description    : Holds the information about opened file
//
/////////////////////////////////////////////////////////////////

struct FileTable
{
    int ReadOffset;
    int WriteOffset;
    int Mode;
    PINODE ptrinode;
};

typedef FileTable FILETABLE;
typedef FileTable * PFILETABLE;

/////////////////////////////////////////////////////////////////
//
//    Structure Name : UAREA
//    Description    : Holds the information about the process file
//
/////////////////////////////////////////////////////////////////

struct UAREA
{
    char ProcessName[20];
    PFILETABLE UFDT[MAXOPENFILES];
};

/////////////////////////////////////////////////////////////////
//
//    Global variable or objects used in the project
//
/////////////////////////////////////////////////////////////////

BootBlock bootobj;
SuperBlock superobj;
UAREA uareobj;

PINODE head = NULL;

/////////////////////////////////////////////////////////////////
//
//    Entry point function og the project
//
/////////////////////////////////////////////////////////////////

int main()
{


    return 0;
}
