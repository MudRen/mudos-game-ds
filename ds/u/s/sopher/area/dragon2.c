#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIW"�}����"HIR"�j�D"NOR);
        set ("long", @LONG
�A���i�����A���F�Q�������|���𮧩ҧl�ޥ~
�A�o�̪��H���G���۷�Mħ�i�ˡA�A���b�@���j�D�W
�C��Ǿ�����ƦC�ۧL���A�q�u��j��C�A�@���ѥ�
�A�C��h�L�ݰ_�Ӥ]���۷�V�m�����C�A���T��[�q
�ȳo�ӭx�ΤF�C
LONG);
        
        set("exits", ([
        "south": __DIR__"dragon1",
        "north": __DIR__"dragon3",
        "west" : __DIR__"dragon4",
        "east" : __DIR__"dragon5",
         ]) );
        set("objects", ([
        __DIR__"npc/soldier" : 1,
        ]) );
set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}    
