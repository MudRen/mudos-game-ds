#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
set_name("�P���x�x�A",({"morral's cloth"}) );
set("long","�z�E�E�E�E�E�o�O�P���x���x�A�C�A�ӥB�٬O
���§Q�����I�I�I�I�I\n");
set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "cloth");
set("unit", "��");
                set("value", 10000);
set("armor_prop/armor",9999);
}
setup();
}          
