inherit ROOM;
void create()
{
 set("short","聖明宮");

 set("long",@LONG
這裡是明教集會的地方，每當有重要事項教主、光明聖使和各堂主
會在這裡宣布，中央的廣場可以容納下數千人，四周強上刻著明教
的豐功偉業，四邊石住上雕著數隻栩栩如生的龍，龍嘴上點著萬年
不滅的聖火將四周照亮。
LONG
    );
 set("exits",([ "west": __DIR__"lighttop",
                "down": __DIR__"wl",
                "up": __DIR__"fire",
    ])); 

set("objects",([
__DIR__"item/ming-sky_tree":1,
]));

        set("no_kill",1);
        set("light",1);
 setup();
  call_other("/obj/board/ming_club_b" , "???");
        set("stroom",1);
}
//這裡該有個board
//have 明教大事板(Ming board)
//這是一個用來post教中大事的留言板

