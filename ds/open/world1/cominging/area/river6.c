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
"�o�̬O�B�F������~�@���e�A�b�o�̦��\\�h�p�ʪ��C\n"
	);
	set("exits", ([
  "south" : __DIR__"river7.c",
  "north" : __DIR__"river5.c",
  "enter"  : __DIR__"bdoor3.c",
  "west"  : __DIR__"fgo.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}