#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIG"�v���˪L-�Q�r���f"NOR);
        set ("long", @LONG
�áA�A����o�A�@�Ѵc��q�A�F���ƨ�...�n��
�O�ͯ��...����P�e�������F��ӪŮ�C�b���P��
�����������U�A�A�뤣�����W���}�o�C
LONG);  
        
        set("exits", ([
        "south": __DIR__"",
        "north": __DIR__"road2",
        "west" : __DIR__"little1",
        "east" : __DIR__"humid",
        ]) );
        set("objects", ([
        __DIR__"npc/dog" : 1,
        ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}
