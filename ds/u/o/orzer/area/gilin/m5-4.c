inherit ROOM;
void create()
{
        set("short","哨樓");
        set("long",@LONG
你來到了哨樓頂端，這裡站著一名穿著厚重裝甲的人，身上流露出
久經沙陣的氣勢，他眼神專注的注意著北方，似乎在擔心下一刻就發生
了什麼事，手上的戟也片刻不離身，看來應當是朝廷一員猛將。
LONG
        );
        set("exits", ([
  "down" : __DIR__"m5-3",
]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}








