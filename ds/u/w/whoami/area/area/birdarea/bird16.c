#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�ѱ���"NOR"�ȩ�");

 set("long",@LONG
�o�̬O�M�����H�{���ȩ�, �@�@���T�i��, �Ф����@�ӵ�
�H�{�������ѱ��۹�, �٦��@�ӷ��U�o�ǫH�{���p��, ���M�O�p
��, ���O�ݥL�������ˤl, �N���D�L�]�|�Z�\�C
LONG
    );
 
 set("exits",(["north":__DIR__"bird15",
    ]));
 set("objects",([__DIR__"npc/man" : 2+random(2),
                 __DIR__"npc/waiter":1,
     ]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}           

