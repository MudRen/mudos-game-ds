inherit __DIR__"std_card.c";
void create()
{
  set("short","守城官兵");
  set("pow", ({4,7,3,6}) );
  set("lv",5);
  set("ver",2);
  set("ver_n","孟村傳奇");
  set("num",26);
  set("long",@LONG
一個守護城門的官兵，看起來精神奕奕，專注地看著過
往的人群，不時擦拭滿頭的汗水。
LONG
);
  setup();
}