inherit ROOM;
void create ()
{
        set ("short", "�ĤE�c�H���y");
        set ("long",
             @LONG

                         :$?
                          :X$$?
                       :uW$$$M
                    :!M$#$$$$~ �g��y�e�{���O�b�H�b�������A�A�㦳�ʪ��M�H��
                       :W$M$? �������ءA�O�ӵۦW�������B  ��ͩM�Ǫ̡C�L�O��
                     :X$# ~R~ þ�ۦW�j�^���ǥ� (Jason)�B�Ȼ��̴� (Achilles)�M
                    :W$"   ~ �ȥ���   (Aeneas)�����i�̡C�ǻ��L�O�dù�Դ�(Cron
                   x$M  us)�M���ܩ� (Philyra)���l ,�]�O�z�������ˡC�L�O�b����
                 :H$"  �~��A��ۤv�ܬ������A������ܩԨ����F��l�b�H�b����
                x$$~   �ǼҼˡA�K�ܦ��F�@�ʵд���C
    :::: :: : :W$?:: : :
    $$$$$$$$$$$$$$$$$$$$?
    M$$$$$$$$$$$$$$$$$$$?~
    ~ ~ ~ :$$~ ~  ~    ~
         X$?~
         ~~~                                 

LONG);
        set("exits", ([
          "northup"    :       __DIR__"room19",
          "southeast"  :       __DIR__"room18", 
        ]));

        set("objects", 
        ([ //sizeof() == 1
               // __DIR__"npc/sagittarius" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}
