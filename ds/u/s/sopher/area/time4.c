#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIC"HANS���ήɪź޲z�B�q�D"NOR);
        set ("long", @LONG
�A�Ө�F�Q�r���f�A�|�P�ſ������A�@�ѴH�N
��W�F���Y�C�F�䩹�Z���ǡA����h�O�q���ɪź�
�z�B�j�U�A�ӫn��A�h�O�@���۷�·t���q�D�C
LONG);  
        set("exits", ([
        "north" : __DIR__"time3",
        "south" :__DIR__"tunnel",
        "east" : __DIR__"weapon",
        "west" : __DIR__"roadx",
         ]) );
        
        set("light",1);
        setup();
        replace_program(ROOM);
}
