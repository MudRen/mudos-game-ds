#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
        set_name(HIB"�]��"NOR, ({ "devil ring","ring" }) );
        set_weight(999);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@�u�L�Ī��]��...");
                set("unit", "�u");
                set("value",1000);
        }
//        set("armor_prop/shield", 3); ->�令bar 1,-alick, �garea���y
        set("armor_prop/bar", 8);
        setup();
}
int query_autoload() { return 1; }

