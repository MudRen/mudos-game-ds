#include <weapon.h> 
#include <ansi.h>
inherit BLADE; 
void create()
{
        set_name("�K�ȤM", ({ "iron_paper blade" , "blade" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "��");
                set("long", "�@����K�A�V�����Ȥ@�˪����A�ݰ_���Z�W�Q���C\n");
                set("value", 1000);
        }
        init_blade(35);
        setup();
}

