// code by blueshadow
// code by blueshadow
// Recode by Promise
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"[�Z�ùC����] "HIW"�԰����~�d�M�橱"NOR);
        set("long","
�o�̬O�Z�îa�����㩱�A���Y���\\�h�{�N�Ҭy�檺�C���P����A
��M���{���̬y�檺�԰����~�d�C�p�G�ݭn�ʶR���ܡA�ЬݤU���
�W�K������(post)�A���Y���Ǭ�����ƥi�H�ѦҡC
\n");
        set("item_desc", ([ /* sizeof() == 1 */
"post" : HIW"
���~�d�K�ʦu�h�G

1 .�Х��R�ӪŵP��
2 .�M��ѭӤpQuest�A������Z�������|���A���y�C
3 .�]�i�H����Quest�A��������K�ʾ԰����~�d�]�C
4 .�@�i�d�̦h�u��b�P�դ����ƤT�i�A�@�ƵP�ճ̦h40�i�P
\n"NOR,
]));
        set("no_fight", 1);
        set("no_kill", 1);
        set("no_clean_up", 1);
        set("exits", ([ /* sizeof() == 4 */
  "out" : "/open/world1/tmr/area/hotel", 
  "east" : __DIR__"playroom_1",]));
        setup();
}


