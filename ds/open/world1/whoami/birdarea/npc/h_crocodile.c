#include <ansi2.h>
inherit NPC; 

void create()
{

 switch( random(3) )
 {
 case 1:
  set_name("�_"HIW+BLK"�Y"NOR"�p�s��",({"headless crocodile","crocodile"}));
  set("limbs", ({ "����", "�e��", "�ᨬ", "����" }) );
  set("verbs", ({ "claw"}) );
  break;
 default:
  set_name("�_"HIW+BLK"�L"NOR"�p�s��",({"footless crocodile","crocodile"}));
  set("limbs", ({ "�Y��", "����", "����" }) ); 
  set("verbs", ({ "bite", "crash"}) );
  break;
 case 2:
  set_name("�_"HIW+BLK"��"NOR"�p�s��",({"tailless crocodile","crocodile"}));
  set("limbs", ({ "�Y��", "����", "�e��", "�ᨬ" }) ); 
  set("verbs", ({ "bite", "crash", "claw"}) );
  break;
 }
 set("long","�e�O�@���ݻ٪��s���A�ݨ�e�o�Ӽˤl�A�٧Ԥ߱��e�ܡH\n");
 set("age",10+random(10));
 set("race", "���~");
 set("level",50+random(20));
 set("title",HIW"�F�_"NOR"�A�L"); 
 set("nickname","���Ѵݻ�"); 
 set("evil",-50);
 set("dodge",100); 
 set("unarmed",100);
 set("parry",100); 
 set("max_hp",random(100000));
 set("addition/bar",-10); 
 set("addition/hit",random(30)); 
 set("addition/dodge",random(30)); 
 setup();
}

void die()
{
        object ob,newob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        ob->add("popularity",1);
        tell_object(ob,HIG"�]���A���ݧԡA�A�o��F���I�n��\n"NOR);
        ::die();
        return;
}

