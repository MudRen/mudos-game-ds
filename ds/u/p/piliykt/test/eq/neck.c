#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(HIY"天晶石"NOR ,({ "sky stone neck","neck" }) );
        set("long","神兵天晶的小塊石頭。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(50);
                set("rigidity",10);
                set("unit","個");
                set("value",0);
                set("armor_prop/int", 50);
                set("armor_prop/con", 5);
                set("armor_prop/str", 5);
                set("armor_prop/dex", 1);
                set("armor_prop/armor", 20);
                              
        }
         set("wear_msg",
HIR"$N戴上$n"HIR"之後"HIG"全身閃著綠光"HIM"\n"NOR);
        set("unequip_msg", HIM"$N拿下$n"HIB"後，綠光慢慢消失。\n"NOR);
        setup();
}
int query_autoload() { return 1; }

