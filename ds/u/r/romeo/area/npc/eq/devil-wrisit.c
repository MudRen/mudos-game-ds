#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
        set_name(HIB "�]�P�@��" NOR,({ "devil-wrisit","wrisit" }) );
        set("long",
"�o�O�@�Ӧn�Ϊ��@�áA�O�����@�ɪ��n�˳ơC\n"
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
        set("armor_prop/int", -3);
        set("armor_prop/con", 1);
        }
        setup();
}

