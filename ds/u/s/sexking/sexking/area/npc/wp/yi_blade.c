#include <weapon.h>
inherit BLADE;

void create()
{
set_name("�̶P�Ԫ̤M",({"bear blade","blade"}));
        set_weight(5000);   
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
�o�O�@�⬰�F�[�ֳt�׵��Ԫ̨ϥΦӰ������S�s�M�A��@��Z�h�M���A
���N�i�ܮe���|�_�ӡC
LONG);
                set("unit", "��");
                set("material","blade");
        }
        init_blade(20);
        set("value",3000);
set("limit_dex",15);
setup();
}
