#include <weapon.h> 
#include <ansi.h>
inherit FIST; 
void create()
{
        set_name("�u��", ({ "short claw" , "claw" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "��");
                set("long", "���q�����l�A�u�O�񥭪������l�ٵu�F�@�I�C\n");
                set("value", 1000);
        }
        init_fist(35);
        setup();
}

