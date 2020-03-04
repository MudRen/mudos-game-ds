#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_VENDOR;

int quest();

void create()
{
  set_name("����", ({ "horse trader","trader" }) );
  set("gender", "�k��" );
  set("long",@LONG
�@��c�����ӤH�C
�A�i�H�ݰݥL���樺�ذ�(list)�A�άO�V�L�ʶR�U�ث~�ت���(buy)�C
LONG
);      
  set("age",35);
  set("level",12);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
"���ӵy�L�M�z�F�@�U�a���C\n",
(: command("say ���������O�U����@�A�ӥB�������D�I�@�� 500 ����I") :),
(: command("say �ҿר}�����M�A�B�֫o��[���֦��A�@���H�`���\\�ɬ��x�ۡA���I") :),
(: quest :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("help!") :),
}) );
  set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
  set("sell_list",([
__DIR__"obj/obj25" : 1,
]));
  setup();
  set("mirror_number",8);
  call_out("re_quest",900);
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
  add_action("do_buy","buy");
  add_action("do_list","list");
}

void greeting(object me)
{
  if( !me || environment(me) != environment() ) return;
  command("say �ȭ��A�R�ǰ��p��H");
  return;
}

int do_no_ask()
{
  write("�Х� say <��ͪ��覡> �Ө��o�һݱ����C\n");
  return 1;
}

int quest()
{
  object ob = this_object();

  if(ob->query_temp("pass_quest"))
    command("say ��A�̪�ͷN�y���M�H�A���ٺ�L�o�h�C");
  else command("say ���A�̪�n�h�Y�s���@��A�����W�L��|�������Ӧ^�A�o�i����~�n�C");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if((strsrch(str,"�D") !=-1 ||
      strsrch(str,"���O") !=-1 ||
      strsrch(str,"�~��") !=-1 ||
      strsrch(str,"��") !=-1 ||
      strsrch(str,"�n") !=-1) && strsrch(str,"�}��") !=-1)
  {
    remove_call_out("best_horse");
    call_out("best_horse",2);
    return;
  }

  if(strsrch(str,"�}��") !=-1 )
    command("say ���������O�U����@�A�ӥB�������D�I�@�� 500 ����I");

  return;
}

int accept_object(object who, object ob)
{
  if( ob->query_amount() > 0 )
  {
    message_vision("$N���X"+chinese_number(ob->query_amount())+"�T"+ob->name(1)+"("+ob->query("id")+")��$n�C\n",who,this_object());
    command("say ���r�I����"+ob->name(1)+"�O�ܡH�u�O�h�§A�աC");
    if( ob->query_amount() > (random(300)+300) && !this_object()->query_temp("pass_quest"))
    {
      command("say �A�u�O�Ӧn�H�A�e�X�Ѧb���F�D�W�ߨ�o�ӡA�ȥ��{�{�A�e�A�a�C");
      new(__DIR__"obj/obj15")->move(this_object());
      command("give " +who->query("id")+ " mirror");
      this_object()->set_temp("pass_quest",1);
      command("say �Ӧn�F�A���F�o�����A�ڥi�H�ʨ��F�C");
      call_out("dest_temp",3);
      return 1;
    }
    return 1;
  }
  command("oh");
  command("thank");
  return 1;
}

void dest_temp()
{
  tell_room(environment(this_object()),this_object()->name(1)+"�榣�����F�C\n");
  destruct(this_object());
}

int re_quest()
{
  this_object()->delete_temp("pass_quest");
  this_object()->delete_temp("item_give");
  call_out("re_quest",900);
  return 1;
}

int best_horse()
{
  string accept = "no";
  object obj;
  int index;
  
  this_player()->add_temp("get_best_horse",1);
  index = this_player()->query_temp("get_best_horse");
  if(this_object()->query_temp("item_give")) index = 99;

  switch(index)
  {
    case 5 : command("say �o�ǽT��O�U����@���}���r�A���D�ȭ��z�����N��H");
             break;
    case 9 : command("sob");
             command("say �ȭ��A�z�h�ߤF�a�A�o�ǰ����O�W�W����O�C");
             break;
    case 12 : message_vision(WHT"[$N�ܺ�i���b�ۤ�]\n"NOR,this_object());
              command("say �ȭ��A�ڭ̳o�̴N�o�ǰ��F�ڡA�p�G�z���Q�R�A�N�O��ê�ڭ̧@�ͷN�r�C");
              break;
    case 14 : command("say ���f�I�u�X�h�a�I�ڭ̳o�̨S���i�H�浹�A�����I�I");
              message_vision("[$N�Q$n�@�}��F�X�h]\n",this_player(),this_object());
              break;
    case 15 : command("sigh");
              command("say �ȭ��A�z�G�M�O�Ѱ����B�֧r... �n�a�A�ڧ�ڪ��R���o�X�ӵ��z��....");
              message_vision(HIC"[$N�ਭ�i�h�o�F�ǰ��X�ӡA�u���������@�D�Z�A���T�O�Ǥd����]\n"NOR,this_object());
              command("say 10000 ����A�p��H�������O�L���A���ڻݭn�o�ǿ��^�Y�s���@��A��O���ӽt�A�N�������P�A�C");
              write(HIW"\n[�R�U�e�ܡH yes / no]\n\n"NOR);
              input_to("get_horse",accept);
              break;
    default : command("say �}�����b�o�̤F�ڡA�z�N�D�ӴX�ǧa�C");
  }
  return 1;
}

