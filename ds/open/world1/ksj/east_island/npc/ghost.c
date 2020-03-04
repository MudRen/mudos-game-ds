#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����",({"ghost"}) );
        set("long",@LONG
�@����Χ��ӡA�h�����L���c���A���[�H�ӳQ�ʦL��۹����U�C
LONG);
        set("race", "���~");    
        set("unit","��");
        set("age",150);
        set("level",35);
        set("attitude", "aggressive");  
        set("limbs", ({ "�Y��", "����","�ⳡ","�}��"}) ); 
        set("verbs", ({ "bite","claw" }) );     
        setup();
}

void init()
{
    ::init();
    if( environment(this_player())->query("no_kill") ) return;
    if( environment(this_player())->query("no_fight") ) return;
    if(!this_object()->visible(this_player())) return;
    if(userp(this_player()) )
      this_object()->kill_ob(this_player());
}

void die()
 {
   object ob;
   if( !ob = query_temp("last_damage_from") )
   ob = this_player(1);
   if( !ob ) 
   {
    ::die();
    return;
   }
   ob->add("popularity",1);
   tell_object(ob,HIG"�A�o�� 1 �I�n��C"NOR);      
   switch( random(99) ) {
    case  0..1: new(__DIR__"eq/ghost-necklace")->move(this_object());
    break;}
   ::die();
   return;
 }
