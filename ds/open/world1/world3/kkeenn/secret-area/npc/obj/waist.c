#include <armor.h>
inherit WAIST;
void create()
{
        set_name("���c�ֱa", ({ "evil of waist","waist" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@���Q�����I�L���y�a�C\n");
                set("unit", "��");
                set("no_sell",1);
                set("no_sac",1);
                set("value",1150);          
                set("wear_msg", "��$N��$n���W�����@��, �A�n���ݨ�F�a��?!\n");
                set("equip_msg", "$N��$n�Q�a���^���F�C\n");
           }
        set("armor_prop/dodge",3);
        set("armor_prop/armor",1);
        setup();
}

