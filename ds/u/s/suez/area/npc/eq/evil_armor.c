
#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("邪氣戰甲" ,({ "evil armor","armor" }) );
        set("long","一件普通的戰甲，但是沾染了不少邪氣。\n");
         set_weight(12000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "steel");
        set("unit", "件" );
        set("value",3000);
        }
set("armor_prop/armor",20);
set("armor_prop/shield", 2);
        setup();
}