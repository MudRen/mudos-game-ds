#include <room.h>
inherit ROOM;
void create()
{
 set("short","���U");
 set("long",@LONG
�o�̬O���U���k��, �Ѧ��i�H�q�L�@�Ө��D�O���k���U����,
�A�ݨ즳��Ӧu�å��ݺ޵۩��k���U����, �Q�n���Ǥ��k����,
���ȨS����e��. �������~, �o�䦳�X�ӽm���h���b���.
LONG
    );
 set("exits",(["north":__DIR__"inroom68",
                "west":__DIR__"inroom62",
                "east":__DIR__"inroom5",
               "south":__DIR__"inroom63",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
