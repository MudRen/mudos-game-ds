#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�]���C",({"meo chung chi","chi","meo",}));
 set("long",@LONG
�L�O�]�a�����v�ڪ�, �w�g���֤C�Q�l��, �ǻ��L���T��, 
�D�N, �Z�N, �H�ΤQ�U�j�s�@�a���a�U�դO�����v, ���L�L
�{�b�ݰ_�Ӥ@�Ưf���檺�ˤl....
LONG
    );
 set("attitude", "peaceful");
 set("age",73);
 set("nickname",CYN"�v�ڪ�"NOR);
 set("evil",-10);
 set("gender","�k��");
 set("level",30);
set("str",100);
set("con",100);
 set_skill("sword", 100);
 set("chat_chance",10);
 set("chat_msg", ({"�]���C��Ѫ����G�ݨӨ���ƧڬO�S��k�������F....\n", 
        }) );
 setup();
}

int talk_action(object me)        
{
 object book;
 if(!book=me->query_temp("notebook")) return 0;
 if(random(2))
 {
   if (me->query("int") > 40)
    {
        command("think");
        command("nod");
      command("say �ݨӤp�ѧ̪����z�]�\\����ץh�o���j��....");
      command("say �����D�p�ѧ̯�_�����Ѥ���(givehand)�o�Ӧ�?");
    }
    else
    {
        command("say �ѤҤ@�I�p�Ƥ����·Цѧ�....^^");
    }
 }
 return 1;
}

void init()
{
        add_action("do_givehand","givehand");
}
int x=0;
int do_givehand(string arg)
{
        object me,where1,p;
        string a;
        me = this_player();
        where1 = load_object(__DIR__"ten42");
        if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
        if( me->is_fighting() )
                return notify_fail("�A�٦b�԰����A�S���ťh���o�بơI\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("���O�榡: givehand <�Y�H>\n");
        if( a!="meo" && a!="meo chung chi" && a!="chi")
                return notify_fail("�A�n���֦�?\n");
  if(this_object()->query_temp("give_hand") == 0) 
  {
      message_vision("�]���C�w�w���D: �ʦ~�e�Q�U�j�s�O�P�H�P���~���Գ�...\n",me);
        message_vision("�]���C�~�򻡹D: �ӥP�H���Ӥ@�w, ���o�S����O�N���~�R��, �]���N���~�ʦL�b�Q�U�j�s�U�s�p�U \n",me);
        message_vision("�]���C�~�򻡹D: �p���ʦL�����, �]�a���N�������Τv������L�N�ʦL�A�ץ[�j.\n",me);
        message_vision("�]���C�~�򻡹D: , �p����~�j�j�N���~�ʦL��, ���ѤҤ��ǵL�N, ��L���N�èS���y�ǤU��,\n",me);
        message_vision("�]���C�~�򻡹D:  �]���Ʊ�ѧ̱N���O�a�������p�W�����H, �p���]�\\�|���@�u�Ʊ�....\n",me);
       message_vision(HIC"�]���C���F$N�T���O�P. \n"NOR,me);
     p=new(__DIR__"obj/wood_plate");
        p->move(this_player());
     p=new(__DIR__"obj/wood_plate");
        p->move(this_player());
     p=new(__DIR__"obj/wood_plate");
        p->move(this_player());
     set_temp("give_hand",1);
   }
   else
   {
    message_vision("�]���C�D: �h�¦ѧ̡A����~�w�g���H�����C��O�F...�I \n",me);
   }
        return 1;

}
int accept_object(object who,object ob)
{
        object obj,p;
        obj=this_object();
        if(ob->name()!="�E��^�")
        {
           command("? "+who->query("id"));
           return 0;
        }
        else {
           if(obj->is_busy() )
           {
            command("whisper "+who->query("id")+" �ЧA���@�U�C");
             return 0;
          }
        message_vision("$N���F�]���C�@��"+ob->query("name")+"�C\n",who);
             obj->start_busy(10);
             obj->set_temp("kill_wang",1);
             destruct(ob);
             call_out("kill_wang",1,obj);
             return 1;
        }

}
int x=0;
void kill_wang()
{
      int i;
      object me,obj,item,p,n;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("kill_wang");
      switch( i ) {
          case 1:
         message_vision("�]���C�h�F�@�h�A�H�Y���Y��V$N!\n",me);
            command("say ���ͦ��٤��O�Ѧa���`���A�]ˢ�o�Ĥl�S�󥲦p���ݤ��}.....");
         command("shake");
            obj->set_temp("kill_wang",i+1);
            call_out("kill_wang",3,me);
            break;
          case 2:
            command("say �Q�Ӥ]�O�ѧ̬��]ˢ��ӳo���ħ����a?");
            obj->set_temp("kill_wang",i+1);
            call_out("kill_wang",3,me);
            break;
          case 3:
            command("think");
             command("say �ѧ��`�O�@�f�߷N�A�p�G�S���Ǫ�ܡA�ѤҤ]�Q���Ǥp���p��?");
            command("hoho");
            obj->set_temp("kill_wang",i+1);
            call_out("kill_wang",3,me);
            break;
          case 4:
    if(x == 1)
   {
    message_vision(HIG"�]���C���$N���������A���M�@�D����q$N���W�{�L!!\n"NOR,me);
    command("say �Ѥҫ��Ǥ��~�A�o�ǪF��d�ۤ]�O�S�ΤF�A�ѧ̮��h�Ϩϧa!");
   message_vision(HIW"�]���C���F$N�@���@��\n"NOR,me);
         p=new(__DIR__"eq/white_wrists");
            p->move(me);
         command("smile");
            obj->delete_temp("kill_wang");
         me->set_temp("bless",1);
            obj->set_temp("kill_wang",i+1);
            call_out("kill_wang",3,me);
   }
   else
   {
       message_vision(HIG"�]���C���$N���������A���M�@�D����q$N���W�{�L!!\n"NOR,me);
    command("say �Ѥҫ��Ǥ��~�A�o�ǪF��d�ۤ]�O�S�ΤF�A�ѧ̮��h�Ϩϧa!");
   message_vision(HIC"�]���C���F$N�@���@��\n"NOR,me);
         p=new(__DIR__"eq/wind_wrists");
            p->move(me);
         command("smile");
        obj->delete_temp("kill_wang");
        x = 1;
         me->set_temp("bless",1);
            obj->set_temp("kill_wang",i+1);
            call_out("kill_wang",3,me);
     }
            break;
         }
}

void reset()
{
        delete_temp("give_hand");
        set("chat_msg",({
      "�]���C��Ѫ����G�ݨӨ���ƧڬO�S��k�������F....\n", 
        (:command("sigh"):),            
        }) );
        return;
}

