#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create() {
        set_name(CYN"�R�V"NOR,({"ghost staff","staff"}));
        set("long",@LONG
�H�R�����V���@��������.
LONG
);
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",25);
        set("unit", "��");        
        set("value",800);
        set("volume",2);        
        set("material","blacksteel");       
              }        
        init_staff(36);
        setup();
}    

