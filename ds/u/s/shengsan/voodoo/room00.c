#include <path.h>
inherit ROOM;

void create()
{
	set("short", "�A�L");
	set("long", @LONG
�b�A�����ǳ��O�C�A���˪L�A�H�ۭ��j�L�����˸����ɦa�o�X�F�F��
�n���C�۶ǻA�L�̬O�D�W�w�[��[35m�y�Ŭr�Сz[m�C�L�N���A�o�{�b�A�L�Ǧ��@
�ӵP�l(sign)�C
LONG
	);

	set("item_desc", (["sign":@NOTE
[1;32m
		�Ŭr��(voodoo)�T�a,�D�ФŤJ�C
		�p�G������i�h�ХX�h(out)�C
		�]�\�A�i�H enter voodoo �i�J�Ŭr�СC

[m
NOTE
        ]) );

//	set("exits", ([ /* sizeof() == 1 */
//	    "enter" : "/u/s/shengsan/voodoo/room01",
//            ]));

	set("no_clean_up", 0);
	set("outdoors",1);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_enter","enter");
	add_action("do_out","out");
}

int do_enter(string arg)
{
	object me;
	me=this_player();
	if(!arg || arg!="voodoo")
		return notify_fail("�A�n�i�J���̡H\n");
	if(query_temp("user")>10)
		return notify_fail("�A�H���o�̬O�[���Ӧa���H\n");
	add_temp("user",1);
	me->move(__DIR__"room01");
	return 1;
}

int do_out(string arg)
{
	object me;
	me=this_player();
	if(query_temp("user")>0)
		add_temp("user",-1);
	me->move(SHENGSAN+"wisland/land24");
	return 1;
}
