#include <armor.h>
#include <ansi.h>
inherit LEGGING;
void create()
{
        set_name(HIR"�������H"NOR ,({ "maigu leggings","leggings"}) );
        set("long",@LONG
�������~�֧Φ����@�H,�ݰ_�Ӥ����n�Ϊ��ˤl.
LONG);
                set_weight(1000);
                set("material", "fur");
                set("unit", "��");
                set("value",100);
                set("volume",3);
                set("armor_prop/armor", 1);
                set("limit_con",10);
                set("limit_str",10);
                set("armor_prop/con", -1);
                set("armor_prop/wit", 0);
                set("armor_prop/bar", 0);
        set("armor_type", "legging");
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
        eq2= present("chini wrists",me);
        eq3= present("maigu gloves",me);
        eq4= present("wo cloak",me);
        eq5= present("wo waist",me);
        me = this_player();
        if( !this_object()->query("equipped") ) {
        if( arg == "leggings" || arg == "maigu leggings" || arg == "all")
        {
         if( me->query_temp("armor/boots")==eq1 ){
          if( me->query_temp("armor/wrists")==eq2 ){ 
           if( me->query_temp("armor/hands")==eq3 ){
            if( me->query_temp("armor/surcoat")==eq4 ){ 
             if( me->query_temp("armor/waist")==eq5 ){ 
           
                set("wear_msg",HIW"$N�M�W�F�������H,�b�ɶ��ѷn�a��,�����~�����F�i�J$N���餺!\n"NOR);
                set("armor_prop/bar", 2);
                set("armor_prop/wit", 2);
                set_weight(1000);
                set("material", "diamond");
                set("unit", "��");
                set("value",100);
                set("volume",3);
                set("armor_prop/armor", 5);
                set("limit_con",10);
                set("limit_str",10);
                set("armor_prop/dex", 1);
                setup();
                }}}}}
         else
         {
                set("wear_msg",HIW"$N�M�W�F�������H.\n"NOR);
                set_weight(1000);
                set("material", "fur");
                set("unit", "��");
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
          message_vision(HIW"�A���W���_�ٰ��N��۲渨�F�I\n"NOR,me);}
        if(me->query_temp("armor/legging")==eq2){
          eq2->unequip();
          message_vision(HIW"�A���W���������H��۲渨�F�I\n"NOR,me);}
        if(me->query_temp("armor/hands")==eq3){
          eq3->unequip();
          message_vision(HIW"�A���W�������ִx��۲渨�F�I\n"NOR,me);}
        if(me->query_temp("armor/surcoat")==eq4){
          eq4->unequip();
          message_vision(HIW"�A���W�������z��۲渨�F�I\n"NOR,me);}
        if(me->query_temp("armor/waist")==eq5){
          eq5->unequip();
          message_vision(HIW"�A���W���������۲渨�F�I\n"NOR,me);}
        if(me->query_temp("armor/boots")==eq6){
          eq6->unequip();
          message_vision(HIW"�A���W���_�ٰ��i��۲渨�F�I\n"NOR,me);}

           
       }
     
}
