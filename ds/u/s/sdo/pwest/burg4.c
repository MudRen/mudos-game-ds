inherit ROOM;

void create()
{
	set("short", "���l�̤p��");
	set("long", @LONG
�o���p������]���۳\�h���A�СA�i�O���X���A�и̦��Q�}�a�L
������A�ݨӨ��ǳQ�}�a�L���A�и̪��@�������ব���F�C�p�����_
�䦳�ۤ@��H�a�A�ЫΪ����䦳�ۤ@�ӭܮw�A�ݨӳo�ǹA�Ъ��D�H�N
�O����H�a�F�C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  		"north" : __DIR__"house4",
  		"east" : __DIR__"burg3",
  		"west" : __DIR__"burg5",
	]));
	set("item_desc",([
        "����":	"�ݰ_�Ӧn���O�Q�@�s���Z���ͪ��v�h�L���ˤl�C\n",
        "�ܮw":	"�@�ӱM���s��@���a��C\n",
        ]));

	setup();
	replace_program(ROOM);
}
