inherit ROOM;

void create()
{

set("short","���Y���D");
set("long", @LONG
�o�@�����Y, ���������F��q�h, �A�����i�Hť��@���n��, ���A�n
�_���Q�h�ݤ@�ݨ쩳���^��.
LONG
);
set("light",1);
set("exits", ([               
         
         "west" : __DIR__"aa_2.c", 
         "east" : __DIR__"aa_9.c", 
   ]));

set("objects",([
__DIR__"npc/guard_3.c" : 1,
              ]) );

setup();
}

