#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create() {
        set_name("���`�۩�",({"stone axe","axe"}));
        set("long",@LONG
���Y�i��������A�����W�Q�A���O�]���H���A�¤O�]���e�p��C
LONG
);
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");        
        set("value",200);
        set("volume",5);        
        set("material","stone");       
              }        
        init_axe(30);
        setup();
}    

