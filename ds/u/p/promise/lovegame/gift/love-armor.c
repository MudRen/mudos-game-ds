//2003年10.10國慶日寫的七夕情人節禮物
//by Promise@DS

#include <armor.h>
#include <ansi.h>
inherit ARMOR; 
void create()
{
        set_name(HIM"七夕 "HIC"鎧"NOR,({ "love armor","armor" }) );
        set("long",HIC"\n\t西元2003年七夕情人節禮物。\n"NOR);
        set_weight(16000);
        if ( clonep() )
                set_default_object(__FILE__);
         else {
         set("volume",5);
         set("material","golden");
         set("unit", "件" );
         set("no_sell",1);
         }
        set("armor_prop/armor", 20);
        setup();
}

int query_autoload() { return 1; }

