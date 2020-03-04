#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIY"靈隱劍"NOR, ({ "ling yan sword", "sword" }));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這把劍是疾風門大弟子萬鮮靈的專用佩劍，設計非常特別，容易使用。\n");
                set("value", 10000);
                set("material", "steel");
                set("no_steal", 1);
}
        init_sword(55);
        set("weapon_prop/tec", 1);
        set("weapon_prop/bar", -1); //2003.5.2 by ksj
        set("wield_msg", "$N裝備$n後，突感到技巧上升。\n");
        setup();
}
