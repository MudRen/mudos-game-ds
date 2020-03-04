#include <ansi.h>
#include <path.h>
inherit ROOM;

string post();

void create()
{
  set ("short", HIC"[Magic-Card �M�橱] "HIW"�j"HIR"����"HIW"�]"NOR);
  set ("long", @LONG

�o�̬O�M���c�� Magic�ȵP���p���A�A�i�H�� [list] �Ӭݬݦ�
����i�H�R���F��A���̭���ۮ�l�A�i�ѧA�C�֡A�t�~�o�̤]
�`�|��p�����ɡA�ɶ����g�b�G�i�� (post) �W�C

 �t�~�A�i�H��:
 checkc          �ˬd�A���W�����ǵP
 listc           �d�ݧA�����ǵP�s�b�d���Ȧ��
 savec �ĴX�i�d  �N�P�s�J�d���Ȧ� (�p�G�S���Ʀr�h�N���W�������P�s�J)
 getc ���� �d��  ���X�A�s�b�d���Ȧ檺�d��

LONG
);
  set("exits", ([
    "south"   : "/open/world1/tmr/area/inn_2f",
    "north" : __DIR__"room2",
]));
  set("item_desc", ([
  "post" : (: post :),
]));
  set("objects",([
  __DIR__"npc" : 1,
]));
  set("light",1);
  set("no_kill",1);
  set("no_cast",1);
  set("no_fight",1);
  setup();
  call_other("/obj/board/magic-card_b1" , "???");
}

string post()
{
  string msg = read_file(__DIR__"post");
  if(!msg) return HIC"�L���󤽧i"NOR;
  return msg;
}

void init()
{
  add_action("do_action","post");
  add_action("do_action","followup");
  add_action("do_checkc","checkc");
  add_action("do_listc","listc");
  add_action("do_savec","savec");
  add_action("do_getc","getc");
}

int do_action()
{
  object me = this_player();
  call_out("action",1,me);
  return 0;
}

void action(object me)
{
  object obj;
  remove_call_out("action");
  if(!me) return;
  if( in_input(me) )
  {
    call_out("action",1,me);
    return;
  }
  obj = load_object("/obj/board/magic-card_b2");
  obj->restore();
  return;
}

void reset()
{
  object obj;
  obj = load_object("/obj/board/magic-card_b2");
  obj->restore();
  ::reset();
}

int do_checkc()
{
  object *obs, me = this_player();
  int i, j = 0;
  string msg = HIW"�A���W���P��:\n"NOR;

  obs = all_inventory(me);
  for(i=0;i<sizeof(obs);i++)
  {
    if(obs[i]->query("id") != "magic card") continue;
    j++;
    msg += sprintf("�s��: "HIC"%3d"NOR" %12-s   ����: %d\n"NOR,j,obs[i]->query("short"),obs[i]->query("lv"));
  }
  write(msg);
  return 1;
}

int do_listc()
{
  object me = this_player();
  mapping c_index;
  int i, j;
  mixed *ver, *num, *amount;
  string msg = "";

  c_index = me->query("magic-card");
  if(!c_index) return notify_fail("�z�|���s�L�P.\n");
  ver = keys(c_index);

  for(i=0;i<sizeof(ver);i++)
  {
    msg += HIG"���� "+ver[i]+" :\n"NOR;
    num = keys(me->query("magic-card/"+ver[i]));
    amount = values(me->query("magic-card/"+ver[i]));
    for(j=0;j<sizeof(num);j++)
    {
      msg += sprintf("�d��"HIC"%3s "NOR,num[j]);
      msg += sprintf("�@�� "HIY"%3d"NOR" �i\n",amount[j]);
    }
    msg += "\n";
  }
  write(msg);
  return 1;
}

int do_savec(string str)
{
  object *obs, me = this_player();
  object *temp;
  int i, j = 0, arg;
  int ver, num;

  obs = all_inventory(me);
  temp = allocate(sizeof(obs));
  for(i=0;i<sizeof(obs);i++)
    if(obs[i]->query("id") == "magic card") 
    {
      temp[j] = obs[i];
      j++;
    }
  if(!j) return notify_fail("�A���W�S�����󪺵P�C\n");

  if(!str)
  {
    for(i=0;i<sizeof(temp);i++)
    {
      if(!temp[i]) break;
      write("�A�N�@�i"HIC+temp[i]->query("short")+NOR"�s�J�d���Ȧ��.\n");
      ver = temp[i]->query("ver");
      num = temp[i]->query("num");
      me->add("magic-card/"+ver+"/"+num,1);
      destruct(temp[i]);
    }
    tell_room(this_object(),HIW+me->query("name")+"��@�ǵP�s�J�F�d���Ȧ�.\n"NOR,this_player());
    me->save();
    return 1;
  }
  if(sscanf(str,"%d",arg) != 1) return notify_fail("�榡: savec �ĴX�i�d, �� savec �N�P�����s�J.\n");

  if(arg < 1 || arg > j) return notify_fail("�A�S���o�i�d.\n");
  arg--;

  write("�A�N�@�i"HIC+temp[arg]->query("short")+NOR"�s�J�d���Ȧ��.\n");
  ver = temp[arg]->query("ver");
  num = temp[arg]->query("num");
  me->add("magic-card/"+ver+"/"+num,1);
  destruct(temp[arg]);
  tell_room(this_object(),HIW+me->query("name")+"��@�ǵP�s�J�F�d���Ȧ�.\n"NOR,this_player());
  me->save();

  return 1;
}

// �Ȯɤ��}�� getc all
int do_getc(string str)
{
  object me = this_player();
  string ver, num;
  int amount;

  if(!str) return notify_fail("���O�榡: getc ���� �d��\n");

  if(sscanf(str,"%s %s",ver,num) != 2) return notify_fail("���O�榡: getc ���� �d��\n");
  amount = me->query("magic-card/"+ver+"/"+num);
  if(amount < 1) return notify_fail("�A�S���o�i�P\n");

  me->add("magic-card/"+ver+"/"+num,-1);
  if(me->money_type() == 1) new(WD_PAST+"magic-card/"+ver+"/card"+num)->move(me);
  if(me->money_type() == 2) new(WD_NOW+"magic-card/"+ver+"/card"+num)->move(me);

  write("�A�V�d���Ȧ洣�F�@�i "HIC"���� "+ver+" �d�� "+num+NOR" ���d�X��.\n");

  return 1;
}
