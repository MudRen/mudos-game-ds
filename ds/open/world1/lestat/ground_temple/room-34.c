inherit ROOM;

void create()
{
        set( "short", "�a���}��") ;
        set( "long", @LONG
���N���q�D���A���ɶǨӪ��~��Į��n�A�ש�b�e��ݨ�F�@�I
���G�A���_�����G���ϩ��b�l��ۧA�A���A�Q���U�@���a�ĹL�h�A��
�O���䪺�����W���@�Ǧr��A�٬O���ݤ@�U����n�C
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "north" : __DIR__"room-36",
                  "south" : __DIR__"room-33",
        ]));
        set("objects",([
                   __DIR__"../npc/beauty_ghost" : 1,
                 ]) );
        set("light",0);
        set("item_desc", ([ /* sizeof() == 1 */
        "�r��" : "�e��D�O����g��}�A�i�h��ɪť���ܴ��A�Q�i�J�̡A�ФT��I\n",
        ]) );
        set("no_clean_up", 0);
        setup();
}

