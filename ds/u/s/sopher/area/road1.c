#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIG"�v���˪L"NOR);
        set ("long", @LONG
�I�I���F���򻷪����A�A�C�C�P�줣�w�A�O�e��
�������O�A�xŸ����ܡH�A�٬O�H....�o�̥|�P���M
��줴�M�۷�Z�K�A���O�e�誺���w�g�V�ӶV�j�F�C
LONG);  
        
        set("exits", ([
        "south": __DIR__"road2",
        "north": __DIR__"dragon1",
        ]) );
        set("objects", ([
        __DIR__"npc/dog" : 1,
        ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}
