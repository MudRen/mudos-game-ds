#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("布衣" ,({ "cloth" }) );
        set("long","這是一件普通的布衣。\n");
        set_weight(800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "cloth");
        set("unit", "件" );
        set("value",150);
        }
          set("armor_prop/armor",1);
        setup();
}
