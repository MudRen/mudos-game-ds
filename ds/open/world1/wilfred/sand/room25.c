#include <ansi2.h>
inherit ROOM;
void create()
{
  set ("short", YEL"���F����"NOR);
  set ("long", @LONG
�o�̬O�@��L�ڪ��j�F�z�A���F�s�P���G���@��Ӫ��~�A�A�]��
���줰��ȱo�`�ت��F��A�@�}���F�j�ӡA�N�|�P�j�o�g���a�g�A��
�p���Z�����F���C
LONG
);

  set("exits", ([
  "north" : __DIR__"room24",
  "south" : __DIR__"room26",
]));
  set("objects",([
  __DIR__"npc/npc1" : 2,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
