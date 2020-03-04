#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
set_name(HIY"宗本式貳刀"NOR,({"left blade","blade"}));
        set_weight(7550);   
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
這是宗本左左氏家族代代相傳的寶刀，上面寫「宗本左左太郎」
似乎是這把刀最早的主人，是施展二刀流的人用的刀。
LONG);
                set("unit", "把");
                set("material","blade");
        }
  
set("value",4500);
set("limit_str",15);
set("limit_dex",20);
set("armor_prop/dex",2);
set("armor_prop/int",1);
set("wield_msg","$N從腰旁迅速拔出兩把$n，拿在手上。\n");
set("unwield_msg", "$N將$n插入刀鞘之中，卻感覺宗本式貳刀的的力量在振動。\n");
init_blade(60,TWO_HANDED);
setup();
}

