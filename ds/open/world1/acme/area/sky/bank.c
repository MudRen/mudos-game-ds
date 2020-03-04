/*	File : "/open/world1/acme/area/sky/bank.c"	*
 *	Author : -Alickyuen@DS-				*
 *	Desc : ���|�M�ݻȦ�,�s�������s��		*
 *	Last Modify : 20-11-2001			*/

#include <dbase.h>
#include <ansi2.h>

inherit CLUB_BANK;
//inherit ROOM;

void create()
{
	set("short", HIW"�y�Ѧa�j�����z"NOR);
	set("long", @long
�o�̴N�O�Ѧa�|���̪��Ѧa�j�����A�Ψө����|�g�O���ΡC
long
+HIR"�@�@�o�̥i�Ϊ����O���G\n\n"
+"�@�@[deposit]�@�ССССССС@[�s�ڡоA�ΩҦb�ɪųf��]\n"
+"�@�@[transfer] �@�СССССС@[��b�оA�Υ���ɪųf��]\n"
+"�@�@[withdraw] �@�СССССС@[���ڡоA�ΩҦb�ɪųf��]\n"
+"�@�@[clear]�@�СССССССС@[�M���s���O��]\n"
+"�@�@[list] �@�СССССССС@[�d�����|�겣�Ʀ�]\n\n"NOR
);
	set("club_id", "sky");
	set("club_level", 7);

	set("light", 1);
	set("exits", ([
		"down" : __DIR__"room15",
	]));

	setup();

	set("long", query("long") 
		+ BANK_D->get_bank_amount(query("club_id")) 
		+ BANK_D->get_log(query("club_id"), "deposit")
		+ BANK_D->get_log(query("club_id"), "withdraw")
	);
}
