#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create() {
        set_name(HIR"�����M"NOR,({"flame blade","blade"}));
        set("long",@LONG
�z��o�X���������b�A�{�{���w�����~���H���ӥͬȡC
LONG
);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",25);
        set("limit_skill",30);
        set("unit", "��");        
        set("value",1000);
        set("volume",4);        
        set("material","bone");       
              }        
        set("weapon_prop/str",1);
        init_blade(55);
        setup();
}    
