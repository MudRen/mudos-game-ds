#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create() {
        set_name("���Y���C",({"ghost-head sword","sword"}));
        set("long",@LONG
�C�⪺�����^�ۤ@���޲������Y�A�C���W�{�ۻ����C���A�ݰ_�ӾW�Q
�L��A�ΰ_�ӥi�o�p�ߡC
LONG
);
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");        
        set("value",500);
        set("volume",2);        
        set("material","iron");       
              }        
        set("weapon_prop/str",1);
        init_sword(30);
        setup();
}    
