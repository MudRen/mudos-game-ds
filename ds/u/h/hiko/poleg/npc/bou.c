#include <ansi.h>
inherit NPC;
void create()
{
 set_name("���y",({"bou-a","bou"}));
 set("long","�L�O�y�������s�@�����s��,�Q������..���̤H���Z�R��L���ܪ��]�N\n"
            "�]�����̤j�j�p�p���ƥL���ٺ�M���A�����D�ӥi�H��L�ͽ�(talk)\n");
 set("age",26);
 set("gender","�k��");
 set("level",30);
 set("title",HIG"�s�⺮��"NOR);
 set_skill("combat",100);
 set("chat_chance",20);
 set("chat_msg", ({"���y���D: �̪�u�O..���|�o�ͳo�بƩO...\n",
                   "���y��仡��:���y�F��z�]�����D�]���h�F...\n",
                   (:command("sigh"):),
 }));
        set("chat_chance_combat",20);

 set("chat_msg_combat",({"���y�j�s�D:�O����!...�ڤ��򳣻��F..."}));
 set("inquiry/����","�����O���[�e�~�W�����A�̪񤣪������I�ǩǪ�...
     ���G��H�e���y���̡z����\n"NOR); set("inquiry/���|�Y��","�N�O�ڭ̺��|�D�Ƨr!��b���̼s���_����...\n"NOR);
 set("inquiry/����","ť���̪�y�����z�M�y���|�Y�ءz�]���Y�ƾx���ܤ��r��? �쩳�O���]�S�H���D..\n"NOR);
 set("inquiry/����","ť�����g�h�~�e���Ӥ��@�����b���a�A���L�{�b�]�����h�V�F\n"NOR);
 set("inquiry/����","���ǥi�c���å�O�b�����W���ᤣ�[�X�{���A�]�����D���Ӫ��A
    ���������|�Y�ئb..\n"NOR);
 set("inquiry/�F��","���F��..�N�O�ڪ�����A�r...�W���h���䪱�ɳQ��������R����F..�Y�A����
    �ڧ��ڴN��A���ӯ��K..\n"NOR);
 setup();
}

int talk_action(object me)        
{
  object ob;      
  ob = this_player();        
      if(random(2))       { 
        command("say �̪�y�����]���@�ǡy����z�x���Q�����r��");
        command("say �ӥB�S�o�͡y����z�X�{����!�u�O�O�H�P���Y�h");
        command("say �]�����D���֯�������������A�u�O�h�ƪ��@�~"); 
       }
       return 1;
}

int accept_object(object who,object ob)
{
        object obj,me;
        me=this_player();
        obj=this_object();
if(ob->name()!="����A")
    {
           command("say �o���O�ڭn���F��A�Ю��^�h�a");
           return 0;
    }
        
  else {  
     if(obj->is_busy() || obj->is_fighting())
            {
             command("whisper "+who->query("id")+" �ЧA���@�U�C");
             return 0;
             }
            message_vision("$N���F���y�@��"+ob->query("name")+"�C\n",who);
             command("say �ڴN��A���F�A�p�G�A�b�������e���_���|�Y��(say)");
             command("say �����N�|�ܪ��ǩǪ���");
             me->set_temp("knowhate",1);
             destruct(ob);
             return 1;
              
       }
}






