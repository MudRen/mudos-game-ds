#include <ansi.h>
inherit NPC;
void create()
{
 set_name("���A",({"chiu gin","chiu","gin"}));  
 set("long","�o�O�b�y�������i�H����W�B�����Ѥ~´���֤k�C�o�@��������\n"
            "�ä��O�̦n������A���L�n���S����H�@�N�īH�o���ܴN�O�F..\n");
 set("age",17);
 set("gender","�k��");
 set("level",7);
 set("nickname","´���֤k");
 set("title",HIR"�y����"NOR);
 set("no_fight",1);
 set("chat_chance",10); 
 set("chat_msg", ({
                   YEL"���A���ۻ��D:���S���H�۫H��....\n"NOR,
                   (:command("cry"):),
                   (:command("sob"):),
 }));

 set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
 setup();
}

void init()
{
   object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
  add_action("do_no_ask","ask");
}

void greeting(object ob)
{
 object me = this_player();
 if ( !me || environment(me) != environment() ) return; 
 if ( me->query_temp("ko_crocodile") >= 1  && !objectp( ob = present("crocodile fur" , me))){
    command("say �p�G�A���A���W�����i�s�����ֵ��ڡA�ڴN´�@��˳Ƶ��A�I");
    command("bow "+ me->query("id") );   
    } else {    command("say �p�G�A�����ڮ���@�i�s�����֡A�ڴN´�@��˳Ƶ��A�I");
    command("addoil "+ me->query("id") );   
    }
}

int do_no_ask()
{
  write("�Х� say <��ͪ��覡> �Ө��o�һݱ����C\n");
  return 1;
}
void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"����") != -1)
  { 
    command("nod "+this_player()->query("id")); 
    command("say ���ְ��X�Ӫ����㵴�藍�O�̦n���I");
    command("say �ڻ{��������̦n�٬O�n���s���֨Ӱ�..");
  }   
  if(strsrch(str,"�s����") != -1)
  { 
    command("hmm "+this_player()->query("id")); 
    command("say �s���ַ�M�n�q�s�����W���աI");
    command("say �ܩ��s���n�h����..�ڴN�����D�F..");
  }  

return;
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "crocodile fur")
        {
           command("say ���O�o��....");
           return 0;
} 
if( query_temp("no_give") )
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
             message_vision("$N���F���A�@�i "+ob->query("name")+"�C\n",who);
             command("bow");
             obj->set_temp("no_give",1);
             obj->set_temp("givefur",1);
             destruct(ob);
             call_out("givefur",1,who);
return 1;
        }
}
void givefur()
{
      int i;
      object me,obj,fur;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givefur");
      if( !me || environment(me) != environment(obj) )
        {
                command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"���A�@�F�@�o�i�s���֡C\n"NOR);
            obj->set_temp("givefur",i+1);
            call_out("givefur",3,me);
            break;
          case 2:
            command("say �o�i�s���֬O�W�W����, �i�H´�X�ܦn���F��ӡC");
            command("smile");
            obj->set_temp("givefur",i+1);
            call_out("givefur",2,me);
            break;
          case 3:
            say(HIY"���A����и�, ���̶ǥX´�������B���n�C\n"NOR);
            obj->set_temp("givefur",i+1);
            call_out("givefur",3,me);
            break;
          case 4:
            say(HIY"�L�F�@�|���A�q�и̨��X, ��W���ۤ@���@��C\n"NOR);
            obj->set_temp("givefur",i+1);
            call_out("givefur",3,me);
            break;
          case 5:
            command("say �ڥΤ@�������s���ְ��X�F�@���@��, �N��O���A������§�a�C");
            obj->set_temp("givefur",i+1);
            call_out("givefur",3,me);
            break;
          case 6:
            fur=new(__DIR__"obj/hands");
            fur->move(obj);
            command("give hands to "+ me->query("id") );
            obj->delete_temp("givefur");
            obj->delete_temp("no_give");
            break;
             
          }
}

