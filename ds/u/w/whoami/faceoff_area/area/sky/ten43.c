#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",MAG"�v���q"NOR);
 set("long",@LONG
�@��i���q���j���A�ߨ観�@�ѯ��t���i�I�Ǫ��Pı��
�i�A���ߤ��A�ǻ��v�����O�гy�Q�U�j�s���T�������A�]
�]���b�Q�U�j�s�H�����ߤ��d�U���i�i�����ζH�A�ҥH�v
�����O�T�����̨��L�R����H....
LONG
    );
 set("exits",([   "westdown":__DIR__"ten42",
                  "east":__DIR__"ten44",
    ]));
 set("objects", ([__DIR__"obj/lion_statue" : 2,
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}

