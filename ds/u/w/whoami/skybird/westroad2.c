#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"��j�Y"NOR);
 set("long",@LONG 
�A�V���e���M�V�P��_�ǡM�o�@���j�Y�V�ӶV�¡M�ӧA�S�A
��ť��W��Ǩө��n�M�A���_�զ��M�o�{�����G�O�H�s�y�X�Ӫ�
�n���M�A�A���h�ð_�K�D���s�b�K�K�Ӱj�Y�����Y�]�����F�K�A
�Q�M���ޫ���, ��������Y�b���a�K
LONG
    );
set("exits",([ "east":__DIR__"westroad1",

    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}

