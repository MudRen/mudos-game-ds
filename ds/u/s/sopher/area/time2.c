#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIC"HANS���ήɪź޲z�B�����f"NOR);
        set ("long", @LONG
�o�̬O�q���ɪŵ��_���q�D�W�I�ѩ�o���p�e�i��o�۷�
���K�C�]�����D���a�誺�H��O�֤��S�֡C�h���e�����޲z
���A���b�M�d��V�d���̪������M��ơC
LONG);  
        
        set("exits", ([
        "north" : __DIR__"time",
        "south" :__DIR__"time3",
         ]) );
        
        set("light",1);
        setup();
        replace_program(ROOM);
}
