#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "船上");
        set("long", @LONG
這是一艘用竹子編織而成的一葉小舟，並無擺置雜物，在你腳邊放著
一枝長竹竿，看來是可用來撐船到湖心小屋。
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "竹竿" : "一枝長數尺的青綠色竹竿，看來倒還堅固，還堪使用(use)。\n",
]));
        set("exits", ([ /* sizeof() == 2 */
	  "out" : __DIR__"nb4",
       ]));
        set("light",1);
        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("douse","use");
}


int douse(string arg)
{
	object me,room,*inv;
	me=this_player();
	if(arg != "竹竿") return 0;
	if(!this_object()->query_temp("moving")) 
	{
		inv = all_inventory(this_object());
	        message_vision( HIW "$N拿起了長竹竿，往湖底插去，船漸漸地離開了岸邊...\n\n" NOR ,me);
		me->start_busy(3);
		call_out("domessage",3,3);
		this_object()->set_temp("moving",1);
		this_object()->delete("exits");
		room = load_object(__DIR__"nb4");
		room->delete("exits/enter");
		room->set("long",@ROOM_LONG
鶴子橋到了這裡就已到底，往北可看到五間竹房，離此尚有一大段距
離，就是當今輕功最高的人也難一蹴而及。

ROOM_LONG
);
		tell_room(room,"你看到橋邊的小船漸漸的離開了..\n");
		return 1;
	}else
	{
		tell_object(me,"船已經離岸了。\n");
		return 1;
	}

}

int domessage(int b)
{
  object *inv,room;
  int i;
  if(b==3) tell_room(this_object(),HIW "由於竹竿的推力，船慢慢的往前移動了...\n\n" NOR);
   else if(b==2) tell_room(this_object(), HIW "只見滿湖清澈，荷花盈盈，不時有鳥兒掠水而過，好一幅天上美景！！\n\n" NOR );
  else if(b==1) tell_room(this_object(), HIW "船划近了小屋，只見小屋離水面尚有數尺，門口有張長梯直達水面。\n\n" NOR );
  else  {
	        inv = all_inventory(this_object());
	        tell_room(this_object(),HIY "小船終於靠了岸，你順著梯子爬上了小屋..\n\n" NOR );
		this_object()->delete_temp("moving");
		room = load_object(__DIR__"waroom");
		tell_room(room,"你看到一條小船漸漸靠了過來..\n");
		for(i=0;i<sizeof(inv);i++)
		{
			if(living(inv[i])) inv[i]->move(__DIR__"waroom");
		}
		tell_room(room,"小船又順著水流漂走了..\n");
		this_object()->set("exits", ([
	  		"out" : __DIR__"nb4",
       		]));
		room = load_object(__DIR__"nb4");
		tell_room(room,"你看到有條小船漸漸的漂流了過來停靠在橋邊..\n");
		room->set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"nb3",
  "enter" : __DIR__"bship",
]));
		room->set("long",@ROOM_LONG2
鶴子橋到了這裡就已到底，往北可看到五間竹房，離此尚有一大段距
離，就是當今輕功最高的人也難一蹴而及。在你西邊停著一艘小船在橋邊
，看來可以上去瞧瞧。
ROOM_LONG2
);
		return 1;
		
	}
	b--;
	call_out("domessage",3,b);
}

