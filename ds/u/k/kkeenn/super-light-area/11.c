inherit ROOM;
void create()
{
     set("short","超•光子練習場『中級區』");
      set("long",@LONG
這裡的機器人看起來十分難纏，看來若不是有兩把刷子的人是不會來
到這邊的，西方傳來陣陣的槍擊聲，看來又有人被擊倒了，真不知道這裡
的生化人是什麼做的，如此強橫！？
LONG);
set("exits",([
       "west":__DIR__"10.c",
]) );
        set("world", "future"); 
set("objects",([
__DIR__"npc/lv12"  : 4,
]));
setup();
replace_program(ROOM); 
}
