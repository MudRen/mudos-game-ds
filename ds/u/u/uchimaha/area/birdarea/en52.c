#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L���d�h�ϡ�");
 set("long",@LONG
�A�Ө�F�_�A�L���˪L�d�h��, �A�@�ӳo�N���@�Ѵc
�ߪ����D��W���Y, �a�W���X�����j���Υ��b���۰٭���
��, �A���T�P��򰩮��M, �Q�n���I���}�o��.

LONG
    );
 
 set("exits",(["east":__DIR__"en53",
               "southwest":__DIR__"en55",
               "southeast":__DIR__"en57",
               ]));
 set("objects",([__DIR__"npc/bug" : 3,
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
