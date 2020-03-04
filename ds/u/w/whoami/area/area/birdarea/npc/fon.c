#include <ansi.h>
inherit NPC;
void create()
{
 set_name("���W��",({"shin-do-fon","fon"}));
 set("long",@LONG
���H��������, �C������, �Y�v�ܪ�, �L���٦׵���,
�������o�Xģ��������, �N�����N�@��, �@�ݴN���D��
�H���\����, �H�٤ѱ��T�t���@, �S�� [ ��p�� ] �]
���L�����\�i�H��O��F���G��ޤF, ���H�O�ѱ��и�
�M�𻴥\������A�L�D�`���w�������Y�C
LONG);
 set("attitude","peaceful"); 
 set("age",42);
 set("gender","�k��");
 set("level",38+random(10));
 set("title",HIC"�ѱ��T�t"NOR);
 set("class1","�ѱ���");
 set("MKS",60000); 
 set("dex",100+random(50));
 set("ap",50000); set_skill("dagger",70);
 set_skill("dodge",100);
 set_skill("bird-eight",100);
 set_skill("force",60);
 set_skill("parry",60);
 set_skill("sky-dagger",70);
 map_skill("dagger","sky-dagger");
 map_skill("dodge","bird-eight");
 set("guild_gifts",({6,4,0,10}));
 set("guild_skills",([
     "bird-eight" : ({ 140,3,80 }),
 ]));
 set("chat_chance",9);
 set("chat_msg", ({  (: command("say ����ڲ��ͪ����@���M����p�@�H�v�H")  :),
                     (: command("say �N�u�t���@�ӤF...")                   :),
                     (: command("sigh")                                    :),
 }));
 set("chat_chance_combat",80);
 set("chat_msg_combat",({(:command,"exert sky-dagger":),
                         (:command,"say �p�l�I�I�A���n�R�F�I�I�h���a�I�I ":),
 }));
 set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
 setup();
 carry_object(__DIR__"eq/dagger3")->wield();
 carry_object(__DIR__"eq/cloth2")->wear();
 carry_object(__DIR__"eq/boots2")->wear();
 carry_object(__DIR__"eq/surcoat")->wear();
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
   add_action("do_skill_list","list");
   add_action("do_skill_train","train");
}
void greeting(object ob)
{
 object me = this_player();
 if ( !me || environment(me) != environment() ) return; 
 if ( me->query("class1") == "�ѱ���" && me->query_skill("bird-eight") >= 100){
   command("tsk " + me->query("id"));
   command("say �S���@�Ӹ�ڤ@�˱j���H�X�{�F�ڡI");
   command("bow " + me->query("id"));
   } 
   if ( me->query("class1") == "�ѱ���" 
        &&  me->query_skill("bird-eight") < 100 &&  me->query_skill("bird-eight") >= 1 ){   command("say �m�\\�m���p��ڡH");
   command("smile");
   } 
   if ( me->query("class1") == "�ѱ���" &&  me->query_skill("bird-eight") == 0){
command("say �A�p�G���ڧ��ڭn�����Y�A�ڷ|���A�ܦn�����S��I");

command("grin "+ me->query("id") );   
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
  if(strsrch(str,"���m��") != -1)
  { 
    command("hmm"); 
    command("say �������m�ۥ��O�ڷQ�䪺���Y.."); 
  }  
  if(strsrch(str,"���Y") != -1)
  { 
    command("hmm"); 
    command("say �ڭn�䪺�O���m��..���N�O�ڰߤ@�ʤ֪��@�����Y�I"); 
  }  
  if(strsrch(str,"���\\") != -1)
  {  
    command("say �ڴN�O�ѱ��и̻��\\�̱j���H�I");  
    command("wahaha"); 
  }  
return;
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if( ob->query("id") != "five color stone" )
{
           command("pig "+who->query("id"));
           command("say �A���ڳo�ӬOԣ��....-.-");
           return 0;
}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
             return 0;
           }
             message_vision("$N���F���W���@�� "+ob->query("name")+"�C\n",who);
             command("think");
             obj->start_busy(10);
             obj->set_temp("givehat",1);
             destruct(ob);
             call_out("givehat",1,who);
             return 1;
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
            say(HIY"���W���Τ⻴����Ĳ�N�o�����Y�C\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 2:
            command("say �N�O�o��....�u�O���§A�F�A�o��" + RANK_D->query_respect(me) + "�C");
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            break;
          case 3:
            say(HIY"���W���p�ߪ��⤭�m�۵����_�ӡC\n"NOR);
            command("jump");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 4:
            if(me->query("class1") == "�ѱ���" && me->query_skill("bird-eight") == 0)
            {
                 command("say �ѤҬݧA�@��H�~�A�K�ЧA�X�⻴�\\�A��O����§�n�F�C");
                 obj->set_temp("givehat",i+1);
                 call_out("givehat",3,me);
            }
            else {
                 command("say �u�i��....");
                 command("sigh");
                 command("say �ڷ|���j�a�����D�A�����U�L��");
                 command("bow");
                 switch( random(3) ){
                 case 0..1:
                 me->add("exp",5000);
                 tell_object(me,HIW"(�]���A���U�F�D�W���A�ҥH�o��F 5000 �I�g��ȡC)\n"NOR);
                 break;
                 default: 
                 me->add("popularity",2);
                 tell_object(me,HIW"(�]���A���U�F���W���A�ҥH�o��F 2 �I�n��C)"NOR);
                 break;
                 }                 obj->delete_temp("givehat");
                 }
            break;
          case 5:
            say(HIG"�u�����W���@��b�󤤸��D���R�A�@������۫l�D�B�ۦ��C\n"NOR);
            message_vision(" ( $N�c�c���O�U�Ҧ����ۦ� )\n",me);
            me->set_skill("bird-eight",10);
            obj->set_temp("givehat",i+1);
            call_out("givehat",5,me);
            break;
          case 6:
            command("say �n�F�n�F�A�A�ۤv�h�m�ߧa..");
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            obj->delete_temp("givehat");
            break;
          }
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( ob ) message("world:world1:vision", HIW"\n  
�Z�L�ǥX�F�@�h��H������:"HIC"\n\n\t�ѱ��T�t���@�� ���W�����M�ѵ��F"NOR+ob->name(1)+"�C\n\n"+NOR,users());
        ob->add("popularity",2);
        tell_object(ob,HIW"(�]���A�����F���W���A�ҥH�o��F 2 �I�n��C)"NOR);
        ::die();
        return;
}

