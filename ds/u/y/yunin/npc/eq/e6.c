#include <armor.h>



#include <ansi.h>



inherit WAIST;



void create()



{



        set_name(HIC"�ϯů����y"NOR ,({ "level A waist","waist" }) );



        set_weight(1300);



        if( clonep() )



                set_default_object(__FILE__);



        else {



 set("long",@LONG

�Ѭɮ��ƤH�̩��������y�T

LONG



     );









        set("unit", "��");



        set("value",2300);



        set("material", "gold");



        set("armor_prop/shield",1);







        set("armor_prop/armor",5);



        }



        setup();



}
