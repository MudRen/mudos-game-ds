#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�W�u�ѤH",({"oldman"})); 
 set("long","�L�O�@�촿�g�������򪺨k�l�A�۱q�L������Q���a�q�Ӭ��_��\n"
            "�A�K�@�����~�b�o�̡A�����@���K�K�A�L���ڷQ�N�O���y�@�⯫\n"
            "�L�Q���A���O�L�n���ʤ֤F����....\n");
 set("age",72);
 set("gender","�k��");
 set("level",20); 
 set("no_fight",1); 
 set("title",HIW"�W�u�K�K"NOR);
 set("chat_chance",10);
 set("chat_msg", ({YEL"�W�u�ѤH���_�⤤���K��ĤF�@�f��.\n"NOR,
                   (:command("sigh"):),
 }));
 set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
 set("reborn",150);
 setup();
}  

void init()
{
  add_action("do_no_ask","ask");
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
  if(strsrch(str,"���K��") != -1)
  {  
    command("oh");    command("say �A�i�H�h�F�_�A�L���d�h�ϸI�I�B��A���̦����֪��K�ۡE"); 
  }   
  if(strsrch(str,"�ʤ�") != -1)
  {  
    command("hmm "+this_player()->query("id"));
    command("say �ڲ{�b�b���y�����C�A���O�ʤF�إ��Y�A�s�����K�ۡA�u���o�إ��Y�~�ॴ�y�X�����C�C"); 
  }
  if(strsrch(str,"�����K��") != -1)
  {  
    command("say �����K�۬O�ѳ����ۻP���K�ۥΤ��O�ĦX�Ӧ����öQ�_���E"); 
  }  
  if(strsrch(str,"�����C") != -1)
  {  
    command("hehe");
    command("say ����A���ڮ��쳱���K�ۮɡA�A�N�|���D�F�E"); 
  }  
  if(strsrch(str,"������") != -1)
  {  
    command("hmm "+this_player()->query("id"));
    command("say �����ۤS�O�ѳ��۩M���۲զX�Ӧ����_���E");  
    command("say �ܩ�..�U��..�ڴN���M���F..");  }  

return;
}int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "sun-moon iron stone")
        {
           command("flop "+who->query("id"));
           command("say �A���ڳo�ӬOԣ��....-.-");
           return 0;
        }
if( query_temp("can_not_give") )
        {
           command("hoho");
           command("say �ڤ��@�w�F..");
        }
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
             return 0;
           }
             message_vision("$N���F$n�@"+ob->query("unit")+ob->query("name")+"�C\n",who,obj);
             command("think"); 
             obj->set_temp("can_not_give");
             obj->set("long","�L�O�@�촿�g�������򪺨k�l�A�۱q�L������Q���a�q�Ӭ��_��\n"
                             "�A�K�@�����~�b�o�̡A�����@���K�K�A�L���ڷQ�N�O���y�@�⯫\n"
                             "�L�Q���A���O�L�n���ʤ֤F����....\n"); 
             obj-> set("chat_msg", ({
                   (:command("hmm")             :),
                   (:command("say ���@�w�F�F.."):),
                   }));
             obj->start_busy(9);
             obj->set_temp("givehat",1);
             destruct(ob); 
            call_out("delete_temp",900); 
             call_out("givehat",1,who);
return 1;
        }
}
void givehat()
{
      int i,exp,pop;
      object me,obj,plate;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givehat");
      pop=1+random(3);
      exp=19000+random(5000);
      if( !me || environment(me) != environment(obj) )
        {
                command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"�ѤH�N�F�N�o�����Y�C\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            break;
          case 2:
            command("say ���§A���A�p�S�̡C");
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            break;
          case 3:
            say(HIY"�ѤH���_�F�@��C�A�}�l���y����C�C\n"NOR);
            command("sweat");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 4:
            say(HIY"�L�F�@�|�W�u�ѤH��W�h�F�@��o���ť��M�������C�C\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",1,me);
            break;
          case 5:
            command("say �ڪ��ڷQ�w�g�����F�A�o��C�b���b�ڨ���w�g�����n�F�A�ڴN�⥦���A�a�C");
            obj->set_temp("givehat",i+1);
            call_out("givehat",1,me);
            break;
          case 6:
            plate=new(__DIR__"obj/sword1");
            plate->move(obj);
            command("give sword to "+ me->query("id") );
//            me->add("popularity",pop);
//            me->add("exp",exp);
//            tell_object(me,HIW"(�A���������ȡA�o��F "+ exp+" �I�g��ȻP "+pop+" �I�n��C)\n"NOR);
            obj->delete_temp("givehat"); 
           break;
          }
} 
int delete_temp()
{
 delete_temp("can_not_give"); 
 set("long","�L�O�@�촿�g�������򪺨k�l�A�۱q�L������Q���a�q�Ӭ��_��\n"
            "�A�K�@�����~�b�o�̡A�����@���K�K�A�L���ڷQ�N�O���y�@�⯫\n"
            "�L�Q���A���O�L�n���ʤ֤F����....\n");
 set("chat_msg", ({YEL"�W�u�ѤH���_�⤤���K��ĤF�@�f��.\n"NOR,
                   (:command("sigh"):),
 }));
 return 1;
}

