#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("�q�l�����",({"electric cloth","cloth"}) );
        set("long","�o�O�@�󰪬�ު���A�A�|�۰ʽո`�ϥΪ̪���šC\n");
        set_weight(1000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
set("value",1000);
set("material","cloth");
set("armor_prop/armor", 5);
        }
        setup();
}
