#include <ansi.h>
inherit NPC;
void create() 
{ 
 set_name("�B����",({"bu liu hu","bu","hu"}));
 set("long","�L�O�b�o���l�̳̦n���u�K�C\n");
 set("age",56);
 set("gender","�k��");
 set("level",30);
 set("title",CYN"������n�P"NOR);
 set_skill("parry",100);
 set_skill("dodge",100);
 set_skill("combat",100);
 set("chat_chance",20);
 set("chat_msg", ({"�B�����ĹD: �̪񳣨S��ԣ���쪺 "+HIG+"�Ƥl"+NOR+" ��?.....\n",
                   (:command("sigh"):), 
                   (:command("think �K���j�D.."):),
 }));
        set("chat_chance_combat",200);

        set("talk_reply","�����դU...��..��F��F... "+HIC+"���r"+NOR+""+HIG+"�i���n�S��!\n"NOR);

        set("inquiry/�Ƥl","���]���@�w�n�O�S�w���F��, �u�n����ѤҤ@�w���L�⪱�ӭӧ�ɨ�...:D.\n"NOR); 
        set("inquiry/�K�[�j�D","��r! �ڳ̪�墨����j�D���ܦ�����...�Υ��Ӱ��F��..�@�w�ܦ���P..:D.\n"NOR);
        set("inquiry/���r","ť���ұ`��..�̪�`�b�����~���L���ݨ�L�@�إ����z�������� "+HIG+"���n��.\n"NOR);

        set("inquiry/���n��","ť�����n�����֩_�Ǥ���! �J���B�X, �J�X�B��! �u�Q���Ӫ���...���L����"+HIG+"�ߩ�"+NOR+"�P�ˤ]�O�_�Ǥ���...\n");

        set("inquiry/�ߩ�","���n���D�o�n��ϥ������~��l�ަA�N������, �i�����L�⦳�S���o�تF��??\n"NOR);

 set("chat_msg_combat",({                         
                         (:command,"hmm":),
 }));
 setup();
}


int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->query("id") == "shark bone")
           {
                if(obj->is_busy() || obj->is_fighting())
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
             return 0;
           }
             message_vision("$N���F�B�����@�q "+ob->query("name")+"�C\n",who);
             command("jump");
             obj->start_busy(10);
             obj->set_temp("givehelmet",1);
             destruct(ob);
             call_out("givehelmet",1,obj);
        return 1;
           }

                if(ob->query("id") == "clam shell")
           {
                if(obj->is_busy() || obj->is_fighting())
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
             return 0;
           }
             message_vision("$N���F�B�����@�� "+ob->query("name")+"�C\n",who);
             command("spank");
             obj->start_busy(10);
             obj->set_temp("giveshield",1);
             destruct(ob);
             call_out("giveshield",1,obj);
        return 1;
           }
        if(ob->query("id") == "light cloth")
           {
                if(obj->is_busy() || obj->is_fighting())
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
             return 0;
           }
             message_vision("$N���F�B�����@�i "+ob->query("name")+"�C\n",who);
             command("jump");
             obj->start_busy(10);
             obj->set_temp("givecloth",1);
             destruct(ob);
             call_out("givecloth",1,obj);
        return 1;
           }

}     

