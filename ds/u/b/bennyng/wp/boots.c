#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("死神運動鞋", ({ "DeadGod","boots" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","這雙運動鞋很輕,好像沒穿一樣。\n");
                set("unit", "雙");
                set("material", "cloth");
//              set("no_drop",1);
                set("no_sac",1);
                set("value",25000);
                set("armor_prop/dex",5);
                set("armor_prop/dodge",5);
                set("armor_prop/armor", 2);
        }
        setup();
}
int query_autoload() { return 1; }
