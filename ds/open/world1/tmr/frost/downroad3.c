// Room: /open/world1/tmr/freezetaoism/downroad3.c

inherit ROOM;

void create()
{
        set("short", "�a�U�۫�");
        set("long", @LONG
�o�̬O�@�B��j���۫ǡA�w�g�ôe���Ů𤤲V���ۤ@�Ѧ�{���A�|�g
���F�۾����~�A�N�A�]�S����L���F��F�A�b�o��V�ݱo�[�A�ߤ����}��
�e���Pı�V�O�W�j�A�u�O���H�@�I�����Q�ݦb�o��F�C
LONG
        );
        set("current_light", 1);
        set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"downroad2",
]));
        set("no_clean_up", 0);

        setup();
        set("item_desc",([
                "�۾�":"�A�o�{�n�����۾��M�t�T����S�O���@�ˡA���G�O�ؾ�����C\n",
        ]));
        setup();
}
void init()
{
        add_action("do_push","push");
}
int do_push(string arg)
{
        object me=this_player();
        if (arg != "�۾�") return 0;
        if (me->is_fighting() || me->is_busy() )
                return notify_fail("�A�����ۡA�L�kĲ�ʾ����C\n");
        if(!me->move(__DIR__"downroad4") )
                return notify_fail("�A�L�k���\\�aĲ�ʾ����C\n");
        tell_room(environment(this_object()),
                me->query("name")+"�ϫl�a���F�@���i���ʪ��۾��A�����H�Y���S�b�۾����C\n",me);
                
        tell_room(environment(this_player()),
                me->query("name")+"���M�X�{�b�A���e�C\n",me );
        return 1;
}

