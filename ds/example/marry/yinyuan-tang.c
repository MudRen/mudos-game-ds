// Room: /d/ruzzhou/yinyuan-tang.c    ���󤧳B
// by llm 99/06

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�ýt��");
   set("long", @LONG
�A²�����i�F�@�����⪺�@�ɡA���C���k�a���ۦU���U�˪�������v
�m�ȶK��A�ӲӬݥh�A�C�@�B����¸����p�m��ġA�z�X�@�Ѫѿ@������
�y��^�A���@����СG
          �d���ýt�@�u�o
LONG
   );
	set("exits", ([
		"west" : __DIR__"hongniang-zhuang",
   ]) );
   set("objects", ([
   ]) );
   set("no_fight",1);
   set("no_steal",1);
   set("no_beg",1);
   set("no_sleep_room",1);

   setup();
	replace_program(ROOM);
}
