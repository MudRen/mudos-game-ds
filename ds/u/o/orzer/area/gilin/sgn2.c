inherit ROOM;
void create()
{
        set("short","樹洞");
        set("long",@LONG
你在樹叢的洞穴中前進著，這裡光線越來越微少，只能勉強看到一點點
事物，洞璧有著一些奇怪的符號，似乎曾經有什麼作用，只是現在已經喪失
了效果，聲音已經很靠近了，似乎就在不遠處。
LONG
        );
        set("exits", ([
  "east" : __DIR__"sgn1",
  "west" : __DIR__"sgn3",
]));
        set("no_clean_up", 0);
        set("light",0);
        setup();
        replace_program(ROOM);
}









