#include <ansi.h>
#define BBLU ESC+"[44m"
inherit ROOM;
void create()
{
	set("short", "�@���e");
	set("long",
NOR"\n"BBLU"�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@ �@�@�@"NOR"\n"NOR
BBLU""HIW"�@�@�@�\\�\\�\\�\\�\\�\\�@�@�@�ʡʡʡʡʡ@�@�@�@�@�@�@�@ �@�@�@�@"NOR"\n"
BBLU""HIW"�@�@�@�ʡʡʡʡʡʡ\\ �\\ �\\�@�\\ �\\�@�@�@�@�@�@�@�@�@�@�@�@�@"NOR"\n"
BBLU""HIW"�\\  �\\ �@�@�@�@�@�@�ʡʡʡʡ@�ʡʡʡ@�@�@�@�@�@�@�@�@�@�@�@"NOR"\n"
BBLU""HIW"�ʡʡʡʡ@�@�@�@�\\�\\�\\�\\�\\�@�@�@�@�@�@�@�\\�\\�\\ �@�@�@�@�@�@"NOR"\n"
BBLU""HIW"�@�@�@�@�@�@�@�@�ʡʡʡʡʡ@�@�@�@�@�@�@�ʡʡʡ@�@�@�@�@ �@"NOR"\n"NOR"\n"
NOR""
"�o�̬O�B�F���F��~�@���e�A�b�o�̦��\\�h�p�ʪ��C\n"
	);
	set("exits", ([
  "south" : __DIR__"river1.c",
  "north" : __DIR__"river3.c",
  "east"  :  "/open/world1/wu_sha_town/seacoun1.c",
  "enter"  : __DIR__"bdoor1.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
