#include <ansi.h>
#include <armor.h>
inherit LEGGING; 
void create()
{
   set_name( HIG"月翎"HIY"波"HIM"鑲"NOR,({"moon wave fiber", "fiber", "leggings"}));
  set("long", @LONG  
這是一件由嫦娥採集月桂樹的纖維－月翎－所製的水波紋護膝裙。月桂樹經
年累月遭受吳剛不眠不休地砍伐，樹身的傷痕卻可以快速回覆，全靠月翎神
奇的功效。嫦娥有鑑於此，遂將月翎縫製成此水波紋擬狀的護膝裙，靠著波
紋外觀可大量吸附攻擊力的功效，更提高了此裝備的防護力。
LONG);
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "串");
    set("volume",1);
    set("material","silver");
    set("no_drop",1);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_sell",1);
  }
  set("wear_msg", HIC"$N圍上了月翎波鑲，煞那間，四周圍散佈著醉人的芳香。\n"NOR);
  set("unequip_msg",HIC"香氣散去，只見$N將月翎波鑲撩起曲在腰間。\n"NOR);
  set("armor_prop/bar", 1);
  set("armor_prop/show_damage",1);
  setup();
}

int query_autoload() { return 1; }


