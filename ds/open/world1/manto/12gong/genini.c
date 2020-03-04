inherit ROOM;

void create ()
{
        set ("short", "第三宮：雙子座");
        set ("long", @LONG

  W$$Wu                :uW$$W
  $$ "*$i             W$#~ $$
   #$x ~$W:          $$~ x$#
    ~*$W$$$:       !$$$i$*~
       !$$$$WWiWiWW$$$$~
        $$$$$~~~~~$$$$W~
        $$$$$!   !$$$$8     神話故事中幾乎找不到和雙子星座有關的傳說。在埃及
        $$$$$W   8$$$$8  它的名稱為「孿子星」，是以這星座中最明亮的兩顆星卡
        $$$$$$  ~$$$$$$  斯達 (Castor)和波利克斯 (Pollux)命名，這兩顆星另外還
        $$$$$$   $$$$$8  有兩組名稱，分別為海克利斯 (Hecules)、阿波羅 (Apollo)
        $$$$$$   $$$$$8  ，崔特勒瑪 (Tritolemus)、艾遜 (Iasion)。埃及人觀念中
        $$$$$M   $$$$$8  的孿子座為幼童，而非一般常見的成人形象。
        $$$$$!   !$$$$8
        $$$$$xuuu:$$$$8
      :u$$$$*######$$$$u:
    x$$#$$$~       ~$$$#$W::
  :$$~ x$#           *$: ~$W
 !$$ uW$"             "$iu $$
 ~#**#~~               ~~#**#

LONG);


        set("exits", ([
        "westup"    :       __DIR__"room07",
       "northeast"  :       __DIR__"room06",        
        ]));

        set("objects", 
        ([
               __DIR__"npc/genini" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

