#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIB "�]�P�ݭ���" NOR,({ "devil-ring","ring" }) );
        set("long",
"�o�O�@���|�o�����]���١A�Q�����n�ݡC\n"
);
        set_weight(900);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "��" );
        set("limit_con",25);
        set("limit_level",20);
        set("value",100);
        set("armor_prop/armor",1);
        set("armor_prop/dex", -1);
        set("armor_prop/int", -1);
        }
        set_temp("has_light",1);        //�o��.
        setup();
}
