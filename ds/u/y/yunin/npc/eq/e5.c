#include <armor.h>



#include <ansi.h>



inherit ARMOR;



void create()



{



        set_name(HIC"Ｂ級神甲"NOR ,({ "level B armor","armor" }) );



        set_weight(1300);



        if( clonep() )



                set_default_object(__FILE__);



        else {



 set("long",@LONG

天界上校們所戴的頭盔﹗

LONG



     );









        set("unit", "個");



        set("value",2300);



        set("material", "gold");



        set("armor_prop/shield",1);







        set("armor_prop/armor",29);



        }



        setup();



}
