inherit ROOM;
void create()
{
      set("short","超•光子練習場『初級區』");
      set("long",@LONG
這裡的新手拿著光束槍到處亂轟，把這裡弄得一團遭，真不知道他們
心裡到底在想什麼。看！又有一名新手的光束槍走火打傷了自己，被醫護
人員抬下去，這裡看起來並不是十分安全。
LONG);
set("exits",([
     "east":__DIR__"2.c",
    "west":__DIR__"4.c",
]) );
set("objects",(
[__DIR__"npc/lv2_guard"   :4]
) );
        set("world", "future");
setup();
replace_program(ROOM); 
}
