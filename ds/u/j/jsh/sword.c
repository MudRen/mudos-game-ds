#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("��l�C", ({ "ap sword" , "sword" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "��"); 
                set("no_sell",1);
                set("no_drop",1);
                set("no_give",1); 
                set("no_get",1);                set("long", "�Ѯ�l�Ҿ��E�Ӧ����C�C\n");
        }
        init_sword(1);
        setup();
}


