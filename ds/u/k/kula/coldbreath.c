#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name( HIW "�H��" NOR ,({ "cold breath","breath" }) );
        set("long","�o�O�@�ѧC�Ū��H��C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(800);
        set("material", "skin");
        set("unit", "��" );
        set("value",1);
        set("volume",4);
             }
        set("armor_prop/shield", 15);
        set("armor_prop/int",2);
        
        setup();
}

void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}

int query_autoload() { return 1; }

