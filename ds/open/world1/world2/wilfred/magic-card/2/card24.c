inherit __DIR__"std_card.c";
void create()
{
  set("short","老人");
  set("pow", ({4,5,5,3}) );
  set("lv",4);
  set("ver",2);
  set("ver_n","孟村傳奇");
  set("num",24);
  set("long",@LONG
一位看來一臉慈祥、與世無爭模樣的老人，看其身形
甚是削瘦，卻給人有種超然物外的感覺。
LONG
);
  setup();
}