inherit ROOM;
void create()
{
      set("short","超•光子練習場『入口』");
      set("long",@LONG
這裡是『超•光子練習場』的入口，裡面傳來隱隱的破空之聲，彷彿
是未來的神龍發威，要把一切的事物通通吞食掉，未來的光子槍的力量當
真是很恐怖的，旁邊有一個跑馬燈，裡面是光子縱橫的戰場。
LONG);
set("exits",([
      "enter":__DIR__"2.c",
      "south":"/open/world3/tmr/basic/digging_road6.c",
] ) );
set("outdoors","land");
        set("world", "future"); 
setup();
 replace_program(ROOM);
}
