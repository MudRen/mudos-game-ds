#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�y����"NOR"��"HIW"�_����"NOR);
 set("long",@LONG
�A�~�򩹥_��, �o�̪��u��S���e�����h, �Pı���I�N�M, 
�b�A���F��O�y�����������a, �A�i�H��L����, ��L�ͤ�. �b
�A�����O�y�����^�����a, �A�i�H�h���ݬݥL������Q�٬��^
��.
LONG
    );
 
 set("exits",(["north":__DIR__"village15",
               "south":__DIR__"village12",
               "east":__DIR__"village14", 
               "west":__DIR__"village19", 
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}

