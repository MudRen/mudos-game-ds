#include <room.h>
inherit ROOM;
void create()
{
 set("short","�𮧫Ǩ��D");
 set("long",@LONG
�o��O�@�ӥ𮧫Ǩ��D�����Y�F. �n�_������G���ǳټM,
�n���O�V���󪺨ͽí̪��ж�, �����D�L�̦b�ͽרǤ��F��.
���@���ӱ�i�H�q���G��.
LONG
    );
 set("exits",([ "north":__DIR__"inroom47",
                 "east":__DIR__"inroom43",
                "south":__DIR__"inroom48",
                   "up":__DIR__"inroom49",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
