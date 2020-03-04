inherit ROOM;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�A�i�Hť����񦳽m���m�C���n���A�]�i�Hť��p���í��b�˪L��
�n���C�N�Z���ĤJ�j�۵M�����]�������O�@��֤H���ơA����A�I�K�b
�䤤���ɡA��M�Q�_�A�Ӱ����Ʀӧ@�}�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "west" : __DIR__"room08",
            "south": __DIR__"room05",
            ]));

	set("objects", ([ /* sizeof() == 2 */
            __DIR__"mob/master" : 1,
	    __DIR__"mob/disciple" : 3,
            ]));

	set("no_clean_up", 0);
	set("outdoors",1);

	setup();
	replace_program(ROOM);
}
