#include <ansi.h>;
inherit BULLETIN_BOARD;

void create()
{
set_name(YEL"���q�T��"NOR,({"119 board","board"}) );
set("location", "/u/a/aoe/workroom");
     set("board_id", "aoe_b");
  set("long","�o�Ӫ��l�Ω����p��Aoe�ΡC\n"NOR);
        setup();
        set("capacity", 50);
        replace_program(BULLETIN_BOARD);
}
