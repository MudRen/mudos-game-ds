// Room: /open/world1/tmr/bagi/ghat13.c

inherit ROOM;

void create()
{
        set("short", "�V���e");
        set("long", @LONG
���䤣�ƨB���O�@�����q���V���A�W�Y�G���F�p�F�Ƥت��n���A�N�⻴�\
�A���A�]���i���k���W�h���A�Ϧӭn�p���H�ɥi��Y�򪺳���C�V�������ӥ�
�}���ˤl�A���u���}�f��C�ݤK���ﺡ�F�۶��B����M�����������A�ݼˤl�n
�i�}�̥h�A�o����o�@��M�z���C
LONG
        );
        set("item_desc", ([ /* sizeof() == 2 */
  "�۬}" : "���G�O�D�ѵM���۬}�A���O�}�f�Q�����צ�F�A���o����ӤJ�C\n",
  "����" : "�ɬO�۶��B����M�����������A���צ�F�}�f�A�����O�_�i�H�j��q�L(pass)�C\n",
]));
        set("outdoors", "snow");
        set("no_clean_up", 0);
        set("current_light", 2);
        set("world", "past");
        set("objects",([
                __DIR__"npc/zhou-ying":1,
        ]) );

        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ghat12",
]));

        setup();
}

void init()
{
        add_action("do_pass","pass");
}

int do_pass(string arg)
{
        object me=this_player();
        if(!arg || arg!="����") return 0;
        if( me->is_busy() || me->is_fighting() )
		return notify_fail("�A�����ۡA�S���Ű��䥦�ơC\n");
        if(me->query("level")<25) {
                message_vision("$N�Q�n��צb���f���������@�ǥh�A���N�O��˲M���M����....\n",me);
        } else {
                message_vision("$N��צb���f���������@�ǥh�A�H�Y�i�h�F�۬}��....\n",me);
                me->move(__DIR__"cave1");
                tell_room(me,me->name(1)+"�q�}�~���F�i�ӡA�åB�M�F�M���W������C\n",({me }) );
        }
        return 1;
}


