inherit ROOM;

void create()
{
        set("short", "森林入口內");
        set("long", @LONG
這裡是森林的入口，在這裡似乎有著比剛剛更多的紫蘇玉蘭花，不
過好像也是還沒成熟，據說被紫蘇玉蘭花所附著的樹木花草，在那株花
死了之後也會慢慢的死去，連御醫都不清楚，這裡的路開始有點陡峭，
令人有點難走。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"fgo1.c",
  "northwest" : __DIR__"fgo3.c",
]));
        set("no_clean_up", 0);
        set("outdoors","forest"); 
        set("objects",([
  __DIR__"npc/obj/wtree.c" :random(4),
]));
        set("item_desc", ([
                "霧洞" : "一團白霧，隱隱約約可以看到洞穴，好像可以進去的樣子(enter)。\n",
                ]));
        setup();
}
void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
          object me;
          me=this_player();
          if(arg != "霧洞")
            return 0;
          else {
            message_vision("$N緩緩的往霧洞走了進去。\n",me);
            me->move("/open/world1/moonhide/area/snake-room");
            return 1;
          }
}

