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
 set("level",30);
 set_skill("blade",90);
 set_skill("sea-blade",100);
 map_skill("blade","sea-blade");
 set_skill("force",60);
 set_skill("combat",70);
 setup();
 carry_object(__DIR__"eq/dragon_blade")->wield();
 carry_object(__DIR__"eq/cloth")->wear();
}

void want_kill()
{
      int i;
      object me,obj,p;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("want_kill");
      switch( i ) {
          case 1:
            command("say ���Ӥp�鴱���J���B !!");
            obj->set_temp("want_kill",i+1);
            call_out("want_kill",2,me);
            break;
          case 2:
            message_vision(YEL"�E�ɴc��������V$N�C\n"NOR,me);
            obj->set_temp("want_kill",i+1);
            call_out("want_kill",2,me);
            break;
          case 3:
	    command("say �����p�l�O�x�����Ӫ� ..?!");
            command("say �Ѥl�b�ݧA��, ���D�s�I�Y�n�Y�����| ...?");
            command("hmm");
            obj->set_temp("want_kill",i+1);
            call_out("want_kill",3,me);
            break;
          case 4:
            command("say �p�鴱���O���o���@�ФF !");
	    command("kill "+me->query("id") );
	    obj->delete_temp("want_kill",i+1);
            break;
            }
}
