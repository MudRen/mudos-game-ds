#include <weapon.h>
inherit BLADE;

void create()
{
set_name("�����M",({"wolf tooth blade","blade"}));
        set_weight(250);   
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
�@��D�`���q����M�A�p�Ĥl�ܷR���C
LONG);
                set("unit", "��");
                set("material","blade");
        }
   init_blade(1,TWO_HANDED);
set("value",10);
setup();
}
