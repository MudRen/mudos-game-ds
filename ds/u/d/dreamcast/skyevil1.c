#include <ansi.h>

inherit ROOM;
inherit DOOR;
#include <room.h>

void create()
{
   ::create() ;
   set ("short", "�@�Ӱ򥻪��ж�") ;
   set ("long", "�o�O�@�ӫD�`" + "²�檺�ж��C\n") ;
   set ("exits", ([
                    "south":__DIR__"skyevil2.c",
                    "up":__DIR__"infinite10.c",
]) ) ;
create_door("up",HIM"�ѧ���"NOR,"down",DOOR_LOCKED,"skyevilkey");


       

        set("no_clean_up", 0);
        set("light", -1); 

        setup();

}

