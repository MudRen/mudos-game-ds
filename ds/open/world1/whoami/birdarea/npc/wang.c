#include <ansi.h>
inherit NPC;
void create()
{
 set_name("���W",({"wang-lou","wang","lou"}));
 set("long","�L�O�b�o���l���Y�������W��´�֤H�A�ڻ��u�n�O�L´�X�Ӫ��F\n"
            "��A���O���~��O�Ҫ��E\n");
 set("age",43);
 set("gender","�k��");
 set("level",20);
 set("nickname",HIY"´�ְ���"NOR);
 set("title",HIR"�y����"NOR);
 set("no_fight",1);
 set("chat_chance",20);
 set("chat_msg", ({ YEL"���W���_�⤤�����֭��n�ĤF�@�f��.\n"NOR ,
                   (:command("sigh"):),
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
 if ( me->query_temp("ko_fox_nine") >= 1  && objectp( ob = present("fox fur" , me) ) ){
    command("say �p�G�A���A���W�����i�E�����ֵ��ڡA�ڴN´�@��˳Ƶ��A�I");
    command("bow "+ me->query("id") );   
    } else {
    command("say �p�G�A�����ڮ���E�����֡A�ڴN´�@��˳Ƶ��A�I");
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
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"���֭��n") != -1)
  { 
    command("hmm " + this_player()->query("id")); 
    command("say �u�n���ڧ�n�����ơA�ڤ@�w�వ�X���Ϊ����n�I");  
    command("sigh"); 
  }  
return;
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
    if(ob->query("id") == "fox fur")
    { 
    if( who->query_temp("ko_fox_nine") && obj->query_temp("no_give") < 1 )
    {
             message_vision("$N���F$n�@"+ob->query("unit")+ob->query("name")+"�C\n",who,obj);
             command("think");
             obj->set_temp("no_give",1);
             obj->set_temp("givehat",1);
             destruct(ob);
             call_out("givehat",1,who);
             return 1;
    } else {
           command("yawn "+who->query("id"));
           command("say �ڤ��n�Ӹ��������F��I");
   }
  write("["+this_object()->name(1)+"��"+ob->name(1)+"�ä��P����]\n");
  return notify_fail("");
       } 
}

void givehat()
{
      int i;
      object me,obj,plate;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givehat");
      if( !me || environment(me) != environment(obj) )
        {
                command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
                return;
        }
      switch( i ) {
          case 1:
            message_vision(HIY"$N�N�F�N�o�i���֡C\n"NOR,obj);
            obj->set_temp("givehat",i+1);
            call_out("givehat",1,me);
            break;
          case 2:
            command("say �N...�N�O�o�i��...�Ӧn�F....");
            obj->set_temp("givehat",i+1);
            call_out("givehat",1,me);
            break;
          case 3:
            message_vision(HIY"$N���_���֦b��l�W�_�_�ӤF�C\n"NOR,obj);
            command("sweat");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 4:
            message_vision(HIY"�L�F�@�|$N��W�K�h�F�@�i���n�C\n"NOR,obj);
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            break;
          case 5:
            command("say �ڧ⨺�i���֪��@�������F�@�i���n, �K�e���A��S�ҧa");
            obj->set_temp("givehat",i+1);
            call_out("givehat",1,me);
            break;
          case 6:
            plate=new(__DIR__"obj/hat");
            plate->move(obj);
            command("give mask to "+ me->query("id") );
            obj->delete_temp("givehat"); 
            break;
          }
          obj->delete_temp("no_give");            
}

