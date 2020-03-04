//u/c/chiaa/obj/eq/crystal_neck.c

#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(HIC"水晶項鍊"NOR,({"crystal_neck","neck"}) );
        set("long","一條用水晶製作而成的項鍊，看起來晶瑩剔透。\n");    
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "條");
                set_weight(5);        
                set("value",6000);          
                set("armor_prop/armor",3);  //防禦5 
                set("material", "crystal");    //材質 水晶  
        }
        
       setup();
}
