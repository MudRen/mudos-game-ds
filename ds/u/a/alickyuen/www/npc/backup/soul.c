#include <ansi.h>
inherit NPC;

object *item = ({ /*-----�ȩw��ITEM-----*/
        "/open/world1/tmr/area/npc/obj/soup",
        "/open/world1/ksj/east_island/npc/eq/genki-pill",
        "/open/world1/tmr/area/npc/obj/manto",
});
void msg();

void create()
{
        set_name("�u�ê��`��", ({ "guard soul","guard","soul" }) ); 
        set("level",5);
        set("age",100);
        set("long","�t�d�u�@�q�D���h�L�C\n");
        set_temp("float",1);
        set("no_fight",1);
        set("talk_reply","�i�H���ڭӦ��ܡH");
//        set("inquiry/����","�ڪ��{�l�n�j�n�j��...�A�i�H���ڱa�Y���F��ӶܡH\n");
        set("chat_chance", 20);
        set("chat_msg", ({
        (: msg() :),
        }));
        setup(); 
//        set_living_name("FSTATUE");
 }

void relay_say(object me, string str)
{
   object ob,citem;

   ob = this_object();
   citem = new(item[random(3)]);

   if( !userp(me) ) return;
   if( me == this_object() ) return;

   if(ob->is_busy())
   { return; }

   if( strsrch(str,"�Y�F��") != -1 )
   {
      message_vision("$N��: �ڦn�[�S���Y�F��A�{�l�n�j���I\n\n",ob);
      message_vision("$N�{�u���..."+HIY"�Y����"NOR+"�n�O�H�I\n",ob);
      return;
   }

   if( strsrch(str,"���i�H") != -1 || strsrch(str,"����") != -1 || strsrch(str,"���n") != -1)
   {
      message_vision("$N�^����: �F...�֭n�A�h�ơI\n\n",ob);
      return;
   }

   if (strsrch(str,"�Y����") != -1 )
   {
      if(ob->query("item_name"))
      {
          if(ob->query("eat_ok"))
          {
             message_vision("$N��: �ڤw�g�Y���F���I\n",ob);
             return;
          }
          else
          {
             message_vision("$N��: �褣�O���L�F...�ڷQ�n�Y"+ob->query("item_name")+"("+ob->query("item_id")+")���I\n",ob);
             return;
          }
      }

      message_vision("$N��: �ڷQ�n�Y"+citem->query("name")+"("+citem->query("id")+")...�A�i�H���ڱa�ӶܡH\n\n",ob);
      message_vision("$N��: �p�G�A���ڳo�Ӧ��A�ڴN���A�Ӧ�...�K�K\n",ob);
      ob->set("item_name",citem->query("name"));
      ob->set("item_id",citem->query("id"));
      ob->set("eat_no",1);
      return;
   }

   if(strsrch(str,"�J�f") != -1)
   {
      message_vision("$N��: �A�Q��J�f�H����...�A�O�䤣�쪺�I\n\n",ob);
      command("knife soul");
      return;
   }

   if(strsrch(str,"���ӪF��") != -1)
   {
      message_vision("$N��: ���ӪF��r....�K�K�ڥi�O�ê��n�n���I\n\n",ob);
      message_vision("$N��: ���L�ڧѰO�æb���F�C...XD\n",ob);
      return;
   }
}

void msg()
{
   object ob;
   ob = this_object();
   switch( random(5) )
   {
      case  0: 
            message_vision("$N�����s�z...�n�Q"HIG"�Y�F��"NOR"��...\n",ob);
            break;
      case  1:
            message_vision("$N�ۨ��ۻy: ����"HIY"�J�f"NOR"...����...�K�K...\n",ob);
            break;
      case  2:
            message_vision("$N�l���X�n...�K�K..."HIY"���ӪF��"NOR"�����٦b�C\n",ob);
            break;
   }
  return;
}

int accept_object(object me,object ob)
{
   object obj;
   obj = this_object();

   if(ob->name() == obj->query("item_name") && obj->query("eat_no"))
   {
         if(obj->is_busy())
         {
            command("whisper "+me->query("id")+" �ЧA���@�U�C");
            return 1;
         }

     command("say �S���S���I�N�O�o�ӡI");
     message_vision("�u��$N�@�f��"+ob->name()+"���L�ڸ�...\n\n",obj);
     message_vision(HIR"$N���Y�j��: �ӡ�n��Y��ա��\n\n"NOR,obj);
     message_vision("$N���ۻ�: �A�Q��J�f�O�a...�ڳ��A��a�I\n",obj,me);
     message_vision("[$N�}�l���$n�C]\n",obj,me);
     obj->delete("eat_no");
     obj->set("eat_ok",1);
     obj->delete("chat_msg");
     me->start_busy(2);
     destruct(ob);
     call_out("follow",1,me);
     return 1;
   }
   else
   {
     message_vision("$N��: ����"+ob->name()+"�F���H\n",obj); 
     message_vision("[$N�ä��Q�n�A���F��C]\n",obj); 
     return notify_fail("");
   }
  return 1;
}

int follow(object me)
{
   object ob;
   ob = this_object();
   ob->set_leader(me);           //follow me
   call_out("follow_none",200,ob);
   return 1;
}

int follow_none(object ob)
{
   command("say ���d���o�[�٨S��H���h�ԡI");
   message_vision("[$N���}�F�C]\n",ob); 
   destruct(ob);
//     ob->set_leader(0);        //follow none
//     ob->delete("eat_ok");
//     ob->delete("item_name");
//     ob->delete("item_id");
//     ob->move(__DIR__"room5");
   return 1;
}
