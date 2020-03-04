// Room: /u/s/suez/area/hotel_back.c
inherit ROOM;
void create()
{
	set("short", "地下密室");
	set("long", @LONG
這裡是間地下密室，充滿了灰土，你掉下來時身上也沾著了不少。仔
細看看這裡，到處都是殘破的書簡，生鏽的兵器，腐壞的衣著等等。看來
似乎很久沒有人來過了，不過你似乎在充斥此地的霉味中嗅到些許的血腥
，難道這裡曾經......？
LONG
	);

        set("objects",([
              __DIR__"npc/eq/star_robe" : 1,
              ]) );
	setup();
}
void init()
{
        add_action("do_push", "push");
}

int do_push(string arg)
{
        object me;
        me=this_player();
 

        if (arg != "牆壁" && arg !="牆" )
                return 0;
        else 
        {
        me->move(__DIR__"base_2");
        tell_room(environment(me),"牆上的雕刻突然轉動！"+me->query("name")+"竟由牆後走了出來！！\n",me);
        return 1;
        }
}