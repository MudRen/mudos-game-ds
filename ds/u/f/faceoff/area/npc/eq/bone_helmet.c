#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(MAG"鯊骨盔"NOR ,({ "bone helmet","helmet" }) );
        set("long", "這是步六弧用鯊骨所加工而成的骨盔, 看起來能夠提供不錯的防禦力.\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件" );
		set("material", "rubber");
		set("limit_str",12);
                set("armor_prop/armor",  11);
                set("armor_prop/shield", 1);
                set("value", 4000);
        }
        setup();
}
