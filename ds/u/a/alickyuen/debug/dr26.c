// Room: /u/a/alickyuen/area/dr26.c
// learn literate
// New room
// For join doctor use
inherit ROOM;
void create()
{
	set("short", "ST。Hospital＠Computer-room");
	set("long", @LONG
這裡是這間醫院的電腦教學室，用現時在先進的科技來教學，一排排
椅子放在這裡，還有這裡懷柔的燈光，真的很容易令人睡著。令你最驚訝
的是，坐在椅子上的人都昏昏沈沈，不像在學習。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"dr25",
]));
set("light",1);
set("no_recall",1);
set("no_fight",1);
set("no_kill",1);
set("no_exert",1);
set("no_cast",1);
	set("world", "future");
	set("no_clean_up", 0);
	setup();
}

int room_effect()
{
object me;
me=this_player();
          switch(random(10))
        {
         case 0:
                message_vision("你漸漸覺得沉悶，開始睡了起來。\n",me);
break;
         case 1:
                message_vision("你感覺到腦海之中跑出一大堆你以前沒學的字。\n",me);
break;         
case 2:
                message_vision("你突然驚醒過來，好像什麼也沒發生過，但你的腦中彷彿充滿學問。\n",me);
break;
         default:
message_vision("你腦海中突然出現一些奇異的影像，你的思想正一步步地進入這神秘世界之中．．．\n",me);
break;       
}
if (me->query_skill("literate",1) <100)
                {
                        me->improve_skill("literate",me->query_int()/10+random(2));
                }
}
