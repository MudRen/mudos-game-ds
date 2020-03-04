#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
        set_name(HIW"鳳翔銀靴"HIR"(S)"NOR, ({ "phoenix boots","boots" }) );
        set("long",@LONG
一雙銀白的靴子，靴子上各有一隻栩栩如生的鳳凰雕刻其上，在靴子
兩旁伸展出一雙羽翼，行走時令人有如同飛翔的感覺。
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(2000);
                set("material", "steel");
                set("unit", "副");
                set("value",3000);
                set("volume",2);
        }
                set("armor_prop/armor", 15);
        setup();
}

int query_autoload() { return 1; }
