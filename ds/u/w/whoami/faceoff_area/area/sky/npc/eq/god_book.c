#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create() {
        set_name(HIR"炎道要術"NOR,({"fire book","book"}));
        set("long",@LONG
一本散發出陣陣靈氣的異書....
LONG
);
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_int",50);
        set("limit_level",26);
        set("unit", "本");        
        set("value",2000);
        set("volume",2);        
        set("material","steel");       
              }        
        set("weapon_prop/str",1);
      set("armor_prop/dodge",15);
        init_fist(1);
        setup();
}    

