#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�T��"NOR);

 set("long",@LONG 
�A�@��i�o�@���T��, �ߨ�P��@���ȭ���, �A���U�F�|�g
, �o�u����@�Ⱓ�]�C�M�@��j��, ��M�ΥD�O�@�ӫ~�w���|��
���H�~�h......�C��! �A���M�Q��, ���]�C�@�V���Z�L�ƥ���? 
���򬰤�����W�|���ۤ@�����]�C�O? ....���D���C�t���䥦��
����?....
LONG
    );
 set("exits",([ "west":__DIR__"eastroad3",

    ]));
 set("item_desc",([
        "���]�C":"�A�J�Ӫ��[��o�@��C, �o�{���C���P�ӫD�P, ���C�ӫD�C , �B
�O�ѷ��n���ҿ����y�Ӧ�, �ϧA��b�Q�n�N�@�N��.\n"
    ]));
// set("objects", ([__DIR__"npc/san_kung" : 1,
//     ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}

