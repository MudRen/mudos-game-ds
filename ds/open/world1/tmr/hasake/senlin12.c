// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","�w���L");
       set("long", "�o�O����Ѥs�}�U���@���w���L�A�L�����~���s�A���a�Q�\\�۫p�p�@
�h�P�w�C��_�誺�@�y���q���s�߫K�O�Ѥs�F�A�s�W�צ~�n���A�s�U�o�O
��𦨽��C���F�n���K�O�j���A�����Ԫ����ħJ�ڤH�b���̩񪪡C\n");

        set("exits", ([
  "north" : __DIR__"senlin2",
        ]));
        
        	set("objects", ([ /* sizeof() == 2 */
	  __DIR__"npc/wolf1" : 4,
	]));

        set("outdoors", "forest");

        setup();
       replace_program(ROOM);
}
