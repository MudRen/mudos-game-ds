#include <ansi.h>
#include <weapon.h>
inherit FORK;

void create() {
        set_name("���e",({"fish fork","fork"}));
        set("long",@LONG
�e�ݦy�U�����e�A�O���ҭ̳��w�ϥΪ������u��C
LONG
);
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",16);
        set("unit", "��");        
        set("value",5000);
        set("volume",4);        
        set("material","iron");       
              }        
        set("weapon_prop/str",2);
        init_fork(42);
        setup();
}

