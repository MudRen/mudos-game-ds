#include <weapon.h>
#include <ansi.h>
inherit FIST;

void create() {
        set_name( "�Ϩ���" ,({"bariour-horn claw","claw"}));
        set("long",@LONG
�o�O�@�ӨϥΦϨ������������Z���A��a�D�`�_�S�C
LONG
);
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");        
                set("value",1000);
                set("volume",2);        
                set("material","ivory");       
        }        
        set("weapon_prop/int", 1);
        init_fist(30);
        setup();
}    

