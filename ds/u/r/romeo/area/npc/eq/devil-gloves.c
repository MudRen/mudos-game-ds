#include <armor.h>
#include <ansi.h>
inherit GLOVES;

void create()
{
        set_name(HIB "�]�P��ŮM" NOR,({ "devil-gloves","gloves" }) );
        set("long",
"�o�O�@�����D�ιϮת���M�A�������^���p�ۡA�ݰ_�ӫܦW�Q��C\n"
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
        set("armor_prop/str", 2);
        }
        setup();
}
