inherit ROOM;
void create()
{
set("short","天樞堂");
set("long",@LONG
天樞堂是教內負責管理新人的地方，天樞堂員負責帶其他教徒練
功為明教培育出最優秀的人才，為明教的未來做最大的努力，堂內新
人的資料堆積如山，明教幾千萬教徒都是由天樞堂培育出來的，牆上
掛著一幅字畫上面寫著【助人為快樂之本】正是天樞堂的堂旨。
LONG
    );
 set("exits",([ 
           "north": __DIR__"darkfire",
    ]));
set("light",1);
set("objects",([
        "/open/world1/npc/goldman7" : 9,
]));
setup();
    set("reborn",300);
}

