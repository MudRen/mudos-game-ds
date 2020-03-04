#include <ansi2.h>
#include <armor.h>
inherit SHIELD;

void create()
{
        set_name(CYN"蟲甲盾"NOR,({"iron-beetle shield","shield"}));
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
        set("unit", "面");
        set("volume",3);
        set("long", @LONG
    甲蟲殼製成的一面盾牌，相當輕巧而堅固，光滑的表面更有助於
卸開擋住敵人的攻擊。。
LONG
        );
        set("value",2000);
        set("material","fur");
        }
        set("armor_prop/armor",15);
        set("armor_prop/block",10);
        set("armor_prop/dex",2);
        setup();
}
