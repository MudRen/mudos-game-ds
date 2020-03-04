inherit ROOM;

void create()
{
        set("short", "地下水道");
        set("long", @LONG
沿著水道來到這裡，一堆儀器擺在角落，好像很久沒人用過。還
有幾張桌子跟椅子，看來曾經有什麼人在這裡待過，做了些實驗的
樣子。牆上有抽風機，不過已經不能轉動了。
LONG
        );
        set("current_light", 0);
        set("exits", ([ /* sizeof() == 1 */
        "south" : __DIR__"pool03",
]));

	setup();
}