
inherit ROOM;

void create()
{
	set("short", "[1;36m�Ŭr�бо�[m");
	set("long", @LONG
�A�ݨ�F���Y���\�]�ε¿p���˹��~�b�о¸̿��ت��a��C�o�̬O��
�{�̽������F���a��A�C�쭫�n���`��A�Ю{�̳��|�b�o�}�|�ζ}�]�k��
�A�Ŭr�Ъ��ХD�]�|�D�������Ю{�Ŵ��Ы¡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "south": __DIR__"room38",
            ]));

	set("objects", ([ /* sizeof() == 2 */
            __DIR__"mob/leader" : 1,
	    __DIR__"mob/protector" : 2,
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
