#include <weapon.h>
inherit DAGGER;
void create()
{
set_name("匕首",({"dagger"}) );
set_weight(14000);
     if( clonep() )
               set_default_object(__FILE__);
     else {
        set("long","\n
這把匕首相當的普遍。\n");
        set("unit", "把");
set("value",1060);
	set("wield_msg","$N從腰帶取出$n。\n");
	set("unwield_msg","$N把$n放進腰袋。\n");
set("dagger",106);
           }
        setup();
}
