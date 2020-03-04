#include <ansi.h>
#include <armor.h>

inherit PANTS;

void create()
{
        set_name(HIM"彩"HIR"霓"HIY"沙"HIC"龍"NOR, ({ "rainbow salon", "salon" }) );
        set("long", @long
一塊畫有七彩雲霓的布，畫工精緻細膩觸感輕柔滑順，絢麗的外
表下似乎隱藏著一股神祕的力量。

Game Gift of [2005 Summer] By Alickyuen@The.Dream.Of.Seven
long);
        set_weight(15000);
        set("value", 777);
        set("armor_prop", ([
                "bar" : 1,
                "shield" : 10,
                "armor" : 10,
        ]));
        set("armor_type", TYPE_PANTS);
        setup();
}

int query_autoload() { return 1; }

void init()
{
        if( environment(this_object()) == this_player() )
                if( !this_object()->query_light() ) this_object()->start_light(1);
}

