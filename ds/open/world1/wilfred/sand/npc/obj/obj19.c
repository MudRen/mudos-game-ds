#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIY"金銀財寶"NOR,({"gold"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","黃澄澄的金子及白花花的銀子，真是人見人愛。");
    set("value",10000);
  }
  setup();
}
