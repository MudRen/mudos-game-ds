#include <weapon.h>

inherit F_SWORD;

void create()
{
          set_name("���C", ({ "heavy sword", "sword" }) );
         set_weight(10000);
          setup_sword(5, 7, 120, 0);

        if( !clonep() ) {
                set("wield_as",({ "sword","twohanded sword"}) );
                set("unit", "��");
                set("value", 800);
                set("rigidity", 60);
                set("long", "�o�O������@�ت����C�A���C�`�N�ݭn�Ⱖ��~�ത�oí�C\n");
        }
        setup();
}

