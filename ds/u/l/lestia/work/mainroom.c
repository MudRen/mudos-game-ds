inherit ROOM;
#include <ansi.h>
#include <room.h>
void create()
{
        set("short", HIW""BLK"����"HIW"����"NOR);
        set("long",
"\n�A���b�@����L���j�a�����A�Ƿt���ѽw�w���y�ʵۡA\n"
"�A���[�|�P�A�o�{�o�̰��F�I�I���~�٬O�I�I�A�A�I�q\n"
"���y�A�C�C���N�ߤ��������h���A�u�d�U���c�����Y�A\n"
"���ݵ۳̫ᤧ�骺���{�C\n\n"
);
      set("light", 0);
        set("no_clean_up", 0);
 set("valid_startroom", 1); 
 set("exits", ([ 
"wiz":"/d/wiz/hall1",
"up":"/u/l/lestia/work/post.c",
"pray":"/u/l/lestia/work/pray.c",
"luky":"/u/l/luky/workroom.c",
 ])); 
        setup();
}
