#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�y����"NOR"�w"HIW"�����a"NOR);
 set("long",@LONG 
�A��F�����a, �A�ݬݥ|�P, ����W���F�Ǭé_���~���Х�
, ���ӬO�����~���ɩ��y�Ӫ�, ��W�ٱ��F�@�����һs���}, 
�ݰ_�����ӫܤ[�S�ΤF.
LONG
    );
 
 set("exits",(["west":__DIR__"village13",
              ]));
 set("objects",([__DIR__"npc/man2" : 1,
     ]));
 set("item_desc",([
        "��}":"�@���g���媺��}�A���M�w�L�F�ܤ[�A���O���G�٬O�i�H�Ϊ��ˤl..\n",     ]));

 set("light",1);
 set("no_clean_up", 0);
 set("reborn",150);
 setup();
}        

