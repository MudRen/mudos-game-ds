#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�q�۱M�a",({"stone expert","expert"}));
 set("long","�L�O�@��M����s�q�۪��H�C\n");
 set("age",33+random(5));
 set("gender","�k��");
 set("level",20);
 set("no_fight",1);
 set("chat_chance",10);
 set("talk_reply","�p�G�A������q�۪���, �ڥi�H�K�O���A���R��...:D\n");
 set("chat_msg", ({YEL"�q�۱M�a���b�V�O�����q�ۡA�o�X�}��~~~�}��~~~�}��~~~���n�T�C\n"NOR,
                   
 }));
 setup();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object(); 
        if(ob->query("id") != "iron stone")
        {
           command("slap "+who->query("id"));
           command("say �Ӷê��ڡH");
           return 0;
        } else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
             return 0;
           }
             message_vision("$N���F�q�۱M�a�@��"+ob->query("name")+"�C\n",who);
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
      object me,obj,ob,ob1,ob2;
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
            say(HIY"�q�۱M�a�V�F�V�o�ӥ��Y�C\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 2:
            command("say ��....�o���Ӥ��O�K��....");
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            break;
          case 3:
            say(HIY"�q�۱M�a�S�V�F�V�o�����Y�C\n"NOR);
            command("think");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 4:
            say(HIY"�q�۱M�a�n���o�{�F����A�������`�C\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 5:
            switch( random(10) ){
             case 0:
              ob1=new(__DIR__"obj/moon-stone");
              ob1->move(obj);
              message_vision(YEL"$N���G �o�O�@���W�n��"+ob1->query("name")+YEL"�A�i�H���y�������Z���A�ڧ⥦�ٵ��A�a�C\n"NOR,this_object());
              break;
             case 1:
              ob2=new(__DIR__"obj/sun-stone");
              ob2->move(obj);
              message_vision(YEL"$N���G �o�O�@���W�n��"+ob2->query("name")+YEL"�A�i�H���y�������Z���A�ڧ⥦�ٵ��A�a�C\n"NOR,this_object());
              break;
             default:
              ob=new(__DIR__"obj/iron2");
              ob->move(obj); 
              message_vision(YEL"$N���G �o�O�@���W�n��"+ob->query("name")+YEL"�A�i�H���y�������Z���A�ڧ⥦�ٵ��A�a�C\n"NOR,this_object());
              break;
             }
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 6:
            command("give stone to "+ me->query("id") );
            obj->delete_temp("givehat");
            break;
          }
}

