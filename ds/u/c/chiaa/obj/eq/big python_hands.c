//u/c/chiaa/obj/eq/big python_hands.c
#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
    set_name(CYN"巨蟒"YEL"手套"NOR,({"big python hands","hands"}) );
    set("long","這是用巨大蟒蛇的蛇皮所製成.\n");
 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(200); 
                set("limit_str",15);
                set("unit", "雙");       
                set("value",1500);          
                set("material", "python"); //蟒蛇
                set("armor_prop/armor",8); //防禦8    
                set("armor_prop/str",1);   //力量+1
        }
        
      set("weapon_prop/parry",10);        //加 enable 技能10
        setup();
}
