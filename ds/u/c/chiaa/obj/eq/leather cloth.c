//u/c/chiaa/obj/eq/leather cloth.c

#include <armor.h>//定義防具
#include <ansi.h>//定義色碼
inherit CLOTH;//大寫
void create()
{
    set_name("皮衣",({ "leather cloth","cloth" }));

      if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "以皮革編製程的普通衣服\n");//防具的敘述
                set_weight(20);//防具的重量  
                set("unit", "件" );//防具的單位
                set("material", "leather"); //材質                 
                set("armor_prop/armor", 5); //防禦力
                set("value", 50); //價值
             }
       setup();
}
