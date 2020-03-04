//u/c/chiaa/obj/eq/dragon scale_hands.c
#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
    set_name(HIC"龍鱗"YEL"手套"NOR,({"dragon scale hands","hands"}) );
    set("long","這是用龍的鱗片所製成,相當珍貴.\n");
 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(400); 
                set("limit_str",20);
                set("unit", "雙");       
                set("value",3000);          
                set("material", "scale"); //鱗片
                set("armor_prop/armor",15); //防禦15  
     
        }
        
      set("weapon_prop/parry",20);        //加 enable 技能20
        setup();
}
