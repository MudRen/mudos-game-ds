#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�ѤH",({"oldman"}));
 set("long","�L�O�@�촿�g�������򪺨k�l�A�۱q�L������Q���a�q�Ӭ��_��
�A�K�@�����~�b�o�̡A�����@���K�K�A�L���ڷQ�N�O���y�@�⯫
�L�Q���A���O�L�n���ʤ֤F����....\n");
 set("age",72);
 set("gender","�k��");
 set("level",20);
 set("title","�W�u�K�K");
 set_skill("parry",50);
 set_skill("dodge",50);
 set("chat_chance",10);
 set("chat_msg", ({"�W�u�ѤH���_�⤤���K��ĤF�@�f��.\n",
                   (:command("sigh"):),
 }));
set("chat_chance_combat",200);
 set("talk_reply","�A�����ѤҤ@�I��(help)��?\n");
 set("inquiry/help","�ڲ{�b�b���y"HIG"�����C"NOR"�A���O�ʤF�إ��Y�A�s"HIG"�����K��"NOR"�A�u���o�إ��Y�~�ॴ�y�X
�����C�C\n");
set("inquiry/���K��","�A�i�H�h�F�_�A�L���d�h�ϸI�I�B��A���̦����֪��K�ۡE\n");
set("inquiry/�����K��","�O��"HIG"������"NOR"�P"HIG"���K��"NOR"�Τ��O�ĦX�Ӧ����öQ�_���E\n");
set("inquiry/�����C","�K�K....����A���ڮ��쳱���K�ۮɡA�A�N�|���D�F�E\n");
set("inquiry/������","ť���b�_�誺�}�ޤ��A���O�h�����o�䤣��F�E\n");
set("chat_msg_combat",({                         
                         (:command,"say �A�Ӥp�ݧڤF!!":),
 }));
 setup();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "�����K��")
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
             message_vision("$N���F�ѤH�@�� "+ob->query("name")+"�C\n",who);
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
            say(HIY"�ѤH�N�F�N�o�����Y�C\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
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
            call_out("givehat",3,me);
            break;
          case 5:
            command("say �ڪ��ڷQ�w�g�����F�A�o��C�b���b�ڨ���w�g�����n�F�A�ڴN�⥦���A�a�C");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 6:
            plate=new(__DIR__"obj/sword");
            plate->move(obj);
            command("give sword to "+ me->query("id") );
            me->add("popularity",3);
            me->add("exp",20000);
            tell_object(me,HIW"(�A���������ȡA�o��F 20000 �IEXP �P 3�I�n��C)\n"NOR);
            obj->delete_temp("givehat");
            break;
          }
}

