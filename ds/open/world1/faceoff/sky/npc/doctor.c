#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�]ˢ",({"meo pun","pun","meo"}));
 set("long",@LONG
�o�O�o�ӭ]�a���̦����N���H�A�b���Ĥ譱�o������A�i�H���w���Ĥ����a�B�F�I
�ӥB�H�S�~���G�R�A�]�a�����l�D�̤��b�ּơA���O�̪�o���F�@��Ʊ��T�ܤ��i
�A�쩳�O......?
LONG
    );
 set("attitude", "peaceful");
 set("age",21);
 set("nickname",HIY"���Ľ�"NOR);
 set("evil",-10);
 set("gender","�k��");
 set("level",20);
set("str",100);
set("con",100);
 set_skill("sword", 100);
 set("chat_chance",40);
 set("chat_msg", ({"�]ˢ�������ĤF�@�f��A�d���A���g�N��....\n", 
        }) );
 set("inquiry/�ħ�","�n����]�ڪ����f���ݭn:����@�ĤޡA���ͯ�,�M�ߥۺ�G�@�Ĩ�A�̫�ӭn�Φʪ��C�ӧ@����....��....\n"NOR);

 setup();
}

int talk_action(object me)        
{
 object book;
 if(!book=me->query_temp("notebook")) return 0;
 if(random(2))
 {
         command("sigh");
        command("say ���A�s�]�ڪ����J�e���L�k�����A�ھ���S�������....�C");
        command("say �����]�ڪ��ҭn���y�ħ��z�ӯS��A�s�ګ��h��.....");
  }
 return 1;
}

