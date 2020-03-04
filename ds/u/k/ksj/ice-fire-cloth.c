#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIC"觀宇"HIR"雙極袍"HIR"(S)"NOR ,({ "ice-fire cloth","cloth" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
 set("long",@LONG
以冰蠶絲及火蠶絲交織而成的衣服，衣服上繡有各地的山水風景，不
僅防護力超群，整件衣服更是難得一見的藝術品。
LONG
     );
        set("unit", "件");
        set("value",20000);
        set("material", "fur");
        set("armor_prop/armor", 26);
        }
        setup();
}

int query_autoload() { return 1; }
