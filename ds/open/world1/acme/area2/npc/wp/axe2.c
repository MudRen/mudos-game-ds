#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
   set_name(HIR "���I��" NOR ,({"ghost fire axe","axe"}));
   set("long","�o�O�@��������j��A�ݨӨä����C\n");
   set_weight(10000);   //�]���q
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",2500);
		set("volume",4);
                set("material","iron");
        }
                init_axe(35);
        setup();
}
