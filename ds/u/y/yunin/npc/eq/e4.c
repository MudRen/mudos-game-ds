#include <armor.h>



#include <ansi.h>



inherit HEAD;



void create()



{



        set_name(HIC"�ѯů���"NOR ,({ "level C helmet","helmet" }) );



        set_weight(1300);



        if( clonep() )



                set_default_object(__FILE__);



        else {



 set("long",@LONG

�Ѭɦu�í̩������Y���T

LONG



     );









        set("unit", "��");



        set("value",2300);



        set("material", "gold");



        set("armor_prop/shield",1);







        set("armor_prop/armor",6);



        }



        setup();



}
