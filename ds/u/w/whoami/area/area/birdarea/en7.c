#include <ansi.h>
inherit MOBROOM;
void create()
{
 set("short",HIW"�F�_"NOR"�A�L");

 set("long",@LONG
�A�{�b�Ө�@�B���L�ߪ��a��, �@�}�}���������Ө�, ��
�W���@�諸�ͥ��b���T�T���s��, �n���w��A�Ө�o��, �o�̩�
�_���~�Q�����B��, �A�֦��ȤH�i�J�ӥ����Ӱh��.
LONG
    );
 
 set("exits",(["north":__DIR__"en8",
               "east":__DIR__"en18",
               "southwest":__DIR__"en6",
     ]));
 
 set("no_clean_up", 0);
 set("outdoors","land");
 set("chance",80);
        set("mob_amount",3);    
        set("mob_max",12);
        set("mob_object",({     
            __DIR__"npc/chan",
        }) );
        set("no_clean_up", 0);
        set("outdoors","forest");
 setup();
}

