inherit __DIR__"waterroom";
void create()
{
 set("short","遺跡─水");
set("long",@LONG
你看到地上有著一條繩子，你剛剛才碰過一樣的機關，立
刻就知道要如何動作，因此很高興的照著剛剛做法便解開了機
關，現在似乎沒有什麼可以阻止你了，只是路途依然還很漫長
。
LONG
    );
set("item_desc", ([
"繩子" : "這是一條連到遺跡牆上的繩子..似乎可以把它放掉(unsling)\n"
 ]));
set("exits",([
"north":__DIR__"fowater_11", 
"southwest":__DIR__"fowater_13",]));
set("open_room",__DIR__"fowater_13");
set("move_room",__DIR__"fowater_8");
set("can_go","can_go2");
setroom();
setup();
}             










