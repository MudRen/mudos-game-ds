#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
  set_name(HIW"[MAGIC-BOARD]"NOR, ({ "board","magic-card_b" }) );
  set("location", "/open/world1/wilfred/magic-card/room1");
  set("board_id", "magic-card_b");
  set("long","�o�O���P�ͯd���Ϊ��O�l�C\n" );
  setup();
  set("capacity",30);
  set("master",({ "wilfred" }));
}

