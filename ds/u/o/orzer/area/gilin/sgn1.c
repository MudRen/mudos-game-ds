inherit ROOM;
void create()
{
        set("short","樹洞");
        set("long",@LONG
你不小心掉進了樹叢的洞穴中，這裡十分的陰暗不明，沒辦法看清楚周
遭的事物，不過洞穴深處有著奇怪的吼聲，不知道有著什麼東西，加上風聲
在洞內的回音環繞，氣氛不是很好，讓人有點膽顫心驚。
LONG
        );
        set("exits", ([
  "out" : __DIR__"t5",
  "west" : __DIR__"sgn2",
]));
        set("no_clean_up", 0);
        set("light",0);
        setup();
        replace_program(ROOM);
}









