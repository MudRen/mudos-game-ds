#include <weapon.h>
inherit BLADE;

void create()
{
set_name("�饻�Z�h�M",({"japen blade","blade"}));
        set_weight(10000);   
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
�o�O�@��饻�X�����Z�h�M�A�q�`���O���H�C�ȺD�Ϊ��L���A
�Q���U�Q�A���ܭ��C
LONG);
                set("unit", "��");
                set("material","blade");
        }
        init_blade(35,TWO_HANDED);
        set("value",3500);
set("limit_str",15);
set("limit_dex",20);
set("armor_prop/dex",-2);
set("wield_msg","$N�q�y���ޥX�@��$n�A�Pı�Q���I���A�C\n");
set("unequip_msg", "$N�N$n�u�|�v���@�n���J�M�T�����A�C\n");
setup();
}

