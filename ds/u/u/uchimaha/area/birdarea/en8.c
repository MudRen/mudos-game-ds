#include <ansi.h>
inherit MOBROOM;
void create()
{
set("short","�F�_�A�L");

set("long",@LONG
�A�{�b�Ө�@�B�g�۲��h���a��, �@�}�}��������
�Ө�, ��Ӿ�W���@�諸�ͥ��b���T�T���s��, ���O��
�F�o��, �o�s�@���ͳ��S��, ������a�F�@�I����, �b
���Ǧ��@�Ӭn�n�ױת���P(sign)�C 
 
LONG
    );
 set("item_desc",([
        "sign":"�A�³o��P�ݤF��, �o�{�W�����X�Ӥj�r,

       "HIR"�� �W ��     �Фža��"NOR"

�A���T�N�����y, �A�Q�Q�]�\\�Ӧ^�Y�F.\n",
     ]));
        set("exits",(["north":__DIR__"en9",
                      "south":__DIR__"en7",
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

