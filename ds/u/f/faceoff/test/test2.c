#include <ansi.h>
inherit NPC;
void create()
{
set_name("�E��",({"yu chen","yu","chen"}));
set("long",@LONG
�o�O�@�Ӧb�L��W�n�T�������Q��, ���L�쩳�O�¹D�չD
�줵���٬O�����ɯ�, ���L�i�H���O, �b�L��|�������F�q��
�e, �E�ɭˬO�۷������B�z�h�I�������ȯ�, �]�]���o�o�F
���ִI�H, �]���۷����󤵤鯸�b�I�H�s��, ���^�a������
�Q, �����E�ɦ��~���o�@���H���I�M�k, �~��b�L�⤤������
�Q���갣.
LONG
    );
set("level",60);
set("str",  80+random(10));
set("evil",-20-random(50));
set("combat_exp",59000);
set("age",random(9)+33);
set("chat_chance",6);
set("chat_msg",({
  (: command("say �̪�@�Ưu�h��") :),
  (: command("say �Ѧ���\\�A�a���ѽL") :),
  (: command("say ���n���~�B�A�����Q�N��") :),
  (: command("exert moon_force recover") :),
  (: command("exert moon_force addtimes") :),
}));
set_temp("sorgitimes",12);
set("max_ap",4500);
set("chat_chance_combat",120);
set("chat_msg_combat",({
         (:command("exert sorgi_sword"):),
         (:command("exert moon_force recover"):),
}));
        set("class","fighter");
        set("class1","�x�H");
        set("title","�e�����ФH");
        set("nickname",HIR"�Z��"NOR);
        set("flurrydodge",1);
        set_skill("unarmed",70+random(10));
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("combat",100);
        set_skill("sorgi_sword",100);
        set_skill("force", 100);
        set_skill("moon_force",100);
        set_skill("fogseven",100);
        map_skill("sword","sorgi_sword");
        map_skill("force","moon_force");
        map_skill("dodge","fogseven");
        setup();
}

void init()
{
        object me,obj;
        me = this_player();
        obj = this_object();
        if( me->query_temp("enter_house") )
        {
                me->delete_temp("enter_house");
                me->set_temp("want_kill",1);
                call_out("want_kill",1,obj);
        }
}


void want_kill()
{
      int i;
      object me,obj,p;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("enter_house");
      switch( i ) {
          case 1:
            command("say ��! �o���O���N���N�ж�?");
            command("say �o��"+RANK_D->query_respect(me)+"�O�q��o���N�Ъ��H");
            obj->set_temp("meet_eagle",i+1);
            call_out("meet_eagle",3,me);
            break;
          case 2:
            message_vision(YEL"$N�N�o���N�Ъ��L�{�i�D���M�y�C\n"NOR,me);
            obj->set_temp("meet_eagle",i+1);
            call_out("meet_eagle",3,me);
            break;
          case 3:
	    command("nod");
            command("say ��Ӧp��...�C");
            command("hoho");
            obj->set_temp("meet_eagle",i+1);
            call_out("meet_eagle",3,me);
            break;
          case 4:
	    if(me->query_skill("sky-dagger") == 0 && me->query("class1") == "�ѱ���") 
            {
            command("say �v���`���ѼS�P�k�i�¤ѱ����H..�C");
            command("say �p�j�L������, �N�Фj�L�@�[!");
	    obj->set_temp("meet_eagle",i+1);
	    call_out("meet_eagle",3,me);
	    }
	     else {
              command("say �u�i���b�U�L�H���� ..�Ш��b�U�@��!");
	      command("bow");
              obj->delete_temp("meet_eagle");
            }
            break;
          case 5:
            message_vision(YEL"���M�y�N�ѼS�P�k���򥻤߳Z���ѵ�$Nť.\n"NOR,me);
            message_vision(HIY"(~~~~~�@~~~~~��~~~~~��~~~~~��~~~~~�L~~~~~�h~~~~~�F~~~~~)\n"NOR,me);      
	    message_vision(HIY"���M�y���D:�j�L�G�M�O�_�H, �o�ѼS�P�k����p���֪��⮩!!\n"NOR,me);
	    command("smile");
            me->set_skill("sky-dagger",5);
            obj->delete_temp("meet_eagle");
            break;
            }
}