inherit ROOM;
void create ()
{
        set ("short", "�ĤK�c���Ȯy");
        set ("long",
             @LONG

      iWWW:  :W$WW   :xW$Wx
     W$$$$ :$$$$$$X u$$$$$$
    W$$$$$W$#~$$$$$$$?~$$$$!  �ѦZ���R�R���ȱq���t���a�����X�ӡA�����ڥ�
   X$?$$$$$?  M$$$$#   $$$$~ �w�] Orion,���w�R���鱡���y�H�A��Ƭ��y��P
  H$! $$$$!   8$$$$    $$$$! �y�^�C�t�~�@���A���ȬI��r��������r�ۤӶ�
  ~~  $$$$    8$$$8    $$$$~ �������g�L����y�A�ӨϥC��S�����|�o�g�p�q
      $$$$~   8$$$8    $$$$! �A�N�b�]�����Ӷ��������C
      $$$$    M$$$8    $$$$!
      $$$$    8$$$8    $$$$~
      $$$$    M$$$8    $$$$!       Xi
      $$$$    8$$$8    $$$$!      X$R
      $$$$    R$$$8    $$$$~    xW$$!
      $$$$    #$$$M    $$$$   W$$$$$
                       $$$$     $$$8
                       $$$$!  :$$  $
                       ~#$$$oW$#

LONG);
        set("exits", ([
          "westup"    :       __DIR__"room17",
          "northeast"  :       __DIR__"room16",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
             //   __DIR__"npc/scorpio" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}
