inherit ROOM;
void create ()
{
        set ("short", "第五宮：獅子座");
        set ("long", @LONG
                ::::
           :uW$$$$$$$$Wx:
         :W$##""""#R$$$$$X
        X$?          "$$$$X
       X$?             #$$$:
       $$!              M$$
       R$8:             !$$     傳說中和這星座有關的表徵是位於希臘之尼米安
       ~$$$W:           !$?  (Nimean)谷地的一頭獅子，在一次搏鬥中被海克
      :X$$$$$W:         MM   利思殺死。
    :H$$###R$$$X:      :$!
   :$$"      ?$$W      HM
   $$!        ?$$:     $$
  !$$         !$$      $$X
   R$W:      :8$!      M$$WxX!
    #$$WuxxxW$$?        R$$$"
      "#R$$$#"           "#R
LONG);

        set("exits", ([
       "eastup"    :       __DIR__"room11",
       "southwest"  :       __DIR__"room10",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                //__DIR__"npc/leo" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

