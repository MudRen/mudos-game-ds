#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�p�Ѥl");
set("long",@LONG
�o�O�@���b�����a���䪺�p�Ѥl, ���M�ä��j, ���o�i�H��
��@�ǥ����L��b�䤤���V. ��O�o�Ӵ䳣���������H�����@��
�a?
LONG
    );
 set("exits",([ "south":__DIR__"seacoun37",
]));
 set("objects", ([__DIR__"npc/thief" : 1,
	           __DIR__"npc/vagabond" : 1,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
}            