// Room: /d/xiangyang/northgate2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�ȪZ�~��");
	set("long", 
"�o�̬O���������_�����A�u�������W��O�T�Ӥj�r�C"HIB"

                      �ȪZ��
\n"NOR
"��~�ӻX�j�𦸫I���������A�G�o���u�۷��Y�K�A�@�ǩx�L
�̥��b�L�d�n�����������H�C����O�ܤj����a�C\n"
 );
//        set("outdoors", "xiangyang");

	set("exits", ([
		"south"  : __DIR__"northgate1",
		"north"  : __DIR__"caodi3",
		"east"   : __DIR__"caodi1",
		"west"   : __DIR__"caodi2",
	]));
	set("objects", ([
		__DIR__"npc/pi"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -500);
	set("coor/y", -400);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}