#include <ansi.h>
#include <armor.h>
inherit BOOTS;
void create()
{
        set_name(HIR"天使長靴"NOR, ({ "Angel boots","boots" }) );
set("long",
"這是"HIR"天使"NOR"的長靴。\n"
);
set_weight(2000);
if(clonep() )
set_default_object(__FILE__);
else
{
 set("unit", "雙");
set("armor_prop/armor", 30);
        }
}