void init()
{ 
  add_action("do_givehead","givehead"); 
  add_action("do_pray","pray");
} 
/* add by JS@DS */
int do_givehead(string arg)
{ 
     object me,ob,head;
     me=this_player();
     ob=this_object(); 
     
     if(arg=="orochi black head")
     {
     if(!objectp(head=present("orochi black head",me) ) )   
       {
       message_vision("�B�����Į�D�G�o���O�ڭn���s�Y..\n",me); 
       }else{ message_vision("�B�����@����H�G�N....�I�N�O�o�ӡI\n",me); ob->add_temp("black-head",1); 
              destruct(head);
              return 1;
            }  
     }
     if(arg=="orochi red head")
     {
     
     if(!objectp(head=present("orochi red head",me) ) )   
       {
       message_vision("�B�����Į�D�G�o���O�ڭn���s�Y..\n",me); 
       }else{ message_vision("�B�����@����H�G�N....�I�N�O�o�ӡI\n",me); ob->add_temp("red-head",1); 
              destruct(head);
              return 1;
            }   
     }
     if(arg=="orochi grey head")
     {
     if(!objectp(head=present("orochi grey head",me) ) )   
       {
       message_vision("�B�����Į�D�G�o���O�ڭn���s�Y..\n",me); 
       }else{ message_vision("�B�����@����H�G�N....�I�N�O�o�ӡI\n",me); ob->add_temp("grey-head",1); 
              destruct(head);
              return 1;
            }  
     }
     if(arg=="orochi green head")
     {
     if(!objectp(head=present("orochi green head",me) ) )   
       {
       message_vision("�B�����Į�D�G�o���O�ڭn���s�Y..\n",me); 
       }else{ message_vision("�B�����@����H�G�N....�I�N�O�o�ӡI\n",me); ob->add_temp("green-head",1); 
              destruct(head);
              return 1;
            }  
     }
     if(arg=="orochi blue head")
     {
     if(!objectp(head=present("orochi blue head",me) ) )   
       {
       message_vision("�B�����Į�D�G�o���O�ڭn���s�Y..\n",me); 
       }else{ message_vision("�B�����@����H�G�N....�I�N�O�o�ӡI\n",me); ob->add_temp("blue-head",1); 
              destruct(head);
              return 1;
            }  
     }
    if(arg=="orochi white head")
    {
     if(!objectp(head=present("orochi white head",me) ) )   
       {
       message_vision("�B�����Į�D�G�o���O�ڭn���s�Y..\n",me); 
       }else{ message_vision("�B�����@����H�G�N....�I�N�O�o�ӡI\n",me); ob->add_temp("white-head",1); 
              destruct(head);
              return 1;
            }  
    }
     if(arg=="orochi purple head")
     {
     if(!objectp(head=present("orochi purple head",me) ) )   
       {
       message_vision("�B�����Į�D�G�o���O�ڭn���s�Y..\n",me); 
       }else{ message_vision("�B�����@����H�G�N....�I�N�O�o�ӡI\n",me); ob->add_temp("purple-head",1); 
              destruct(head);
              return 1;
            }   
     }
     if(arg=="orochi gold head")
     {
     if(!objectp(head=present("orochi gold head",me) ) )   
       {
       message_vision("�B�����Į�D�G�o���O�ڭn���s�Y..\n",me); 
       }else{ message_vision("�B�����@����H�G�N....�I�N�O�o�ӡI\n",me); ob->add_temp("gold-head",1); 
              destruct(head);
              return 1;
            }   
     }
} 
/* add by JS@DS */
int do_pray(string arg)
{ 
    object me=this_player(),ob=this_object();
    if(ob->query_temp("black-head")!=1 ||
       ob->query_temp("red-head")  !=1 ||
       ob->query_temp("green-head")!=1 ||
       ob->query_temp("purple-head")!=1||
       ob->query_temp("white-head")!=1 ||
       ob->query_temp("gold-head") !=1 ||
       ob->query_temp("blue-head") !=1 ||
       ob->query_temp("grey-head") !=1  ) 
    {   message_vision("�B�����n�Y�ĹD�G�٤���.....\n",me);  
            return 1;
    } else {
    message_vision("�B�����y�D�G�n�I�е��ڤ@�|��\n",me);
            call_out("do_ggivehead",3,me); 
            ob->delete_temp("black-head",1); 
            ob->delete_temp("red-head",1);
            ob->delete_temp("green-head",1);
            ob->delete_temp("purple-head",1);
            ob->delete_temp("white-head",1);
            ob->delete_temp("gold-head",1);
            ob->delete_temp("blue-head",1);
            ob->delete_temp("grey-head",1); 
            return 1;
            }
}
void do_ggivehead()
{
   object me=this_player(),ob=this_object(),eq; 
    int i;
   i=random(99); 
   switch(i)
   {
case 0..3:
   message("world:world1:vision",HIG"�B����"+HIW"�����F�v�W�̲׷����˳Ƣw"+GRN"�K�["+RED"�E"+HIY"�s�v\n"NOR,users());  
   message_vision("�B�������D�G�o�O�ڲ��ͳ̧������@�~�A�бz���^�h�A�o�˧ڤw�����F�C\n"
                  "�B�������F$N�@�˪F��\n",me);
   new(__DIR__"orocho-eq")->move(me);
   return; 
break;
case 4..33:
   message_vision("�B�����ĹD�G����r.....�ڥ��ѤF�I�a�F�A�����N�A�u�O�L�N���h..\n"
                  "�B�����f�M���ਭ�i�J�Ф�\n",me);
   destruct(ob);
   return;
   break;
   case 34..63:  
   message_vision("�B�����D�G�o���s�Y..�l�ˤ��Y���A��������ո˰_��\n");
   destruct(ob);
   break;
   case 64..99:  
   message_vision("�B�����D�G�o���s�Y..�l�ˤ��Y���A��������ո˰_��\n");
   return;
   break; 
   }}
