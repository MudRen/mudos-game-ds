#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
set_name( YEL "�p���C" NOR ,({"light sword","sword"}));
set("long","�o�O�@��ѤѦ�̩Ҩرa���C.\n");
set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",100000);
set("limit_str",5);
set("limit_dex",6);
        }
set("wield_msg","$N���ⴤ��$n�C�`�����A�u�ݨ�$n�o�X�F��H���{��\n");
set("unequip_msg", "$N���W����,$n���{���N���������F. \n");

init_sword(999);
set("combat_msg", ({
   "$N�ⴤ$w,���W�����u�Τߥh�Pı$n���s�b,��$n�d�F�@�M. \n",
}) );
setup();
}
