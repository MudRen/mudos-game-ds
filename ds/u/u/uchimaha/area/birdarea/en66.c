#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L���d�h�ϡ�");
 set("long",@LONG
�A�Ө�F�_�A�L���d�h��, �o�̦��ǧA�q�����L��
�Ӫ�, �٦��@�ǧA�q�����L������, �A�߷Q�o�O����_
�Ǫ��˪L.

LONG
    );
 
 set("exits",(["east":__DIR__"en67",
               "southwest":__DIR__"en70",
               ]));
 set("objects",([__DIR__"npc/bee" : 3,
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
