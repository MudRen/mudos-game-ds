#include <weapon.h>
inherit AXE;

void create()
{
set_name("���Y",({"axe"}));
set("long","�o�O�@����Ҭ��ҨϥΪ����Y�C\n");
set_weight(8000);   //�]���q
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",700);
set("volume",3);
set("material","iron");
        }
init_axe(15);
        setup();
}
