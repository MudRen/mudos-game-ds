#include <armor.h>



#include <ansi.h>



inherit ARMOR;



void create()



{



        set_name(HIC"�Яů���"NOR ,({ "level B armor","armor" }) );



        set_weight(1300);



        if( clonep() )



                set_default_object(__FILE__);



        else {



 set("long",@LONG

�ѬɤW�խ̩������Y���T

LONG



     );









        set("unit", "��");



        set("value",2300);



        set("material", "gold");



        set("armor_prop/shield",1);







        set("armor_prop/armor",29);



        }



        setup();



}
