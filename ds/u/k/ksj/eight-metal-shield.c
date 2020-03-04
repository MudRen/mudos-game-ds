#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
        set_name(MAG"八卦"HIM"合金盾"HIR"(S)"NOR,({"huge-turtle shield","shield"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
        set("unit", "面");
        set("volume",3);
        set("long", @LONG
一面八卦形狀的盾牌，八個卦象分別以不同的金屬融合成一面合金盾
，利用各種金屬互相之間的特性，能將承受的攻擊化為無形。
LONG
        );
        set("value",8000);
        set("material","steel");
        }
        set("armor_prop/armor",28);
        setup();
}

int query_autoload() { return 1; }
