#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
set_name("�}ù���M" NOR ,({"kailo-long blade","blade"}));
set("long","�}ù�h�L�ҥΪ����M�A���ˤO���j�A�����@�w�������{�סC\n");
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
init_blade(35);
setup();
}

