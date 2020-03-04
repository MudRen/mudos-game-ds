// Room: /tmr/garea/shrine.c

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�A�b�@�����j���q���A�ǻD���_�˪L�����b�ƤQ�~�e�N�Q�@�s���Ǧ�
�ڡA�����q���N�O�ΨӲ����A�H�D���w�C�e�観�y���ɭ��l�A���Y�|�I��
�T�W�j���A���l����\�]�ۤ@�y�K�ذ����j�۹��C
LONG
        );
        set("no_clean_up", 0);
        set("objects",([
        __DIR__"npc/statue":1,
        ]) );
        set("light",1);
        set("exits", ([ /* sizeof() == 1 */
          "west" : __DIR__"forest13",
        ]));

        setup();
}

void reset() // added by Cominging
{
        object statue;
        statue = present("ghost statue", this_object());
        if( statue )
                if( statue->query_ghost() )
                        return;
        ::reset();
}

