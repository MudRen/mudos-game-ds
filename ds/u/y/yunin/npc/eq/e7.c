#include <armor.h>



#include <ansi.h>



inherit BOOTS;



void create()



{



        set_name(HIC"��ů��c"NOR ,({ "level S boots","boots" }) );



        set_weight(1300);



        if( clonep() )



                set_default_object(__FILE__);



        else {



 set("long",@LONG

�ѬɧԪ̭̩Ҭ諸�c�T

LONG



     );









        set("unit", "��");



        set("value",2300);



        set("material", "gold");



        set("armor_prop/shield",1);







        set("armor_prop/armor",11);



        }



        setup();



}
