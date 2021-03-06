#include <room.h>
#include <ansi.h>
#include <path.h>
inherit ROOM;  
void entercheck(object ob);

void create()
{
 set("short","地道盡頭");
 set("long",@LONG
你來到了這個地道的盡頭, 當你一過來時你就知道事情不妙了,
你的前方有許多凶神惡煞般的強盜正在等著他們的獵物..而你當然
就成了他們的獵物了!!(如果他們還在的話). 這邊就是地道盡頭了
, 你看到一個比你強壯許多的人坐在一張虎皮椅上, 看來他就是這
兒的頭頭了. 不過你似乎沒路出去..!?四周有一些油燈(lamp)掛在
牆上, 你可以熄滅(dough)它.
LONG);

 set("exits",(["east":__DIR__"bandit2"]));
 //此處要加 mob.
 set("objects",([ __DIR__"npc/chang":1,
                  __DIR__"npc/biaw":1,
                  __DIR__"npc/ler":1,
                  __DIR__"npc/jur":1, ]));
 set("no_clean_up", 0);
 set("light",1);
 set("no_recall",1);
 setup();
}

void init()
{
  add_action("do_dough","dough");
  add_action("do_press","press");
  call_out("entercheck",1,this_player());
}

void clean()
{
  object popppl;
  mapping pops=([ ]);
  string *poplist;
  int a;
  if(!query_temp("clean") > 3 || !query_temp("die/jur") || !query_temp("die/ler") ||
     !query_temp("die/biaw") || !query_temp("die/chang") ) return;
  pops = query_temp("pop");
  poplist = keys(pops);
  message("world:world1:vision",HIY"\n【江湖快報】皇城東郊四大盜被 "NOR,users());
  for(a = 0; a < sizeof(poplist) ; a++ ) {
    if( find_player(poplist[a]) ) {
      popppl = find_player(poplist[a]);
      popppl->add("popularity",12/sizeof(poplist) );
    }
    if(a == 0) message("world:world1:vision",HIC+popppl->query("name")+" "+NOR,users());
    else if( a > 0 && poplist[a-1] != poplist[a] )
      message("world:world1:vision",HIC+popppl->query("name")+" "+NOR,users());
  }  
  message("world:world1:vision",HIY+chinese_number(a)+"人給消滅了，真是可喜可賀。\n"NOR,users());
  delete_temp("clean");
  delete_temp("die");
  delete_temp("pop");
  return;
}

int user_light(object me)
{
 object *inv2;
 int j;
 if(me->query_temp("has_light")) return 1;
 if(living(me))
 {
    	  inv2 = all_inventory(me);
    	  if( sizeof(inv2) > 0)
	  for(j=0; j<sizeof(inv2); j++)
    	  {
    	   if( inv2[j]->query_temp("has_light") ) return 1;
  	  }
  } 
 return 0;
}

int can_look(object me) 
{
	object env,*inv;
	int i;
	
        if(!me) return 0;
	env=environment(me);
	if(!env) return 0;
	if(env->query("light") > 0) return 1;	//有設照明
        if(user_light(me)) return 1;		//本人有照明
	inv = all_inventory(env);

	// 以下程式由 shengsan 簡化了 ..Luky 再簡化一次..:P
	if( env->query("outdoors") && NATURE_D->query_light() > 1) return 1;	//戶外白天

	if( sizeof(inv) > 0)
	for(i=0; i<sizeof(inv); i++)
	{
	  if(user_light(inv[i])) return 1;
	}
  	return 0;
}


int do_dough(string arg)
{
  object me;
  me=this_player();
  if(!arg || (arg != "油燈" && arg != "lamp")) return notify_fail("你要熄滅什麼?\n");
  if( query("doughed") ) return notify_fail("油燈已經熄了.\n");
  if( me->is_fighting() || me->is_busy() )
    return notify_fail("你正在忙喔!\n");
  message_vision(RED"$N熄滅了油燈, 四周變一片漆黑.\n"NOR,me);
  delete("light");
  add("current_light",-1);
  set("doughed",1);
  set("long",@LONG
你來到了這個地道的起點, 當你一過來時你就知道事情不妙了,
你的前方有許多凶神惡煞般的強盜正在等著他們的獵物..而你當然
就成了他們的獵物了!!(如果他們還在的話). 這邊就是地道盡頭了
, 你看到一個比你強壯許多的人坐在一張虎皮椅上, 看來他就是這
兒的頭頭了. 不過你似乎沒路出去..!?四周有一些已經無法點著的
油燈.
LONG);
  call_out("entercheck",1,this_player());
  return 1;
}

void entercheck(object ob)
{
  if(!can_look(ob)) {
    message_vision("$N似乎發現了什麼....!\n",ob);
    write(HIR"你注意到似乎牆上有個會發淡光的小扣鎖(button)可以去按(press)它!\n"NOR);
    ob->set_temp("findbutton",1);
  }
  return;
}
int do_press(string arg)
{
  object me;
  object room;
  me=this_player(); 
  room = load_object(COMINGING_PAST+"area/fgo8");
  if( !me->query_temp("findbutton") ) return 0;
  if( !arg || (arg != "小扣鎖" && arg != "button" && arg != "扣鎖") ) 
    return notify_fail("你要按什麼?\n");
  if( query("light") || user_light(me) )
    return notify_fail("這邊光線太亮, 擋住了扣鎖發出的淡光, 以至於你暫時無法看見扣鎖.\n");
  if( me->is_fighting() || me->is_busy() )
    return notify_fail("你正在忙喔!\n");
  if( sizeof(query("exits")) > 1 )
    return notify_fail("扣鎖鎖住的牆已經裂開一個縫了, 你就快點出去吧!\n");
  message_vision(HIW"$N將扣鎖用力的一按, 突然往北方的密門突然打開了!!\n"NOR,me);      
  room->printmessage(1,room);
  set("exits",([ "east":__DIR__"bandit2",
                 "northup":COMINGING_PAST+"area/fgo8", ]));
  room->set("exits",([ "north" : COMINGING_PAST+"area/fgo9",
                       "east" : COMINGING_PAST+"area/fgo7", 
                       "southdown" : "/open/world1/linjack/emperor/bandit3", ]));
  tell_room("/open/world1/linjack/emperor/bandit3",HIW"\n光線照了進來...這裡明亮了許\多.\n"NOR);
  set("light",1);
  me->delete_temp("findbutton");
  call_out("closewall",7,me,room);
  return 1;
}
void closewall(object me,object room)
{
  tell_room("/open/world1/linjack/emperor/bandit3","這真是太神奇了! 密門居然自己又關上了...!\n");
  room->printmessage(0,room);
  set("exits",([ "east":__DIR__"bandit2" ]));
  room->set("exits",([ "north" : COMINGING_PAST+"area/fgo9",
                       "east" : COMINGING_PAST+"area/fgo7", ]));
  tell_room("/open/world1/linjack/emperor/bandit3",HIB"\n這裡又暗了下來...\n"NOR);
  delete("light");
  return;
}
