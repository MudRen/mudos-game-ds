#include <ansi.h>

inherit ROOM;

void create()
{
   ::create() ;
   set ("short", "�c�F�F�z") ;
   set ("long", "�o�̴N�O�c�F�F�z�A�]�N�O�۶Ǥѧ��Q�ʩ󦹳B..\n") ;
   set ("exits", ([
                    "west":__DIR__"infinite2.c",
                    "south":__DIR__"infinite4.c",
                    "north":__DIR__"infinite3.c",
                    "east":__DIR__"infinite3.c",
   ])  ) ;
       
        set("outdoors","desert");
        set("no_clean_up", 0);
        set("light", -1); 

        setup();
        replace_program(ROOM);
}

