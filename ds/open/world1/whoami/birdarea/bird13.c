#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�ѱ���"NOR"�j��");

 set("long",@LONG
�o�̬O�ѱ��Ъ��j��, �O�@�Ӥj�۪�, ���W��ۤT�Ӽg���⪺�j
�r�m�ѱ��Сn, ���k�U���@�ӱ����۹�, �b���f���ƭӦu��, �ݰ_��
���O�m�Z���H, �A�Q�g�o����⪺�r���H, ���ӴN�b�o�̤F�C
LONG
    );
 
 set("exits",(["east":__DIR__"bird14",
               "west":__DIR__"bird12",
     ]));
 set("objects",([__DIR__"npc/guard" : 3+random(3),
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           

