inherit ROOM;
void create()
{
 set("short","闇燄堂");
 set("long",@LONG
這是明教之中負責追殺被長老、光明聖使和教主通緝的人與違反
教規的人，堂內牆上刻著明教的教規，當你讀到最後一行時，赫然看
見三個血紅色的大字【違者•死】你不禁嚇了一身冷汗，仔細看看四
周，牆上掛滿了刑具和追殺令，地上血跡斑斑，空氣中瀰漫著一股血
腥的氣味。
LONG
    );
 set("exits",([ "west": __DIR__"wl",
"north": __DIR__"gw",
 "south": __DIR__"skycenter",
    ]));
        set("light",1);

 setup();
        set("stroom",1);
}
int do_kill(string arg)
{
        if( arg == "guard" || arg == "ming guard" )
        {
                tell_object(this_player(),"你想要殺害自己的手足？！\n");
                return 1;
        }
        else return 0;
}

//have 陰陽聖火追殺令<===board
//這是一個用來通緝別人的留言板，當你要通緝他人時，請post名
//單和罪行長老將會表決是否通緝。
