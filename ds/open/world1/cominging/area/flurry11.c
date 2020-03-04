inherit MOBROOM;
void create()
{
        set("short", "花園");
        set("long", @LONG
你現在在階梯的下方，階級上刻有一行行的文字，不過經過風雨的
摧殘似乎已大部分銷毀，你只隱隱的看出幾行的文字，現在這裡是一座
小花園，有鳥的鳴聲，蟲的叫聲，宛如交響曲一般的好聽。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"flurry17.c",
  "north" : __DIR__"flurry12.c",
  "east" : __DIR__"flurry16.c",
  "southup" : __DIR__"flurry10.c",
]));
        set("no_clean_up", 0);
        set("chance",40);
        set("outdoors","land");
        set("mob_amount",4);
        set("mob_object",({
  __DIR__"npc/cat",
  __DIR__"npc/dog",
}));
        setup();
}

