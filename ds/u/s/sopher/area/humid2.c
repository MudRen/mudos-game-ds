#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", YEL"�q���h�A�a���q���W"NOR);
        set ("long", @LONG
�A�@�ѵL�O�P�ۧA���Y�B�{�A�A���}�B�C�C��
�H���F�_�ӡA�ܦV���J�F�·t�����ҡA�o�@���h�A
�u���O�Ӹ޲��աI
LONG);  
        
        set("exits", ([
        "west" : __DIR__"humid",
        "east" : __DIR__"humid3",
        ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}
