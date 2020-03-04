#include <ansi2.h>
#include <combat.h>
inherit NPC; 
inherit SSERVER;
void power();
void heal();  
void create()
{
  set_name("�����J", ({ "suoo bey keh","keh","bey","suoo","hero" }) );
  set("gender", "�k��" );
  set("nickname","�y������");
  set("title",HIR"�y����"NOR+HIC" �^��"NOR);
  set("long",@LONG
�L�O�b�ƤQ�~�e���g���ѹL�E��������A�b�������E�Ԥ����F��
�˨즹���~���ˡEť���b�L�����o�ӧ��l���^�����e�٥u�O�ӥ�
�K�K�A�o�]���ǥL�����Z���A�q�ӳ��S�ݹL�E
LONG);      
  set("age",30+random(10));
  set("level",43+random(4));
  set("exp",40000+random(3000));
  set("race","human"); 
  set("max_hp",13000+random(5000)); 
  set("max_ap",25000+random(10000));
  set("max_mp",25000+random(10000));

  set_skill("unarmed",100);
  set_skill("parry",100);
  set_skill("dodge",100);
  set_skill("force",100);
  set_skill("fork",100);
  set_skill("da-fork",100);
  set_skill("bagi_fist",100);
  set_skill("bagi_force",100);
  set_skill("horse-steps",100);
  set_skill("bird-eight",100);
  set_skill("moon_force",100);
  set_skill("buddha-force",100);
  set_spell("god-kill",100); 
  set_spell("god-fire",100);
  set_spell("god-benison",100); 
  set("addition/wit",3+random(5)); 
  set("addition/bar",1+random(5));  
  set("addition/damage",10+random(50)); 
  set("addition/armor",100+random(50)); 
  set("addition/shield",100+random(50)); 
  set("addition/con",100+random(20));
  set("addition/dex",100+random(20));
  set("class1", "���Z��");
  set("class2", "���Z��");

  set("chat_chance", 300);
  set("chat_msg", ({
(: command("exert da-fork")   :),
(: command("exert bagi_fist") :),
(: command("exert bird-eight") :),
(: command("exert buddha-force armor") :),
(: command("exert bagi_force power_up") :),
(: command("exert horse-steps twine-power") :),
}));

  set("chat_chance_combat",100);
  set("chat_msg_combat", ({
(: heal :),
(: power :),  
(: command("wield pike") :),}) );
  set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
  setup();
  add_money("coin",random(5000));
  carry_object(__DIR__"eq/tooth")->wield();
}
void init()
{
  object me;
 
  ::init();
  if( interactive(me = this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting", 1, me);
  }
  add_action("do_no_ask","ask");
}

void greeting(object me)
{
  if( !me || environment(me) != environment() ) return;
  if( me->query_temp("ko_fox_nine") ){
  command("whisper "+me->query("id")+"�p�G�A�ʨ���i�H���������I");
  }
  return;
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
  if(strsrch(str,"����") !=-1 && this_player()->query_temp("ko_fox_nine") )
  {
   command("hmm");
   command("say �ڬO�ݧA�]�O������ѤE�����i�̤~��A����..");
   command("say �b�F�_�A�L���Y�������r���s��");
   command("say �p�G�A������Ѩe�A��e���������ڡA�ڴN�����A���X����������");   
  }
  if(strsrch(str,"�E��") !=-1)
  {
   command("say �ڴN�O���ѤE�������ӤH�ڡI");
   command("cac");
  }
  if(strsrch(str,"�s��") !=-1 && this_player()->query_temp("ko_fox_nine") )
  {
   command("hmm");
   command("say �F�_�A�L�i�O�ܤj���A���̳s�ڳ��S�i�h�L�E");
   command("say ���s���]�u�Oť����"); 
   command("ant");  }
  return;
}

int accept_object(object who, object ob)
{ 
  object obj=this_object();
  if(ob->query("id") == "crocodile teeth")
  {
    if( who->query_temp("ko_crocodile") && who->query_temp("ko_fox_nine") 
    && obj->query_temp("no_give") < 1 )
    {
    message_vision("$N���F$n�@"+ob->query("unit")+ob->query("name")+"�C\n",who,obj);
    command("tsk "+who->query("id")); 
    command("say �ڰ��W�N���A���󨾨�I");
    destruct(ob); 
    obj->set_temp("no_give",1);
    obj->set_temp("give_item",1);
    call_out("giveitem",1,obj);  
    } else {
    command("say �ڤ~���n�Ӹ��������F��I");
  }
  return 0;
}
  command("say �e�ڪF��ڡH�h�§A�F�A���L�ڪ��[���b���a�A�ˤ]���ʤ���A�A�٬O���^�h�a�C");
  write("["+this_object()->name(1)+"��"+ob->name(1)+"�ä��P����]\n");
  return notify_fail("");
}

void giveitem()
{
      int i;
      object me,obj,item,item1;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("give_item");
      if( !me || environment(me) != environment(obj) )
        {
                command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
                return;
        }
      switch( i ) {
          case 1:
            message_vision(HIY"$N�J�Ӫ����q�F�@�U�o�������C\n"NOR,obj);
            obj->set_temp("give_item",i+1);
            call_out("giveitem",2,me);
            break;
          case 2:
            command("say �����A�o�ӥi�H�����Z�n������");
            obj->set_temp("give_item",i+1);
            call_out("giveitem",1,me);
            break;
          case 3:
            command("say �A������I");
            message_vision(HIY"$N����и̥h�}�l�V�V�����E�E�E\n"NOR,obj); 
            obj->set_temp("give_item",i+1);
            call_out("giveitem",3,me);
            break;
          case 4:  
            switch( random(5) ){
            case 0..2:            
              item=new(__DIR__"eq/bar-neck");
             item->move(obj); 
             message_vision(HIY"$N�ש�q�и��Y���F�X�ӡE�E�E\n"NOR,obj);
             command("say ��..�N�O�o�ӪF��..");
             command("give necklace to "+ me->query("id") );
             break;
            default:
             item1=new(__DIR__"eq/wit-neck");
             item1->move(obj); 
             command("sorry"); 
             command("say �ڥ��ѤF�A�o�ӪF�赹�A���@���v�a�I"); 
             command("give necklace to "+ me->query("id") ); 
             break;
            }  
             obj->delete_temp("give_item");  
             obj->delete_temp("no_give");          
 break;          
   }
} 

void die()
{
        object ob,newob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( ob )     message("world:world1:vision", 
HIB"\n�F�_�誺�ѪŤ��A����"BLINK+HIY"�P"NOR+HIB"�Y�J�F�a���u���
\n\n\t"HIR"�y�������^���Q"+ob->name(1)+"�����F�C\n\n"+NOR,users());
        ob->add("popularity",10);
        tell_object(ob,HIG"\t�A�o��F�����I�n��I\n"NOR);
        ::die();
        return;
}
 
void heal()
{
    object me=this_object();
message_vision(HIW"$N�ⴤ���w�A�b$N���W���˪��a���F�X�U�A���M$N�˲����_���C�C�}�l�v¡�F�I\n"NOR, me);              
    me->receive_heal("hp",random(1000));
    me->receive_heal("mp",random(1000));
    me->receive_heal("ap",random(1000));
    return;
}
void power()
{
  switch( random(10) )
  {
    case 0 : command("exert da-fork");
             break;
    case 1 : command("exert da-fork");
             break;
    case 2 : command("cast god-fire");
             break;
    case 3 : command("cast god-kill");
             break;
    case 4 : command("cast god-kill");
             break;
    case 5 : command("cast god-kill");
             break;
    case 6 : command("exert moon_force long-arc"); 
             break; 
    case 7 : command("exert moon_force moon-arc"); 
             break;  
    case 8 : command("cast god-benison"); 
             break;  
    case 9 : command("exert bagi_fist");
             break;
           
  }
  return;
}

int receive_damage(string type,int cost)
{
  object ob = this_object(), me = this_player();

  if(ob->is_busy()) ob->add_busy(-10);
  if(!random(3) && ob->is_fighting() && me != ob)
  {
    message_vision(HIG"\n$N�j�q�@�n�A�~�o$n���}�o�n�A�ʼu���o�I\n\n"NOR,ob,me);
    me->start_busy(1);
    power();
  }
  ::receive_damage(type,cost,me);
  return 0;
}

int be_stolen(object me, object what)
{
        if( !me || !what )
                return notify_fail("[���~]:�Х� report ���O�^���C\n");
        tell_object(me, this_object()->name() + "���g�N�a�@���Y�M�A�榣�N���Y�F�^�h�T\n"
                "�٦n�M�S���Q�o�{�C\n");
        me->start_busy(2);
        return 1;
}
