#include <ansi.h>

inherit BULLETIN_BOARD;
void create()
{
  set_name(HIR"�����d���O"NOR,({"board"}));
  set("location","/u/s/sonicct/workroom.c");
  set("board_id", "sonicct_b");
  set("long",
    "�o�O�@���d���O�C\n");
  setup();
  set("capacity",100);
   replace_program(BULLETIN_BOARD);
}
