#include <armor.h>
#include <ansi.h>
inherit SURCOAT; 

void create()
{
        set_name(HIW"�E�����l"NOR,({ "nine-fox surcoat","surcoat" }) );
        set("long",HIW"�E�������I������֡A��e�ջȦ�A�����p�ȡA��b�p���C\n"NOR);
        set_weight(4000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","golden");
        set("unit", "��" );
        set("value",30000); 
        }   
        set("armor_prop/armor", 10); 
        set("armor_prop/dodge",10); 
        set("armor_prop/bar",1);
        set("armor_prop/tec",1); 
        set("armor_prop/str",-3);
        setup();
}
