#include <weapon.h>
inherit STAFF;

void create()
{
set_name("����",({"long stick","stick"}));
set("long","�o�O�@�K�������Ҥl�C\n");
set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "�K");
set("value",300);
set("material","wood");
        }
init_staff(12);
        setup();
}

