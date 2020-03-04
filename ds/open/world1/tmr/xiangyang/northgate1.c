// Room: /d/xiangyang/northgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�ȪZ����");
	set("long", 
"�o�̬O���������_�������������A�u�������W��O�T�Ӥj
�r�C"HIB"

                      �ȪZ��
\n"NOR
"��~�ӻX�j�𦸫I���������A�G�o���u�۷��Y�K�A�@�ǩx�L
�̥��b�L�d�n�����������H�C����O�W���Y���۶��A�V�n�i�J
���ϡC\n"
 );
        set("outdoors", "xiangyang");

	set("exits", ([
		"eastup" : __DIR__"walln1",
		"westup" : __DIR__"walln2",
		"south"  : __DIR__"northjie",
		"north"  : __DIR__"northgate2",
	]));
	set("objects", ([
		__DIR__"task/pi1"   : 1,
		__DIR__"npc/bing" : 2,
	]));

	setup();
	replace_program(ROOM);
}
