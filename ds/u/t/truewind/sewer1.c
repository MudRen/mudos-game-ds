// Room: /u/t/truewind/sewer1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�U���D");
	set("long", @LONG
�������L���b�@�y���W��A�A�`�N��o�̬O�Ӧa�U���D�C�P��D
�`���t����A�٦��@�Ǥp�ѹ��b�a���Ӫ��h�C������G���Y�ة_
�Ǫ��n���Ǩ�...�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"Minetown/area/machinefield5",
]));
	set("current_light", 0);
	setup();

}
