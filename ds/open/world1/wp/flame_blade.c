#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create() {
        set_name(HIR"炎骨刀"NOR,({"flame blade","blade"}));
        set("long",@LONG
透體發出紅光的長刃，閃爍不定的光芒讓人見而生畏。
LONG
);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",25);
        set("limit_skill",30);
        set("unit", "把");        
        set("value",1000);
        set("volume",4);        
        set("material","bone");       
              }        
        set("weapon_prop/str",1);
        init_blade(55);
        setup();
}    
