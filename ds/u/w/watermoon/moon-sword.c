#include <ansi.h>

#include <weapon.h>

inherit SWORD;

void create()

{

set_name( CYN "����C" NOR ,({"Moon sword","sword"}));

set("long","�o�O�@������N���v�����o�����L�Q���C\n");

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

set("wield_msg","$N�������B�Q�� �����k�����Ź� �s�C�H���a�Q�� �g�M�@�R���^�� $n\n");

set("unequip_msg","$N��U�⤤��$n,�N$n���J�C�T���C\n");

        set("weapon_prop/hit",10);

        set("weapon_prop/dex",20);

        set("weapon_prop/str",20);

init_sword(300);

setup();

();

}

