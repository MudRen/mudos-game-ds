#include <ansi2.h>
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name(HIC"�^���ԥ�"NOR,({"hero armor","armor"}));
        set_weight(25000);            
        if( clonep() )
   	        set_default_object(__FILE__);
        else 
	{
     	set("unit", "��");
        set("material","steel");
       	set("long",@LONG 
�o��ԥҬO�Ѻ���ҥ��y�Ӧ��A���M�g�����־԰��A�W�������o��
�h�A�Ѧ��i�����ԥҪ�����h���w�C
LONG
	);
  	set("value",4000);
        set("volume",5);
	set("armor_prop/con",2);
        set("armor_prop/armor",30);  
        }
        setup();
}