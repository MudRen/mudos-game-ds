// 這部分正在寫 wilfred@DS

#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIW"石柱"NOR,({"stone"}));
  set_weight(99999);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","一個石柱 -- 說是石柱, 不如說是益智遊戲的 item");
  }
  set("no_get",1);
  set("no_sac",1);
  setup();
}
/*
void init()
{

}
*/