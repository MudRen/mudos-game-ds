#include <weapon.h>
#include <ansi.h>
inherit FIST;

void create() {
        set_name( "�C�Ϥ�" ,({"qing-yang claw","claw"}));
        set("long",@LONG
�o�O�@�Ӥ����Z���A�W�Y�観�D�б`�������~�ЫC�ϡC�C�Ϥ�������X���H���Z���C
LONG
);
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_str",10);
                set("unit", "��");        
                set("value",5500);
                set("volume",2);        
                set("material","ivory");       
        }        
        set("weapon_prop/int", 1);
        init_fist(50);
        setup();
}    

