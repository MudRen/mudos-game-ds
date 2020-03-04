#include <armor.h>
#include <ansi2.h>

inherit CLOTH;

void create()
{
        set_name(HIR"鳳凰羽衣"NOR, ({ "phoenix leather", "leather" }));
        set_weight(200);
        set("long", @long
這一件是由鳳凰身上的羽毛所製成的衣服，由寶藏家製成，
具有不知名的功效。
long);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 5000);
                set("material", "leather");
                set("armor_prop/armor", -100 );
                set("armor_prop/shield", -100 );
                set("armor_prop/damage", -100 );
        }
        setup();
}

