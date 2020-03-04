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
 set("attitude","peaceful"); 
 set("title",HIY"�Q�L"NOR);
 set("age",51);
 set("gender","�k��");
 set("level",39);
 set_skill("blade",100);
 set_skill("sea-blade",100);
 map_skill("blade","sea-blade");
 set_skill("force",60);
 set_skill("combat",70);
set("chat_msg_combat", ({
                  (:command("exert sea-blade"):),
        }) );

set("inquiry/���Q","�N�O���b���F�q�e�������ӽ��Y��! ���L�L���|�����P�H�ʤ�, �@�w�n���E��L...!\n"NOR);

set("talk_reply","���f�դU..���Q���V�b�Q��a�F�ƤQ�өx�L�N�ڥS�̤Q�h�H���F�Ӱ��b, �����ڤS�t��, �o�V�b�w������....\n"NOR);
 setup();
 carry_object(__DIR__"eq/dragon_blade")->wield();
 carry_object(__DIR__"eq/viper_cloth")->wear();
 carry_object(__DIR__"eq/water_boots")->wear();
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
        message("world:world1:vision",
CYN"\n  [�L��p��] :\n\n\t�Q�L �E�� �Q"+ob->name(1)+"�������F�C\n\n"+NOR
        ,users());
        ob->add("popularity",1); //�n��
       tell_object(ob,HIW"(�]���A�����F�E�ɡA�ҥH�o��F 1 �I�n��C)"NOR);
        ::die();
        //destruct(this_object());
        return;
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="���Q���x�L")
        {
           command("? "+who->query("id"));
           return 0;
        }
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ЧA���@�U�C");
             return 0;
          }
	message_vision("$N���F�E�ɤ@��"+ob->query("name")+"�C\n",who);
             obj->start_busy(10);
             obj->set_temp("kill_wang",1);
             destruct(ob);
             call_out("kill_wang",1,obj);
             return 1;
        }

}

void kill_wang()
{
      int i;
      object me,obj,item;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("kill_wang");
      switch( i ) {
          case 1:
            command("say ��! �o���O���Ӫ��骺�x�L��?");
            command("say �o��"+RANK_D->query_respect(me)+"�O�q��o���x�L���H");
            obj->set_temp("kill_wang",i+1);
            call_out("kill_wang",3,me);
            break;
          case 2:
            message_vision(YEL"$N�N���o�x�L���L�{�i�D�E��...�C\n"NOR,me);
            obj->set_temp("kill_wang",i+1);
            call_out("kill_wang",3,me);
            break;
          case 3:
	    command("nod");
            command("say ��������....������]�⦳�F����....�C");
            command("smile");
            obj->set_temp("kill_wang",i+1);
            call_out("kill_wang",3,me);
            break;
          case 4:
	    if(me->query_skill("blade") > 30 && me->query_skill("sea-blade") == 0) 
            {
            command("say �ݨӥS�̮ڰ򤣿�....�C");
            command("say �b�U�@�M�ɮ��M�Z��O���@�S��, �p���»P�դU, ����W�]�S�ܦn���F�}?");
	    obj->set_temp("kill_wang",i+1);
	    call_out("kill_wang",3,me);
	    }

	     else {
        command("say �u�i���S�̤��A�X�A�m�ɮ��M�Z...");
          command("say �Ш��Y�a�@��!");
          command("bow");
          command("say �b�U���~�b����W����, ���M�o��@�Ӥp���N��, �o�U�N�e���F�դU�a!");
          item=new(__DIR__"eq/sea-blade");
            item->move(obj);
            command("give blade to "+ me->query("id") );
              obj->delete_temp("kill_wang");
            }
            break;
          case 5:
            message_vision(YEL"�E�ɱN�ɮ��M�Z���|�M�ܤƲӲ�����$Nť.\n"NOR,me);
            message_vision(YEL"$N�b�E�ɪ������U�ޤM�t�m....\n"NOR,me);      
          message_vision(YEL"�E�ɻ��D:�t���h�F...�t���h�F.....\n"NOR,me);
         message_vision(YEL"(�g�L�@�f�W�m, $N�m���F�ɮ��M�Z) .\n"NOR,me);
         command("smile");
            me->set_skill("sea-blade",4);
            obj->delete_temp("kill_wang");
            break;
            }
}

