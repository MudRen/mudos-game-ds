#include <armor.h>
#include <ansi.h>
inherit ARMOR; 
inherit F_UNIQUE;
void create()
{
        set_name(HIR"���]�Z��"NOR,({ "evil armor","armor" }) );
        set("long","���]���W�Ҭ諸���ҡA���m�O�۵M���b�ܤU�C\n");
        set_weight(16000);
        if ( clonep() )
                set_default_object(__FILE__);
         else {
         set("volume",5);
         set("material","golden");
         set("unit", "��" );
         set("value",30000);
                set("replica_ob",__DIR__"evil-armor"); 
   } 
	set("armor_prop/armor", 40);
	set("armor_prop/parry", 5);
	set("armor_prop/dodge", -10);
	//�H�W�galickyuen�վ�έ��s���m
        set("armor_prop/tec",1);
        set("armor_prop/bar",-1);
        setup();
}

