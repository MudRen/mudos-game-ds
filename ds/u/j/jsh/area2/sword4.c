#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("�ô��b", ({ "light sword" , "sword" }) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "��");
                set("long", "�@��ܻ����C  ���z���C\n");
                set("value", 2000);
        }
        init_sword(45);
        setup();
}

