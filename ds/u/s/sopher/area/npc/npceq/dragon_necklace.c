#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(HIW"�s������"NOR,({ "necklace" }) );
        set("long","�@�����s���ꦨ������C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
         set_weight(50);
        set("material", "neck");
        set("unit", "��" );
        set("value",30);
 set("armor_prop/armor",3);
set("armor_prop/dex",1);
        }
        setup();
}
