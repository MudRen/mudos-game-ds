inherit __DIR__"std_card.c";
void create()
{
  set("short","白毛大猿");
  set("pow", ({2,7,7,5}) );
  set("lv",6);
  set("ver",2);
  set("ver_n","孟村傳奇");
  set("num",27);
  set("long",@LONG
一隻白毛大猿，獨居在此山谷，得天地之靈氣，雖已年過八十
，仍蹦跳自如，不見老樣。其眼神深邃中透露著一股靈性。
LONG
);
  setup();
}
