#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("羽翼藍衫" ,({ "plume cloth","cloth" }) );
        set("long","這是一件輕柔的衣服，在左胸有個羽毛裝飾，但防禦力差。\n");
        set_weight(900);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "cloth");
        set("unit", "件" );
          set("value",600);
        }
          set("armor_prop/armor", 5);
        setup();
}
