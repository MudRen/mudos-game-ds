#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create() {
        set_name("�����",({"flame claw","claw"}));
        set("long",@LONG
�Ϊ�H���Q���s�����Z���A�W�Q�L��C
LONG
);
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",10);
        set("unit", "��");        
        set("value",500);
        set("volume",2);        
        set("material","ivory");       
              }        
        set("weapon_prop/str",1);
        init_fist(40);
        setup();
}    

