inherit ROOM;

void create()
{
        set("short", "街道");
        set("long", @LONG
你正走在一條街道中，只見東邊一座大牢，圍著一道黑色圍牆，牆高
兩丈，塗著黑漆漆的，甚是恐怖，更奇的是竟看不到任何門戶，不知如何
出入。牆前豎有一面佈告欄，上頭貼著一紙公告。往北可看到一座小廣場
，在西南方似乎有條小巷子，南邊是條小街道。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
	  "south" : __DIR__"vroad5",
	  "north" : __DIR__"vroad2",
	  "southwest" : __DIR__"vroad6",
	]));
	set("item_desc",([
	"公告" : "一張已泛黃的紙張，上頭寫著：「八氣牢」。\n",
      "圍牆" : "一大片黑鐵皮圍成的牆，看來年代頗為久遠，你在牆角看到一個小破洞。\n",
	]) );
        
	set("outdoors","land");
	set("no_clean_up", 0);
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
        if(!arg|| arg!="破洞") return 0;
        message_vision("$N一縮身，鑽進了一個破洞。\n",me);
        me->move(__DIR__"eight-room");
        tell_room(environment(me),me->query("name")+"忽然出現在你的面前。\n",({ me }) );
        return 1;
}

