#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
set_name( HIY "���a���M" NOR ,({"jue dei blade","blade"}));
set("long","�o�O�@��W�Y��ۨ��]�ϧΪ��]�M�A�x�ۤ@���]��C\n");
set_weight(16800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",10240);
set("limit_str",13);
set("limit_dex",11);
        }
set("wield_msg","$N�q�I���X�@��$n���b�⤤,����$N���زu��A�������۶®�C\n");
set("unequip_msg", "$N��U�⤤��$n, �N$n���J�I��C�T���C\n");

init_blade(32);
set("combat_msg", ({
   "$N�@�ۡu�]���|�g�v�A�C�y�|�I�A���I$n���ܶ��B�e�ݡB��ߡB�j�L�C\n\n",
   "$N�@���u���v�l�l�v�A�Φp���y�A�B�C���w�A��M�q$n���e�_�X�A�u��$n�~�o�Q�ۨ��Z�����i�����C\n\n",
   "$N��M�g�R��W���M�A���O���g�A�@�ۡu�s�]�ûR�v�A�r��$n�A�u��$n�y���K�C�A����ۧڡC\n\n",
}) );
setup();
}
