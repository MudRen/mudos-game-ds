#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name( WHT"��"HIW"��"NOR"�G��T", ({ "Twin-kee robe","robe" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "�D�a���K�T�A�W�Y¸�F�����G�𪺮�ιϮסC");
        set("unit", "��");
        set("value",1);
        set("material", "silk");  
         }
        set("armor_prop/armor", 10 );
        set("armor_prop/show_damage",1);
        setup();
}
int query_autoload() { return 1; }
