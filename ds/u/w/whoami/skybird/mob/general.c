#include <ansi.h>
#include <combat.h>
inherit NPC;
void combat_ai();
void create()
{
        set_name("�^��N�x", ({"fenq-gwo general","general"}) );
        set("title", HIY"�@�~��"NOR);
        set("gender", "�k�m");
        set("race", "�H��");
        set("age", 45+random(15));
        set("level",70);
        set("Merits/wit",9); 
        set("Merits/bar",5); 
        set("max_hp",10000+random(2000));
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("force", 100); 
        set_skill("berserk", 100);
        set_temp("callnpc",2);
        set_temp("pill",3); 
        set("chat_chance_combat",200);
        set("chat_msg_combat", ({
           (: combat_ai() :),
        }));
        set("can_defend", 1);
        setup(); 
        set_living_name("General");
        carry_object(__DIR__"wp/sword2.c")->wield();
        carry_object(__DIR__"wp/sword2.c")->wield();
        carry_object(__DIR__"eq/huge_armor.c")->wear();
}

void init()
{ 
           add_action("do_kill","kill"); 
           add_action("do_accept","accept");
}

void combat_ai()
{
        object me=this_player(),ob=this_object(),npc,
               mob=find_living("General_guard");
                if(!ob->query_temp("weapon"))
           command("wield sword");
           command("wield sword 2");
        if ( ob->query_temp("pill") && ob->query("hp") < ob->query("max_hp")/2) {
        message_vision("$N�q�h�̺N�X�@��"HIR"�����ĤY"NOR"�A�^�^�A�U�E\n",ob);
        ob->receive_heal("hp",ob->query("max_hp")-3000); 
        ob->receive_heal("mp",ob->query("max_mp"));
        ob->receive_heal("ap",ob->query("max_ap")); 
        ob->add_temp("pill",-1);        } 
        if ( !ob->query_temp("pill") && ob->query("hp") < ob->query("max_hp")/8 && !ob->query_temp("ber") ) {
        ob->set_temp("ber",1); 
        command("snort");
        command("say �C�������F�A���a�I");
        ob->receive_heal("hp",4000);
        }
        if( ob->query_temp("callnpc") ) {
        message_vision("�N�x�@�èӨ즹�a�E\n",ob);
        npc=new(__DIR__"general_guard");
        npc->move(environment(ob));
        npc->guard(1); 
        ob->add_temp("callnpc",-1);
        } 
}

int special_attack(object me, object target, int hitchance)
{
  object wp;
  int mysk = me->query_skill("berserk"),
      myint = me->query("int"),
      mybar = me->query("Merits/bar"),
      mydex = me->query("dex"),
      mylv = me->query("level"),
      tbar = target->query("Merits/bar"),
      bk1,bk,damage,addbar;
  if(me->query_temp("attacking")) return 0;
  if(!me) return 0;
  if(me->is_busy()) return 0; 
  if(!me->query_temp("weapon")) {
  command("wield sword");
  return 0;
  }
  wp = me->query_temp("weapon");
  if(me->query("ap") < 150) return 0;

  addbar = tbar - mybar + 1;
  damage =  mysk * (myint/20);

  if( !random(4) || me->query_temp("ber") )
  {
    me->add_temp("attacking",1);
    me->start_busy(random(3));
    message_vision("\n$N"HIR"�����o���A�����C���z�S�A�����W"+wp->query("name")+HIR"�K��$n"HIR"�@�}�g���r��I�I�I�I\n\n"NOR, me, target);
    me->add_temp("apply/damage", damage);
    if( mybar < tbar ){
    me->add_temp("apply/bar",addbar);
    me->set_temp("addbar",1);
    }   
    bk1=mysk/20+mydex/30-mybar/5; 
    if(bk1>5) bk1=5;
    if(me->query_temp("ber")){
    bk1=7;
    }
    for (bk=0;bk<bk1;bk++)
    {
     COMBAT_D->do_attack(me,target,wp,4);
     COMBAT_D->report_statue(target);
     me->receive_damage("ap",mysk/5);
    }
    if( me->query_temp("addbar") ){
    me->add_temp("apply/bar",-addbar); 
    me->delete_temp("addbar");
    }
    me->add_temp("apply/damage", -damage);
    me->delete_temp("attacking");
    return 1;
  }
  return 0;
}

