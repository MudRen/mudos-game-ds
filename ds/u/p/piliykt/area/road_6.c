inherit ROOM;

void create()
{

set("short","�����s��");
set("long", @LONG
�o�̴N�O������������s��, �]�O�̼��x���a��, �o�̨�B���O�H�v
, �����������q, �n�����x, ���ܦh�H�b�o�̳}��, ���Ǥp�c��B�c���
���~, ���n�����ȴ�, ���ө����L���H��, ���F���쩳�i�����, ���_
�O���j��.
LONG
);
set("outdoors", "desert");
set("light",1);
set("exits", ([                
        "west" : __DIR__"road_5.c", 
        "east" : __DIR__"road_10.c", 
        "south" : __DIR__"road_7.c", 
        "north" : __DIR__"road_11.c", 
   ]));
set("objects",([
__DIR__"npc/guard_2.c" : 2,
       ]) );
 setup();
}

