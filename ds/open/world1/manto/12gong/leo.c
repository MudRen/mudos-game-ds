inherit ROOM;
void create ()
{
        set ("short", "�Ĥ��c�G��l�y");
        set ("long", @LONG
                ::::
           :uW$$$$$$$$Wx:
         :W$##""""#R$$$$$X
        X$?          "$$$$X
       X$?             #$$$:
       $$!              M$$
       R$8:             !$$     �ǻ����M�o�P�y��������x�O����þ�����̦w
       ~$$$W:           !$?  (Nimean)���a���@�Y��l�A�b�@���i�����Q���J
      :X$$$$$W:         MM   �Q������C
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

