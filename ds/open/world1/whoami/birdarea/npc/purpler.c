#include <ansi.h>
inherit NPC;
void create()
{
 set_name("���L",({"purpler"})); 
 set("long","�o�O�b����W�ǻD�����Ѥk��A�~�������o����D�Z�A�`�`�T�I\n"
            "�ٳh�A�O�h�����j���H�A���I���o����o���o�o���A�Q�P�o��\n"
            "�a�A���{�b�o�o���F����...\n");
 set("age",20);
 set("gender","�k��");
 set("level",20);
 set("title",HIW+BLK"���Ѥk��"NOR);
 set_skill("parry",50);
 set_skill("dodge",100);
 set("chat_chance",20);
 set("max_hp",10000);
 set("hp",1);
 set("chat_msg", ({ 

YEL"���L�C�n���D�G�n�O�ள�쨺"HIW"�F��"NOR+YEL"����....�i�O....�S�ɶ��F....����....\n"NOR,
YEL"���L�C�n���D�G�����D�N���h�������ȿ����F��F...���M�N���|���p���ˤF....\n"NOR,
YEL"���L���ݤf���X�F���\n"NOR,
                   (:command("sigh"):),
                   (:command("walileh"):),
 }));
 set("talk_reply","�ֱϱϧڰڡI�ڻݭn�ͥͳy�Ƥ��ӱϧڪ��R�I\n");
 setup();
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "stream pill")
        {
           command("say ���O�o��....");
           return 0;
}
      else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
             return 0;
           }
             message_vision("$N���F���L�@��"+ob->query("name")+"�C\n",who);
             command("think");
             obj->start_busy(10);
             obj->set_temp("givestone",1);
             destruct(ob);
             call_out("givestone",1,who);
return 1;
        }
}
void givestone()
{
      int i;
      object me,obj,stone;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givestone");
      if( !me || environment(me) != environment(obj) )
        {
                command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"���L�@�F�@�o�ɤ��ġC\n"NOR);
            obj->set_temp("givestone",i+1);
            call_out("givestone",3,me);
            break;
          case 2:
            say(HIY"���L��Ÿ�ݪ��⮳�_�ͥͳy�Ƥ��æY�U�C\n"NOR);
            obj->set_temp("givestone",i+1);
            call_out("givestone",3,me);
            break;
          case 3:
            command("say ����....�ϤF�ڪ��ʩR....");
            command("bow");
            obj->set_temp("givestone",i+1);
            call_out("givestone",2,me);
            break;
          case 4:
            command("say �ڳo���@�Ӱ��Ӫ��_�S���Y, �����󪺸ܴN���h�a");
            obj->set_temp("givestone",i+1);
            call_out("givestone",3,me);
            break;
          case 5:
            command("say �ǻD�n���D�W���ѫe���b��o�ӥ��Y, ���p�A�h��L�ݬݧa");
            obj->set_temp("givestone",i+1);
            call_out("givestone",3,me);
            break;
          case 6:
            stone=new(__DIR__"obj/stone");
            stone->move(obj);
            command("give stone to "+ me->query("id") );
            obj->delete_temp("givestone");
            message_vision("�o�����ܫ�N���}�Ϧ������}�F�C\n",me);
            destruct(obj);
            break;
         }
}

