inherit ROOM;

void create()
{
	set("short", "�A�L�۶�");
	set("long", @LONG
�b�A�����ǳ��O�C�A���˪L�A�H�ۭ��j�L�����˸����ɦa�o�X�F�F��
�n���C�A�}�U���۶��O�δ��q�����Y�䦨���A�èS������ǲ����B�C�L�N
���A�o�{�b�۶��Ǧ��@�ӵP�l(sign)�C
LONG
	);

	set("item_desc", (["sign":@NOTE
[1;32m
		�Ŭr�иT�a,�D�ФŤJ�C
[m
NOTE
        ]) );

	set("exits", ([ /* sizeof() == 2 */
            "up" : __DIR__"room02",
	    "out": __DIR__"room00",
            ]));

	set("objects", ([ /* sizeof() == 1 */
            __DIR__"mob/believer" : 1,
            ]));

	set("no_clean_up", 0);
	set("outdoors",1);
	setup();
	replace_program(ROOM);
}
