#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
set_name( HIY "�����F�C" NOR ,({"six-devil sword","sword"}));
set("long","�o�O�@�⩨���ӥN�N�۶Ǫ��@��a�����𪺼C�C\n");
set_weight(11100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",2456);
set("volume",2);
set("limit_str",30);
set("limit_dex",24);
        }
set("wield_msg","$N�q�y�W��X�@��$n���b�⤤,����$N�C�W�����_�A�������ۧ���C\n");
set("unequip_msg", "$N��U�⤤��$n, �N$n���J�I��C�T���C\n");

set("combat_msg", ({
   HIY"$N�@�ۡu���F�ө���v�A�C��@���|�A�٦V$n���y�l�B���١B�p�L�B�j�L�C\n"NOR,
    HIC"$N�@���u����q�|�P�v�A�C��ҽk���M�A�B�C���w�A��M�q$n���e�_�X�F����A�b�V$n
    �h�F�C\n"NOR,
 HIW"$N��M�g�R��W�F�C�A�a�����𪺡A�@��"HIY"�u�g�]�s�ӱ١v�A�r��$n�A�u��$n�y���K�C�A����
�ۧڡC\n"NOR,
}) );
init_sword(66);
setup();
