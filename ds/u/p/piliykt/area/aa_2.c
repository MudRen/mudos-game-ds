inherit ROOM;

void create()
{

set("short","���Y���D");
set("long", @LONG
�o�O�@����e�F�誺���Y, ���Y���\��F�\�h�p�֮�, ���H�@�غ�N
�s�M���Pı, ��ǦU���@�����D, ���O�q���ש�. 
LONG
);
set("world", "past");
set("light",1);
set("exits", ([                
         "south" : __DIR__"aa_1.c", 
         "north" : __DIR__"aa_3.c", 
         "west" : __DIR__"aa_4.c", 
         "east" : __DIR__"aa_5.c", 
   ]));
set("objects",([
__DIR__"npc/guard_3.c" : 1,
              ]) );

setup();
}

