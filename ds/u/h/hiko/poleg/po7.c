inherit ROOM;
void create()
{
        set("short", "泊浪村市集");        
        set("long",@LONG
這裡是泊浪村的市集，看起來還蠻熱鬧的，許多遊客和村民都在此
選購日常用品和特產，北邊就是一家特產店，裡面賣的東西都是屬於泊
浪村的特產別地方是買不到的，因此生意還不錯，東邊也是屬於市集，
可以過去瞧瞧。
LONG
        );
        set("exits", ([
  "north" : __DIR__"po7n",
  "west" : __DIR__"po4" ,  "east" : __DIR__"po8",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}




