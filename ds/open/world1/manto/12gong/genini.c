inherit ROOM;

void create ()
{
        set ("short", "�ĤT�c�G���l�y");
        set ("long", @LONG

  W$$Wu                :uW$$W
  $$ "*$i             W$#~ $$
   #$x ~$W:          $$~ x$#
    ~*$W$$$:       !$$$i$*~
       !$$$$WWiWiWW$$$$~
        $$$$$~~~~~$$$$W~
        $$$$$!   !$$$$8     ���ܬG�Ƥ��X�G�䤣��M���l�P�y�������ǻ��C�b�J��
        $$$$$W   8$$$$8  �����W�٬��u�p�l�P�v�A�O�H�o�P�y���̩��G�������P�d
        $$$$$$  ~$$$$$$  ���F (Castor)�M�i�Q�J�� (Pollux)�R�W�A�o�����P�t�~��
        $$$$$$   $$$$$8  ����զW�١A���O�����J�Q�� (Hecules)�B���iù (Apollo)
        $$$$$$   $$$$$8  �A�Z�S�Ǻ� (Tritolemus)�B�㻹 (Iasion)�C�J�ΤH�[����
        $$$$$M   $$$$$8  ���p�l�y�������A�ӫD�@��`�������H�ζH�C
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

