//移動房間.c 
//update by luky. 1998.11.12
#include <ansi.h>
//#include <path.h>
#define UP_DOOR "climb"
#define DOWN_DOOR "out"
inherit ROOM;
int index=1;
int close_time;
int indexp=0;
int stay=1;
//設定目的地順序
string *place=({
"/d/wiz/hall1",
"/u/s/shengsan/workroom",
"/u/l/luky/workroom1",
});
//相對於place順序的航行時間
int *span_time=({25,30,40});
//航行時的訊息(每5秒一次)
string *float_msg=({
"清涼的海風微微地吹拂你的臉頰。\n",
"一陣大浪打來，把你的褲管給打濕了。\n",
"突然有一隻海鷗從你的頭上飛過。\n",
"船身緩緩的搖了一下。\n",
"突然有隻海豚從你腳旁探出頭來，過了一會兒又潛了下去。\n",
});
void start();
void boat(string);
void swim(int);
string query_filename()
{
  return place[index];
}

int getall()
{
  int i;
  for(i=0;i<sizeof(place);i++)
    if(stay)
      tell_object(this_player(),sprintf("%2d %10s %s %s \n",
           i+1,
           i==indexp ? HIY"目前停在->"NOR:"  ",
           place[i]->query("short"),
wiz_level(this_player())>=wiz_level("(apprentice)")?"=> ("+place[i]+")":"
"
             ));
     else
      tell_object(this_player(),sprintf("%2d %8s %s %s \n",
           i+1,
           i==index ? HIY"下一站->"NOR:" ",
           place[i]->query("short"),
 wiz_level(this_player())>=wiz_level("(apprentice)")?"=> ("+place[i]+")":"
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
set("no_kill",1);
set("ship_long",@LONG
你正站在大螃蟹背上的小木台上，木台是由數十支金剛木樹幹銜接而成。
上面有幾個簡單的木椅以及一張方型的桌子，牢固的釘在木板上。桌子上有一
張地圖(Map) 和一張紙(Note)。由於大螃蟹奇特的巡游習性，使得人們可以方
便的越洋旅行，甚至不必付代價。

LONG
);
set("item_desc",([
  "note":"\n旅客請注意以下守則: \n\n"
  	+"   1. 請勿亂丟垃圾, 共同維持環境整潔.\n"
  	+"   2. 可以用(List)來看看沿途有停靠的地點.\n\n",
  "map":"\n你發現那只是一張白紙, 似乎還沒畫好。\n",
]));
setup();
call_other( "/obj/board/luky_b", "???" );
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
    message_vision(HIG"$N[1;32m登上了"+this_object()->query("name")+" 。\n"NOR,me);
}

void swim(int secs)
{
	int k;
	k=random(7)+6;
	if(secs>7)
	{
		tell_room(this_object(),float_msg[random(sizeof(float_msg))]);
		secs-=k;
		remove_call_out("swim");
		call_out("swim",k,secs);
	}
	else
	{
		tell_room(this_object(),"\n我們即將抵達目的地: "+place[index]->query("short")+"\n");
		remove_call_out("swim");
		call_out("boat",7,"前正往 "+place[index]->query("short")+"中");
	}
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
  s=sprintf(" [1;34m%s[0m\n"NOR, (place[index])->query("short"));
  set("long",this_object()->query("ship_long")+HIR"  大螃蟹"HIG"正停靠在"+s+"\n "NOR);
  tell_room(this_object(),HIG"\n  我們已經抵達 "+place[index]->query("short")+" !!\n\n"NOR);
  tell_room(this_object(),HIW"  要離開的旅客請排隊離開(out)..\n"+NOR+"\n");
  setup();
  ex=place[index]->query("exits");
// add by Nilekil
        ob1=new("/u/l/luky/tempship.c");
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
close_time=30;
  stay=1;
  call_out("closedoor1",0,"正停靠在 "+place[indexp]->query("short"));
}
void closedoor1(string s)
{
  object this_ship,temp_ship,ob1,ob2;
  mapping ex;
  this_ship=this_object();

  if(close_time>10)
  {
  	close_time -=10;
	remove_call_out("closedoor1");
	call_out("closedoor1",10,"停靠在 "+place[indexp]->query("short"));
  }
  else if(close_time>0)
  {
	tell_room(this_object(),"還有" +HIY+sprintf("%d",close_time)+NOR+"秒就要出發了\n");
	tell_room(place[indexp],"大螃蟹就要出港了!請要搭乘的旅客趕快爬上來("+UP_DOOR+").....\n"NOR);
	close_time -=5;
	remove_call_out("closedoor1");
	call_out("closedoor1",5,"停靠在 "+place[indexp]->query("short"));
  } else 
  {
	tell_room(this_object(),HIW"螃蟹震動了一下...緩緩的往"+place[index]->query("short")+HIW+"前進...\n"NOR);
	// add by nilekil
	ob1=find_object(place[indexp]);
	ob2=present("cancer",ob1); 
	if (!ob2)
	{ 
        	tell_room(place[indexp],"大螃蟹的屍體漸漸沉下去了...\n");
         	destruct(this_ship); // Luky
         	return;
        } else
        { 
                tell_room(place[indexp],"大螃蟹伸個懶腰, 往海面移動...\n");
                destruct(ob2);
        }
	tell_room(place[indexp],HIR"大螃蟹[1;36m緩緩的離開了陸岸，開始往"+
		place[index]->query("short")+HIC"移動..[0m\n");
	set("long",this_object()->query("ship_long")+HIR"  大螃蟹"HIG"現在正在前往 "
		+place[index]->query("short")+" 的途中...\n\n"NOR);
   ex=this_object()->query("exits");
   if(mapp(ex)) map_delete(ex,DOWN_DOOR);
   ex=place[indexp]->query("exits");
   if(mapp(ex)) map_delete(ex,UP_DOOR);
   place[indexp]->set("exits",ex);
   remove_call_out("closedoor1");
   stay=0;
//call_out("boat",span_time[index],"前正往 "+place[index]->query("short")+"中");
  call_out("swim",5,span_time[index]);
  }
}
