#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L���d�h�ϡ�");
 set("long",@LONG
�A�Ө�F�_�A�L���˪L�d�h��, �o�̦��ǥհ�����
�b�a�W, ���ӬO�~���o��Ө����X�h�����H, �̫ᦺ�b
�o��, �A�̦n���֨�, ���n�r�d.

LONG
    );
 
 set("exits",(["west":__DIR__"en53",
               "southwest":__DIR__"en57",
               "southeast":__DIR__"en59",
               ]));
 set("objects",([__DIR__"npc/bug" : 2,
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
