/**
 * Shadow's area [荒廢漁村 - a2]
 */
 
#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

string *find_msg=({ HIW"\n$N撥開四周雜亂的芒草，一吋一吋仔細地尋找出路...\n"NOR,
                    HIW"\n$N奮力往上一躍，希望藉此看出逃生之路...\n"NOR,
                    HIW"\n$N不死心的繼續搜尋著四周的芒草堆...\n"NOR });

void create()
{
	set("short",HIW"荒徑"NOR);
	set("long",
"路上的芒草似乎比剛剛還茂密，走著走著你不禁懷疑繼續走下去\n"
"會不會是條死路，再加上這無邊無際的芒草堆遮蔽了你的視線，真有\n"
"前不著村後不著店之苦，一股莫名的不安盤據著你的心頭，若不"HIW"尋覓"NOR"\n"
"出一條出路，恐將迷失在這荒廢小徑之中。\n"
	);
	set("light",1);
	set("outdoors","land");
	set("exits",([
		"west": __DIR__"a1",
	]));

	setup();
}

void init()
{
  add_action("do_find", "find");
  add_action("do_squeeze", "squeeze");
}

int do_find(string arg)
{
  object me = this_player();
  int a = 0;
  
  a = 10-((me->query("dex") + me->query("int"))/10);
  	
  if ( query("finding_now") ) 
	return notify_fail("似乎已有人正在尋找了!\n");

  if ( arg ) {
	message_vision(HIW"$N正屏氣凝神地想找"+arg+", 不過卻一無所獲...\n"NOR, me);
	return 0;
  }
  set("finding_now", 1);
  
  if ( !arg && !query("wasfound") ) 
  	call_out("find_one", 1, me, ( (a<2) ? random(a) : random(2) ), 0);
  	
  if ( !arg && query("wasfound") ) {
	message_vision(HIG"$N目光一閃，終於在芒草堆中發覺有個往北的出口，看來非得使上一番勁兒才鑽得過去。\n"NOR, me);
	delete("finding_now");
  }
  return 1;
}

void find_one(object me, int failed, int z)
{
  string msg;
  
  if ( !me ) { 
  	delete("finding_now"); 
  	return; 
  }
  
  if ( z < sizeof(find_msg) ) {
    z++;
    msg = find_msg[z-1];
    message_vision(msg, me);
    me->start_busy(2);
    call_out("find_one",2,me,failed,z);
  } else {
    if (failed) {
      message_vision(HIG"\n可惜$N啥東東都沒找到~~\n"NOR, me);
      delete("finding_now");
      return;
    }
    message_vision(HIG"$N目光一閃，終於在芒草堆中發覺有個往北的出口，看來非得使上一番勁兒才鑽得過去(squeeze)。\n"NOR, me);

    set("item_desc",(["出口": "這個出口看起來足夠讓一個人鑽過去。\n"]));       
    delete("finding_now");
    set("wasfound",1);
    return;
  }
}

int do_squeeze(string arg)
{
  object me = this_player();
  
  if ( !arg || arg != "出口" )
    return notify_fail("你以為你是鑽地獸嗎？找得到出口再鑽吧！\n");
     
  message_vision("$N縮著身子硬是鑽出了這芒草堆的包圍。\n", me);
  me->start_busy(2);
  me->move(__DIR__"a3");
  return 1;
}


