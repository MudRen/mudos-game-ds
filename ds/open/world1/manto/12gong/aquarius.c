inherit ROOM;
void create ()
{
        set ("short", "�ĤQ�@�c�_�~�y");
        set ("long",             @LONG

 :i$$$$Wx     xoW$$$$$Wu:      xi$$$$$Wx:     :ui:
 "#*$$$$$$WW$$$*#"#$$$$$$$$WW$$$**$$$$$$$$WeW$$*#
  : ~ #$$$$$*"~     ~#$$$$$$#"~    "#$$$$$$*#"
                       ~                        ~
 :xW$$Wi      :xiW$$$Wi::       iW$$$Wu:       :u:
 !$$$$$$$Wooo$$$*#$$$$$$$$Wooo$$$$$$$$$$$iuooW$$#
     "*$$$$$$#~     "*$$$$$$$#"   ~"*$$$$$$$*"~
        ~"~            ~~"~           ~~~
            �S���쪺���l�z�����w�O�Ӷ����몺���֦~�A���@�ѥL�b���ϮɡA
        ��M�Q�z���ܦ������N������L�����A�t�d�������J�O������Ѥ��D    
        ��Ҿ�����r�s�u�@�C�b�j�N��ù���A��Ӷ�����m�b�o�ӬP�y����
        �@�Ӥ묰�B�u�A�ҥH�w�W�����~�C

LONG);
        set("exits", ([
        "northwest"    :       __DIR__"room22",
        "southup"  :       __DIR__"room23",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                //__DIR__"npc/aquarius" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

