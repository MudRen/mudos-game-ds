#include <armor.h>
inherit SURCOAT;
void create()
{
        set_name("����@��", ({ "green sea surcoat","surcoat" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@���æ������v�������ԪӡC\n");
                set("unit", "��");
                set("no_sell",1);
                set("no_sac",1);
                set("value",1050);          
                set("wear_msg", "$N�w�w����$n�a�W�h,���G�ܳ��w�������O\n");
                set("unequip_msg", "$N�H��N$n�汼�C\n");
           }
        set("armor_prop/dodge",2);
        set("armor_prop/armor",4);
        setup();
}

