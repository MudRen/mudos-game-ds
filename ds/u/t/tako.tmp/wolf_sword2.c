#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create() {
        set_name(WHT"�T���C"NOR,({"tooth-wolf sword","sword"}));
        set("long",@LONG
�ѼƦʰ����T�������s����,�ߤW�ٷ|����ť�쳥�T�H�����n��
LONG
);
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_dex",20);
        set("limit_skill",30);
        set("unit", "��");        
        set("value",1000);
        set("volume",4);        
        set("material","steel");       
              }        
        set("weapon_prop/dex",1);
        init_sword(65);
        setup();

}



