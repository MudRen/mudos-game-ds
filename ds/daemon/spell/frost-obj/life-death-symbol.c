#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("�ͦ���", ({ "life death symbol", "symbol", "__LIFE_DEATH_SYMBOL_"}) );
          set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�o�O�@���H���D�[�W�����ͦ��šA���W�O�@���G�鰵�������B���C");
                set("unit", "��");
                set("base_unit", "��");
               set("value", 1);
        }
       set("power",1);
       set_amount(1);
       init_throwing(10);
       setup();
}

void init() {
        set("power", this_player()->query_spell("life-death-symbol") );
}

