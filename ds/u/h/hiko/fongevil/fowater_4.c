inherit __DIR__"waterroom";
void create()
{
 set("short","遺跡─水");
set("long",@LONG
你來到了一間房間，看到地上有著一條繩子，讓你覺得很
奇怪，不知道可以做什麼，但是似乎這裡就沒有其他的東西了
，眼前的情景你不禁感到有一些疑惑，但時也許它便是測驗的
關鍵。
LONG
    );
set("item_desc", ([
"繩子" : "這是一條連到遺跡牆上的繩子..似乎可以把它放掉(unsling)\n"
 ]));
set("exits",([
"east":__DIR__"fowater_3",
]));
setroom();
set("open_room",__DIR__"fowater_7");
set("move_room",__DIR__"fowater_1");
set("can_go","can_go1");
setup();
}             








