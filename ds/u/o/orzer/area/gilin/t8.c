inherit ROOM;
void create()
{
        set("short","祭靈森林西側");
        set("long",@LONG
你走到了往森林的西北邊前進，已經可以隱約看到林內似乎有個建
築，不知道會是什麼樣的人住在此地，想必應該是不平凡的人才會選擇
住在這危機重重的森林中，這裡的寒氣已經若有似無了。
LONG
        );
        set("exits", ([
  "southeast" : __DIR__"t7",
  "northwest" : __DIR__"t9",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}










