inherit ROOM;
void create()
{
      set("short","超•光子練習場『初級區』");
      set("long",@LONG
眼前一片白茫茫的，旁邊有兩個新手正在合力修他們的光子槍，看來
是他們的光子推進器出了一點問題，後面有一名頂級教練正在教導他的學
生練習用光子槍射電子標把。
LONG);
set("exits",([
      "west":__DIR__"2.c",
       "east":__DIR__"6.c",
]) );
set("objects",([
__DIR__"npc/lv3_guard"      :4,
]) );
        set("world", "future"); 
setup();
replace_program(ROOM);
}
