#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");

 set("long",@LONG
�A�������F�h�[, �S�J���~���@�s���W, ���̥ΧG��
�嵷������, ��򪺨n�ۧA��, �A���G�ש�F��, �A�w�g�I
�J�F���̪��a�L, ���L�w�g�ӿ�F, ���ֻ����o�Ӭ}�ާa..
...
LONG
    );
 
 set("exits",(["northeast":__DIR__"en16",
               "southwest":__DIR__"en14",
           ]));
 set("objects",([__DIR__"npc/bfox" : 3,
     ]));
 
 set("no_clean_up", 0);
 setup();
}           
