inherit __DIR__"std_card.c";
void create()
{
  set("short","農夫");
  set("pow", ({2,3,2,4}) );
  set("lv",2);
  set("ver",2);
  set("ver_n","孟村傳奇");
  set("num",14);
  set("long",@LONG
一位正彎腰、赤腳站在田裡插秧的農夫，瞧他辛苦揮汗的背影，令人
不由地打從心裡感謝農夫終年的辛勞。
LONG
);
  setup();
}