inherit ROOM;

void create()
{
        set("short", "�}�������");
        set("long", @LONG
�@������������A���@���e�y�A���L�ݨӪe���Z��������h�T�|��
�A�N�ⱼ�U�h�]�L�����A�]���|�Q�o���e�y�ҨR���C���n��O�@�y�p�s��
�A���_��O����D�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
                "south" : __DIR__"kore.c",
                
]));

        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
