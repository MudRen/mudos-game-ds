#include <ansi.h>
inherit MOBROOM;
void create()
{
 set("short",HIC"�ѱ���"NOR"�m�Z��");

 set("long",@LONG 
�A�Ө�F�ѱ��Ъ��m�Z��, �A�ݨ��o�̦��\�h���p�{�̦b�o
�̽m�\, �A�ݬݳo�Ǥp�{��, �A�o�{�L�̤��L�O��Ǧ��F�l�K�B
�Z���p�s��, �ӥB�Z�\�ܮt, �٤��|�ѼS�P�k, �ҥH�b�o�m�ߡC 
LONG
    );
 
 set("exits",(["south":__DIR__"bird22",
               "north":__DIR__"bird21",
               "east":__DIR__"bird23",
               "west":__DIR__"bird24",
     ]));
 
 set("no_clean_up", 0);
 set("outdoors","land");
 set("chance",80);
        set("mob_amount",4);    
        set("mob_max",12);
        set("mob_object",({     
            __DIR__"npc/fighter",
        }) );
        set("no_clean_up", 0);
        set("outdoors","land");
 setup();
}

