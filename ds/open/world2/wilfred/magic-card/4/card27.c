inherit __DIR__"std_card.c";
void create()
{
  set("short","藍天");
  set("pow", ({8,4,1,7}) );
  set("lv",6);
  set("ver",4);
  set("ver_n","龍槍系列");
  set("num",27);
  set("long",@LONG
藍天是龍騎將奇蒂拉的坐騎, 牠身長42呎, 口中吐出的強力雷電足以
摧毀堅固的城牆, 牠與奇蒂拉近乎完美的配合, 讓這組搭擋成為黑暗
之后最得力的部屬。
LONG
);
  setup();
}