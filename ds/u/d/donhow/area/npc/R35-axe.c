#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
set_name( RED "R-35" NOR,({"R-35 axe","axe"}));
set("long","�@���Hans�X�����u��,���e�O���Ӷ}�q�ҥ�,��ӳQ���Ψ�Գ��W
            �ѩ�Hans�[�J�F�t�@�ش���,�񤧫e��R-35�٧�r�F��\n");
set_weight(2000);   //�]���q
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",30000);    //�]����
set("material","iron");
init_axe(999);
        }
}
