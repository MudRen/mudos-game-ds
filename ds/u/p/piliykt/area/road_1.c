inherit ROOM;

void create()
{

set("short","�p�D��");
set("long", @LONG
�o�̬O�j����Ǫ��p��, ���䦳�ܦh���Цa, �A�i�H�ݨ����ܦh��
�A�Ҧb���W���ѥ�, ���観�ʤj��.     
LONG
);
set("outdoors", "land");


set("exits", ([ 
      
      "west" : __DIR__"big_tree.c",
      "north" : __DIR__"road_2.c", 
       
    ]));
set("objects",([
__DIR__"npc/mob_1.c" : 2,
       ]) );
setup();
}

