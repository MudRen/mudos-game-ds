#include <ansi2.h>
#include <armor.h>
inherit LEGGING;
void create()
{
        set_name(HIC"�{"HIY"��"HIW"�H��"NOR ,({ "Dreamcast leggings","leggings" }) );
        set("long","�۶ǳo�O�A�{�F���������_���A��W�[���ʳt�סE\n");
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("material", "leather");
        set("volume",5);
        set("unit", "��");
        set("value",1500);
        }
        set("armor_prop/armor",3);
        set("armor_prop/dex",3);
        set("armor_prop/dodge",10);
        setup();
}

