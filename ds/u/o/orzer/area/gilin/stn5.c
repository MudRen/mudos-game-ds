inherit ROOM;
void create()
{
        set("short","古木上");
        set("long",@LONG
你在古木的分枝上緩緩前進著，往下看離地面已經頗高了，也算是難得
的感覺，不過卻還是要小心翼翼的提防，這裡的生物看來沒被寒氣所影響到
，可是不知道什麼原因，依然不斷阻止你前進。
LONG
        );
        set("exits", ([
  "west" : __DIR__"stn4",
  "north": __DIR__"stn6",
]));
        set("no_clean_up", 0);
        set("light",0);   
        setup();
        replace_program(ROOM);}










