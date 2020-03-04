#include <path.h>
#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�����L��",({"vagabond",}));
 set("long",@LONG
�@�ӳB�B�i���������L��, ���L���Y���ت��ˤl���A�ݤF��
��Q��.
LONG
    );
 set("attitude", "peaceful");
 set("age",41);
 set("gender","�k��");
 set("level",20);
 set("chat_chance",10);

set("chat_msg", ({"�����L�����C�n���D:���ѧ�L���Y�� "+HIY+"�_��"+NOR+" ���N��!!. \n",
                          "�����L��o�{�A�b�ݥL, �c�������§A���F�@��.. \n",
}));
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"../eq/cloth")->wear();
 carry_object(__DIR__"../wp/longsword")->wield();
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->query("id") == "gold tackle")
        {
                if(obj->is_busy() )
                {
                        command("whisper "+who->query("id")+" �Ѥl�S��, �t��l���@�U�C\n");
                        return 0;
                }
                message_vision("$N���F�����L��@�� "+ob->query("name")+"�C\n",who);
                command("hehe");
                obj->start_busy(10);
                obj->set_temp("give_tackle",1);
                destruct(ob);
                call_out("give_tackle",1,obj);
                return 1;
        }
}

void give_tackle()
{
      int i;
      object me,obj,thing;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("give_tackle");
      if( !me || environment(me) != environment(obj) )
        {
                command("say �x�H�t��l�H�O�H�H");
                return;
        }
      switch( i ) {
          case 1:
            say(CYN"�����L���ۤ⤤����������, �o�N�����F��...\n"NOR);
            obj->set_temp("give_tackle",i+1);
            call_out("give_tackle",2,me);
            break;
          case 2:
            command(CYN"say ��...�t��l�A���@��.."NOR);
            obj->set_temp("give_tackle",i+1);
            call_out("give_tackle",2,me);
            break;
          case 3:
            say(CYN"�����L��ݵ۪�������, �f�������D: �ª����O....�C\n"NOR);
            obj->set_temp("give_tackle",i+1);
            call_out("give_tackle",3,me);
            break;
          case 4:
            message_vision(CYN"$N��$n���D: �S�̪G�M��²��, �W���Ѥj���F�ڤ@�����O...\n"NOR, this_object(), me);
            obj->set_temp("give_tackle",i+1);
            call_out("give_tackle",2,me);
            break;
          case 5:
            command("say �]�����D�O�Fԣ�Ҥ��l��, �N�e���A�������a....:Q");
            obj->set_temp("give_tackle",i+1);
            call_out("give_tackle",2,me);
            break;
          case 6:
            thing=new(PAST"obj/mark");
            thing->move(obj);
            command("give mark to "+ me->query("id") );
            obj->delete_temp("give_tackle");
            break;
          }
}

void init()
{
       add_action("typeask","ask");
}
int typeask(string arg)
{
        object me;
        me=this_player();
        if( arg != "vagabond about �_��" ) return 0;
        if( me ->query("evil") >= 0 )
        {
                message_vision("�����L���$N��: �ݨӫ��̤]�O�P�D...\n\n",me);
                message_vision("�����L���$N��: �N��A���F�a!!.\n\n",me);
                message_vision("�����L���$N��: �L���Y�a�̤��O���˫G�G���F���?ť�����i�ȤW�U�e�O!!\n\n",me);
                message_vision("�����L���$N��: �u�n�S�̥i�H���ӵ���, �֤��F�A���n�B�� !!\n\n",me);
        }
        else message_vision("�����L�ण�h����F�@�n, �L�̳�仡�D: �N�O�Q���A�̳o�إ��H�g�l...\n",me);

        return 1;
}

