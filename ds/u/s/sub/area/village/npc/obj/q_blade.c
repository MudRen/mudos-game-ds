#include <weapon.h>
inherit BLADE;
void create()
{
set_name("�q�ۤ��ΤM",({"mineral blade","mineral","blade"}));
set("long",@LONG
�o�O�@��ΨӤ����q�۪��M�A�۷��W�Q�C�ΨӤ��}���q���a����O��靈�l�C
LONG);
set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",1000);
set("volume",2);
set("limit_str",20);
set("limit_int",20);
        }
init_blade(40);
setup();
}
