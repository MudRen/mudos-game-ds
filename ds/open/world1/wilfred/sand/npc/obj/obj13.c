// 繼承國人貪多嚼不爛, 一定吃到飽的精神, 東西能吃, 很便宜, 帶不出場
// 價錢約為原設定值的三分之一
// wilfred@DS

inherit ITEM;
inherit F_WATER;
void create()
{
  set_name("紅蠍藥酒", ({ "cheap wine","wine" }) );
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","以有毒的紅(赤)蠍泡製的藥酒，對於回復精神有很好的功\效。\n");
    set("unit", "瓶");
    set("value",40);
    set("heal_mp",30);
    set("water_remaining",2);
  }
  setup();
  set("no_auc",1);
}
