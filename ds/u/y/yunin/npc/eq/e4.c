#include <armor.h>



#include <ansi.h>



inherit HEAD;



void create()



{



        set_name(HIC"Ｃ級神盔"NOR ,({ "level C helmet","helmet" }) );



        set_weight(1300);



        if( clonep() )



                set_default_object(__FILE__);



        else {



 set("long",@LONG

天界守衛們所戴的頭盔﹗

LONG



     );









        set("unit", "個");



        set("value",2300);



        set("material", "gold");



        set("armor_prop/shield",1);







        set("armor_prop/armor",6);



        }



        setup();



}
