#include <ansi.h>
#include <weapon.h>
inherit FORK;


void create()
{
  set_name(HIW"麟馬槍"NOR, ({ "dragon horse-spear","spear" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "隻");
    set("long", HIW"問蒼天情何以堪，問萬物落葉彬紛，陳人麟鑄鋼鐵煉，迴馬盼似美人憐。\n"NOR);
    set("material", "iron");
    set("value",3000);
    set("volume",3);
    set("limit_int",15);
    set("weapon_prop/str",2); 
    set("weapon_prop/dex",1);
    set("weapon_prop/int",-3); 
 }
  init_fork(65);
  setup();
}

