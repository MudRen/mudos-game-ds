/**
 * Shadow's area [荒廢漁村 - a1]
 */
 
#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

string *find_msg=({ HIW"\n$N撥開雜亂的芒草堆，企圖找出前人所遺留下來的足跡...\n"NOR,
                    HIW"\n$N將四周的芒草攔腰折斷，期盼能找到一條出路...\n"NOR, });


void create()
{
	set("short",HIW"荒徑"NOR);
	set("long",@LONG
這是一條人跡罕至的小道。舉目環繞四周，遍地盡是高逾人肩的
芒草，昔人的足跡早已被夾道的芒草所掩蓋，銜接的道路在你眼前沒
入芒草堆中，不知何去何從，看來似乎需要花一番功夫尋找(find)才
行。
LONG
	);
	set("outdoors","land");
	set("light",1);
	set("exits",([
		"west": __DIR__"arearoom",
	]));

	/**
	 * 設計物品與生物
	 */	 

	setup();
}

void init()
{
  add_action("do_find", "find");
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
	message_vision(HIG"$N目光一閃，終於在芒草堆中發覺有條往東的小徑。\n"NOR, me);
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
    message_vision(HIG"$N目光一閃，終於在芒草堆中發覺有條往東的小徑。\n"NOR, me);

    set("exits",([
	"west": __DIR__"arearoom",
	"east" : __DIR__"a2",
	]));

    delete("finding_now");
    set("wasfound",1);
    return;
  }
}
