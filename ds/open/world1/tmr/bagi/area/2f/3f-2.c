// Room: /open/world1/tmr/bagi/area/2f/3f-2.c

inherit ROOM;

void create()
{
        set("short", "�۪��e");
        set("long", @LONG
�A���B�b�@���e�s���۫Ǥ��A�b�A���e�X�{�O�@�D�̵۩����سy����
���A�����O�۪��W�]���O���U�w�[�����A�۫Ǥ��]�����F�U���L���B��
��M�ƤQ��H���C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "west" : __DIR__"3f-1",
        ]));
        set("item_desc",([
        "�۪�":"�@�D�ݰ_�ӫD�`�p�������ƥ۪��A�W�Y�L��L�աA�����p��}�ҡC\n",
        ]));
        set("current_light", 1);
        set("no_clean_up", 0);
        set("objects",([
                __DIR__"npc/freeze-sun-monster":1,
        ]));
        setup();
        replace_program(ROOM);
}

