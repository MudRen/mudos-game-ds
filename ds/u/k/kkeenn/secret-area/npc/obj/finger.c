#include <armor.h>
inherit FINGER;
void create()
{
        set_name("�����٫�", ({ "god of finger","finger" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@�u�����M�Ϊ��٫�, �������󸨤J�H�����C\n");
                set("unit", "�u");
                set("no_sell",1);
                set("no_sac",1);
                set("value",950);          
                set("wear_msg", "��$N��$n���W�����@��, �|�P�ǥX�ѨϪ�����!\n");
                set("unequip_msg", "$N�����ֳQ�W�a���^�h�F�C\n");
           }
        set("armor_prop/dodge",1);
        set("armor_prop/armor",2);
        setup();
}

