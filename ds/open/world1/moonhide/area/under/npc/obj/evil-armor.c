#include <armor.h>
#include <ansi.h>
inherit ARMOR; 

void create()
{
        set_name(RED"���]�Z��"NOR,({ "evil armor","armor" }) );
        set("long","���]���W�Ҭ諸���ҡA���m�O�۵M���b�ܤU�C\n");
        set_weight(16000);
        if ( clonep() )
                set_default_object(__FILE__);
         else {
         set("volume",5);
         set("material","golden");
         set("unit", "��" );
         set("value",30000);
               
   }  
        set("armor_prop/armor", 40);
        set("armor_prop/parry", 5);
        set("armor_prop/dodge", -10);
        //�H�W�galickyuen���g�Χ��
        setup();
}
