#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
        set_name(HIM"�R"NOR"��"MAG"��",({"ba-chi cloak","cloak"}) );
        set("long",@LONG
�ѤU���i�h�o�����㤧�@
LONG
);
        set_weight(999);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",13);
                set("unit", "��");
                set("value",1500);
                set("volume", 2);
                set("material", "silver");
        }
        set("armor_prop/armor",20);
        set("armor_prop/con",4);
setup();
}
