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
 
 set("exits",(["south":__DIR__"en70",
               "northeast":__DIR__"en61",
               "north":__DIR__"en60",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        