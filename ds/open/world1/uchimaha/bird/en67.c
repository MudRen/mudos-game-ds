#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L���d�h�ϡ�");
 set("long",@LONG
�A�Ө�F�_�A�L���˪L�d�h��, �A�ݨ�a�W���@��
�j�D���L������, ����D�`���j, ���ӬO�@�ثD�`�j��
�D�үd�U��...

LONG
    );
 
 set("exits",(["west":__DIR__"en66",
               "northeast":__DIR__"en63",
               "northwest":__DIR__"en61",
               "north":__DIR__"en62",
               "east":__DIR__"en68",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
