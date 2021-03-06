// Room: /open/world1/tmr/bagi/area/2f/3f-2.c

inherit ROOM;

void create()
{
        set("short", "石門前");
        set("long", @LONG
你正處在一間寬廣的石室內，在你眼前出現是一道依著岩壁建造的石
門，巧的是石門上也滿是乾涸已久的血跡，石室內也散滿了各式兵器、防
具和數十具人骨。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "west" : __DIR__"3f-1",
        ]));
        set("item_desc",([
        "石門":"一道看起來非常厚重的光滑石門，上頭無鎖無孔，不知如何開啟。\n",
        ]));
        set("current_light", 1);
        set("no_clean_up", 0);
        set("objects",([
                __DIR__"npc/freeze-sun-monster":1,
        ]));
        setup();
        replace_program(ROOM);
}

