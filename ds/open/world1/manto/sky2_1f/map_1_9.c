// Room: /open/world1/manto/sky2_1f/map_1_9.c

#include <dbase.h>
#include <ansi2.h>

inherit CLUB_BANK;

void create()
{
        set("short", HIW"�y�Ѧa�j�����z"NOR);
        set("long", @long
�o�̴N�O�Ѧa�|���̪��Ѧa�j�����A�Ψө����|�g�O���ΡC
long
+HIR""
+"�@�@[deposit]�@�ССССССС@[�s�ڡоA�ΩҦb�ɪųf��]\n"
+"�@�@[transfer] �@�СССССС@[��b�оA�Υ���ɪųf��]\n"
+"�@�@[withdraw] �@�СССССС@[���ڡоA�ΩҦb�ɪųf��]\n"
+"�@�@[clear]�@�СССССССС@[�M���s���O��]\n"
+"�@�@[list] �@�СССССССС@[�d�����|�겣�Ʀ�]\n\n"NOR
);
        set("club_id", "sky");
        set("club_level", 7);
	set("light", 1);
	set("current_light", 1);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"map_3_9",
]));

	setup();
        set("stroom", 1);
        set("long", query("long") 
                + BANK_D->get_bank_amount(query("club_id")) 
                + BANK_D->get_log(query("club_id"), "deposit")
                + BANK_D->get_log(query("club_id"), "withdraw")
        );
}
