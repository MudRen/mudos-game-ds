
inherit ROOM;

void create()
{
        set("short", "�ⶳ�p��-���x�_��");
        set("long", @LONG
�A�����b�ⶳ�p���W�_�����@�B���x���A�b�A�e�褣���B�ѩ^�ۤ@�L
�u���]ù�~�۹��v�A�b���e�ƨB�N�O�p�����V��A�a�W�n����`�A�y�@��
��í�A�N�|�s�u�a�����L�U�s�h�C���誺����g�ѳ��a�ӤϮg�b�A�����W
�A�ϱo�A���������I���L���C���}�ӡC
LONG
        );
        set("current_light", 1);

        set("no_clean_up", 0);
        set("outdoors", "snow");
        set("exits", ([ /* sizeof() == 1 */
         "south":__DIR__"summit1.c"
]));

        setup();
        replace_program(ROOM);
}

