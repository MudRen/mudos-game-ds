inherit ROOM;
void create ()
{
        set ("short", "第十一宮寶瓶座");
        set ("long",             @LONG

 :i$$$$Wx     xoW$$$$$Wu:      xi$$$$$Wx:     :ui:
 "#*$$$$$$WW$$$*#"#$$$$$$$$WW$$$**$$$$$$$$WeW$$*#
  : ~ #$$$$$*"~     ~#$$$$$$#"~    "#$$$$$$*#"
                       ~                        ~
 :xW$$Wi      :xiW$$$Wi::       iW$$$Wu:       :u:
 !$$$$$$$Wooo$$$*#$$$$$$$$Wooo$$$$$$$$$$$iuooW$$#
     "*$$$$$$#~     "*$$$$$$$#"   ~"*$$$$$$$*"~
        ~"~            ~~"~           ~~~
            特洛伊的王子干尼梅德是個黃金般的美少年，有一天他在牧羊時，
        突然被宙斯變成的老鷹捉到奧林帕斯，負責嫁給海克力斯的西碧公主    
        原所擔任的斟酒工作。在古代的羅馬，當太陽的位置在這個星座的第
        一個月為雨季，所以定名為水瓶。

LONG);
        set("exits", ([
        "northwest"    :       __DIR__"room22",
        "southup"  :       __DIR__"room23",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                //__DIR__"npc/aquarius" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

