#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
  set_name(HIR"�d���O"NOR, ({ "muder's board" }) );
  set("location", "/u/m/muder/workroom");
  set("board_id", "muder_b");
  set("long","�p�G�j�a��p�̧ڦ�ԣ��ĳ�M�n�D���Яd���b�������C\n" );
  setup();
  set("capacity",100);
  set("master",({ "muder" }));
}

