#include <weapon.h> 
#include <ansi.h>
inherit FIST; 
void create()
{
        set_name(MAG"���s��"NOR, ({ "perple fist" , "fist" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "��");
                set("long", MAG"���]�b���s�ɩҳy�����A�G�H�s�W����R�W�C\n"NOR);
                set("value", 10000);
        }
        init_fist(40);
        setup();
}

