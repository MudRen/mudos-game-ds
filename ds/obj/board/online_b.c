#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
  set_name(HIG"�ԳN�Q�תO"NOR, ({ "board","online_b" }) );
  set("location", "/open/world1/wilfred/club/dragon/online");
  set("board_id", "online_b");
  set("long","�o�O���s�u�Ԥͯd���Ϊ��O�l�C\n" );
  setup();
  set("capacity",100);
  set("master",({ "wilfred" }));
}

