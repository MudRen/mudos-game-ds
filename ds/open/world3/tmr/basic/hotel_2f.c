// Room: /open/world3/tmr/basic/hotel_2f.c
//update -By Tmr- 2000/4/9

inherit ROOM;

void create()
{
        set("short", "酒館二樓");
        set("long", @LONG
你正在酒館的二樓，你可以清楚著看到裡並不是給大夥喝酒吃飯用，
有十數台微光傳波網機器架設在此，你可以透過這些機器連上世界網路，
享受許多服務。
LONG
        );
        set("world", "future");
        set("light", "1");
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
          "down" : __DIR__"hotel",
        ]));
        set("item_desc",([
"微光傳波網":"屬於較初級的上網機器，你可以按上頭的help鍵，以取得相關資訊。(push help)\n",
        ]) );

        setup();
}

void init()
{
        add_action("do_push","push");
}

int do_push(string arg)
{
        object me;
	me=this_player();
        if(!arg || arg!="help")
                return notify_fail("似乎沒有這個按鍵。\n");
        tell_object(me,@long

□微光傳波網服務系統□

            線上服務：     收費：

電子帳戶轉帳(virement)    100 Dsg

long
);

return 1;
}

