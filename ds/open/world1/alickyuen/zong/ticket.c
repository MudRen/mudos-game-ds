/*	File : "/open/world1/alickyuen/zong/ticket.c"
	Author: Alickyuen@DS
*/
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"2008 年度端午節抽獎卷"NOR,({ "zong ticket" }));
        set("long", "這是2008 年端午節的抽獎卷，可以交給賣粽嫂子抽獎。\n");
        set("long", @LONG
這是2008 年端午節的抽獎卷，可以交給賣粽嫂子抽獎。
[give zong ticket to seller]
LONG);
	set("value", 0);

	setup();
}

