#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", "����");
  set ("long",NOR""+
"�۷��_�����p�����ѡA���]���¡A�Ыί}��A"HIC"�̭��u�i�۴X��\n"+
"�H���A�ݨӬO���ҩҭP�A���|���X�}���C\n"NOR);

  set("exits", ([
  "east" : __DIR__"room13",
]));
  set("objects",([
  __DIR__"npc/npc31" : 1,
]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

