// Room: /d/xiangyang/southgate2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�����~��");
	set("long", 
"�o�̬O���������n�����A�u�������W��O�T�Ӥj�r�C"HIR"

                      ������
\n"NOR
"��~�ӻX�j�𦸫I���������A�G�o���u�۷��Y�K�A�@�ǩx�L
�̥��b�L�d�n�����������H�C����O�ܤj����a�C\n"
 );
//        set("outdoors", "xiangyang");

	set("exits", ([
		"east"   : __DIR__"caodi4",
		"west"   : __DIR__"caodi5",
		"south"  : __DIR__"caodi6",
		"north"  : __DIR__"southgate1",
	]));
	set("objects", ([
		__DIR__"npc/pi"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -500);
	set("coor/y", -560);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}