inherit MOBROOM;
void create()
{
        set("short", "後山");
        set("long",@LONG
你到了後山中的叢林中，這裡枝葉茂密樹叢遮天，自然的生機
非常蓬勃，樹上不時有野猴跑來跑去，看來十分逗趣，這裡的景色
優美，讓你放開胸懷靜靜的悠遊其中。
LONG
        );
  
set("exits", ([
  "southdown" : __DIR__"mu20",
  "northwest" : __DIR__"mu15",
   ]) );
        set("chance",50);
        set("mob_amount",2);
        set("mob_object",({
  __DIR__"animal/monkey",
  }) );
set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
 









