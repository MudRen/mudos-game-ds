//by lestia

inherit "/u/l/lestia/workroom2.c";
#include <ansi.h>
void create()
{
        set("short", HIW""BLK"����"HIW"����"NOR);
        set("long",
"\n�A���b�@����L���j�a�����A�Ƿt���ѽw�w���y�ʵۡA\n"
"�A���[�|�P�A�o�{�o�̰��F�I�I���~�٬O�I�I�A�A�I�q\n"
"���y�A�C�C���N�ߤ��������h���A�u�d�U���c�����Y�A\n"
"���ݵ۳̫ᤧ�骺���{�C\n\n"
);
   set("light", 1);
        set("no_clean_up", 0);
 set("valid_startroom", 1); 
 set("exits", ([ 
"wiz":"/d/wiz/hall1",
"area":"/u/l/lestia/area/map_7_3.c",
"up":"/u/l/lestia/work/post.c",
"luky":"/u/l/luky/workroom.c",
 ])); 
        setup();
call_other("/obj/board/lestia_b.c","??????");
}

