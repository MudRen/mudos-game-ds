#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIC"�M�D���D"NOR);
        set ("long", @LONG
�Ө�o�A�A�Q�@�}�᭻�Ұg�C��~�n������ڡI�A
�����۸T���a���ڴ��o�B...�F����G���y��骺��
�l�H
LONG);
        
        set("exits", ([
        "west" : __DIR__"dragon2",
        "east" : __DIR__"flower_road1",
         ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}    
