#include <ansi.h>
#include <path.h>
inherit ROOM;

string post();

void create()
{
  set ("short", HIC"[Magic-Card 專賣店] "HIW"大"HIR"火堯"HIW"包"NOR);
  set ("long", @LONG

這裡是專門販賣 Magic紙牌的小店，你可以打 [list] 來看看有
什麼可以買的東西，店裡面放著桌子，可供你遊樂，另外這裡也
常舉辦小型比賽，時間都寫在佈告欄 (post) 上。

 另外你可以用:
 checkc          檢查你身上有哪些牌
 listc           查看你有哪些牌存在卡片銀行裡
 savec 第幾張卡  將牌存入卡片銀行 (如果沒打數字則將身上全部的牌存入)
 getc 版本 卡號  提出你存在卡片銀行的卡片

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
  if(!msg) return HIC"無任何公告"NOR;
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
  string msg = HIW"你身上的牌為:\n"NOR;

  obs = all_inventory(me);
  for(i=0;i<sizeof(obs);i++)
  {
    if(obs[i]->query("id") != "magic card") continue;
    j++;
    msg += sprintf("編號: "HIC"%3d"NOR" %12-s   等級: %d\n"NOR,j,obs[i]->query("short"),obs[i]->query("lv"));
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
  if(!c_index) return notify_fail("您尚未存過牌.\n");
  ver = keys(c_index);

  for(i=0;i<sizeof(ver);i++)
  {
    msg += HIG"版本 "+ver[i]+" :\n"NOR;
    num = keys(me->query("magic-card/"+ver[i]));
    amount = values(me->query("magic-card/"+ver[i]));
    for(j=0;j<sizeof(num);j++)
    {
      msg += sprintf("卡號"HIC"%3s "NOR,num[j]);
      msg += sprintf("共有 "HIY"%3d"NOR" 張\n",amount[j]);
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
  if(!j) return notify_fail("你身上沒有任何的牌。\n");

  if(!str)
  {
    for(i=0;i<sizeof(temp);i++)
    {
      if(!temp[i]) break;
      write("你將一張"HIC+temp[i]->query("short")+NOR"存入卡片銀行裡.\n");
      ver = temp[i]->query("ver");
      num = temp[i]->query("num");
      me->add("magic-card/"+ver+"/"+num,1);
      destruct(temp[i]);
    }
    tell_room(this_object(),HIW+me->query("name")+"把一些牌存入了卡片銀行.\n"NOR,this_player());
    me->save();
    return 1;
  }
  if(sscanf(str,"%d",arg) != 1) return notify_fail("格式: savec 第幾張卡, 或 savec 將牌全部存入.\n");

  if(arg < 1 || arg > j) return notify_fail("你沒有這張卡.\n");
  arg--;

  write("你將一張"HIC+temp[arg]->query("short")+NOR"存入卡片銀行裡.\n");
  ver = temp[arg]->query("ver");
  num = temp[arg]->query("num");
  me->add("magic-card/"+ver+"/"+num,1);
  destruct(temp[arg]);
  tell_room(this_object(),HIW+me->query("name")+"把一些牌存入了卡片銀行.\n"NOR,this_player());
  me->save();

  return 1;
}

// 暫時不開放 getc all
int do_getc(string str)
{
  object me = this_player();
  string ver, num;
  int amount;

  if(!str) return notify_fail("指令格式: getc 版本 卡號\n");

  if(sscanf(str,"%s %s",ver,num) != 2) return notify_fail("指令格式: getc 版本 卡號\n");
  amount = me->query("magic-card/"+ver+"/"+num);
  if(amount < 1) return notify_fail("你沒有這張牌\n");

  me->add("magic-card/"+ver+"/"+num,-1);
  if(me->money_type() == 1) new(WD_PAST+"magic-card/"+ver+"/card"+num)->move(me);
  if(me->money_type() == 2) new(WD_NOW+"magic-card/"+ver+"/card"+num)->move(me);

  write("你向卡片銀行提了一張 "HIC"版本 "+ver+" 卡號 "+num+NOR" 的卡出來.\n");

  return 1;
}