int do_kill(string arg)
{
        object *ob,me;
        int i;

        me=this_player();

        if (!arg) return 0;
        if(!objectp(present(arg, environment(me)))) return 0;
        
        if( is_fighting(me) ) return 0;
        command("snort");
        command("say �h���a�I�I \n");

        ob=all_inventory(environment());
        for(i=0;i<sizeof(ob);i++)
        {
                ob[i]->soldier_assist(this_object(), me);
        }
        return 1;
}

void soldier_assist(object alert, object me)
{
          if(
             !living(this_object())
        ||      is_fighting(me) )
                return;

          switch(random(2)) {
        case 0: command("say �j�x�I�����a�I\n"); break;
        case 1: command("say �ݨӧA�]�O�s��@�٪��I���I�I\n"); break;
        }
        kill_ob(me);
        me->fight_ob(this_object());
} 

void die()
{
        object me=this_player(),ob=this_object();
                if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        } 
        ob->add("popularity",5); 
        message("world:world1:vision",
        HIR"\t�i�F�_����j\n"NOR
        CYN"\n\t\t�����@�ͪ��^��N�x���b�Q��ԧФ�������"+ob->query("name")+"����I�I\n"NOR
        ,users() );
        tell_object(ob,HIW"\n(�]���A�����F�^��N�x�A�ҥH�o��F 5 �I�n��C)\n"NOR); 
        
        ::die();
        return;
}

int talk_action()
{
        object me=this_player(),ob=this_object();
        if( me->is_fighting() || ob->is_fighting() || ob->is_busy() ) return 0;
        if( me->query_temp("Ten-mount_soldier") || me->query_temp("Ten-mount") ) return 0;
        if( ob->query_temp("quest") ) return 0;
  
        if( me->query("level") > 40 ) {
            command("say �·ж�..��ڨӻ�..�̤j���·в��L��s�U���@�s�s��F..");
            command("sigh");
            call_out("quest1",2,ob);
            me->set_temp("Ten-mount_soldier",1);
            ob->set_temp("quest",1); 
        }
        return 1;                   
}

void quest1()
{
        object me=this_player(),ob=this_object();
        switch( ob->query_temp("quest") ){
               case 1:
                command("say ���s��u�O�L�k�L��..�~�M�s�n�m���ӤW���^�~�����m���F..");
                call_out("quest1",2); 
                ob->add_temp("quest",1);
               break;
               case 2:
                command("say �n�O�A���^�~���^��..�ڤ@�w�|�n�n���§A��..");
                tell_object(me,HIY"(�n�O�A�@�N���U�o�ӥ��ȡA�п�Jaccept)\n"NOR);
                ob->delete_temp("quest"); 
                me->set_temp("Ten-mount_soldier","quest1");
               break;
        }
        return;
}

int do_accept()
{
        object me=this_player(),ob=this_object(),guardian;
        string npc,*npcs; 
        int i;
        npcs = ({"axe_soldier","pike_soldier","sword_soldier"});
        npc = npcs[random(sizeof(npcs))];  
        if( !me->query_temp("Ten-mount_soldier") ) return 0;
          if( ob->query_temp("quest") ) return 0;
        switch( me->query_temp("Ten-mount_soldier") ){
            case "quest1":
             command("really "+me->query("id"));
             command("say ���o��ӤH�A�a�ۥh�a..�L�����ӯ����A���֦�..");
             me->delete_temp("Ten-mount_soldier");
             me->set_temp("Ten-mount","Quest1");
               for(i=0;i<2;i++){
                guardian=new(__DIR__+npc);
                guardian->move(environment(ob));
                guardian->set_temp("protect",me->query("id"));
                guardian->guard();
                message_vision("$N�Ө즹�a�E\n",guardian);
               }
            break;
        // switch case default !!! -alick
        default:
        break;
        }
        return 1;
} 

