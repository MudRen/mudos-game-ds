#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
void create()
{
        set_name(HIR"泣心"NOR, ({ "dragon dagger","dagger" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "傳說中這是絕命雙煞的成名武器之一, 據說此匕
原為一位女俠所有, 而且似乎和天梟有一段難解的緣份, 這把匕首到了每月二十二
日夜晚都會發出哭泣之聲, 且從匕鞘發出安慰之聲撫慰, 不過傳說歸傳說, 這一把
匕首刀身微泛暗紅, 似乎有一股血光之氣附在其上.");
                set("value", 600);
                set("material", "steel");
        }
        init_dagger(45);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", "$N單手握住$n, 霎時一陣熱氣直衝百里穴! 。\n");
        set("unwield_msg", "$N將手中的$n藏入懷中。\n");

// The setup() is required.

        setup();
}
