/*	File : "/std/room/club_bank.c			*
 *	Author : -Alickyuen@DS-			*
 *	Desc : ���|�M�ݻȦ�,�s�������s��	*
 *	Last Modify : 14-11-2001			*/

#include <dbase.h>
#include <ansi2.h>

inherit CLUB_BANK;

mapping bank_amount, bank_record;

void init()
{
	set("short", "testing");
	set("long", @long
testing..............





long);
	set("club_id", "sky");
	set("club_level", 5);
	add_action("do_deposit", "deposit");
}

