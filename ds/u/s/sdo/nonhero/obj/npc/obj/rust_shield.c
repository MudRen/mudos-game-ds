#include <armor.h>
inherit SHIELD;

void create()
{
        set_name("�}�ꪺ��",({"broken shield","shield"}));
        set_weight(4000);
        if( clonep() )
		set_default_object(__FILE__);
        else 
	{
        set("unit", "��");
        set("volume",5);
        set("long", @LONG
�o�O�@���}�}���ꪺ�޵P�C
LONG
	);
       	set("value",100);
        set("material","wood");
        }
        set("armor_prop/armor",1);
        setup();
}