#include <path.h>
#include <ansi.h>
inherit NPC;

void create()
{
  set_name(WHT"����M"NOR, ({ "nin tsai ho","tsai","ho" }) );
  set("gender", "�k��" );
  set("long",@LONG
�Z�L�s�ͥN�_�~���@�A�P�e�������U�A�F�æC���W�A���L�b�@����
�N�~�����h�F�@���A�K�M�w�h������A���b�L�ݥ@�U���ơA�K�b�v
�騦�o�@�a���~�A�@�H�١y�v�騦�D�z�C�@
LONG
);
  set("title",HIY"�v�騦�D"NOR);
  set("age",32+random(3));
  set("level",48);
  set("race","human");
  set("chat_chance", 20);
  set("chat_msg", ({
"����M���صL��A���y�~�{�I�I\n",
}));
  set_skill("unarmed",100);
  set_skill("parry",100);
  set_skill("dodge",100);
  set_skill("combat",100);
  set("Merits/wit",2);
  setup();
  add_money("coin",3333+random(1111));
  carry_object(__DIR__"wp/wp1")->wield();
  carry_object(__DIR__"eq/8-mirror")->wear();
}

void init()
{
  add_action("do_no_ask","ask"); 
  } 
int do_no_ask(string arg)
{
  write("�O�ݧڡA�Q���D�ۤv���Ǧ������z�ץX��(say)!!\n");    return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if(strsrch(str,"���_") != -1)
  {
    command("tsk");
    command("say �u�F�`�A�ڰh���Ʀ~�q��ť��ڦ��ܬöQ���F��!?"); 
    return;  
  }
  if(strsrch(str,"�p��l") !=-1 || strsrch(str,"��p��") != -1)
  {
    command("emote ����M�𪺸��}!!");
    command("say ���{��!!�u�R�X���!!���...�A�Q�o���!?"); 
    return; 
  }
  if(strsrch(str,"�Q") != -1)
  {
    command("say ��....");
    command("say �����ڤ@��ơA�ڴN���A!!"); 
    return;   }
  if(strsrch(str,"�����") != -1)
  {
  command("say �A��v�騦���F��Ӧa�A���ڧ��ڷR�H�����e�Ҩرa�������A�ڴN�⦹�ˬöQ�������A!!");  //�S��""
  }
  return;
}  
int accept_object(object who,object ob)
{
                object obj;
                obj=this_object();
                if(ob->query("name")!="����")
                {
                 command("? "+who->query("id"));
                 return 1;
                }
                else  
                if(obj->is_busy() || obj->is_fighting())                                   {
                  command("whisper "+who->query("id")+" �ЧA���@�U�C");
                  return 0;
                                                            }  
                 else                    
       message_vision("$N���F����M�@��"+ob->query("name")+"�C\n",who);
       command("say �o...���O���p��������?..�گu�O�Ӱ����F.!!");
               obj->set_temp("earring_quest",1); 
               obj->start_busy(6);
               destruct(ob); 
               call_out("earring_quest",1,obj);                                 return 1;

}  
void earring_quest()
{
      int i;
      object me,obj,item;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("earring_quest");
      switch( i ) {
                case 1:
                command("say �o....���O���p��������..!?");
                command("say ����"+RANK_D->query_respect(me)+"��˱o�즹���O!?");
                obj->set_temp("earring_quest",i+1);
                call_out("earring_quest",1,me);
                break;
                case 2:
                message_vision(HIC"$N��b�Ӧa�G�D���Ʊ��i�D����M..!!\n"NOR,me);
                obj->set_temp("earring_quest",i+1);
                call_out("earring_quest",1,me);
                break;
                case 3:
                command("hmm");
                command("say ��!!�ڦ��q��|�t�ܦ��o��..�ҥH�ڨä��P��d��,���٬����p�බ�Q��ͷP�찪��!!");
                obj->set_temp("earring_quest",i+1);
                call_out("earring_quest",1,me);
                break;
                case 4:
                                command("say ���L..�٬O�¤F!!");
                                command("bow");
                                command("say �ܻ��^��,�ڤ]�n�u��쪺�ӿ�,�e�A�ڳ̬öQ������!!\n");
                                item=new(__DIR__"eq/mo-ring");
                                item->move(obj); 
                                command("give ring to "+ me->query("id") ); 
                                obj->delete_temp("earring_quest");  
                               break;  
            }
} 
void greeting(object ob)
{ 
object me=this_player();
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0: 
                        message_vision(HIB"\n����M�@���������V�A,�¤O��H�L��!!\n"+NOR,me);
                        me->receive_damage("hp",300);
                        this_object()->kill_object(environment(me));
                        break;
                
        }
}
int special_attack(object me,object target,int hitchance)
{
  int damage;
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(7))

    {
      message_vision(HIR"����M�f�����ۻy�G���N�P���A�P�کw�U�}���A�U�ڱ٧����]�a�I�I
            "HIR"����M�P�i���N�ְ��j�F����ĳ�A���趡�����P���U�N���ΡA�Φ��p�P����$N���Y�����ġC
            "HIC"����M�P�i���N�ְ��j�F����ĳ�A���趡�ʷʲr���E�����ΡA�Φ��p������$N���y�����ġC
            "HIY"����M�P�i�g�N�ְ��j�F����ĳ�A���趡���d���g�׶����ΡA�Φ��p�g����$N��������ġC
            "NOR""YEL"����M�P�i��N�ְ��j�F����ĳ�A���趡�W�U����զX���ΡA�Φ��p������$N���y�����ġC
            "HIW"����M�P�i�B�N�ְ��j�F����ĳ�A���趡�N��H�B���ɦ��ΡA�Φ��p�B����$N���������ġC\n"NOR,target);
                      if(random(target->query_dex()) >35){
                      damage=300-target->query_armor()+random(100);
                      target->receive_damage("hp",damage,target);
                      message_vision("\n���U�`�X�@�y��$N"HIR""+damage+""NOR"�I���ˮ`�C\n",target);
} 
else
    {
    message_vision(HIG"\n$N�ϥX���l�몺���աA�׶}�F�o�i�j�P�������I�I\n"NOR,target);
    return 1;
    }
        return 1;
  }
  return 0;
}



void die()
{
   object ob;
   if( !ob = query_temp("last_damage_from") ) ob = this_player(1); 
   if( !ob )
   {
     ::die();
     return;
   }
   message("world:world1:vision",
HIG"\n�i�[�P�̤��j�W�ŤK�褪�P�f���A�~�ǹ���M���u�h�F�I�I\n\n"NOR,users());

   ob->add("popularity",3+random(2));
   ::die();
   return;
}

