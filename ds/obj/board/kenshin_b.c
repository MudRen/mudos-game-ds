#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
set_name(HIW"����"HIC"����"NOR, ({ "kenshin's board","board" }) );
set("location", "/u/k/kenshin/workroom");
set("board_id", "kenshin_b");
setup();
set("capacity",100);
replace_program(BULLETIN_BOARD);
}

