#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIC"HANS���ήɪŵ��_�޲z�h��"NOR);
        set ("long", @LONG
�e��N�O�ɪŵ��_�F�I�ѩ�o���p�e�i��o�۷����K
�C�]�����D���a�誺�H��O�֤��S�֡C�h���e�����޲z
���A���b�M�d��V�d���̪������M��ơC
LONG);  
        
        set("exits", ([
        "north" : __DIR__"timeroom",
        "south" : __DIR__"time2",
        ]) );
        set("objects", ([
        __DIR__"npc/admin" : 2,
        ]) );
        set("light",1);
        setup();
        replace_program(ROOM);
}
