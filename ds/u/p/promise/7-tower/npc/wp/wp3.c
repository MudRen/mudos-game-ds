#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
  set_name(NOR+MAG"勿魔杖"NOR , ({ "evil staff","staff" }) );
  set_weight(9000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "隻");
    set("long", "與如來憾魔杖成對比的杖類神兵，此杖擁有著強烈的妖氣，在武林被封為佛家剋星。\n"NOR);
    set("material", "sliver");
    set("value",12000);
    set("weapon_prop/con",2);
    set("weapon_prop/int",-2);
    set("limit_lv",40);
    set("limit_dex",30);
    set("limit_con",50);
    set("limit_int",50);
    set("limit_str",30);  
  }
    init_staff(55);
  setup();
} 

