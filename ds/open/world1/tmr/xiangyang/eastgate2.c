// Room: /d/xiangyang/eastgate2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�C�s�~��");
	set("long", 
"�o�̬O���������F�����A�u�������W��O�T�Ӥj�r�C"HIG"

                      �C�s��
\n"NOR
"��~�ӻX�j�𦸫I���������A�G�o���u�۷��Y�K�A�@�ǩx�L
�̥��b�L�d�n�����������H�C����O�ܤj����a�C\n"
 );
	set("exits", ([
		"west"  : __DIR__"eastgate1",
//		"east"  : "/d/jianzhong/shanlu1",
	]));
	set("objects", ([
		__DIR__"npc/pi"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -440);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}