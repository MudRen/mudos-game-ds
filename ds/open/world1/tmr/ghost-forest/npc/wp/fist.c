#include <weapon.h>
inherit FIST;

void create()
{
  set_name("��R�e�x",({"ghost fist","fist"}) );
  set("long",
"�o�O�@���K��M�A�W���G���F�����������A�ҼˤQ���j�ǡA\n"
"�b��M�W��A���ۤT���K�ġA�Ħ������A�H�W�j���ˤO�C\n"
);
        set_weight(12000);
        if (clonep() )
             set_default_object(__FILE__);      
        else {
                set("material","iron");
		set("volume",2);
                set("unit","��");
               set("value",2500);
                set("limit_str",40);
        }
                set("weapon_prop/parry",10);
               set("weapon_prop/con",-2);
                set("weapon_prop/str",1);
                set("weapon_prop/dex",1);
init_fist(55);
        setup();
}
