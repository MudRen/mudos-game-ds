#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
  set_name(YEL"���ɴ�"NOR,({"copper cane","cane"}) );
  set("long",
"�@�K���V���������ɴҡA�q�馳����u�j�p�A�ҭ��ɬO�貪�A�ݨӦ���\n"
"�w�[�C�Ҩ��@�Y������ۡu���]�v�G�r�A�����a������t�N�C\n"
);
        set_weight(25000);
        if (clonep() )
             set_default_object(__FILE__);      
        else {
                set("material","copper");
                set("unit","�K");
                set("value",5000);
                set("limit_level",20);
                set("weapon_prop/parry",10);
                set("weapon_prop/dex",-2);
        }
        init_staff(50);
        setup();
}
