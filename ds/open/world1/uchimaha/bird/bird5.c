#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���@�k��"NOR);

 set("long",@LONG
�A�S���W���F���֤F�Z��, �A�ݤF�ݥ|�P, �A�o�{
�A�w�g�b���h���W�F, �ŷx������, ���A���W�����L��,
�M�s���Ů�, ���A�Ҧ������O��o����, �A���T�r�}�_
��b�o�k���W���H�C

LONG
    );
 
 set("exits",(["up":__DIR__"bird6",
               "down":__DIR__"bird4",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
