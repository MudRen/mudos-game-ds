//Room: /d/ruzhou/hong-damen.c
// by llm 99/06/12

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "���Q�ܤj��");
   set("long",
"���e�O�@�y��ն������j�ܮx�A���Y���j�B������ˡA�����ǻP�Ӯc\n"
"�ۦ������D�A�u�O�j������ߪ����O�Q��B���~�A�ӬO���N�N���߰]���l\n"
"���k�A�ӥB�j�����}�A���H�H�N�i�J�A�����W���@�����j���Q��еP\n"
HIR"            ��    �Q    ��\n"NOR
"\n");
	set("exits", ([
		"west" : __DIR__"ruzhou",
                "east" : __DIR__"hong-zoulang",
   ]) );


   set("objects", ([
//   	__DIR__"npc/meipo" : 1,
      ]) );
   setup();
   replace_program(ROOM);
}

