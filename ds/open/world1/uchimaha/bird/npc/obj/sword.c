#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
set_name( HIC "��"HIR"��"NOR"�C" ,({"moon-sun sword","sword"}));
set("long","�o�O�@��ѿW�u�ѤH�ҥ��y�X�Ӫ��̨γǧ@�C\n");
set_weight(11000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("limit_str",25);
set("limit_dex",20);
set("material","blacksteel");
        }
set("wield_msg","$N�q�I���X�@��$n�A�u��$N���ǳ�¶�ۤ@�ѳ���M�@�Ѷ���C\n");
set("unwield_msg","$N��U�⤤��$n�A�N$n���J�I�᪺�C�T���C\n");
        set("weapon_prop/sou",-1);
        set("weapon_prop/bar",1);
        set("weapon_prop/int",1);
init_sword(55);
setup();
}

