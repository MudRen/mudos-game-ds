#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
set_name( CYN "���Z�C" NOR ,({"god sword","sword"}));
set("long","�o�O�@�⯫�Z���N�x���H�ҨϥΪ����L�Q���C\n");
set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",125000);
set("limit_str",20);
set("limit_dex",15);
        }
set("wield_msg","$N�q�y����X�@��o�X�U�V���~��$n�A�uť��$n�o�X�u������v���n���C\n");
set("unequip_msg","$N��U�⤤��$n,�N$n���J�C�T���C\n");
init_sword(55);
setup();
}
