#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("���v�C",({"shu-yiing sword","sword"}));
        set("long",
	"�@����T�ت����C�A�q�鳷�ղ��a���I����Z�I�A�C�`�����u�O\n"
	"�@�q���۶¥����C�ݡC\n"
	);
          set_weight(5000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
           set("value",2880);
		set("volume",3);
                set("material","iron");
	}
	init_sword(35);
                set("waepon_prop/int",2);
        set("limit_str",10);
setup();
}

