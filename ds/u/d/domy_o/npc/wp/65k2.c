#include <weapon.h>
#include <ansi.h>

inherit GUN;

void create()
{
set_name(GRN"65k2�B�j"NOR,({"65k2 rifle","rifle"}) );
set("long","�o�O�x�H�`�Ϊ��B�j,�]�ள�Ӧ׷i��,�i�˶�(reload)10�o5.56�����l�u�C\n");
set_weight(4600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",380);
                set("rigidity",500);   
                set("material","iron");
                set("limit_level",10);
                
        }

        set("wield_msg","$N�q�I�᮳�X�@��$n,�Φ����j���աC\n");
        set("unwield_msg", "$N�N����۪�$n�I�b�I��C\n");


        set("bullet_type","middle");
        set("max_load",10);
        init_gun(10);   
        setup();
}
