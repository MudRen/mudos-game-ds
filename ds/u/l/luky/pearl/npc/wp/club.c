#include <weapon.h>
inherit HAMMER;
void create()
{
set_name("ĵ��",({"guard club","club"}));
set_weight(27000);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long","\n
�@��Q������ĵ�ҡC\n");
            set("unit", "��");
            set("rigidity",70); //�w��
            set("material","steel"); //����
set("hammer",45);
set("value",3750);
           }
// init_hammer(1000);
        setup();
}



