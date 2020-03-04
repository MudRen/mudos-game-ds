// Room: /open/world1/tmr/dragoncity/northgate2.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�C�s�~��");
        set("long", 
"�o�̬O�Y�s�����F�������~�����A�u�������W��O�T�Ӥj�r�C\n"
"\n"
HIC"                      �C�s��\n"NOR
"\n"
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"eastgate1",
]));
        set("current_light", 2);
        set("no_clean_up", 0);
        set("outdoors", "land");

        setup();
        replace_program(ROOM);
}

