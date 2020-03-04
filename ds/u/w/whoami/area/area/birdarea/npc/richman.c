#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�I��",({"rich man","man"}));
 set("long","�L�O�y���������I�Ať���L�O�M���F�@�Ǥ����H�����a�U�ķ�~\n"

            "�|�o�򪺦������E���O�L���G�J��F�I�p�·СE\n");
 set("age",60);
 set("gender","�k��");
 set("level",20);
 set("title",HIR"�y����"NOR"���I");
 set("no_fight",1);
 set("chat_chance",10);
 set("chat_msg", ({ YEL"�I�ΧC�n���ۨ��ۻy:�����..���򭫭n���F��~�M..\n"NOR,
                   (:command("sigh"):),
 }));
 set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
 setup(); 
 add_money("coin",random(50000));
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
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"�·�") != -1)
  { 
    if ( this_object()->query_temp("can_not_give") >= 1){
    command("say �ڨS����·а�.."); 
    command("hoho");  
    } else {
    command("say �ЧA���ڧ�^�ڦ��äw�[�����Y�a�A���ӪF�褣���D�O���ѳQ�H���N���F");
    command("thank "+ this_player()->query("id"));
    }
  }   
  if(strsrch(str,"�a�U�ķ�") != -1)
  { 
    command("hehe"); 
    command("say �o�بƧA�O�����n���D��..");  
  }
  if(strsrch(str,"���n���F��") != -1)
  { 
    command("say �N�O�����ڦ��äw�[�����Y�ڡI"); 
  }        
     
  if(strsrch(str,"���Y") != -1)
  { 
    if ( this_object()->query_temp("can_not_give") >= 1){
    command("say ���O�ڪ����K��.."); 
    command("say �ڥi�O���|���A�ݪ�");
    command("giggle "+ this_player()->query("id")); 
    } else {
    command("say �������Y�s�����m�ۡA�b�t�B��o�X���~��I");
    } 

}  
return;
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object(); 
if(ob->query("id") != "five color stone")
        {
           command("flop "+who->query("id"));
           command("say �o���O�ڭn���F���..");
          return 1;
} 
if( query_temp("can_not_give") ){
           command("hoho");
           command("say ���ڳo��ԣ�H");
           return 1;
}        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
             return 0;
           }

             message_vision("$N���F$n�@"+ob->query("unit")+ob->query("name")+"�C\n",who,obj);
             command("think");
             obj->set_temp("can_not_give",1);
             obj->set_temp("giveitem",1);
             destruct(ob); 
            obj->set("long","�L�O�y���������I�Ať���L�O�M���F�@�Ǥ����H�����a�U�ķ�~\n"
                            "�|�o�򪺦������E\n");
        
            obj->set("chat_msg", ({ (:command("say �̫��٬O���F.."):),
                                    (:command("sweat"):),
                                  }));
             call_out("giveitem",1,who); 
             call_out("rb",150);
             return 1;
        }
}
void giveitem()
{
      int i;
      object me,obj,item;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("giveitem");
      if( !me || environment(me) != environment(obj) )
        {
                command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"�I�ΥJ�Ӫ����q�F�@�U�o�����Y�C\n"NOR);
            obj->set_temp("giveitem",i+1);
            call_out("giveitem",3,me);
            break;
          case 2:
            command("say �����A�N�O�o�����Y");
             obj->set_temp("giveitem",i+1);
             call_out("giveitem",1,me);
             break;
          case 3:
            say(HIY"�I�Τp���l�l����Y���F�_�ӡE\n"NOR); 
            switch( random(10) ){
             case 0..3:
              command("say �A�G�M�N�O���Ӹ�I�I");
              message_vision("����$N�Q�}�f�������ɭԡE�E�E",me);
              message_vision(HIW"\n��M��$N������X��ӧ��~�A��$N��i�F�c�̡I\n"NOR,me);
              obj->delete_temp("giveitem");
              me->move(__DIR__"../jail");
              break;
             default: 
              command("say �ڦ��ӪF��n�e�A�A�A�����C");
              obj->set_temp("giveitem",i+1);
              call_out("giveitem",2,me);
              break;
              }    
            break;
         case 4: 
            item=new(__DIR__"obj/seal");
            item->move(obj); 
            message_vision(HIY"$N�q���W���X�@��"NOR+item->query("name")+HIY"�E\n"NOR,obj);
            obj->set_temp("giveitem",i+1);
            call_out("giveitem",1,me);
            break;
          case 5:
            command("say �o�O�ڪ�j���R�U���A�����D������ΡA���N�e�A�a");
            command("give seal to "+ me->query("id") );
            obj->set_temp("giveitem",i+1); 
          }
}

int rb()
{ 
    delete_temp("can_not_give");
    set("long","�L�O�y���������I�Ať���L�O�M���F�@�Ǥ����H�����a�U�ķ�~\n"
               "�|�o�򪺦������E���O�L���G�J��F�I�p�·СE\n"); 
    set("chat_msg", ({ YEL"�I�ΧC�n���ۨ��ۻy:�����..���򭫭n���F��~�M..\n"NOR,
                     (:command("sigh"):),
                     }));
    message_vision(YEL"$N�y�F���n�C\n"NOR,this_object());
    return 1;
}

