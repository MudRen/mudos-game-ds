#include <ansi.h>
inherit NPC;
void looking_for_help();
void create()
{
        set_name("�p�k��" , ({ "litte girl" , "girl"}) );
        set("level",1); 
        set("race","human");
        set("gender","�k��");
        set("age",5+random(5));
        set("no_fight",1); 
        set("max_hp",10000);      
        set("long","�b�A���e���O�@�Ӧ~�����p�k�ġA�ݨӦo�O�b�o�̰g�F���F�A��\n" 
                   "�o�W�ê��ˤl�A�A���g�Q�n�����o�E\n");
        set("chat_msg", ({
           (: command("help!") :),
           (: command("cry") :),
        })); 
        set("chat_chance_combat",3000);
        set("chat_msg_combat",({
           (: looking_for_help :),
        }));  
        set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
        setup();
}

void init()
{ 
  object ob1; 

  object ob=this_object(); 
  object me=this_player();      
  object inv=environment(ob);
  if(inv->query("short") == HIY"����"BLK"��"NOR"�`�B")
  {
    call_out("stupid",1,ob); 
    set_temp("stupid",1);  }
 
  if ( me->query_temp("can_k")){
  set("long","�b�A���e���O�@�Ӧ~�����p�k�ġA�ݨӦo�O�b�o�̰g�F���F�E��\n" 
             "�L�o���W���G�@�v���ˡA�ӥB�A�]��P����q�o���W�Ҵ��o�X��\n"
             "�H�H����A�������o�N�O�E�����ƨ��E\n");  
  set("no_fight",0);
  }
  add_action("do_no_ask","ask"); 
}
int do_no_ask()
{
  write("�Х� say <��ͪ��覡> �Ө��o�һݱ����C\n");
  return 1;
}
void stupid()
{
      int i;
      object me,obj,ob1;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("stupid");
      switch( i ) {
          case 1:
            command("hehe"); 
            command("grin");
            obj->set_temp("stupid",i+1);
            call_out("stupid",1,me);
            break;
          case 2:
            set_name( HIW"�E"HIY"��"NOR, ({ "killer fox" , "fox"}) );     
            set("title",HIR"���H��");
            command("say �S�F��@�ӧb�ʤF..�ݨӤ��ѯu�O��ì���ְڡI");
            obj->set_temp("stupid",i+1); 
            call_out("stupid",1,me);
            break;
          case 3:
            message_vision(HIB"����$N�i�}�j�f�n��$n�Y�U�h���P�ɡE�E�E\n"NOR,obj,me);
            obj->set_temp("stupid",i+1);
            call_out("stupid",1,me);
            break;
          case 4: 
            message_vision(HIW"$N���U�@�����γ̧֪��t�װk�}�o�̡I�I\n"NOR,me); 
            tell_object(me,HIR"�A�b�k�R���L�{�٬O���F���p����\n");
            tell_object(me,HIY"�A�U�w�M�ߤ@�w�٭n�A�h���F��������");
            me->set_temp("can_k",1);
            me->set_temp("can_enter",1);
            me->set("hp",10);
            me->move("/open/world1/whoami/birdarea/village1"); 
            "/open/world1/whoami/birdarea/fox18.c"->delete("exits/enter");
            ob1=new(__DIR__"qgirl");
            ob1->move("/open/world1/whoami/birdarea/fox18");
            destruct(obj);
            obj->delete_temp("stupid");
            break;
          }
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"�g��") != -1)
  {
    command("cry " + this_player()->query("id"));
    command("say ��r..�ڰg���F..�A�i�H�a�ڦ^�a�ܡH");  
    command("@@");
  }
  if(strsrch(str,"�i") != -1)
  {
    command("flip " + this_player()->query("id"));
    command("follow " + this_player()->query("id"));
    command("say ���ڭ̨��a�I�ڮa�N�b�e�������B�I"); 
 "/open/world1/whoami/birdarea/fox18.c"->add("exits", 
([ "enter" : "/open/world1/whoami/birdarea/fox20.c"]));
  }
  return;
}

void looking_for_help()
{ 
    object me=this_object();
    object inv=environment(me);
    message_vision("$N"HIW"��o���ݱ��S�A�@�ȷϴN�����F�I\n"NOR,me,this_player());
    new(__DIR__"spider")->move(inv);
    new(__DIR__"qgirl1")->move("/open/world1/whoami/birdarea/fox19");
message_vision("��M���@��"HIR"����"MAG"�j��"NOR"�X�{�b�A�����e�A�צ�A���h���I\n"NOR,
this_player()); 
    destruct(me);
    return;
}

