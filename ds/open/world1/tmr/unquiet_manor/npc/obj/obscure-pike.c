#include <weapon.h>
inherit FORK;

void create()
{
  set_name("�L����j",({"obscure pike","pike"}) );
  set("long",
"�@��ºҦ⪺���j�A�j�Y�ٯd�ۥ��������B�H�׸H�����C"
);
        set_weight(20000);
        if (clonep() )
             set_default_object(__FILE__);      
        else {
                set("material","iron");
                set("unit","��");
				set("volume",6);
                set("value", 1500);
        }
        set("weapon_prop/str", 1);
        set("weapon_prop/int", 1);
		init_fork(50);
        setup();
}
