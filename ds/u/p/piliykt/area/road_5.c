inherit ROOM;

void create()
{

set("short","�j��");
set("long", @LONG
�A���b�@���e�j����D�W, �o�̫D�`�����x, �]���o�̬O���������
�n�D��, �o�̦��\�ǧ��צb�a�W���^��, �L�̥��b�V�H�^�Q�F��Y, ���_
�䦳�a�ľQ.���F�쥫����.
LONG
);
set("outdoors", "desert");

set("exits", ([                
         "west" : __DIR__"road_4.c", 
         "north": __DIR__"shop_1.c",       
         "east" : __DIR__"road_6.c",
   ]));
set("objects",([
__DIR__"npc/mob_3.c" : 1,
       ]) );

 setup();
}

