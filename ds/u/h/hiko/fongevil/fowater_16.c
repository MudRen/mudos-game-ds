inherit __DIR__"waterroom";
void create()
{
 set("short","遺跡─水");
set("long",@LONG
你一來到此地就看到地上的繩子，你一看到就準備動作了
，立刻就要解除機關，因為實在是太熟悉的東西了，讓你忍不
住想偷偷的笑，現在似乎沒有什麼可以阻止你了，只是路途依
然還很漫長。
LONG
    );
set("item_desc", ([
"繩子" : "這是一條連到遺跡牆上的繩子..似乎可以把它放掉(unsling)\n"
 ]));
set("exits",([
"north":__DIR__"fowater_15", 
"east":__DIR__"fowater_19",]));
set("open_room",__DIR__"fowater_19");
set("move_room",__DIR__"fowater_14");
set("can_go","can_go1");
setroom();
setup();
}             











