// 設定最多能裝 8 張牌
inherit ITEM;

void create()
{
  set_name("牌盒", ({ "card box","box" }) );
  set("long","用來裝 Magic Card 的牌盒，通常比賽或遊戲時才會用到。\n");
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "個");
    set("volume",6);
    set("value",100);
  }
  setup();
  set_max_capacity(8);
  set_max_encumbrance(12);
}
