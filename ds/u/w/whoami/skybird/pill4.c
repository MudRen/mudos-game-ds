#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�Ѱ|"NOR);
 set("long",@LONG
�o�̴N�O�ѱ��M�Ĥ@�����Ѱ|, �o�̪��ǥͤ��h, ���O�b��
�x�W�����v�o�Q����O���½�. �ڻ��ѱ��v�Ĥ@���ޥH���ƪ���
�ѻմN�b�o�Ѱ|�����.
LONG);
 set("exits",(["southeast":__DIR__"pill3",
    ]));
/* set("item_desc",([
        "�W�l":"�@�ڤj�j���W�l, �q�o�Ө��׬ݤ��X�����򲧱`.\n"
    ]));
*/
 set("objects", ([__DIR__"npc/teacher" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}

