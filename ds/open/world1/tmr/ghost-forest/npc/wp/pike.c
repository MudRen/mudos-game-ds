#include <weapon.h>
inherit FORK;

void create()
{
  set_name("���c�j",({"ghost woo pike","pike"}) );
  set("long",
"�@��۷�����j�A�j���e���A�ݨӥO�H�ߥͮ��ߡA�b�j�Y�ٯd��\n"
"���������C\n"
);
        set_weight(22000);
        if (clonep() )
             set_default_object(__FILE__);      
        else {
                set("material","iron");
                set("unit","��");
		set("volume",6);
               set("value",2500);
                set("limit_str",40);
        }
      set("wield_msg","$N�q�I���X�@���a�ۦ�⪺���j���b��W��Z���C\n");
                set("weapon_prop/parry",10);
                set("weapon_prop/int",-2);
                set("weapon_prop/str",1);
		init_fork(55,TWO_HANDED);
        setup();
}
