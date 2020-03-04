#include <ansi2.h>
inherit NPC;
void create()
{
 set_name(HIY"����"NOR,({"god bird","god","bird"}));
 set("long","�L�O�ǻ������j���A�S�H���D�e�q��B�ӡA�]�S�H
���D�e�O���س��A�j�a�u�]���e�������_�S�B�髬
���j�A�ӵ��L�@�Ӻٸ������������A�L�ݰ_�Ө{�l
�j�F�A�ǻD���L���w�Y�@�غ�⪺�p�ΡC\n");
 set("age",500+random(600));
 set("race", "���~");
 set("level",30+random(20));
 set("title","�ǻ�����");
 set("limbs", ({ "�Y��", "����", "�ͻH", "�}", "����" }) );
 set("verbs", ({ "bite", "claw" }) );
 set("evil",-50);
 set("dodge",100); 
 set("unarmed",100);
 set("parry",100); 
 set("max_hp",20000+random(3000));
 set("addition/wit",random(7)); 
 set("addition/bar",2+random(2)); 
 set("addition_damage",140+random(20)); 
 set("addition_armor",120+random(15)); 
 set("addition/hit",random(60)); 
 set("addition/dodge",random(60)); 
 setup();
}
int special_attack(object me, object target, int hitchance)
{
 int x = random(80);
 
 if(!me || !target) return 0;
 if(!random(3)){
  switch( random(7) ){
  case 0..1: 
   message_vision("\n\n$N"+HIW"�η��֪��t�׽ĦV�ѻڡE�E\n"
                         +HIB"���۫K���t���ĦӤU��$n���h�I",me,target);
   if( random(target->query_dex()) >=50 ) {
     message_vision("\n"HIR"�Q"NOR"$N"+HIR"���I�����L�F�o���������I\n",target);
     } else {
     message_vision("\n$N"+HIY"����j�P�����A�ͩR���p��������I\n",target);
     target->receive_damage("hp",200+random(200));
     target->receive_wound("head",3);
     target->receive_wound("body",random(3));
     }
   break;
  case 2..4:
   message_vision("\n\n$N"+HIW"�ίͻH�¦V$n��F�L�h�E�E",me,target);
   if( random(target->query_skill("dodge")) >=70 ) {
   message_vision("\n$N"+HIR"���������L�F�����I\n",target);
   } else {
   message_vision("\n$N"+HIY"�Q$n���ͻH�����Y������A�����M�F��n�_�F�I\n",target,me);
   target->receive_damage("hp",100+random(100));
   target->start_busy(random(3)+2);    
   target->receive_wound("head",random(3));
   }
   break;
  default:
   message_vision("\n\n$N"+HIW"���ʯͻH�A�o�̧j�_�n�j�@�}���g���E�E\n",me,target);
    if( random(target->query_con()) >= 80 ) {
   message_vision("\n$N"+HIW"�j�j�������餣�Q�����j���E\n",target);
   } else {
   message_vision(HIC"\n�g���j�o"NOR"$N"HIC"�S�k��í�}�A�Q�����j���F�I\n",target);
    target->start_busy(random(3)); 
    target->receive_wound("head",random(30));
    target->receive_wound("body",random(30));
    target->receive_wound("left_arm",random(30));
    target->receive_wound("right_arm",random(30));
    target->receive_wound("left_leg",random(30));
    target->receive_wound("left_leg",random(30));
    target->move("/open/world1/whoami/birdarea/en"+x);
    message_vision("\n\n$N�ܯT�V���q�Ť��^�F�U�ӡE�E�E\n",target);
    }
     break;
  }
  }  
return 0;

}
void die()
{
       object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( ob ) message("world:world1:vision", 
        HIW"\n\t�i"HIB"���@�@��"NOR+HIW"�j"HIW"\t�ǻ�����"HIY"����"NOR+HIW"�p�����G���b"NOR+ob->name(1)+HIW"����U�E\n\n"+NOR,users());
        ob->add("popularity",4);
        switch( random(10) ) {
        case 0..7:  break;
        default:  new(__DIR__"obj/fur2")->move(this_object());  break;
        }
        ::die();
        return;
}

