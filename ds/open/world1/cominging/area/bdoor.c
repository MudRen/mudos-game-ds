#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�B�F���n��");
	set("long",
"\n"
"�����@�@�����@�@�����@�@�����@�@�����@�@�����@�@�����@�@����\n"
"�i�i�@�@�i�i�@�@�i�i�@�@�i�i�@�@�i�i�@�@�i�i�@�@�i�i�@�@�i�i\n"
HIR"�i�i�i�i"HIW"�i�i�i�i"HIR"�i�i�i�i"HIW"�i�i�i�i"HIR"�i�i�i�i"HIW"�i�i�i�i"HIR"�i�i�i�i"HIW"�i�i\n"
HIW"�i�i�i�i"HIR"�i�i�i�i"HIW"�i�i�i�i"HIR"�i�i�i�i"HIW"�i�i�i�i"HIR"�i�i�i�i"HIW"�i�i�i�i"HIR"�i�i\n"
HIR"�i�i�i�i"HIW"�i�i�i�i"HIR"�i�i�i"HIC"���B�F���n����"HIR"�i�i"HIW"�i�i�i�i"HIR"�i�i�i�i"HIW"�i�i\n"
HIW"�i�i�i�i"HIR"�i�i�i�i"HIW"�i�i�i�h"HIR"�h�h�h�h"HIW"�h�h�i�i"HIR"�i�i�i�i"HIW"�i�i�i�i"HIR"�i�i\n"
HIR"�i�i�i�i"HIW"�i�i�i�i"HIR"�i�i�i�i"HIW"�@�@�@�@"HIR"�@�i�i�i"HIW"�i�i�i�i"HIR"�i�i�i�i"HIW"�i�i\n"
HIW"�i�i�i�i"HIR"�i�i�i�i"HIW"�i�i�i�i"HIR"�@�@�@�@"HIW"�@�i�i�i"HIR"�i�i�i�i"HIW"�i�i�i�i"HIR"�i�i\n"
HIR"�i�i�i�i"HIW"�i�i�i�i"HIR"�i�i�i�i"HIW"�@�@�@�@"HIR"�@�i�i�i"HIW"�i�i�i�i"HIR"�i�i�i�i"HIW"�i�i\n"
HIW"�i�i�i�i"HIR"�i�i�i�i"HIW"�i�i�i�i"HIR"�@�@�@�@"HIW"�@�i�i�i"HIR"�i�i�i�i"HIW"�i�i�i�i"HIR"�i�i\n"
HIR"���i�i�i"HIW"�i�i�i�i"HIR"�i�i�i�i"HIW"�@�@�@�@"HIR"�@�i�i�i"HIW"�i�i�i�i"HIR"�i�i�i�i"HIW"�i��\n\n"NOR
	);
	set("exits", ([
  "north" : __DIR__"bsouth4.c",
  "out" : __DIR__"river.c",
]));
	set("objects",([
  __DIR__"npc/gateguard.c": 3,
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	set("light",1);
	setup();
	replace_program(ROOM);
}
int valid_leave(object me,string dir)
{
        if( dir== "out" && !userp(me))
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me,dir);
}
