#include <ansi2.h>
inherit ROOM;
void create()
{
  set ("short", YEL"���F����"NOR);
  set ("long", @LONG
�o�̬O�@��L�ڪ��j�F�z�A���F�s�P���G���@��Ӫ��~�A�A�]��
���줰��ȱo�`�ت��F��A�@�}���F�j�ӡA�N�|�g�j�o�g���a�g�A��
�p���Z�����F���A�u���F�䤣���B���ӧ����A�O�H�ߦw�C
LONG
);

  set("exits", ([
  "east" : __DIR__"room24",
]));
  set("no_clean_up", 0);
  set("outdoors", "land");
  setup();
  replace_program(ROOM);
}
