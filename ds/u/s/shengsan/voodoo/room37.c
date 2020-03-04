
inherit ROOM;

void create()
{
	set("short", "�Ҥ���");
	set("long", @LONG
�o�̬O�Ŭr�зҤ����a��A���@��Ҥ��v�űM���b�o�ҦU�دS����
���C�A�i�H�ݨ즳�@�ӷҤ��Ϊ��Ҥ��l(furnace)�b�o�ж����������A�٦�
�@�Ǥu��ηҤ����ī~���Ƴ��b��W�C
LONG
	);

	set("item_desc", (["furnace":@NOTE
[1;36m
�o�ӷҤ��l�O�M���ҥX�U�د��_�Ĥ������Τu��A�]�\�A�|�Q�h�N�N��
(touch furnace)�C
[m
NOTE
        ]) );

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room35",
            ]));

	set("objects", ([ /* sizeof() == 1 */
            __DIR__"mob/alchemist" : 1,
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
}

void init()
{
  add_action("do_touch","touch");
}

int do_touch(string arg)
{
object me;
me=this_player();
  if (!arg || arg!="furnace") return notify_fail("�A�n�N����?\n");
    message_vision("$N[1;36m�N�F�Ҥ��l�@�U......[1;31m�z!!!�n�S��[1;36m...[m\n",this_player());
    me->add("hp",-(10+random(10)));
//	message_vision("$N�Q�S�ˤF�C\n",this_player());
	message_vision("$N�Q�S�ˤF�C\n",me);
	return 1;
}
