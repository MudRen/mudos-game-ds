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
  set("level", 50);
  set("title",HIW"�F�_"NOR"�A�L"); 
  set("nickname","�h�A����"); set("limbs", ({ "�Y��", "����", "�e��", "�ᨬ", "����" }) );
  set("verbs", ({ "bite", "claw" ,"crash"}) );
  set("evil",150);
  set("dodge",100); 
  set("unarmed",100);
  set("parry",100); 
  set("max_hp",15000 );
  setup();
  set_temp("apply/damage", 100); 
  set_temp("apply/armor", 150); 
  set_temp("apply/shield", 150); 
}

int special_attack(object me, object target, int hitchance)
{
 if(!me || !target) return 0;
 if(random(10) < 3 || target->is_busy() ){
         message_vision("\n$N"+YEL"�i�}�j�f��$n�r�F�U�h�K�K\n",me,target);
         if( random(target->query_skill("dodge"))>60 || random(target->query_dex()) > 65 ){
                 message_vision("\n$N"+HIB"�����^�סA�T�V�������F�o�@���K�K\n",target); 
                 target->start_busy(1);
          } else {
                 message_vision("\n$N"+HIR"�{�����γQ$n"HIR"�������r�F�@�f�A�������Y��G�����_���I\n",target,me);
                 target->receive_damage("hp", target->query("max_hp")/8);
                 target->receive_wound("head", 1+random(20));
                 target->receive_wound("body", 1+random(20));
                 target->receive_wound("left_arm", 1+random(20));
                 target->receive_wound("left_leg", 1+random(20));
                 target->receive_wound("right_arm", 1+random(20));
                 target->receive_wound("right_leg", 1+random(20));
                 target->start_busy(random(3));
         }
        }
 return 0;
}

void die()
{
        object ob;
        object sc;
        int rnd;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( ob )  message("world:world1:vision", HBK"\n\t�i�F�_�A�L�j"HIW"���Z�N�媺���~"+this_object()->query("name")+HIW"�ש�Q"HIW+ob->name(1)+HIW"���ݱ��F�I\n\n"+NOR,users());
        ob->add("popularity",3); 
        ob->set_temp("ko_crocodile",1);
        
        rnd = random(200);
        if( rnd == 1) { // 1/200
                new(__DIR__"obj/teeth")->move(this_object()); 
        } else if(rnd==2) {     // 1/200
                new(__DIR__"obj/fur")->move(this_object());
        }

        sc = ENHANCE_D->createScroll(45);
        sc->move( this_object() );

        ::die();
        return;
}

