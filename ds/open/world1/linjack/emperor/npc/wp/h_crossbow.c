#include <weapon.h>
inherit BOW;

void create()
{
	set_name("����",({"heavy cross bow","bow"}));
	set_weight(10000);
	set("long","�o�O�@��j�ƹL�᪺��, �g�X�����b�t�׳��۷��}�a�O�C\n");

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",1500);
                set("material","wood");
		set("limit_skill",60);
                set("limit_int",30);
                set("limit_dex",30);
                set("limit_str",30);
        }
        set("weapon_prop/str",2);
	set("weapon_prop/dex",-1);
       init_bow(60,TWO_HANDED);
        setup();
}
