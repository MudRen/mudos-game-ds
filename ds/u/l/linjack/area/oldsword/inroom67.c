#include <room.h>
inherit ROOM;
void create()
{
 set("short","���U");
 set("long",@LONG
�o�̬O���U������, �Ѧ��i�H�q�L�@�Ө��D�O�������U����,
�A�ݨ즳��Ӧu�å��ݺ޵۩��k���U����, �Q�n���Ǥ��k����,
���ȨS����e��. �t�~, �o�䦳�T�|��W��b���������, �A
�Y������f�h�����w�i�H��L�̬ݤ@��.
LONG
    );
 set("exits",(["north":__DIR__"inroom69",
                "west":__DIR__"inroom6",
                "east":__DIR__"inroom62",
               "south":__DIR__"inroom64",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
