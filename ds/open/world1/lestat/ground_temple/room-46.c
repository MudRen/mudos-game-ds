inherit ROOM;

void create()
{
        set( "short", "�a���}��") ;
        set( "long", @LONG
��Ӭ}�޳Q�}�w���|�|��誺�j�ж��A�|�P���۾��W�J��۳\�h
���e�A���Y�¿p����^�A�E�j���u�{���H�A���Aı�o�ӤH�����p�A�t
�I���F�U�ӽ����C�ж������Y���@�ө��U���j�ӱ�A���b���ۧA�C
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "down" : __DIR__"room-01",
                  "south" : __DIR__"room-45",
        ]));
        set("objects",([
                   __DIR__"../npc/tree_monster" : 1,
                 ]) );
        set("light",0);
        set("item_desc", ([ /* sizeof() == 1 */
        "���e" : "�J��ۤK���ݮݦp�ͪ����s�����e�A�è観�u�K�[�v��Ӥj�r�C\n",
        ]) );
        set("no_clean_up", 0);
        setup();
}
