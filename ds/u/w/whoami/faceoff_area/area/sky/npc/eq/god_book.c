#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create() {
        set_name(HIR"���D�n�N"NOR,({"fire book","book"}));
        set("long",@LONG
�@�����o�X�}�}�F�𪺲���....
LONG
);
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_int",50);
        set("limit_level",26);
        set("unit", "��");        
        set("value",2000);
        set("volume",2);        
        set("material","steel");       
              }        
        set("weapon_prop/str",1);
      set("armor_prop/dodge",15);
        init_fist(1);
        setup();
}    