int get_horse(string accept)
{
  object only_check;
  if(accept == "no" || accept == "n")
  {
    command("sigh");
    command("say ����A��F�C");
    message_vision("$N�Ⱘ�o�i�h�F...\n",this_object());
    return 1;
  }
  if(accept == "yes" || accept == "y")
  {
    command("say ���ڮڥ����Q���A���A�u�O�ոէA���۷N�}�F�C");

    only_check = filter_array( children(__DIR__"obj/obj7"), (: clonep :) );
    if(sizeof(only_check) > 0)
      new(__DIR__"obj/obj8")->move(environment(this_object()));
    else
      new(__DIR__"obj/obj7")->move(environment(this_object()));
    command("say �İ���A�H��i�n�n�n��ť�D�H���ܡC");
    command("pat horse");
    message_vision(HIW"\n\t[����$N�K�ਭ�X���ѤF�C]\n\n"NOR,this_object());
    random_move();
    destruct(this_object());
    return 1;
  }
  command("say �A������H��ť�����A�A�u�S�۷N�A��F�A�ڪ��R�����������A�C");
  return 1;
}

// ----- ���j�q(�H�U code ���� cominging ���P�Գs :P) (�ɧڥγ� cominging *_^) ------

int do_buy_amount()
{

}

string item_list(object ob)
{
  int b;
  b=ob->query("value");
  return sprintf(" %7d �w�w�w�w�w�w�w�w  %-26s",b,ob->short());
}

int do_list(string arg)
{
  object goods,me;
  mapping item;
  string list, *file;
  int i,*supply_cost,debug;

  me=this_player();

  if(wizardp(me) && me->query("env/debug")) debug=1;
    else debug=0;

  if( ! mapp( item = query("sell_list") ) )
  {
    write("�o��p�c�S�����~�C��I\n");
    return 0;
  }

  file =  keys(item);
  supply_cost = values(item);
  list = "\n\n\n�z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{\n"
              +"�x �� ��                          �ثe�i�H�ʶR�����زM��    �x\n"
              +"�|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�}\n";
  for( i=0 ; i<sizeof(file) ; i++)
  {
    goods = load_object(file[i]);
    if(goods) list+= item_list(goods);
    if(debug) list+= sprintf(GRN+" SP:(%3d)\n"+NOR,supply_cost[i]);
      else list+="\n";
    list +="\n";
  }
  list +="\n";
  if( i==0 ) return notify_fail(this_object()->query("name")+"��A��: �藍�_��..�����槹�F�C\n");
  else
  {
    tell_object(me,"\n");
    me->start_more(list);
  }
  return 1;       
}

int do_buy(string arg)
{
  int valus,j,world;
  object goods,ob,me;
  string item,*file;
  mapping items;
        
  items = query("sell_list");
  me = this_player();

  if( arg!="horse" ) return notify_fail("�A�n�R����F��H\n");

  file = keys(items);
  goods = load_object(__DIR__"obj/obj25");
  valus=goods->query("value");

  if( !me->can_afford( valus ) ) return notify_fail("�A���W���������C\n");

  me->receive_money(-valus);
  me->add("supply_point",-50);

  world = me->money_type();
  message_vision("$N��F "+price_string(valus,me->money_type())+
                 " �V$n�R�F�@"+goods->query("unit")+goods->name()+"�C\n", me , this_object() );

  ob = new(__DIR__"obj/obj25");
  call_out("buy1",0,me,ob);
  call_out("buy2",4,me,ob);
  me->save();
  return 1;
}

void buy1(object me,object ob)
{
  message_vision("���ӹ��$N���R$n�A�n�A���W�ӡI\n",me,ob);
  command("hehe");
  return;
}

void buy2(object me,object ob)
{
  message_vision("���ӹ��$N���G�ȭ��A�z��$n�ӤF�I\n[���ӧ�$n�o��$N���e�C]\n",me,ob);
  ob->move(environment(me));
  me->save();
  return;
}


