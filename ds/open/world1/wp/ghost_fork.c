#include <ansi.h>
#include <weapon.h>
inherit FORK;

void create() {
        set_name("���e",({"ghost fork","fork"}));
        set("long",@LONG
�z��q�ª��K�e�A�O���t�̳��w�ϥΪ��Z���C
LONG
);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",10);
        set("unit", "��");        
        set("value",200);
        set("volume",4);        
        set("material","iron");       
              }        
        set("weapon_prop/str",1);
        init_fork(40);
        setup();
}    

