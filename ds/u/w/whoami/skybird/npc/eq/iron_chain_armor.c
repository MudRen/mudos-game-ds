#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
  set_name("鐵製環鎖鎧",({"iron chain armor","armor"}));
  set("long", @LONG
一件鐵製的戰甲，就防禦力而言，這種鎧甲可說是無可挑剔的，
唯一的缺點就是過於沉重，導致行動不便•
LONG);
  set_weight(15000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "件");
    set("volume",3);
    set("value",8000);
    set("material","iron");
  }
  set("limit_lv",35);
  set("armor_prop/armor",60);
  set("armor_prop/dex",-3);
  setup();
}


