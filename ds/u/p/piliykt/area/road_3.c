inherit ROOM;

void create()
{

set("short","��j��");
set("long", @LONG
�A�����b��j��W, �o�̨�Ǧ��ܦh���ө��M�u�c, �V�A�c�⪫�~
, ���A��������.���F��F�j��. ���n�����D��.
LONG
);
set("outdoors", "desert");
set("exits", ([            
         "south": __DIR__"road_2.c",       
         "east" : __DIR__"road_4.c",
   ]));
set("objects",([
__DIR__"npc/mob_2.c" : 1,
       ]) );

 setup();
}