int accept_object(object who,object ob)
{
                object obj,item;
                obj=this_object();
                if(ob->name()=="���ͯ�")
                {
if(obj->is_busy() || obj->is_fighting())
                 {
                 command("whisper "+who->query("id")+" �ЧA���@�U�C");
                 return 1;
                }
      if (obj->query_temp("find_wine") == 1 && obj->query_temp("find_fruit") == 1 && obj->query_temp("find_sand") == 1 )
      {
       message_vision("�]ˢ���������$N�j��: ���F!���F!�C\n",who);
       message_vision("�]ˢ�ਭ�i�J�Ҥ���,�L�F���褧��,�]ˢ���������F�^��.\n",who);
       message_vision("�]ˢ���$N��:�нЧA�N���ıa���]�ڪ���~!\n",who);
      message_vision(HIC"�]ˢ���F$N�@�ɤ���\n"NOR,who);
item=new(__DIR__"obj/pill");
            item->move(who);
obj->delete_temp("find_grass");
    obj->delete_temp("find_wine");
    obj->delete_temp("find_fruit");
    obj->delete_temp("find_sand");

      }

      if (obj->query_temp("find_grass") == 0)
    {
        message_vision("$N���F�]ˢ�@��"+ob->query("name")+"�C\n",who);
                 command("jump "+who->query("id"));
                 command("kiss "+who->query("id"));
                 command("say �o�˴N�u�ʨ䥦���ħ��F....");
             obj->set_temp("find_grass",1);
             destruct(ob);
             return 1;
   }
      else
     {
  message_vision("$N���F�]ˢ�@��"+ob->query("name")+"�C\n",who);
      command("pig "+who->query("id"));
                 command("hmm "+who->query("id"));
                 command("say �o���ħ��ڤw�g���F...���Y��~");
             return 1;
                }

                }

  if(ob->name()=="���F")
                {
if(obj->is_busy() || obj->is_fighting())
                 {
                 command("whisper "+who->query("id")+" �ЧA���@�U�C");
                 return 1;
                }
      if (obj->query_temp("find_wine") == 1 && obj->query_temp("find_fruit") == 1 && obj->query_temp("find_grass") == 1 )
      {
       message_vision("�]ˢ���������$N�j��: ���F!���F!�C\n",who);
       message_vision("�]ˢ�ਭ�i�J�Ҥ���,�L�F���褧��,�]ˢ���������F�^��.\n",who);
       message_vision("�]ˢ���$N��:�нЧA�N���ıa���]�ڪ���~!\n",who);
      message_vision(HIC"�]ˢ���F$N�@�ɤ���\n"NOR,who);
item=new(__DIR__"obj/pill");
            item->move(who);
obj->delete_temp("find_grass");
    obj->delete_temp("find_wine");
    obj->delete_temp("find_fruit");
    obj->delete_temp("find_sand");
      }
      if (obj->query_temp("find_sand") == 0)
    {
        message_vision("$N���F�]ˢ�@��"+ob->query("name")+"�C\n",who);
                 command("jump "+who->query("id"));
                 command("kiss "+who->query("id"));
                 command("say �o�˴N�u�ʨ䥦���ħ��F....");
             obj->set_temp("find_sand",1);
             destruct(ob);
             return 1;
      }
            else
     {
  message_vision("$N���F�]ˢ�@��"+ob->query("name")+"�C\n",who);
      command("pig "+who->query("id"));
                 command("hmm "+who->query("id"));
                 command("say �o���ħ��ڤw�g���F...���Y��~");
             return 1;
                }

                }
  if(ob->name()=="�M�H�ۺ�G")
                {
if(obj->is_busy() || obj->is_fighting())
                 {
                 command("whisper "+who->query("id")+" �ЧA���@�U�C");
                 return 1;
                }
      if (obj->query_temp("find_sand") == 1 && obj->query_temp("find_wine") == 1 && obj->query_temp("find_grass") == 1 )
      {
       message_vision("�]ˢ���������$N�j��: ���F!���F!�C\n",who);
       message_vision("�]ˢ�ਭ�i�J�Ҥ���,�L�F���褧��,�]ˢ���������F�^��.\n",who);
       message_vision("�]ˢ���$N��:�нЧA�N���ıa���]�ڪ���~!\n",who);
      message_vision(HIC"�]ˢ���F$N�@�ɤ���\n"NOR,who);
item=new(__DIR__"obj/pill");
            item->move(who);
obj->delete_temp("find_grass");
    obj->delete_temp("find_wine");
    obj->delete_temp("find_fruit");
    obj->delete_temp("find_sand");
      }
      if (obj->query_temp("find_fruit") == 0)
    {
        message_vision("$N���F�]ˢ�@��"+ob->query("name")+"�C\n",who);
                 command("jump "+who->query("id"));
                 command("kiss "+who->query("id"));
                 command("say �o�˴N�u�ʨ䥦���ħ��F....");
             obj->set_temp("find_fruit",1);
             destruct(ob);
             return 1;
      }
            else
     {
  message_vision("$N���F�]ˢ�@��"+ob->query("name")+"�C\n",who);
      command("pig "+who->query("id"));
                 command("hmm "+who->query("id"));
                 command("say �o���ħ��ڤw�g���F...���Y��~");
             return 1;
                }

                }
 if(ob->name()=="�ʪ��C")
                {
if(obj->is_busy() || obj->is_fighting())
                 {
                 command("whisper "+who->query("id")+" �ЧA���@�U�C");
                 return 1;
                }
      if (obj->query_temp("find_sand") == 1 && obj->query_temp("find_fruit") == 1 && obj->query_temp("find_grass") == 1 )
      {
       message_vision("�]ˢ���������$N�j��: ���F!���F!�C\n",who);
       message_vision("�]ˢ�ਭ�i�J�Ҥ���,�L�F���褧��,�]ˢ���������F�^��.\n",who);
       message_vision("�]ˢ���$N��:�нЧA�N���ıa���]�ڪ���~!\n",who);
      message_vision(HIC"�]ˢ���F$N�@�ɤ���\n"NOR,who);
item=new(__DIR__"obj/pill");
            item->move(who);
obj->delete_temp("find_grass");
    obj->delete_temp("find_wine");
    obj->delete_temp("find_fruit");
    obj->delete_temp("find_sand");
      }
      if (obj->query_temp("find_wine") == 0)
    {
        message_vision("$N���F�]ˢ�@��"+ob->query("name")+"�C\n",who);
                 command("jump "+who->query("id"));
                 command("kiss "+who->query("id"));
                 command("say �o�˴N�u�ʨ䥦���ħ��F....");
             obj->set_temp("find_wine",1);
             destruct(ob);
             return 1;
      }
      else
     {
  message_vision("$N���F�]ˢ�@��"+ob->query("name")+"�C\n",who);
      command("pig "+who->query("id"));
                 command("hmm "+who->query("id"));
                 command("say �o���ħ��ڤw�g���F...���Y��~");
             return 1;
                }

                }
}
