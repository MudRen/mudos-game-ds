#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
        set_name(HIW"冰絲"HIC"纏龍褲"HIR"(S)"NOR ,({ "ice-dragon pants","pants" }) );
        set("long",@LONG
以極地冰蛛的絲織成的長褲，褲子上織有十二條各種型態的龍，飛舞
交纏其上。
LONG
);
        set_weight(1300);
        if ( clonep() )
        set_default_object(__FILE__);
        else
        {
         set("material", "leather");
         set("volume",2);
         set("unit", "條");
         set("value",10000);
        }
        set("armor_prop/armor",10);
        setup();
}

int query_autoload() { return 1; }
