#include <weapon.h>

inherit DAGGER;
void create()
{
set_name("�񴹤P��",({"green dagger","dagger"}));
set_weight(7500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
set("long","�o�O�@�⾥��⪺�P���M���b��W�Pı�Q�������C\n");
//set("limit_sk",12);
set("dagger",30);
set("value",3500);
set("material","gem");
init_dagger(240);
}
setup();
}
