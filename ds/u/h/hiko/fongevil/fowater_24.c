inherit __DIR__"waterroom";
void create()
{
 set("short","遺跡─水");
set("long",@LONG
這個房間似乎很眼熟，而地上有著一條繩子，讓你覺得很
熟悉，一看你就全然了解一切，這個機關對你而言已是家常便
飯，所以你很快的便就解開了，朝著最後的目標全力邁進，一
切就快畫上句點了。
LONG
    );
set("item_desc", ([
"繩子" : "這是一條連到遺跡牆上的繩子..似乎可以把它放掉(unsling)\n"
 ]));
set("exits",([
"west":__DIR__"fowater_23",
]));
set("open_room",__DIR__"fowater_25");
set("move_room",__DIR__"fowater_20");
set("can_go","can_go2");
setroom();
setup();
}             










