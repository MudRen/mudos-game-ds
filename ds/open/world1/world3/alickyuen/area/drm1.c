// Room: /u/a/alickyuen/area/drm1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CDoor�ISecret"NOR);
	set("long", @LONG
�i�J�F�o�̫�A�A�o�{�o�̫D�`�t�A�o���q�D�����O�q�����̪��C��
�A�������ݨ��@�Ӧu�å��b������઺�ݵۧA�C���ְk�R�a�I
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"dpy2",
]));
            set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/protector.c" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
