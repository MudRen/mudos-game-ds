#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
set_name("�}ù���C" NOR ,({"kailo-long sword","sword"}));
set("long","�}ù�h�L�ҥΪ����C�A���ˤO���j�A�����@�w�������{�סC\n");
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
init_sword(35);
setup();
}

