#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
  set_name(HIW+BLK"�ªO"NOR, ({ "board" }) );
  set("location", "/u/u/uchimaha/workroom");
  set("board_id", "uchimaha_board");
  set("long","�o�O�@���Ψӥ洫�T�����O�l�C\n" );
  setup();
  set("capacity", 100);
}

