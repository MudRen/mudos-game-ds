//�ѥ|��ɪ�mob
#include <ansi.h>
inherit NPC;
void fongquest();
void create()
{
  set_name("�s���Ѫ�",({"mountain old man","man"}));
  set("long",@LONG
�L�O�@�W�~��b�s�����Ѫ̡A���G�O���j�H�Ӿ���u�@���@
�ڪ���ǡA���~�ɲ@�L�pô�A�ߤ@����l�h�~�e�N�~���h�A
�u�ѤU�]�l�M��̬ۨ��R�A�ҥH���Q���d�R�A���W�]�\����
���񪺱����C
LONG
    );
  set("attitude", "peaceful");
  set("age",62);
  set("gender","�k��");
  set("level",25);
  set("chat_chance",20);
  set("chat_msg", ({"�s���Ѫ̻��D: ���Ĥl..�u�O�R��...�ѬO��ť��\n",
                    "�s���Ѫ̼~�߭��������_�Į�\n",
                    "�s���Ѫ̻��D: �����G�S�X�{���R�F...���D�����S�n�X�{�F\n",
                  }));
  set("inquiry/���","���O�ڭ̤@�ڥ@�N�u�@���ϩR�A�ǻ��̭�������\n"NOR);
  set("inquiry/�]�l","�L�s�p�y�A�۱q�L���R�Q���h���ܦ�ڬ̬ۨ��R�F�A\n"NOR);
  set("inquiry/����","ť���O�Ӯ��ƪ����y�A���ۥi�Ȫ���O..\n"NOR);
     setup();   
  add_money("coin",1200);
}
 
void init(){
        object ob;
        ::init();
        add_action("do_say","say");
        if(this_player()->query_temp("pass_mission")==1) call_out("fongquest",1);
}
int do_say(string arg)
{
          object me,npc;          
          npc=this_object();
          me=this_player();
           if(!arg && !npc->query_temp("home_right") && me->query_temp("know_boy") )          
           {
            write(HIW"[�A�Q���L��? say �i / ���i] "NOR);
            return 1;
           }
   if(arg == "�i" && !npc->query_temp("home_right") && !me->query_temp("get_mission")
&& me->query_temp("know_boy"))
     { 
      message_vision(YEL"$N���G"+ arg +"\n"
                    "�s���Ѫ̹��$N���D�G�u����!�ӷP�§A�F�A�@���N���U�A�F�C\n"
                    "�s���Ѫ̻��D:�Ӧn�F�A�ש󦳤H�����ڤF�C\n"    
                    "�s���Ѫ̻��D:���ڧ�o�ӥ浹�L..�L�K�|�F�ѤF\n"NOR,me);
       new(__DIR__"re-letter")->move(this_object());
       command("give " +me->query("id")+ " letter");
            me->set_temp("get_mission",1); 
            return 1;
     }
   else
     { 
      if(arg == "�i" && me->query_temp("get_mission"))
      command("say �A���O�����ڹL�F��?");
      return 1;
     }
  if(arg == "���i" && !npc->query_temp("home_right") && me->query_temp("know_boy")  )      
      { 
       message_vision(YEL"$N���G�b�U�L�k���A\n"   
                         "�s���Ѫ̥��檺��:��...���]���j�j...\n"
                         "�s���Ѫ̿W�۳��ۻy��:�y��..�A�֦^�ӧr�C\n",me);   
      }
      return 1; 
    
} 

int talk_action(object me)      //talk �ɷ|���榹�禡.
{
 if(this_object()->query_temp("home_right")) command("say �ثe�@���w�n�A�h�����ߡC");
 else
 {
        switch(random(3))
        {
                case 0: command("say �аݧA�i������L�ڪ��]�l?");
                        break;
                case 1: command("say ��..�u�O���H�Ҿ��A�i�_���ڴM��ڪ��]�l�^�ӡC(say)");
                        me->set_temp("know_boy",1);
                        break;
                case 2:
                default:
                        command("say �аݧA�i�����L�ڪ��]�l?");
                        break;
        }
 }
 return 1;
}

void fongquest()
{
    object me,npc;  
       me=this_player();
       npc=this_object();
message_vision("�s���Ѫ̤Q������������:�u�O�ӷP�E�A�F...�Ѧ��L�H�^���A�N��o���A�a�C\n"
               "�s���Ѫ̻��D:�o�O�ڭ̤@�ڶǻ��ධ�Ѧa���𪺥ɡA�K�N���A��S�¡C\n"
               ,this_player());
       new(__DIR__"jade")->move(this_object());  //�|���
       command("give " +me->query("id")+ " jade");       
       me->delete_temp("pass_mission");       
       me->delete_temp("know_boy");
       npc->set_temp("home_right",1);      
       call_out("delay",600);
}

int accept_object(object who, object ob)
{

  object npc=this_object();
  if(npc->is_busy() || npc->is_fight())
    return notify_fail("�s���Ѫ̦��G���b���C\n");
 if(ob->query("id") == "alien-beast stone")
  {
    command("say ��?..�W������r�n���x...�O�ڭ̯�������r�r");
    command("say �W���n���O���A�s���k��B�J���Y�{");
    command("say �ӥB�o�����Y�n���n�b���𭫪��a��~����}..");
    command("say �Ѧ��N�u���D�o�ˡA�Ʊ��A�����U...���Y�ٵ��A�a...");    
    call_out("return_stone",1,who);
    return 1;
  }
  else
  {
       command("?");
       command("say �o�O������?..�֦��^�h..");
  }
}
 


void delay()
{   
     object ob,boy;
     ob=this_object();
     if(!ob) return;
     boy=present("boy yu",environment(ob));
     ob->delete_temp("home_right");    
     if(!boy) return;
     boy->go_way();
}

void return_stone(object who)
{
  command("give " +who->query("id")+ "stone");
}

