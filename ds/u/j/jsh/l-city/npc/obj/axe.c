#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
set_name("�}ù����" NOR ,({"kailo-long axe","axe"}));
set("long","�}ù�h�L�ҥΪ�����A���ˤO���j�A�����@�w�������{�סC\n");
set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",1000);
set("limit_str",20);
set("limit_dex",10);
set("material","wooden");
        }
init_axe(35);
setup();
}

