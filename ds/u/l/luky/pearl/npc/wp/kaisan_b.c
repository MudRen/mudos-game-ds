#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
set_name("[1;30m�}�s�M[0m",({"kaisan blade","blade"}));
set_weight(16600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("long","�o�O�@����Y���K�s�¦���M,���o�ؤM���H�q�`���O����n�H.\n");
set("value",2390);
set("blade",41);
set("material","iron");
        }
set("wield_msg","$N�q�@�����Ȥ���X�@��W�Q��$n\n");
set("unequip_msg", "$N��U�⤤��$n, �γ��ȥ]�n���ð_�ӡC\n");
init_blade(665);
setup();
}
