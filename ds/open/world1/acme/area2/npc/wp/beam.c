#include <weapon.h>
inherit WHIP;
void create()
{
set_name("����",({"beam"}));
set("long","�o�O�@��Ψӯ��q�F�誺����C\n");
set_weight(2000);   //�]���q
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("limit_int",10);
set("unit", "��");
set("value",1500);
set("material","iron");
        }
init_whip(30);
        setup();
}
