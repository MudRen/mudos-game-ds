#include <room.h>
inherit ROOM;
inherit MOBROOM;
void create()
{
 set("short","�F�_�A�L");

 set("long",@LONG
 �A�{�b�Ө�@�B���L�ߪ��a��, �@�}�}��������
 �Ө�, ��W���@�諸�ͥ��b���T�T���s��, �n���w��A
 �Ө�o��, �o������G�O���W���_��, �]���A�ݨ�o��
 ���\�h�����W�X�S�C 
 
LONG
    );
 
 set("exits",(["north":__DIR__"en8",
               "east":__DIR__"en18",
               "southwest":__DIR__"en6",
     ]));
 
 set("no_clean_up", 0);
 set("outdoors","land");
 set("chance",80);
        set("mob_amount",4);    
        set("mob_max",15);
        set("mob_object",({     
            __DIR__"npc/fox",
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
