#include <ansi.h>
#include <room.h>
#include <door.h>
inherit DOOR;
inherit ROOM;

string *find_msg=({ HIC"\n$N決定開始找些什麼東西..不過茫無頭緒...\n"NOR,
                    HIC"\n$N開始東摸摸, 西摸摸, 可是啥都找不到...\n"NOR,
                    HIC"\n$N不死心的繼續盯著這四周景物看.........\n"NOR, });

void create()
{
 set("short","密林小路盡頭");
 set("long",@LONG
這是一片密林之中，看起來光線格外的不足，仔細看看四周環境，
確實是已經沒有任何可以再往下走的小徑了，但你四周充滿著不安的
氣息! 如果沒人發現你就快點離開吧! 要是這些大盜和你打起來就不
好了。咦？或許你發現(find)了什麼，總覺得這裡怪怪的。
LONG
);

 set("exits",([ "southeast":__DIR__"forest5",]));
 set("objects",([ __DIR__"npc/bandit3":1,
                  __DIR__"npc/bandit2":3, ]));
 set("no_clean_up", 0);
 set("outdoors","forest");
 setup();
}

void clear_key() {
  delete("picked");
  set("item_desc",([ "草堆" : "你明顯注意到這堆草叢似乎有點怪異。\n" ]));
}

void init()
{
  add_action("do_find","find");
  add_action("do_pick","pick");
}

int do_pick(string arg)
{
  object me,key;
  me=this_player();
  key = new(__DIR__"npc/obj/greenkey");
  if( !query("active_action") ) return 0;
  if( query("picked") ) return 0;
  if( me->is_fighting() || me->is_busy() ) return notify_fail("你正在忙耶!\n");
  if( !arg || ( arg != "key" && arg != "鑰匙" ) ) return notify_fail("你要撿什麼?\n");

  message_vision(HIB"$N突然從草叢間找出了一把鑰匙!\n"NOR,me);

  if( me->query_encumbrance() + key->query_weight() > me->query_max_encumbrance() ||
      me->query_capacity() + key->query("volume") > me->query_max_capacity() )
      key->move(environment(me)); 
  else
        key->move(me);

  set("picked",1);
  set("item_desc",([ "草堆" : "這草堆又沒什麼好看的..\n" ]));
  call_out("clear_key", 600 + random(300) );
  return 1;
}

int do_find(string arg)
{
  object me;
  int a,b,c;
  me=this_player();
  a=10-((me->query("dex") + me->query("int"))/10);
  if( me->is_fighting() || me->is_busy() ) return notify_fail("你正在忙耶!\n");
  if( query("finding_now") ) return notify_fail("已經有人在找了喔!\n");
  if( arg ) {
    message_vision(CYN"$N看起來想要找"+arg+", 不過找了老半天都找不到...\n"NOR,me);
    return 0;
  }
  set("finding_now",1);
  if(!arg && !query("wasfound") ) call_out("find_one",1,me,( (a<2) ? random(a) : random(2) ),0);
  if(!arg && query("wasfound") ) {
    message_vision(CYN"$N很輕易的看到有個往下(down)的門.\n"NOR,me);
        delete("finding_now");
  }
  return 1;
}

void find_one(object me,int failed,int z)
{
  object room;
  string msg;
  int a,b,c;
  me = this_player();
  room = load_object(__DIR__"bandit1");
  if(!me) { delete("finding_now"); return; }
  if( z < sizeof(find_msg) ) {
    z++;
    msg = find_msg[z-1];
    message_vision(msg,me);
    me->start_busy(2);
    call_out("find_one",2,me,failed,z);
  }
  else {
    if(failed) {
      message_vision(HIC"\n可惜$N啥東東都沒找到。\n"NOR,me);
      delete("finding_now");
      return;
    }
    message_vision(HIY"\n竟然給$N發現了一道往下(down)的密門!!\n"NOR,me);

    set("exits", ([ "down" : __DIR__"bandit1",
                    "southeast" : __DIR__"forest5",]));
    room->set("exits", ([ "up" : __DIR__"forest6",
                          "northwest" : __DIR__"bandit2", ]));
    create_door("down","硬木板密門","up",DOOR_LOCKED,"greenkey");
    room->create_door("up","硬木板密門","down",DOOR_LOCKED);
    delete("finding_now");
    set("wasfound",1);
    return;
  }
}
int valid_leave(object me, string dir)
{
  mapping doors;
  doors = environment(me)->query_doors();
  if( dir=="down" && doors[dir]["status"] == DOOR_OPENED ) {
    message_vision(YEL"\n$N走下去後, 只見『碰』的一響, 密門馬上關上了!...\n"NOR,me);
    lock_door(dir);
    return 1;
  }
  else if( dir=="down" && !doors[dir]["status"] == DOOR_OPENED ) 
    return notify_fail("門還沒開喔!\n");
  else if(dir=="southeast") return 1;
  else return 0;
}

