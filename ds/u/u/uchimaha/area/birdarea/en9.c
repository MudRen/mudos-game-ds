#include <ansi.h>
inherit MOBROOM;
void create()
{
set("short","�F�_�A�L");

set("long",@LONG
�A�~�򩹥_�e�i, �@�}�}���������Ө�, ��Ӿ�
�W���@�諸�ͥ��b���T�T���s��, ���O��F�o��, �o�s
�@���ͳ��S��, �@�}�}����{���H�ۭ��ƴ��L��, ��^
���a�F�@�I����, �b���Ǧ��@�Ӫg���媺��P(sign)�C 
LONG
    );
 set("item_desc",([
        "sign":"�A�³o��P�ݤF��, �o�{�W�����X�Ӥj�r,

        "HIR"�e�観  ��  �H  ��!!!"NOR".\n",

        ]));
        set("exits",(["northwest":__DIR__"en10",
                      "south":__DIR__"en8",
              ]));
 
 
        set("chance",80);
        set("mob_amount",3);    
        set("mob_max",15);
        set("mob_object",({     
            __DIR__"npc/fox2",
        }) );
        set("no_clean_up", 0);
        set("outdoors","land");
 setup();
}
