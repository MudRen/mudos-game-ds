#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
set_name(HIC"��"HIR"��"NOR"�C",({"negative positive sword","sword"}));
set("long","�o�O�@��ѿW�u�ѤH�ҥ��y�X�Ӫ��̨γǧ@�A�C�b���a�観�۵������N��A
�N�𪺥~��o�S�]��F�@�h�x��A�J�⤧��A�O�H�����@�_�C\n");
set_weight(11000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("limit_str",25);
set("limit_dex",20);
set("value",15000);
set("material","blacksteel");
        }
set("wield_msg","$N�q�I���X�@��$n�A�u��$N���ǳ�¶�ۤ@�ѳ����թM����C\n");
set("unwield_msg","$N��U�⤤��$n�A�N$n���J�I�᪺�C�T���C\n");
        set("weapon_prop/sou",-2);
        set("weapon_prop/bar",1);
        set("weapon_prop/wit",1);
        set("weapon_prop/int",2);
init_sword(55);
setup();
}

