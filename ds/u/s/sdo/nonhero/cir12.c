inherit ROOM;

void create()
{
	set("short", "�L�۪k��������");
	set("long", @LONG
�A�{�b�����b�@�����j����Ϯת������A�ӳo�ӹϮ׳Q�e�b�@��
��Ϊ����x���W�C�o�ӥ��x���a�����A�ݨӨ̤j�L�A����O�A�����P
�P�N��w�����D�U�C�A�ݤF�ݥ|�P��A�o�{��Ǫ�����O���Ϊ��A�W
�Y�躡�F��g�A�R���F���Y�P�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"north" : __DIR__"cir7",
  		"south" : __DIR__"cir17",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
