// Room: /d/xiangyang/westgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�ժꤺ��");
	set("long", 
"�o�̬O���������諰�����������A�u�������W��O�T�Ӥj
�r�C"HIW"

                      �ժ��
\n"NOR
"��~�ӻX�j�𦸫I���������A�G�o���u�۷��Y�K�A�@�ǩx�L
�̥��b�L�d�n�����������H�C����O�W���Y���۶��A�V�F�i�J
���ϡC\n"
 );
        set("outdoors", "xiangyang");

	set("exits", ([
		"southup" : __DIR__"wallw2",
		"northup" : __DIR__"wallw1",
		"east"    : __DIR__"westjie3",
		"west"    : __DIR__"westgate2",
	]));
	set("objects", ([
		__DIR__"task/pi4"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -550);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
