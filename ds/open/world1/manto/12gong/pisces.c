inherit ROOM;
void create ()
{
        set ("short", "�ĤQ�G�c�����y");
        set ("long",             @LONG

   ~?$$$$W:                x$$$$#
      ?$$$$u :           :$$$$#
        "$$$W           :$$$#~
          #$$$:        W$$$~
           #$$$       !$$$!                                             
            $$$X      $$$!   ���Ǵ��M�C��S���@���Q���H���p�] Typhon�^��
            M$$$:: ::H$$$  �l�v�A�������J���o�ԩ��e���A�ƨ������k���C�e�g
            !$$$$$$$$$$$$  �ء] Mineave�A����R���O�W�^�N���Ƭ��P���m���
            !$$$"#"""$$$8  �W�A�H�����o��ơC
            H$$$     ?$$$
            $$$?     ~$$$!
           W$$$       M$$$:
          W$$$~        #$$$:
        :$$$#           ?$$$x:
      xW$$$?             "$$$$u
    !R$$$#                 "*$$$!
LONG);
        set("exits", ([
      //  "northup"    :       __DIR__"topalace1",
        "east"  :       __DIR__"room24",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
           //     __DIR__"npc/pisces" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

