#include <weapon.h>

inherit AXE;

void create()
{
        set_name("����", ({ "huge axe","axe"}) );
        set_weight(10000);
        init_axe(45);

        if( !clonep() ) {
                set("unit", "��");
                set("value", 3500);
                set("rigidity", 80);
                set("long",@long
    �o�O�@�⥨�j�B�I��������A�S���۷��u�O���H�A�X�G�O�����ʪ��C
long
                );
        }  else
		   set_default_object(__FILE__);
        setup();
}

