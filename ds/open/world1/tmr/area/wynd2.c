inherit ROOM;

void create()
{
        set("short", "巷子口");
        set("long", @LONG
你正在一條不知名的巷子口，往南可看到一間賭坊，只聽得裡頭不時
傳來吆三喝六的吵雜聲，門口站著兩名彪形大漢，看來是此間賭坊的保鏢
，要進去此間賭坊似乎不是那麼地容易。往東是條頗陰暗的巷子。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
          "south" : __DIR__"casino",
          "east" : __DIR__"wynd",
        ]));
        set("item_desc",([
        "彪形大漢" : @GUYS
兩個凶惡的大漢正在賭坊大門口檢查賭客，除非你能
展示(show)一些賭客的證明物給他們看，否則很難進入。
GUYS
,
        ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_show","show");
}

int valid_leave(object me, string dir)
{
         return ::valid_leave(me, dir);
        if( dir == "south")
        {
                if (!me->query_temp("casino_enter"))
                {
                        message_vision("彪形大漢伸手把$N攔了下來，說道：「這位"+RANK_D->query_respect(me)+"，這可不是你該來的地方吧！」\n",me);
                        return 0;
                }
                else 
                {
                        message_vision("彪形大漢對著$N拱手說道：「這位" +RANK_D->query_respect(me)+"請進請進！！」\n", me);
			me->set_temp("casino_enter",0);
                        return ::valid_leave(me, dir);
                }
        }
        return ::valid_leave(me, dir);
}

int do_show(string arg)
{
        object who;
        who=this_player();
        if( !objectp(present("dice", who)) ) return 0;
        if(arg != "骰子" && arg !="dice" ) return 0;
        message_vision("$N從懷裡拿出了一粒骰子，在彪形大漢的面前晃了晃。\n",who);
        if (who->query_temp("casino_enter")) return 1;
        who->set_temp("casino_enter",1);
        message_vision("彪形大漢仔細地看了看$N手上的骰子，說道：「原來這位"+ who->query("name")+"也是一位同好中人。」\n",who);
        return 1;
}

