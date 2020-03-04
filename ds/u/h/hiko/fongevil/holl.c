inherit ROOM;
void create()
{
        set("short", "山洞");
        set("long",@LONG
你來到了山洞內，山洞內黑漆漆的，竟然好像一東西瞪著你，忽
然你聽到一聲獸吼，原來是一隻大黑熊在你身前，它的眼神十分憤怒
，看來你是侵入了牠的地盤了。
LONG
        );
  
set("exits", ([
  "north" : __DIR__"holl-n",  "out" : __DIR__"mu18",
   ]) );       
set("objects",([
  __DIR__"npc/black_bear" : 1,
        ]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
 }
 

 int valid_leave(object me, string dir)
{
  object guard;
  if( objectp(guard=present("black bear", this_object())) && dir == "north" )
  {
    message_vision("一聲怒吼，$n忽然撲了過來，只見牠擋在$N面前，不讓$N過去。\n",me ,guard);
        return notify_fail("");
  }
  return ::valid_leave(me, dir);
}




