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
 
 set("exits",(["west":__DIR__"en56",
               "east":__DIR__"en58",
               "south":__DIR__"en62",
               "northeast":__DIR__"en54",
               "northwest":__DIR__"en52",
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
