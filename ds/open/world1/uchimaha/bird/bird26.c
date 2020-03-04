#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit MOBROOM;
void create()
{
 set("short",HIC"�ѱ���"NOR"�m�Z��");

 set("long",@LONG
 �A�Ө�F�ѱ��Ъ��m�Z��, �o�̬O�M�����j�{�̽m
 �\�Ϊ�, �o�̪��P���h�����ɨ��, �A�ݨ�L�̥��b��
 �߮���ѱ��۹�������, �C�ӤH�����������@��, �L��
 �N�b�o�̽m���F�l�K�B�Z�C
 
LONG
    );
 
 set("exits",(["south":__DIR__"bird24",
               "east":__DIR__"bird21",
     ]));
 
 set("no_clean_up", 0);
 set("outdoors","land");
 set("chance",80);
        set("mob_amount",3);    
        set("mob_max",10);
        set("mob_object",({     
            __DIR__"npc/fighter2",
        }) );
        set("no_clean_up", 0);
        set("outdoors","land");
 setup();
 
}
void init()
{
        ::init();
        add_action("d_creat","creat");
        add_action("d_stop","stop");
}

int d_stop(string arg)
{
 this_object()->set_temp("stop_creat",1);
 tell_object(this_player(),"�Ǫ��a�p�w����!\n");
 return 1;
}
int d_creat(string arg)
{
this_object()->set_temp("stop_creat",0);
 tell_object(this_player(),"�Ǫ��a�p�w�}��!\n");
 return 1;
}
