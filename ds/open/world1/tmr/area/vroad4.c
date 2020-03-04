inherit ROOM;

void create()
{
        set("short", "��D");
        set("long", @LONG
�A�����b�@����D���A�u���F��@�y�j�c�A��ۤ@�D�¦����A��
��V�A��۶º������A�ƬO���ơA��_���O���ݤ���������A�����p��
�X�J�C��e�ݦ��@���G�i��A�W�Y�K�ۤ@�Ȥ��i�C���_�i�ݨ�@�y�p�s��
�A�b��n����G�����p�Ѥl�A�n��O���p��D�C
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
	  "south" : __DIR__"vroad5",
	  "north" : __DIR__"vroad2",
	  "southwest" : __DIR__"vroad6",
	]));
	set("item_desc",([
	"���i" : "�@�i�w�x�����ȱi�A�W�Y�g�ۡG�u�K��c�v�C\n",
      "����" : "�@�j�����K�ֳ򦨪���A�ݨӦ~�N�ᬰ�[���A�A�b�𨤬ݨ�@�Ӥp�}�}�C\n",
	]) );
        
	set("outdoors","land");
	set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        object me;
        me=this_player();
        if(!arg|| arg!="�}�}") return 0;
        message_vision("$N�@�Y���A�p�i�F�@�ӯ}�}�C\n",me);
        me->move(__DIR__"eight-room");
        tell_room(environment(me),me->query("name")+"���M�X�{�b�A�����e�C\n",({ me }) );
        return 1;
}

