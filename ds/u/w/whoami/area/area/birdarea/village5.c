#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�y����"NOR"��"HIW"�n����"NOR);
 set("long",@LONG 
�A���n��, �Ө�F�s���n�誺��D, �b�A���F��O�@�a�y��
����Q, ���ϧA���F��n��������, �h���O�Ӥ��������, �o��
���q�_��n�����U�h.
LONG
    );
 
 set("exits",(["north":__DIR__"village4",
               "south":__DIR__"village7",
               "east":__DIR__"village6",
           ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        

