#include <armor.h>
#include <ansi.h>

inherit CLOTH;
void create()
{
set_name(WHT"紫金袈裟"NOR, ({ "bonze cloth" ,"cloth" }));
set_weight(3000);
if (clonep())
set_default_object(__FILE__);
else {
set("long" , "這是一件僧侶所穿的束腰，上面繡著些梵文。\n"NOR);
set("material", "silk");
set("unit", "件");
set("limit_str",5);
set("limit_level",15);
set("wear_msg", "只見$N雙手一抖，便把一件隱隱透著紫色光彩的袈裟披在身上。\n" NOR);
        }
        set("armor_prop/armor", 6);
        set("armor_prop/shield", 18);
        set("armor_prop/bar", -1);
        set("armor_prop/str", 1);
        set("armor_prop/int", 1);
        setup();
}
