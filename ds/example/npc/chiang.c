#include <ansi.h>
inherit NPC;
void create()
{
 set_name("���M�y",({"chiang chin liu","chiang","chin","liu"}));
 set("long","�L�N�O�L��k���j�̤l----���M�y, ���٤Q�U�L��, ���L\n"
            "�A�ݥL�T�ܤ��i��.��M�J��F���j���x��.\n"
     );
 set("attitude","peaceful"); 
 set("age",43);
 set("gender","�k��");
 set("level",25);
 set("title",HIR"�Q�U�L��"NOR);
 set_skill("dagger",90);
 set_skill("sky-dagger",90);
 set("chat_chance",5);
 set("chat_msg", ({"���M�y�ĤF�f����.... \n",
                   "���M�y�Ĥf��:�u�O�@�����N��½�@��H��....\n",
                   "���M�y���ۻ�:�i�O�ڭ̭��̨S�j�L?....\n",
                   "���M�y���M���D:���D�S�^��Ѥѥj��W���N�ޤF?....\n"
}));
setup(); 
carry_object(__DIR__"eq/cloth")->wear();
carry_object(__DIR__"eq/sob_dagger")->wield();
}

void meet_eagle()
{
      int i;
      object me,obj,p;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("meet_eagle");
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
            call_out("meet_eagle"t",3,me);
            break;
          case 4:
            if(me->query_skill("sky-dagger") == 0) 

            {
              command("say �v���`��: �o�M�P�k�i�ǥi���񳾤��H...");
              command("say �p�j�L������,�N�Фj�L�@�[!.");
              obj->delete_temp("meet_eagle");
            }
            else {
              command("say �u�i���b�U�L�H����...�Ш��b�U�@��.");
	      command("bow");
              obj->set_temp("meet_eagle",i+1);
              call_out("meet_eagle",2,me);
            }
            break;
          case 5:
            message_vision(YEL"���M�y�N�ѼS�P�k���򥻤߳Z���ѵ�$Nť.\n"NOR,me);
            message_vision(HIY"(~~~~~�@~~~~~��~~~~~��~~~~~��~~~~~�L~~~~~�h~~~~~�F~~~~~)\n"NOR,me);
	    message_vision(HIY"���M�y���D:�j�L�G�O�_�H, �o�ѼS�P�k����p���֪��⮩!!\n"NOR,me);

            command("cong"+me->query("id"));
	    command("smile");
            me->set_skill("sky-dagger",5);
            obj->delete_temp("meet_eagle");
            break;
      }
}