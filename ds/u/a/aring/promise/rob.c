#include <ansi.h>
#include <combat.h>
inherit NPC;

void heal();
void create()
{
  set_name(HIW+BLK"���H�]��"NOR, ({"rob"}) );
  set("long",@LONG
���������C
LONG
);
  set("gender", "�k��");  
  set("race", "�H��");
  set("age",20);
  set("level",1);
  set("attitude", "aggressive");
  set("evil",1000000);
    setup();

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
  message("world:world1:vision","\n\n\t"HIY"����"HIG"�u�����t�x�v�u���N���H�v�uZmud 4.62�v"HIY"��"BLK"�t�]�]��"NOR"(Rob)"HIY"�A�ש�Q�����F�I�I\n\n\t"HIW+BLK"���H�]��"NOR"(Rob)"HIW"���D�G "HIC"���I.....���]�����ܡH\n\t"HIW"��"NOR"(Deaon)"HIW"�G"HIC"���������A�A���藍��ڡH���Y�H\n\t"HIW"���Y"NOR"(Dkfum)�G"HIC"�S���S���A�A���藍����HExri�BPiliykt�H\n\t"HIW"���I�P�j�����f�P�n���G"HIC"���H�N�O���H�A�O�����FRob�I�I\n\n\t"HIW"�o��"BLK"���H�]��"NOR"(Rob)"HIW"�۰_�F��ɬY�H�����W���G"HIC"�ڬO�@���p�p�p�p����..�M��N���w���F�I�I\n\n"NOR
       ,users());
  ob->add("popularity",500000);      
  
   ::die();
  return;
}

