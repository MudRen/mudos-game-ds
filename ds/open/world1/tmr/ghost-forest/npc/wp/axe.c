#include <weapon.h>
inherit AXE;

void create()
{
       set_name("�L������",({"hug axe","axe"}) );
  set("long",
"�@��Q�����j�p�������Y�A���O���`�N�����H���u�j�p�A����s\n"
"��V�A�ݨӫD�n�M�O�L�H�A�~���R���ʡC\n"
);
        set_weight(30000);
        if (clonep() )
             set_default_object(__FILE__);      
        else {
                set("material","iron");
                set("unit","��");
		set("volume",6);
             set("value",2500);
                set("limit_str",40);
        }
                set("weapon_prop/parry",10);
                set("weapon_prop/dex",-2);
                set("weapon_prop/str",1);
		init_axe(60,TWO_HANDED);
        setup();
}
