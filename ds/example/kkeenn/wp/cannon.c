#include <ansi.h>; 
#include <weapon.h>
inherit GUN;
void create()
{
set_name(HIR"���l���[�A��"NOR,({"firestorm cannon","cannon"}));
set("long","���Z���i�H�b�Ƭ��H�j�j�����O�����ĤH�C
[�̦h����90�o�����l�l�u]\n");
 set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
             set("limit_str",15);
                set("value",5000);
                set("rigidity",600);   
                set("material","iron");
        }

        set("wield_msg","$N��$n���O�I��Ѷ}�C\n");
        set("unwield_msg", "$N��$n�O�I�������C\n");
        set("bullet_type","firestorm");     
        set("max_load",90);           
        init_gun(30);   
        setup();
}

