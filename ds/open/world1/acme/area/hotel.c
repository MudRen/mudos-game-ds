inherit ROOM;

void create()
{
        set("short", "天香客棧");
        set("light",1);
        set("long", @LONG
這裡是一間客棧，門口掛著偌大的招牌，上寫著『天香客棧』，只
見店小二正殷勤的招呼客人，在東邊有個上樓的樓梯，旁邊寫了「二樓
雅座」，似乎是給一些達官貴人使用的。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"hotel2f",
  "north" : __DIR__"st.c",
]));
      set("objects", ([
         __DIR__"npc/oldwang" : 1,
// 又吵又壁雕..:P         __DIR__"npc/drooler" : 1,
           __DIR__"npc/fanny" : 1,
       ]));
           set("room_type","hotel");       //旅館
        set("no_fight", 1);
        set("no_clean_up", 0);

        set("valid_startroom", 1);
        setup();
     call_other("/obj/board/acme_h1_b", "???");
}
