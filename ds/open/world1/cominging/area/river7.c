#include <ansi.h>
#include <path.h>
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
"�o�̬O�B�F����n��~�@���e�A�b�o�̦��\\�h�p�ʪ��C\n"
        );
        set("exits", ([
  "north" : __DIR__"river6.c",
  "east"  : __DIR__"river.c",
  "west"  : COMINGING_PAST + "purple_sun/psin.c",
  "southwest" : LINJACK_PAST + "emperor/path1.c",
]));

        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}

