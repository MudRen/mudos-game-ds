#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�D���F��");
set("long",@LONG
�A�B��\�[, �ש��F�o����F�q���x����F, �A�o�{�L��
�K�P��W������ƶq�~�M����ݤ������F�q���x���C�e! �u�j�j
�i�H�ݨ����@�ӤH�b���夤�İ�, ���n�b�L���F��P����S�U��
�@��Ʈv���U, �_�h�u�O�����]�Q....
LONG
    );
 set("exits",([ "east":__DIR__"seacoun12",
		"west":__DIR__"seacoun13",
		"south":__DIR__"seacoun10",
]));
  set("item_desc",([
        "����" : "�@�綠��...\n",
    ]));
 set("objects", ([__DIR__"../npc/sea_master" : 1,
		  __DIR__"../npc/bladeguard" : 2,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
}
             
