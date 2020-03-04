#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
        set_name(HIW"迴光"HIG"遁甲戒"HIR"(S)"NOR,({"refractile ring","ring"}) );
        set("long",@LONG
鑲嵌三色水晶的銀戒，能折射光線讓敵人的攻擊產生誤差。
LONG
);
        set_weight(300); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",30);
                set("unit", "只");       
                set("value",30000);          
                set("volume", 2);                       
                set("material", "stone");   
        }
        set("armor_prop/armor",5);       
        setup();
}

int query_autoload() { return 1; }
