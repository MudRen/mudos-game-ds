#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create() {
        set_name(HIR"�����"NOR,({"phoenix claw","claw"}));
        set("long",@LONG
�@���������O���⪺���,�ݰ_�ӥi�H���ѫܦn�������O.
LONG
);
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",50);
        set("limit_level",30);
        set("unit", "��");        
        set("value",7000);
        set("volume",3);        
        set("material","steel");       
        set("wield_msg","$N�˳Ƥ@��$n"+NOR", "HIC"���M�g���j�@, ����ɰ��C\n" NOR);
        }
                
        set("weapon_prop/bar",1);
        set("weapon_prop/str",2);
        init_fist(60);
        setup();
}    

