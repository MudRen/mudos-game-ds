#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create() {
        set_name(WHT"狼牙劍"NOR,({"tooth-wolf sword","sword"}));
        set("long",@LONG
由數百隻野狼的牙齒製成的,晚上還會隱約聽到野狼咆哮的聲音
LONG
);
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_dex",20);
        set("limit_skill",30);
        set("unit", "把");        
        set("value",1000);
        set("volume",4);        
        set("material","steel");       
              }        
        set("weapon_prop/dex",1);
        init_sword(65);
        setup();

}



