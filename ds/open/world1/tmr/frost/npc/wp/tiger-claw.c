#include <ansi.h>
#include <weapon.h>


inherit FIST;

void create() {
        set_name( "��Τ�" ,({"tiger claw","claw"}));
        set("long",@LONG
�o�O�@��������Ϊ������Z���A�W�����ӧQ���A�ݰ_�ӵL��W�U�C
LONG
);
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");        
                set("value",5500);
                set("volume",2);        
                set("material","iron");       
        }        
        init_fist(35);
        setup();
}    

