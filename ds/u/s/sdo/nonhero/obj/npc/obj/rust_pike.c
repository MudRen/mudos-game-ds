#include <weapon.h>
inherit FORK;
void create()
{
        set_name("���ê����j",({"rusty pike","pike"}) );
        set("long",@LONG
�o�u�O�@����ê����j�C
LONG
	);
        set_weight(25000);
        if (clonep() )
        	set_default_object(__FILE__);
        else 
	{
        set("unit","��");
        set("value",100);
        set("volume",5);
        set("material","steel");
        init_fork(1);
   	}
        setup();
}