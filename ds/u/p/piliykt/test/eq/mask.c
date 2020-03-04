#include <armor.h>
#include <ansi.h>

inherit MASK;

void create()
{
        set_name(HIY"王"HIG"者"HIW"面"HIR"具"NOR, ({"king mask" ,"mask" }));
        set_weight(500);
        set("long", @long
這張面具散發出一股王者的力量,讓你不禁的發出一陣顫抖,誰擁有了這張面具,無疑的他一定可
以獨步江湖.
long);
        set("unit", "張");
        set("value", 0);
        set("armor_prop/armor", 50);
        set("armor_prop/con", 10);
        set("armor_prop/str", 10);
        set("armor_prop/int", 10);
        set("armor_prop/dex", 10);
        set("armor_type", "mask");
        set("wear_msg",
HIW"$N戴上$n"HIC"之後散發出"HIY"王者風範"HIR"，四周的空氣變的嚴肅\n"NOR);
        set("unequip_msg", HIC"$N拿下$n"HIC"後，四周的空氣恢復。\n"NOR);
       
setup();
}
int query_autoload() { return 1; }

