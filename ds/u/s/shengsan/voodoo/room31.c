
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�\�h�}�G���p���Φb���O������_�R�A�A�����b��骺���D���W�A�A
�o�{�o�̪��Ӫ����I���ǲ��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "west" : __DIR__"room30",
	    "north": __DIR__"room33",
            ]));

   set("objects",([
   PUDON"npc/sweeper":1,
   ]));
	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
