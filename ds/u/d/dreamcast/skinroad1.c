#include <ansi.h>

inherit ROOM;

void create()
{
   ::create() ;
   set ("short", "�@�Ӱ򥻪��ж�") ;
   set ("long", "�o�O�@�ӫD�`" + "²�檺�ж��C\n") ;
   set ("exits", ([
                    "west":__DIR__"skinroad2.c",
                    "east":__DIR__"desert1.c",
   ])  ) ;
       
        set("outdoors","desert");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
