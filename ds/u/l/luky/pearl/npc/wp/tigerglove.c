#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
set_name("手指虎",({"tiger finger","finger"}));
set_weight(32500);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long","\n 精鋼做成的雙手武器, 適合近身搏鬥用。\n");
            set("unit", "雙");
            set("rigidity",90); //硬度
            set("material","steel"); //材質
set("hammer",55);
//set("flag", (int)flag | TWO_HANDED );
//set("limit_lv",35);
set("weapon_prop/dex",2);
set("value",5520);
           }
init_hammer(847,TWO_HANDED);
  set("wield_msg", HIC"$N拿出$n, 用雙手緊緊握住。\n"NOR);
  set("unequip_msg", HIB"$N從手上取下$n, 順手放回口袋。\n"NOR);
        setup();
}



