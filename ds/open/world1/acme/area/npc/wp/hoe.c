#include <weapon.h>
inherit HAMMER;

void create()
{
set_name("�S�Y",({"hoe"}));
set("long","�o�O�A�ҥΨӺإЪ��S�Y�C\n");
set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",300);
set("volume",2);
set("material","iron");
        }
init_hammer(15);
        setup();
}

