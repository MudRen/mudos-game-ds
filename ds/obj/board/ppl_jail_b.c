inherit BULLETIN_BOARD;

void create()
{
  set_name("反省留言板", ({ "board","jail_board" }) );
  set("location", "/open/always/ppl_jail");
  set("board_id", "jail_board");
  set("long","\n你說：對不起，我真的在反省了，請原諒我吧。\n\n" );
  setup();
  set("capacity", 100);
  set("master",({ "acme","cominging","tmr","wilfred" }));
}

