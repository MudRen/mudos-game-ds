#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIR"�s���"NOR, ({ "dragon ghost ring","ring" }) );
        if( clonep() )
        set_default_object(__FILE__);
        else {
                 set("long","�ڻ����٫��O�ΤT�ίu���ҿN�s�C�C�|�Q�E��,\n"
                            "�~���y�Ӧ�.\n");
                set("unit", "�u");
         set_weight(2500);
         set("value",1900);
         set_weight(600);
         set("material","gem");
set("limit_lv",20); 
}  
       set("armor_prop/armor", 5);
       set("armor_prop/int",1);
       set("armor_prop/con",2);   
       setup();
}

