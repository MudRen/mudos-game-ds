inherit ROOM;
void create()
{
        set("short","哨樓");
        set("long",@LONG
你來到了哨樓裡面，這裡的官兵看來訓練有素，應該不是普通士兵
，個個看來威猛氣盛，而且眼神銳利無比，感覺時時刻刻都保持著警戒
，這也許是朝廷派來的精銳部隊。
LONG
        );
        set("exits", ([
  "up" : __DIR__"m5-4",
  "east" : __DIR__"m5-2",
]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}








