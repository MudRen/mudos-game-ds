inherit ROOM;
void create ()
{
        set ("short", "�Ĥ@�c�G�զϮc");
        set ("long", @LONG

    :iW$$$$Wi:          :uWW$$$WWx
  :W$$$####$$$$W:    :i$$$$*###*$$$x
  $$$?      ~#$$$X  :$$$#~      ~$$$
  $$$          $$$X:$$$~         8$$!
  #$$i  ~      ~$$$$$$!   :   ~ x$$$
   #$$$WWi$$    ?$$$$$    8$WiW$$$#
     ~""""      ~$$$$!      """""
                 $$$$~  ��Q�봵(Phrixus)�D�`�i��(Nepele)���l�A
                 $$$$~�X�W���úѶ��� (Biadice)�����դ��ޡA�ӳQ�P�B���D�A
                 $$$$:�{�D���e�@�����⪺���ϤήɱN�L�M�f�f����(Helle) �@
                 $$$$~�_�I���������O�A�f�f�]�����Að�A�@�ɲ��Ḩ�U�ϭI�A
                ~$$$$ ��Q�봵�h�w�M��ϡA�L�N�����m���z����§�A�z���N
                 ?$$? �����ζH�Ƭ��ѤW���P�y�C��ӳǥͬ��F�ܨ��o���Ϫ���
                      ��A�ٮi�}�F�@�q��m���_�I�G�ơC

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

