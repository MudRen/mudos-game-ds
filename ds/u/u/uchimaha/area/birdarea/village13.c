#include <room.h>
inherit ROOM;
void create()
{
 set("short","�_����");
 set("long",@LONG
�A�~�򩹥_��, �o�̪��u��S���e�����h, �Pı���I
�N�M, �b�A���F��O�y�����������a, �A�i�H��L����, 
��L�ͤ�.
LONG
    );
 
 set("exits",(["north":__DIR__"village15",
               "south":__DIR__"village12",
               "east":__DIR__"village14",
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
