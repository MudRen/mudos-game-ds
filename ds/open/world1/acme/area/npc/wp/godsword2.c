#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
set_name( YEL "���Z�C" NOR ,({"god sword","sword"}));
set("long","�o�O�@�⯫�Z���N�x���H�ҨϥΪ����L�Q���C\n");
set_weight(11000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",5000);
set("limit_str",20);
set("limit_dex",15);
set("material","blacksteel");
        }
set("wield_msg","$N�q�y����X�@��o�X�U�V���~��$n�A�uť��$n�o�X�u������v���n���C\n");
set("unequip_msg","$N��U�⤤��$n,�N$n���J�C�T���C\n");
        set("weapon_prop/hit",8);
        set("weapon_prop/int",1);
        set("weapon_prop/str",1);
init_sword(55);
setup();
}