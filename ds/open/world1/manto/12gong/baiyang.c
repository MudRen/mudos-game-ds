inherit ROOM;
void create ()
{
        set ("short", "第一宮：白羊宮");
        set ("long", @LONG

    :iW$$$$Wi:          :uWW$$$WWx
  :W$$$####$$$$W:    :i$$$$*###*$$$x
  $$$?      ~#$$$X  :$$$#~      ~$$$
  $$$          $$$X:$$$~         8$$!
  #$$i  ~      ~$$$$$$!   :   ~ x$$$
   #$$$WWi$$    ?$$$$$    8$WiW$$$#
     ~""""      ~$$$$!      """""
                 $$$$~  菲利塞斯(Phrixus)乃奈波勒(Nepele)之子，
                 $$$$~蒙上姦污碧雅蒂 (Biadice)的不白之冤，而被判處死刑，
                 $$$$:臨刑之前一隻金色的公羊及時將他和妹妹海□(Helle) 一
                 $$$$~起背走不幸的是，妹妹因不勝顛簸，一時眼花落下羊背，
                ~$$$$ 菲利塞斯則安然獲救，他將公羊獻給宙斯當祭禮，宙斯將
                 ?$$? 它的形象化為天上的星座。後來傑生為了奪取這金羊的羊
                      毛，還展開了一段精彩的冒險故事。

LONG);

        set("exits", ([
        "eastup"  :       __DIR__"room03",
       "west"  :       __DIR__"room02",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/baiyang" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

