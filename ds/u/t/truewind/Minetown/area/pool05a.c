inherit ROOM;

void create()
{
        set("short", "�a�U���D");
        set("long", @LONG
�u�ۤ��D�Ө�o�̡A�@������\�b�����A�n���ܤ[�S�H�ιL�C��
���X�i��l��Ȥl�A�ݨӴ��g������H�b�o�̫ݹL�A���F�ǹ��窺
�ˤl�C��W���⭷���A���L�w�g������ʤF�C
LONG
        );
        set("current_light", 0);
        set("exits", ([ /* sizeof() == 1 */
        "south" : __DIR__"pool05",
]));

	setup();
}