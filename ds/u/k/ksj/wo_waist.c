#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name(HIR"霧氣之纏"NOR ,({ "wo waist","waist"}) );
        set("long",@LONG
霧獸之氣形成的腰帶,看起來不怎麼好用的樣子.
LONG);
                set_weight(1000);
                set("material", "fur");
                set("unit", "對");
                set("value",100);
                set("volume",3);
                set("armor_prop/armor", 5);
                set("limit_con",10);
                set("limit_str",10);
                set("armor_prop/dex", 1);
                set("armor_prop/wit", 0);
                set("armor_prop/bar", 0);
        set("armor_type", "waist");
        setup();
}

void init()
{

        if( userp(environment(this_object()) ) )
        {
                add_action("do_wear", "wear");
                add_action("do_remove", "remove");
        
        }
}

int do_wear(string arg)
{
        object me,eq1,eq2,eq3,eq4,eq5; 
        me = this_player();
        eq1= present("chini boots",me);
        eq2= present("maigu leggings",me);
        eq3= present("maigu gloves",me);
        eq4= present("wo cloak",me);
        eq5= present("chini wrists",me);
        me = this_player();
        if( !this_object()->query("equipped") ) {
        if( arg == "waist" || arg == "wo waist" || arg == "all")
        {
         if((me->query_temp("armor/boots")==eq1)&&(me->query_temp("armor/legging")==eq2)
          &&(me->query_temp("armor/hands")==eq3)&&(me->query_temp("armor/surcoat")==eq4)  
          &&(me->query_temp("armor/wrists")==eq5)){ 
           
                set("wear_msg",HIW"$N套上了霧氣之纏,剎時間天搖地動,眾神獸的元靈進入$N的體內!\n"NOR);
                set("armor_prop/bar", 2);
                set("armor_prop/wit", 2);
                set_weight(1000);
                set("material", "diamond");
                set("unit", "件");
                set("value",100);
                set("volume",3);
                set("armor_prop/armor", 5);
                set("limit_con",10);
                set("limit_str",10);
                set("armor_prop/dex", 1);
                setup();
                }
            
         else
         {
                set("wear_msg",HIW"$N套上了霧氣之纏.\n"NOR);
                set_weight(1000);
                set("material", "fur");
                set("unit", "對");
                set("value",100);
                set("volume",3);
                set("armor_prop/armor", 5);
                set("limit_con",10);
                set("limit_str",10);
                set("armor_prop/dex", 1);
                set("armor_prop/wit", 0);
                set("armor_prop/bar", 0);
                setup();
                }
        }
        }
}

int do_remove(string arg)
{
       if(arg){
        object me,eq1,eq2,eq3,eq4,eq5,eq6; 
        me = this_player();
        eq1= present("chini wrists",me);
        eq2= present("maigu leggings",me);
        eq3= present("maigu gloves",me);
        eq4= present("wo cloak",me);
        eq5= present("wo waist",me);
        eq6= present("chini boots",me);

        if(me->query_temp("armor/wrists")==eq1){
          eq1->unequip();
          message_vision(HIW"你身上的奇倪骨鐲跟著脫落了！\n"NOR,me);}
        if(me->query_temp("armor/legging")==eq2){
          eq2->unequip();
          message_vision(HIW"你身上的滅骨皮脛跟著脫落了！\n"NOR,me);}
        if(me->query_temp("armor/hands")==eq3){
          eq3->unequip();
          message_vision(HIW"你身上的滅骨皮掌跟著脫落了！\n"NOR,me);}
        if(me->query_temp("armor/surcoat")==eq4){
          eq4->unequip();
          message_vision(HIW"你身上的霧氣之璧跟著脫落了！\n"NOR,me);}
        if(me->query_temp("armor/waist")==eq5){
          eq5->unequip();
          message_vision(HIW"你身上的霧氣之纏跟著脫落了！\n"NOR,me);}
        if(me->query_temp("armor/boots")==eq6){
          eq6->unequip();
          message_vision(HIW"你身上的奇倪骨履跟著脫落了！\n"NOR,me);}

           
       }
     
}
