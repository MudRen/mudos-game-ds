// Room: /d/xiangyang/eastgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "�C�s����");
	set("long", 
"�o�̬O���������F�������������A�u�������W��O�T�Ӥj
�r�C"HIG"

                      �C�s��
\n"NOR
"��~�ӻX�j�𦸫I���������A�G�o���u�۷��Y�K�A�@�ǩx�L
�̥��b�L�d�n�����������H�C����O�W���Y���۶��A�V��i�J
���ϡC\n"
 );
        set("outdoors", "xiangyang");

	set("exits", ([
		"southup" : __DIR__"walle1",
		"northup" : __DIR__"walle2",
		"west"    : __DIR__"eastjie3",
		"east"    : __DIR__"eastgate2",
	]));
	set("objects", ([
		__DIR__"task/pi2"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
	replace_program(ROOM);
}
