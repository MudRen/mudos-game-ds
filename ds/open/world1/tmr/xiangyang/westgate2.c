// Room: /d/xiangyang/westgate2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�ժ�~��");
	set("long", 
"�o�̬O���������諰���A�u�������W��O�T�Ӥj�r�C"HIW"

                      �ժ��
\n"NOR
"��~�ӻX�j�𦸫I���������A�G�o���u�۷��Y�K�A�@�ǩx�L
�̥��b�L�d�n�����������H�C����O�ܤj����a�C\n"
 );
//        set("outdoors", "xiangyang");

	set("exits", ([
		"east"  : __DIR__"westgate1",
	]));
	set("objects", ([
		__DIR__"npc/pi"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -560);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}