#include <weapon.h>
inherit STAFF;
void create()
{
        set_name("����", ({ "junk stick" , "stick" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material","plant");
                set("long", "�o�������a�W�H�K�߳���, �A����ҵۧA�F�®��ۥ��C\n");
                set("value",1);
        }
        init_staff(1);
        setup();
}