#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���"NOR);

set("long",@LONG
�o�̬O�x���H�M�ХD�ҤH�����, �o�̦P�ˬO�δX����O�f
�ئӦ�, �i�H���o�v�Ĥ@��������. �o�̭ȱo�`�N�]�N�u������
�����d, �M�ɤW���۪����ӤH�F. 
LONG
    );
 set("exits",([ "northwest":__DIR__"pill5",
    ]));
 set("objects", ([__DIR__"npc/master_walf" : 1,
    ]));
 set("item_desc",([
         "���d" : "�@�Ӥ�s���d�A�~�����}�ꤣ���A���Q�����Y���Ѥ@�w�j�����Y�C\n",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();                  
}

