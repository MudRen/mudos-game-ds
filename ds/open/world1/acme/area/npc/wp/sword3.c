#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
set_name( HIB "�Ԥѯ��C" NOR ,({"zhan tian sword","sword"}));
set("long","�o�O�@��W�Y��ۤӶ����˪��_�C�A�ݰ_�Ӧ��G�����O���z�C\n");
set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",2000)
;
set("volume",2);
}
set("limit_str",12);
set("limit_dex",14);
set("wield_msg","$N�q�I���X�@��$n���b�⤤,����$n���~�|�g�A�۷�벴�C\n");
set("unequip_msg", "$N��U�⤤��$n, �N$n���J�I��C�T���C\n");
set("combat_msg", ({
   "$N�@�ۡu���ѷ��a�v�A�C�۷�����F�A\n  �W��$n�����A�U��$n�G�Ѥ���"  ,
   "$N���}�@�ޡA�����D�_�A�ѤW���ĦӤU�A\n  �@�ۡu���s���@�v�A��$n���Y�����h",
   "$N�C������A���N���w�A���a$N�q$n�I��«�X�A\n  �@���u�F�@��Y�v�A��$n��h",
}) );
init_sword(35);
setup();
}
