// Room: /u/a/alickyuen/area/zoo2.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST�CRoad�ICyberZoo"NOR);
	set("long", @LONG
�i�F�ʪ���A�A�����ݨ쪺�O�@�Ǥ���i�R���p�ʪ��A�����ߡB���V
���B�Q�t���C�O�A�ؤ��v���A�@�����L�h�K�i�ݨ��h�ʪ��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zoo4",
  "south" : __DIR__"zoo",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
