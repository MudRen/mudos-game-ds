#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
set_name( HIC "�H�H�C" NOR ,({"cici sword","sword"}));
set("long","�o�O�@��C�C\n");
set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("unit", "��");
              set("material","blacksteel");
             }
        set("wield_msg","$N�q�I���X�@��$n�A�u��$N�H�H�H�����F�_�ӡC\n");
        set("unwield_msg","$N��U�⤤��$n�A�N$n�p�ߪ��Υ��]�_�A��b�I��C\n");
        set("weapon_prop/sou",2);
        set("weapon_prop/bar",2);
        set("weapon_prop/int",2);
init_sword(100);
setup();
}

