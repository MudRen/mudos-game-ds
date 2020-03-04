inherit ROOM;
void create ()
{
        set ("short", "第九宮人馬座");
        set ("long",
             @LONG

                         :$?
                          :X$$?
                       :uW$$$M
                    :!M$#$$$$~ 射手座呈現的是半人半馬的型態，具有動物和人類
                       :W$M$? 雙重面目，是個著名的先知、  醫生和學者。他是希
                     :X$# ~R~ 臘著名大英雄傑生 (Jason)、亞齊裡斯 (Achilles)和
                    :W$"   ~ 亞尼斯   (Aeneas)的撫養者。傳說他是卡羅拉斯(Cron
                   x$M  us)和斐萊拉 (Philyra)之子 ,也是宙斯的父親。他是在受驚
                 :H$"  嚇後，把自己變為馬身，其母斐萊拉受不了兒子半人半馬的
                x$$~   怪模樣，便變成了一棵菩提樹。
    :::: :: : :W$?:: : :
    $$$$$$$$$$$$$$$$$$$$?
    M$$$$$$$$$$$$$$$$$$$?~
    ~ ~ ~ :$$~ ~  ~    ~
         X$?~
         ~~~                                 

LONG);
        set("exits", ([
          "northup"    :       __DIR__"room19",
          "southeast"  :       __DIR__"room18", 
        ]));

        set("objects", 
        ([ //sizeof() == 1
               // __DIR__"npc/sagittarius" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}
