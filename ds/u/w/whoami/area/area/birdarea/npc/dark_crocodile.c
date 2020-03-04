#include <ansi2.h>
inherit NPC;
void create()
{
 set_name(HIW+BLK"��]"NOR+YEL"���s"NOR,({"dark-night crocodile","crocodile"}));
 set("long","�e�N�O�~��b�o�F�_�A�L�����j�s���A�h�~�Q�@�Ӥ����W���H��\n"
            "�L�󦹡A�p���A�����^��o�ӥ@�ɡA�Q���|�a�Ӥ��֫�w�C\n");
 set("age",200+random(100));
 set("race", "���~");
set("attitude","aggressive");
 set("level",50+random(20));
 set("title",HIW"�F�_"NOR"�A�L"); 
 set("nickname","�h�A����"); set("limbs", ({ "�Y��", "����", "�e��", "�ᨬ", "����" }) );
 set("verbs", ({ "bite", "claw" ,"crash"}) );
 set("evil",500);
 set("dodge",100); 
 set("unarmed",100);
 set("parry",100); 
 set("max_hp",15000+random(3000));

 set("addition/wit",random(7)); 
 set("addition/bar",-3); 
  set("addition/hit",random(60)); 
  set("addition/dodge",random(60)); 
 setup();
}
int special_attack(object me, object target, int hitchance)
{
 
 if(!me || !target) return 0;
 if(!random(5)){
 message_vision("\n$N"+YEL"�i�}�j�f��$n�r�F�U�h�E�E\n",me,target);
 if( random(target->query("dodge"))>60 ){
 message_vision("\n$N"+HIB"�����^�סA�T�V�������F�o�@���E\n",target); 
 target->start_busy(1); } else {
 message_vision("\n$N"+HIR"�{�����γQ$n"HIR"�������r�F�@�f�A�������Y��G�����_���I\n",target,me);
 target->receive_damage("hp",target->query("hp")/10);
 target->receive_wound("head",1+random(98));
 target->receive_wound("body",1+random(98));
 target->receive_wound("left_arm",1+random(98));
 target->receive_wound("left_leg",1+random(98));
 target->receive_wound("right_arm",1+random(98));
 target->receive_wound("right_leg",1+random(98));
 target->start_busy(random(3));
 }
}return 0;
 
}
void die()
{
        object ob,newob,newob1;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( ob ) message("world:world1:vision", 
        
        HIG"\n\t�i"HIW"�F�_"NOR"�A�L"HIG"�j
"HIW"\n\t�F�_�A�L�������~"+this_object()->query("name")+HIW"�ש�Q"NOR+ob->name(1)+HIW"���ݱ��F�I\n\n"+NOR,users());
        ob->add("popularity",7); 
        ob->set_temp("ko_crocodile",1);
        tell_object(ob,HIG"\t�A�o��F���I�n��I\n"NOR);
        switch( random(100) ) {
        case 0..5:
        newob1=new(__DIR__"obj/teeth"); 
        newob1->move(this_object());
        break;
        case 6..20:
        newob=new(__DIR__"obj/fur"); 
        newob->move(this_object());
        break;
        default:
        new(__DIR__"obj/scroll")->move(this_object());
        break;
        }
        ::die();
        return;
}

