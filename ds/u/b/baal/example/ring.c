#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name("昊戠戒指" ,({ "hao chi ring","ring" }) );
        set("long","這是一只刻著火焰標誌的戒指。\n");
        set_weight(300);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "jade");
        set("unit","只");
       set("value",200);
        }
         set("armor_prop/armor", 2);
        setup();
}
