inherit ROOM;

void create ()
{
        set ("short", "�Ĥ��c�G�B�k�y");
        set ("long", @LONG
   !$$$$$!:i$$$$$W: :W$$$$Wu:  uWW$WWu
    ~$$$$W$*" ~$$$$W$#~ !$$$$W$$#*$$$$:
     $$$$$~    $$$$$~    $$$$$?~  !$$$
     $$$$!     $$$$$     $$$$!    W$#
    ~$$$$!     $$$$!     $$$$~  u$*~      �ھ�ù�����ܡA�B�k�y�S�W���A��
     $$$$!     $$$$!     $$$$ :W$"   (Astraes)�A���ѯ��C��S�M�ƻe���k����
     $$$$~     $$$$H     $$$$W$#~  �k��A�O���q�k���C�����ɥN�����A�H��Ĳ��
     $$$$      $$$$!     $$$$#~ �F�o�A��O�j�㤧�U�^��Ѯx�C
    ~$$$$!     $$$$H    :$$$$
    !$$$$!     $$$$!  :W$$$$$
    !$$$$!    !$$$$R i$$~$$$$
   ~**###*~  ~#**#*#W$#  $$$!
                    $$  X$$!
                    $W:W$$~
                    *$$*#

LONG);


        set("exits", ([
        "eastup"    :       __DIR__"room13",
       "southwest"  :       __DIR__"room12", 
        ]));

        set("objects", 
        ([ //sizeof() == 1
             //   __DIR__"npc/virgo" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

