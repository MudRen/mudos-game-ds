#include <ansi.h>
#include <weapon.h>
#include <ansi.h>
inherit FIST;

void create() {
        set_name(HIW"�Ѷ�a���"NOR,({"taoism claw","claw"}));
        set("long",@LONG
�o�O�@�ӶH�x�Ѷ�a�誺�Z���A���H�����[�D���빩���H���Z���C
LONG
);
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_str",10);
                set("unit", "��");        
                set("value",8500);
                set("volume",2);        
                set("material","ivory");       
        }        
        set("weapon_prop/int", 2);
        set("weapon_prop/con", -1);
        set("weapon_prop/hit",10);
        set("beast_weapon_prop/damage",30);
        init_fist(60);
        setup();
}    


