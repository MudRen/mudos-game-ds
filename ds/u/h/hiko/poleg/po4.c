inherit ROOM;
void create()
{
        set("short", "泊浪村西側");        
        set("long",@LONG
這裡已經是泊浪村中央了，往北邊可以到泊浪村的漁港，可以看見
漁夫在辛勤工作，他們在把捕到的漁獲清理，希望能賣個好價錢，而有
些則是做出航的準備，畢竟不做好萬全預防在海上是很無助的，西邊則
是市集，可以過去看看有什麼新鮮東西。
LONG
        );
        set("exits", ([
  "north" : __DIR__"po5",
  "south" : __DIR__"po3",
  "east"  : __DIR__"po7",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}



