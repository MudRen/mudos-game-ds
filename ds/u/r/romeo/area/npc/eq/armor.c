#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
        set_name(HIB "萬骨將軍鎧" NOR,({ "general-armor","armor" }) );
        set("long",
"所謂一將功成萬骨枯！這件破舊的鎧甲亦是如此，不知有
多少將領穿過他在戰場殺敵，不知有多少人命在他面前一一殞落。
在怨恨，悲哀，生不知死的戰場上穿梭數百年的鎧甲，把將死之人
最後的意願聚集起來。痛苦，絕望，死去的人以他們的意志將這件
鎧甲鍛造成一件具有靈性的鎧甲！為了生存而存在的鎧甲！。\n"
);
        set_weight(5000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "件" );
        set("limit_con",20);
        set("limit_level",15);
        set("value",100);
        set("armor_prop/armor",5);
        set("armor_prop/dex", -2);
        }
        setup();
}

