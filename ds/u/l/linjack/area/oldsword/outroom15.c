#include <room.h>
inherit ROOM;
void create()
{
 set("short","���O��");
 set("long",@LONG
�A���n�䦳�ǩ_�Ǫ��n��, �̦n�O���n�L�h����w��.
�A������N�O�V����F, �n�^�h�V����o���V�L�@���p�e. 
LONG
    );
 set("exits",(["south":__DIR__"outroom14",
               "westup":__DIR__"inroom20",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}