inherit ROOM;

void create()
{
        set("short", "�Ѥl�f");
        set("long", @LONG
�A���b�@�������W���Ѥl�f�A���n�i�ݨ�@����{�A�uť�o���Y����
�ǨӦ[�T�ܤ����n���n�A���f���ۨ�W�C�Τj�~�A�ݨӬO������{���O��
�A�n�i�h������{���G���O����a�e���C���F�O���ᳱ�t���Ѥl�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
          "south" : __DIR__"casino",
          "east" : __DIR__"wynd",
        ]));
        set("item_desc",([
        "�C�Τj�~" : @GUYS
��Ӥ��c���j�~���b��{�j���f�ˬd��ȡA���D�A��
�i��(show)�@�ǽ�Ȫ��ҩ������L�̬ݡA�_�h�����i�J�C
GUYS
,
        ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_show","show");
}

int valid_leave(object me, string dir)
{
         return ::valid_leave(me, dir);
        if( dir == "south")
        {
                if (!me->query_temp("casino_enter"))
                {
                        message_vision("�C�Τj�~�����$N�d�F�U�ӡA���D�G�u�o��"+RANK_D->query_respect(me)+"�A�o�i���O�A�ӨӪ��a��a�I�v\n",me);
                        return 0;
                }
                else 
                {
                        message_vision("�C�Τj�~���$N���⻡�D�G�u�o��" +RANK_D->query_respect(me)+"�жi�жi�I�I�v\n", me);
			me->set_temp("casino_enter",0);
                        return ::valid_leave(me, dir);
                }
        }
        return ::valid_leave(me, dir);
}

int do_show(string arg)
{
        object who;
        who=this_player();
        if( !objectp(present("dice", who)) ) return 0;
        if(arg != "��l" && arg !="dice" ) return 0;
        message_vision("$N�q�h�̮��X�F�@�ɻ�l�A�b�C�Τj�~�����e�̤F�̡C\n",who);
        if (who->query_temp("casino_enter")) return 1;
        who->set_temp("casino_enter",1);
        message_vision("�C�Τj�~�J�Ӧa�ݤF��$N��W����l�A���D�G�u��ӳo��"+ who->query("name")+"�]�O�@��P�n���H�C�v\n",who);
        return 1;
}

