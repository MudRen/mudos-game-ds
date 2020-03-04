inherit ROOM;
void create()
{
        set("short", "扶桑浪人營");
     set("light",1);
        set("long", @LONG
這裡就是遠近馳名的扶桑浪人營了，你的身旁有許多浪人武士們正在
聊天，也有的在練劍，看樣子個個都武術高強，但每個人都笑容可鞠，
畢竟也都是練武之人，他們應該都會很尊敬你，你發現旁邊好像有一
條小路的樣子。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"map_1",
  "northeast" : __DIR__"map_4",
  "east" : __DIR__"map_3",
  ]));
  set("item_desc",([
        "小路":"你從小路那似乎聽到了涓涓溪水聲..你可以走(goin)過去看看。\n",
        ]));
    set("objects",([
       __DIR__"npc/fu_man" : 2,
    ]) );
         set("outdoors","land");
         set("no_clean_up", 0);
 setup();
  }
void init()
{
        add_action("do_goin","goin");
}

int do_goin(string arg)
{
        object me;
        me=this_player();
        if(!arg|| arg!="小路") return 0;
        message_vision("$N蹦蹦跳跳的往小路走去....好不快樂。\n",me);
        me->move(__DIR__"fu");
        tell_room(environment(me),me->query("name")+"從小路那走了過來。\n",({ me }) );
        return 1;
}


