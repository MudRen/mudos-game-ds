#include <ansi.h>  
#include <armor.h>
inherit SHIELD; 
void create()
{
        set_name(HIW"���褧��"NOR,({ "water-mirror shield","shield" }) );
        set("long","�o�O�Υդ����Ӳӿi�����p�ޡA�����ƦӰ{�G�A�̭��h�躡�᯾ \n"                   "����]�k�������������Ϊ���ܤO�C\n");
        set_weight(6000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material","gold");
                set("unit", "��" );
                set("no_sell",1); 
                set("value",30000);
                set("armor_prop/armor", 10);
                set("armor_prop/shield",45);
        }
        setup();
} 

