#include <ansi2.h>
inherit NPC;
void create()
{
 set_name(HIY"����"NOR,({"god bird","god","bird"}));
 set("long","�L�O�ǻ������j���A�S�H������e�q��B�ӡA�]�S
�H���D�e�O���س��A�j�a�u�]���e�������_�S�B��
�����j�A�ӵ��L�@�Ӻٸ������������A�L�ݰ_�Ө{
�l�j�F�A�ǻD���L���w�Y�@�غ�⪺�p�ΡC\n");
 set("age",235);
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
  set("addition/hit",random(60)); 
  set("addition/dodge",random(60)); 
 setup();
}
int special_attack(object me, object target, int hitchance)
{
 
 if(!me || !target) return 0;
 if(!random(5)){
  switch( random(7) ){
  case 0..1: 
   message_vision("\n\n$N"+HIW"�η��֪��t�׽ĦV�ѻڡE�E\n"
                         +HIB"���۫K���t���ĦӤU��$n���h�I\n",me,target);
   if( random(target->query("dex")) >=50 ) {
     message_vision("\n"HIR"�Q"NOR"$N"+HIR"���I�����L�F�o���������I\n",target);
     } else {
     message_vision("\n$N"+HIY"����j�P�����A�ͩR���p��������I\n",target);
     target->receive_damage("hp",200+random(200));     target->receive_wound("head",3);
     target->receive_wound("body",random(3));     }
   break;
  case 2..4:
   message_vision("\n\n$N"+HIW"�ίͻH�¦V$n��F�L�h�E�E\n",me,target);
   if( random(target->query_skill("dodge")) >=50 ) {
   message_vision("\n$N"+HIR"���������L�F�����I\n",target);
   } else {
   message_vision("\n$N"+HIY"�Q$n���ͻH�����Y������A�����M�F��n�_�F�I\n",target,me);
   target->receive_damage("hp",100+random(100));
   target->start_busy(random(3));    
   target->receive_wound("head",random(3));
   }
   break;
  default:
   message_vision("\n\n$N"+HIW"���ʯͻH�A�o�̧j�_�n�j�@�}���g���E�E\n",me,target);
    if( random(target->query("con")) >=50 ) {
   message_vision("\n$N"+HIW"�j�j�������餣�Q�����j���E\n",target);
   } else {
   message_vision(HIC"\n�g���j�o"NOR"$N"HIC"�S�k��í�}�A�Q�����j���F�I\n",target);
    switch( random(8) ) { 
    case 0:    
    target->move("/open/world1/whoami/birdarea/en65");
    message_vision("\n\n$N�ܯT�V���q�Ť��^�F�U�ӡE�E�E\n",target);
    target->start_busy(random(3)); 
    target->receive_damage("hp",target->query("hp")*9/10);
    target->receive_wound("head",random(10));
    target->receive_wound("body",random(10));
    target->receive_wound("left_arm",random(10));
    target->receive_wound("right_arm",random(10));
    target->receive_wound("left_leg",random(10));
    target->receive_wound("left_leg",random(10));
    break;
    case 1:
    target->move("/open/world1/whoami/birdarea/en51");
    message_vision("\n\n$N�ܯT�V���q�Ť��^�F�U�ӡE�E�E\n",target);
    target->start_busy(random(3)); 
    target->receive_damage("hp",target->query("hp")*9/10);
    target->receive_wound("head",random(10));
    target->receive_wound("body",random(10));
    target->receive_wound("left_arm",random(10));
    target->receive_wound("right_arm",random(10));
    target->receive_wound("left_leg",random(10));
    target->receive_wound("left_leg",random(10));
    break;  
    case 2:
    target->move("/open/world1/whoami/birdarea/en30");
    message_vision("\n\n$N�ܯT�V���q�Ť��^�F�U�ӡE�E�E\n",target);
    target->start_busy(random(3)); 
    target->receive_damage("hp",target->query("hp")*9/10);
    target->receive_wound("head",random(10));
    target->receive_wound("body",random(10));
    target->receive_wound("left_arm",random(10));
    target->receive_wound("right_arm",random(10));
    target->receive_wound("left_leg",random(10));
    target->receive_wound("left_leg",random(10));
    break;  
    case 3..4:
    target->move("/open/world1/whoami/birdarea/en35");
    message_vision("\n\n$N�ܯT�V���q�Ť��^�F�U�ӡE�E�E\n",target);
    target->start_busy(random(3)); 
    target->receive_damage("hp",target->query("hp")*9/10);
    target->receive_wound("head",random(10));
    target->receive_wound("body",random(10));
    target->receive_wound("left_arm",random(10));
    target->receive_wound("right_arm",random(10));
    target->receive_wound("left_leg",random(10));
    target->receive_wound("left_leg",random(10));
    break;  
    case 5..6: 
    target->move("/open/world1/whoami/birdarea/en70");
    message_vision("\n\n$N�ܯT�V���q�Ť��^�F�U�ӡE�E�E\n",target);
    target->start_busy(random(3)); 
    target->receive_damage("hp",target->query("hp")*9/10);
    target->receive_wound("head",random(10));
    target->receive_wound("body",random(10));
    target->receive_wound("left_arm",random(10));
    target->receive_wound("right_arm",random(10));
    target->receive_wound("left_leg",random(10));
    target->receive_wound("left_leg",random(10));
    break;  
    default:
    target->move("/open/world1/whoami/birdarea/en78");
    message_vision("\n\n$N�ܯT�V���q�Ť��^�F�U�ӡE�E�E\n",target);
    target->start_busy(random(3)); 
    target->receive_damage("hp",target->query("hp")*9/10);
    target->receive_wound("head",random(10));
    target->receive_wound("body",random(10));
    target->receive_wound("left_arm",random(10));
    target->receive_wound("right_arm",random(10));
    target->receive_wound("left_leg",random(10));
    target->receive_wound("left_leg",random(10));
    break;      } 
    }
     break;
  }
  }  
return 0;
 
}
void die()
{
        object ob,newob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( ob ) message("world:world1:vision", 
        
        HIW"\n\t�i"HIB"���@�@��"NOR+HIW"�j
        "HIW"\n\t�ǻ�����"HIY"����"NOR+HIW"�p�����G���b"NOR+ob->name(1)+HIW"����U�E\n\n"+NOR,users());
        ob->add("popularity",7);
        tell_object(ob,HIG"\t�A�o��F���I�n��I\n"NOR);
        switch( random(20) ) {
        case 0..5:
        break;
        default:
        newob=new(__DIR__"obj/fur2"); 
        newob->move(this_object());
        break;
        }
        ::die();
        return;
}

