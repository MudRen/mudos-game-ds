#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name(HIB"�K���W��"NOR,({"eight-mirror","eight","mirror"}) );
        set("long","���m�O��������l�C\n");
        set_weight(1000);
        set("unit","��");
        if (clonep() )
                set_default_object(__FILE__);
        else {                
                set("value",6000);
                set("material","silver");
                set("armor_prop/armor", 15);
                set("armor_prop/int", 1);
                set("armor_prop/dex", 1);
                set("armor_prop/con", 1);
                set("armor_prop/str", 1);
                }
        setup();
}
void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}

