#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("���C", ({ "heavy sword" , "sword" }) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "��");
                set("long", "�@��ܭ����C�C\n");
                set("value", 2000);
        }
        init_sword(45);
        setup();
}


