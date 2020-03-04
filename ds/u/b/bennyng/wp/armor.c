#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("死神裝甲", ({ "DeadGod","armor" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","這件裝甲隱隱透出黑氣,令你產生恐佈的幻覺....\n");
                set("unit", "件");
                set("material", "steel");
                set("no_drop",1);
                set("no_sac",1);
                set("value",56000);
                set("armor_prop/con",2);
                set("armor_prop/dex",1);
                set("armor_prop/dodge",5);
                set("armor_prop/shield",10);
                set("armor_prop/armor", 10);
        }
        setup();
}
int query_autoload() { return 1; }
