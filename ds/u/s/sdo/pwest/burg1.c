inherit ROOM;

void create()
{
	set("short", "���l�f");
	set("long", @LONG
�p�G�o�X���ЫΥ[�_�Ӫ��E���i�H�s�����l���ܡA����o�̬ݰ_
�ӴN�O���l�f�F�C�]���o�̦��ۤ@����P�A�W���n�����@�Ǥ�r�A�]
�\�O�g�ۧ��l���W�٧a�C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("shout", "���l�f");
	set("exits", ([ /* sizeof() == 4 */
  		"north" : __DIR__"burg2",
  		"east" : __DIR__"burg6",
  		"west" : __DIR__"burg3",
  		"south" : __DIR__"path5",
	]));
	set("item_desc",([
        "��P":	"�z�w�w�w�w�w�w�w�{\n"
        	"�x ��  �� �J �� �x\n"
        	"�x ��  �g���˪L �x\n"
        	"�|�w�s�s�w�s�s�w�}\n",
        ]));

	setup();
}
