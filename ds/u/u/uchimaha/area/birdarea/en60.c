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
 
 set("exits",(["north":__DIR__"en55",
               "south":__DIR__"en65",
               ]));
 set("objects",([__DIR__"npc/fly" : 4,
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
