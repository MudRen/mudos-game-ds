#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", "�ĥ|�c�G���ɮy");
        set ("long", @LONG

               :XxuxuX:::
        :uWW$$$$$$$$$$$$$$$Wix:
     :U$$$$$#""~~      ~~""##$$$ix      �t�z�����R�W�F���y�k����
   !W$$$$$$$$$Wi:             ~~#*$W::  �פ�M�o�l�v��˪L����
  !$$*"~    ~"T$$$:                ~#8: ���y�k���ͤU�@�k��
  $$?          ~$$$          :          �����Z�۷���
 !$$            X$$    XWW$$$$$$$Wu:    ���E�Y���ɥh���`���k��H
 !$$:       :  ~8$$  !$$$?~     ~?*$W:  ���y�k�����F�O�@�ۤv���k��
  ?$$X        !W$$! !$$!           #$8  �i�����M�����ޤ�]�Ө���
   ~T*$$WWW$$$$*!~  !$$            !$$  �����Z�Q�o�����R�ҷP��
       ~~"~!~       !$$X  :        W$$  ���p�k�ĤɪŦ��F���ɬP�y ......
 !W::                ?$$Wx:     :!W$$!
  ~#$WU::             ~#*$$$WWW$$$$#~
     "#$$$Wxx::          ::W$$$$$#~
        ~"#$$$$$$$$$$$$$$$$$$#"~

LONG);

        set("exits", ([
       "northup"    :       __DIR__"room09",
       "southeast"  :       __DIR__"room08",     
        ]));

        set("objects", 
        ([ //sizeof() == 1
               __DIR__"npc/cancer" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

