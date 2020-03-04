//boat.c 
//update by luky. 1998.11.12
#include <ansi.h>
#include <path.h>
#define TIME_SPAN tt
#define UP_DOOR "climb"
#define DOWN_DOOR "out"
inherit ROOM;
int index=1;
int close_time;
int indexp=0;
int stay=1;
string *place=({
LUKY+"pearl/sand2",
LUKY+"pearl/pearl_32",
});
int tt=30;
void start();
void boat(string);
string query_filename()
{
  return place[index];
}
int getall()
{
  int i;
  for(i=0;i<sizeof(place);i++)
    if(stay)
      write(sprintf("%2d %10s %s %s \n",
           i+1,
           i==indexp ? HIY"目前停在->"NOR:"  ",
           place[i]->query("short"),
wiz_level(this_player())>=wiz_level("(admin)")?"=> ("+place[i]+")":"
"
             ));
     else
      write(sprintf("%2d %8s %s %s \n",
           i+1,
           i==index ? HIY"下一站->"NOR:" ",
           place[i]->query("short"),
 wiz_level(this_player())>=wiz_level("(admin)")?"=> ("+place[i]+")":"
"
             ));

  return 1;
}

void create()
{
//seteuid(getuid());
set("short","[1;31m大螃蟹[0m");
set("name","[1;31m大螃蟹�[m");
set("id","cancership");
set("long", @LONG
              ◢███◣                  ◢███◣
            ◢██◤  ◥◣              ◢█◤  ◥█◣
        ◢███◤                                 ◥█◣
      ◢████◣▁▁◢█◤             ◣      ◢███◣
      ██◤  ◥████◤               ◥████◤  ◥█◣
      ◥█◣                ☉          ☉               █◤
        ◥██◣            ��          ��           ◢█◤
             ◥██◣ ▁▃▄▆▆▇█▇▆▆▄▃▁◢██◤
            ▁▃▅▇███████████████▇▅▃▁
    ◢██◣◥█████████████████████◤◢██◣
  ◢◤    ◥◣█████████████████████◢◤    ◥◣
◢◤          ◥███████████████████◤          ◥◣
        ◢██◤████▇▆▅▄▃▂▃▄▅▆▇████◥█◣
      ◢◤      ◥█████████████████◤    ◥◣
    ◢◤    ◢█◣◥██████████████◤◢█◣    ◥◣
    ◤    ◢◤    ◢◤◥███████████◤◥◣  ◥◣    ◥
          █      █        ◥█████◤        █    █
          ◥      ◥◣                          ◢◤    ◤ 
LONG);
set("unit","隻");
set("light",1);
call_out("boat",0,place[index]->query("short"));
}
void init()
{
        object ob;
        ob=this_player();
        start();
  add_action("getall","list");

}

void start()
{
    object me;
    me=this_player();
    message_vision(HIG"$N[1;32m登上了"+this_object()->query("name")+"。\n"NOR,me);
}

int getman()
{
  object *inv;
  int i,all;
  all=0;
  inv=all_inventory(this_object());
//  for(i=0;i<sizeof(inv);i++)
//  if(userp(inv[i]))all++;
  all=sizeof(inv);
  return all;
}

void boat(string ss)
{
  object ob,this_ship,temp_ship,ob1,ob2;
  string s;
  mapping ex;
  this_ship=this_object();
  set("exits",([
  DOWN_DOOR: place[index],
  ]));
  s=sprintf(HIR"大螃蟹已到達 [1;34m%s[0m\n"NOR
  HIC"目前螃蟹上的旅客總共有 %d 個人\n"NOR, (place[index])->query("short")
  , getman());
  set("long",HIG"你向窗外望去，赫然發現"+s+"\n\n "HIY+"list"NOR+"可查看沿途停靠的站喔\n "NOR);
  write(s+"你看到窗外的景物是:\n"+place[index]->query("long")+"\n");
  write(HIW"要離開的旅客請排隊下車(out)..\n"+NOR+"\n");
  setup();

  ex=place[index]->query("exits");
// add by Nilekil
        ob1=new(LUKY+"pearl/tempship.c");
        ob2=find_object(place[index]);
        ob1->move(ob2);
  tell_room(place[index],
HIC"[1;31m大螃蟹[1;36m慢慢的游進了港口.....\n"NOR);
  if(mapp(ex))
  place[index]->set("exits",(mapping)(place[index]->query("exits"))+
  ([ UP_DOOR : base_name(this_object()), ]) );
  else {
    ex=([]);
 ex[UP_DOOR]=base_name(this_object());
    place[index]->set("exits",ex);
  }
  indexp=index;
  index++;
  if(index==sizeof(place)) index=0;
remove_call_out("boat");
close_time=20;
  stay=1;
  call_out("closedoor1",0,"正停靠在 "+place[indexp]->query("short"));
}
void closedoor1(string s)
{
  object this_ship,temp_ship,ob1,ob2;
  mapping ex;
this_ship=this_object();
  if(close_time>0)
{
//write("還有" +HIY+sprintf("%d",close_time)+NOR+"秒就要出發了\n");
tell_room(place[indexp],"大螃蟹就要出港了!請要搭乘的旅客趕快爬上來("+UP_DOOR+").....\n"NOR);
close_time -=10;
remove_call_out("closedoor1");
call_out("closedoor1",10,"停靠在 "+place[indexp]->query("short"));
} else 
{
write(HIW"螃蟹震動了一下...緩緩的往"+place[index]->query("short")+HIW+"前進...\n"NOR);
// add by nilekil
ob1=find_object(place[indexp]);
ob2=present("cancer",ob1); 
if (!ob2)         { 
                tell_room(place[indexp],"大螃蟹覺得太累..躲起來不上班了!!\n");
         destruct(this_ship); // Luky
        }
        else { 
                tell_room(place[indexp],"大螃蟹伸個懶腰, 往海面移動...\n");
                destruct(ob2);
        }
tell_room(place[indexp],HIR"大螃蟹[1;36m緩緩的離開了港口，開始往"+
place[index]->query("short")+HIC"移動..[0m\n");
set("long","你現在正由 "+place[indexp]->query("short")+
   " 行駛往 "+place[index]->query("short")+" 途中...\n"+
   "可打 "+HIY+"list"+NOR+" 來查看沿途經過的站\n\n");
   ex=this_object()->query("exits");
   if(mapp(ex)) map_delete(ex,DOWN_DOOR);
   ex=place[indexp]->query("exits");
   if(mapp(ex)) map_delete(ex,UP_DOOR);
   place[indexp]->set("exits",ex);
   remove_call_out("closedoor1");
   stay=0;
call_out("boat",TIME_SPAN,"正開往 "+place[index]->query("short")+"中");
  }
}
