#include <weapon.h>
inherit BLADE;

void create()
{
set_name("��M",({"blade"}));
set("long","�o�O�@��Z�̱`�Ϊ���M�C\n");
set_weight(5000);   //�]���q
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",300);    //�]����
set("material","iron");
init_blade(25);
        }
}
