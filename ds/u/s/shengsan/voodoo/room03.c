inherit ROOM;
#include <path.h>    

void create()
{
	set("short", "�˪L�B�D");
	set("long", @LONG
�o�ӨB�D�ݨӦ��I���˩ǲ��A�A�i�Hť�찣�F�˸��n���~�A�٦���
���۴������n���A�J��o�ر��ΡA�A�]���ѦۥD������ĵı�ߡA�H���I
��Ӫ����p�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "west" : __DIR__"room04",
            "south" :PUDON"cut_evil/room1",
	    "down" : __DIR__"room02",
            ]));

	set("no_clean_up", 0);
	set("outdoors",1);
	setup();
load_object("/u/p/pudon/war2/tfighter");
load_object("/u/p/pudon/war2/tiger");
	replace_program(ROOM);
}
