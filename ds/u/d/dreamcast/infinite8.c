#include <ansi.h>

inherit ROOM;

void create()
{
   ::create() ;
   set ("short", "�c�F�F�z") ;
   set ("long", "�o�̴N�O�c�F�F�z�A�]�N�O�۶Ǥѧ��Q�ʩ󦹳B..\n") ;
   set ("exits", ([
                    "west":__DIR__"infinite8.c",
                    "south":__DIR__"infinite9.c", 
                    "east":__DIR__"infinite7.c",
                    "north":__DIR__"infinite8.c",   ])  ) ;
       
        set("outdoors","desert");
        set("no_clean_up", 0);
        set("light", -1); 

        setup();
        replace_program(ROOM);
}