int accept_object(object who, object ob)
{  
  if( ob->query("id") == "secret bottle" && who->query_temp("ask_general") && !this_object()->query_temp("no_give")){
    command("say �o�O..?");
    destruct(ob);
    this_object()->add_temp("no_give",1); 
    call_out("quest2",2,this_object());
    return 1;
  }  
  if( ob->query("id") == "head of wen tzyy ian" && !this_object()->query_temp("no_give") )
  {
    message_vision(YEL"$N�J�Ӫ����q�۳o�ӪF��A�y�W�S�X�F�@�Ƥ��i�m�H�������E\n"NOR,this_object());
    this_object()->set_temp("no_give",1);
    this_player()->set_temp("Quest1",1);
    destruct(ob);
    call_out("reward1",1,this_object());  
    return 1;
  }
  tell_object(who,this_object()->name(1)+"���G��"+ob->name(1)+"�ä��P����E\n");
  return notify_fail("");
}

void reward1()
{
      object ob=this_object(),me=this_player(),obj;
      if( me->query_temp("Ten-mount") != "Quest1" || !me->query_temp("ko_ian") ){
      command("say ���������o���P�N�������ȤF���");
      message_vision(YEL"$N��W�԰����§ʪ���V��b�ӥh�E\n"NOR,ob);
      this_object()->delete_temp("no_give");
      destruct(ob);
      return;
      }
        switch( me->query_temp("Quest1") )
        {
          case 1:
           command("say �o...�o...���O���۱i�s�骺�Y�`��..");
           me->add_temp("Quest1",1); 
           call_out("reward1",3); 
          break;
          case 2:
           command("look "+me->query("id"));
           me->add_temp("Quest1",1);
           call_out("reward1",1); 
          break;
          case 3:
           command("say �ݨӱ��F�o���H�N�O�A�F�a.."); 
           me->add_temp("Quest1",1);
           call_out("reward1",3); 
          break;
          case 4:
           if( me->query("age") < ob->query("age") ){
              command("say �~�M�~�������N���o�إ���, �G�u�O����������e��..");
              command("pat "+me->query("id"));
              me->add_temp("Quest1",1);
           } else {  
              command("say �ݧA�ᦳ����, �Q���쨭���٤���.."); 
              me->add_temp("Quest1",2);
           }
           call_out("reward1",3); 
          break;
          case 5:
              obj=new(__DIR__"obj/ashura_pill");
              command("say �ڴN���A�I�F���@�A���������y�a, �Ʊ�A�n�n�[�o, �~�����ڭ̰Q��o�Ǹ�F");
              message_vision(YEL"$N�q�h���N�X�@��"HIR"�����"YEL"�ĤY�E\n"NOR,ob); 
              obj->move(ob);
              command("give pill to "+me->query("id")); 
              me->add_temp("Quest1",2);
              call_out("reward1",3); 
          break;
          case 6:
              obj=new(__DIR__"obj/age_pill"); 
              obj->move(ob);
              command("hmm");
              message_vision(YEL"$N�q�h���N�X�@��"HIC"�C�m"YEL"�ĤY�E\n"NOR,ob);
              command("give pill to "+me->query("id"));
              command("say �o�i�O�§ʪ�����, �ݧA���ڳo��j�����~�j���������A��..");
              command("say �ۤv�n�n�Q�Χa..");
              me->add_temp("Quest1",1);
              call_out("reward1",3); 
          break;                  
          case 7:
              command("say ���ȵ����F, �ڭ̦���a..");                       
              message_vision(YEL"$N��W�԰����§ʪ���V��b�ӥh�E\n"NOR,ob);
              this_object()->delete_temp("no_give");
              me->delete_temp("Quest1"); 
              me->delete_temp("Ten-mount"); 
              destruct(ob);
          break; 
        }

}         

void quest2()
{
      object ob=this_object(),me=this_player(),obj;
      switch( me->query_temp("ask_general") ){
          case 1:
            command("hmm");
            message_vision(YEL"$N��p�~�l���F�_�ӡA�J�Ӫ��@�F�@�|�E\n"NOR,ob);
            me->add_temp("ask_general",1);
            call_out("quest2",6,ob);
          break;
          case 2:
            command("say �ݰ_��..�n���O�ī~�������F��a..");
            command("say �o��..�A�٬O�h�ݬݬݭx��a.."); 
            me->add_temp("ask_general",1);
            call_out("quest2",2,ob);
          break;
          case 3:
            obj=new(__DIR__"obj/bottle");
            obj->move(ob);
            command("give bottle to "+me->query("id"));         
            me->delete_temp("ask_general");
            me->add_temp("ask_doctor",1);            
            ob->delete_temp("no_give");
          break;
      }
  return;
}
