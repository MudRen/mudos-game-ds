#include <weapon.h>
#include <ansi.h>

inherit GUN;

void create()
{
set_name(GRN"65k2�B�j"NOR,({"65k2 rifle","65k2","rifle"}) );
set("long","�o�O�x�H�`�Ϊ��B�j,�]�ள�Ӧ׷i��,�i�˶�(reload)20�o�����l�u�C\n");
set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",2000);
                set("rigidity",500);   
                set("material","iron");
                set("limit_level",10);
                
        }

        set("wield_msg","$N�q�I�᮳�X�@��$n,�Φ����j���աC\n");
        set("unwield_msg", "$N�N����۪�$n�I�b�I��C\n");

        set("bullet_type","middle");
        set("max_load",20);
        init_gun(20);   
set("combat_msg", ({    
"$N�ⴤ$w,�κj���r�a���$n���{�l���F�L�h",
"$N��$w���e�ݪ���b��$n�����@��h", 
"$N����$w�j�ީ�$n���Y����,�}�@�����@�n,�t�I������" ,
"$N����$w��$n���}�@��,$n�t�I�����_��",

}) );
setup();
}

