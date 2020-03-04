#include <ansi.h>
inherit NPC;
void create()
{
 set_name("���W��",({"shin-do-fon","fon"}));
 set("long","���H��������, �C������, �Y�v�ܪ�, �L���٦׵���,
�������o�Xģ��������, �N�����N�@��, �@�ݴN���D��
�H���\\����, �H�٤ѱ��T�t���@, �S�� [ �Φp�� ] �]
���L�����\\�i\�H��O��F���G��ޤF, ���H�O�ѱ��и�
�M�𻴥\\������A�L�D�`���w�������Y�C\n" );
 set("attitude","peaceful"); 
 set("age",42);
 set("gender","�k��");
 set("level",38);
 set("title",HIC"�ѱ��T�t"NOR);
 set_skill("dagger",70);
 set_skill("dodge",100);
 set_skill("bird-eight",100);
 set_skill("force",60);
 set_skill("parry",60);
 set_skill("sky-dagger",70);
 map_skill("dagger","sky-dagger");
 map_skill("dodge","bird-eight");
 set("guild_gifts",({6,4,0,10}));
 set("chat_chance",10);
 set("chat_msg", ({"���W���Į𻡹D:����ڲ��ͪ����@���M����p�@�H�v?\n",
                   "���W���Į𻡹D:�N�u�t���@�ӤF�C\n",
                   (:command("sigh"):),
 }));
 set("chat_chance_combat",200);
 set("chat_msg_combat",({(:command,"exert sky-dagger":),
                         (:command,"say �p�l!!�A���n�R�F!!�h���a!! ":),
 }));
 set("talk_reply","�A�����ڤ@�I��(help)��?\n");
 set("inquiry/help","�ЧA���ڧ�줭�m�ۡA���O�کҨS�������@�@�����Y�C\n");
 setup();
 carry_object(__DIR__"eq/dagger3")->wield();
 carry_object(__DIR__"eq/cloth2")->wear();
 carry_object(__DIR__"eq/boots2")->wear();
 carry_object(__DIR__"eq/surcoat")->wear();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->query("id") != "five-color-stone")
        {
           command("slap "+who->query("id"));
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
            say(HIY"���W���Τ⻴�M��Ĳ�N�o�����Y�C\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 2:
            command("say �N�O�o��....�����§A�F�p�S�̡C");
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
            command("say �ѤҬݧA�@��H�~�A�K�ЧA�X��\��\�\\�A��O����§�n�F�C");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 5:
            say(HIG"�u�����W���@��b�󤤸��D���R�A�@������۫l�D�B�ۦ��C\n"NOR);
            message_vision(" ( $N�c�c���O�U�Ҧ����ۦ� )\n",me);
              if(me->query_skill("bird-eight") == 0 || me->query("class1") == "�ѱ���")
               {
                me->set_skill("bird-eight",10);
                     }
	      else 
               {
                say(HIG"���]�\�O�A�̽t������..�A�����L�k�⮩....�C\n"NOR);
		     }
            obj->set_temp("givehat",i+1);
            call_out("givehat",5,me);
            break;
          case 6:
            command("say �n�F�n�F�A�A�ۤv�h�m�ߧa....:D");
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
        if( ob ) message("world:world1:vision", HIW"\n  �Z�L�ǥX�F�@�h��H������:"HIC"\n\n\t�ѱ��T�t���@�� ���W�����M�ѵ��F"+ob->name(1)+"�C\n\n"+NOR,users());
        ob->add("popularity",1);
        ::die();
        return;
}


