#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
        set_name(HIB"魔戒"NOR, ({ "devil ring","ring" }) );
        set_weight(999);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一只無敵的魔戒...");
                set("unit", "只");
                set("value",1000);
        }
//        set("armor_prop/shield", 3); ->改成bar 1,-alick, 寫area獎勵
        set("armor_prop/bar", 8);
        setup();
}
int query_autoload() { return 1; }

