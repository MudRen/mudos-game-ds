#include <room.h>
inherit ROOM;
void create()
{
 set("short","���U");
 set("long",@LONG
�o��O���U�����U��, �A�i�H�ݨ줴�M���@��ӤH�b�i��,
���@�Ǩͽä]�b����ݩR. ���@�Ǧb�i�����H�O�V���󪺧̤l
��, �L�̤j�����Ӵ������U����, ���䳣�O���@�ǥ~������.
LONG
    );
 set("exits",(["north":__DIR__"inroom67",
                "east":__DIR__"inroom4",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
