/*	File : "/open/world1/alickyuen/zong/ticket.c"
	Author: Alickyuen@DS
*/
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"2008 �~�׺ݤȸ`�����"NOR,({ "zong ticket" }));
        set("long", "�o�O2008 �~�ݤȸ`��������A�i�H�浹���A�l����C\n");
        set("long", @LONG
�o�O2008 �~�ݤȸ`��������A�i�H�浹���A�l����C
[give zong ticket to seller]
LONG);
	set("value", 0);

	setup();
}

