inherit BULLETIN_BOARD;

void create()
{
  set_name("�Ϭٯd���O", ({ "board","jail_board" }) );
  set("location", "/open/always/ppl_jail");
  set("board_id", "jail_board");
  set("long","\n�A���G�藍�_�A�گu���b�Ϭ٤F�A�Э�̧ڧa�C\n\n" );
  setup();
  set("capacity", 100);
  set("master",({ "acme","cominging","tmr","wilfred" }));
}