void givehelmet()
{
      int i;
      object me,obj,helmet;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givehelmet");
      if( !me || environment(me) != environment(obj) )
        {
                command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
                return;
        }
      switch( i ) {
          case 1:
            say(CYN"�B�������Ī��ݵ��T��...�f���s�D: ����! ����!\n"NOR);
            obj->set_temp("givehelmet",i+1);
 
            call_out("givehelmet",2,me);
            break;
          case 2:
            command(CYN"say ��..." + RANK_D->query_respect(me) + " �A���@��.."NOR);
            obj->set_temp("givehelmet",i+1);
            call_out("givehelmet",2,me);
            break;
          case 3:
            say(CYN"�B�����ਭ���i�ж�....�C\n"NOR);
            obj->set_temp("givehelmet",i+1);
            call_out("givehelmet",3,me);
            break;
          case 4:
            say(CYN"�L�F�@�|�A�Kť��Ф��ǨӤ@�}�s�n : ���F! ���F!\n"NOR);
            obj->set_temp("givehelmet",i+1);
            call_out("givehelmet",2,me);
            break;
          case 5:
            command("say �o�������]���٦ѤҪ��ǧ@���@�F..�Ѥүd�ۤ]�S��..�N���F�A�a!!");
            obj->set_temp("givehelmet",i+1);
            call_out("givehelmet",2,me);
            break;
          case 6:
            helmet=new_ob(__DIR__"../eq/bone_helmet");
            helmet->move(obj);
            command("give helmet to "+ me->query("id") );
            obj->delete_temp("givehelmet");
            break;
          }
}

void giveshield()
{
      int i;
      object me,obj,shield;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("giveshield");
      if( !me || environment(me) != environment(obj) )
        {
                command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
                return;
        }
      switch( i ) {
          case 1:
            say(CYN"�B�����ݵۥ��F��, �I�u�b��, �ۨ��ۻy�D: �Q�ӳo�]���I���...\n"NOR);
            obj->set_temp("giveshield",i+1);
            call_out("giveshield",2,me);
            break;
          case 2:
            command(CYN"say ��..." + RANK_D->query_respect(me) + " �A���@��.."NOR);
            obj->set_temp("giveshield",i+1);
            call_out("giveshield",2,me);
            break;
          case 3:
            say(CYN"�B�����ਭ���i�ж�....�C\n"NOR);
            obj->set_temp("giveshield",i+1);
            call_out("giveshield",3,me);
            break;
          case 4:
            say(CYN"�L�F�@�|�B�����K�q�Ф����F�X��.\n"NOR);
            obj->set_temp("giveshield",i+1);
            call_out("giveshield",2,me);
            break;
          case 5:
            command("say �o�@�ӥ��F�ާگd�ۤ]�S��, �N�e���A�a!");
            obj->set_temp("giveshield",i+1);
            call_out("giveshield",2,me);
            break;
          case 6:
            shield=new_ob(__DIR__"../eq/clam_shield");
            shield->move(obj);
            command("give shield to "+ me->query("id") );
            obj->delete_temp("giveshield");
            break;

          }       
}

void givecloth()
{
      int i;
      object me,obj,helmet;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givecloth");
      if( !me || environment(me) != environment(obj) )
        {
                command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
                return;
        }
      switch( i ) {
          case 1:
            say(CYN"�B�������Ī��ݵ۳���..�f���s�D: �N�O�o��!!\n"NOR);
            obj->set_temp("givecloth",i+1);
            call_out("givecloth",2,me);
            break;
          case 2:
            command(CYN"say ��..." + RANK_D->query_respect(me) + " �A���@��.."NOR);
            obj->set_temp("givecloth",i+1);
            call_out("givecloth",2,me);
            break;
          case 3:
            say(CYN"�B�������_����, �ਭ���i�ж�....�C\n"NOR);
            obj->set_temp("givecloth",i+1);
            call_out("givecloth",3,me);
            break;
          case 4:
            say(CYN"�L�F�@�|�A�Kť��Ф��ǨӤ@�}�s�n : ���F! ���F!\n"NOR);
            obj->set_temp("givecloth",i+1);
            call_out("givecloth",2,me);
            break;
          case 5:
            command("say �o�����n�u��O�H�����~, �N���դU���h��������a!");
            obj->set_temp("givecloth",i+1);
            call_out("givecloth",2,me);
            break;
  
          case 6:
            helmet=new_ob(__DIR__"../eq/dex_boots");
            helmet->move(obj);
            command("give boots to "+ me->query("id") );
            obj->delete_temp("givecloth");
            break;
          }
}
