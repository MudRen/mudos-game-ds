#include <weapon.h>
inherit WHIP;
void create()
{
    set_name("����",({"fishing rod","rod"}));
    set("long","�o�O�@�䳨���Ϊ�����C\n");
    set_weight(2100);
    if( clonep() )
       set_default_object(__FILE__);
    else {
       set("unit", "��");
   set("material", "wood");
		set("value",300);
    }
init_whip(15);
    setup();
}

