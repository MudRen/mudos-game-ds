#include <weapon.h>
inherit DAGGER;
void create()
{
set_name("�P��",({"dagger"}) );
set_weight(14000);
     if( clonep() )
               set_default_object(__FILE__);
     else {
        set("long","\n
�o��P���۷����M�C\n");
        set("unit", "��");
set("value",1060);
	set("wield_msg","$N�q�y�a���X$n�C\n");
	set("unwield_msg","$N��$n��i�y�U�C\n");
set("dagger",106);
           }
        setup();
}
